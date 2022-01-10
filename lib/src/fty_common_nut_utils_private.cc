/*  =========================================================================
    fty_common_nut_utils_private - class description

    Copyright (C) 2014 - 2020 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#include "fty_common_nut_utils_private.h"
#include <fty_log.h>

namespace fty::nut::priv {

int runCommand(
    const std::string& cmd, const Process::Arguments& args, std::string& stdout, std::string& stderr, int timeout)
{
    std::stringstream fullCommand;
    fullCommand << cmd << " ";
    for (const auto& i : args) {
        fullCommand << i << " ";
    }

    int msTimeout = timeout * 1000;

    std::string fullCommandStr = fullCommand.str();
    logInfo("Running command {} (with {} seconds timeout)...", fullCommandStr, timeout);

    Process proc(cmd, args, Capture::Out | Capture::Err);
    if (auto pid = proc.run(); !pid) {
        logError("{}", pid.error());
        return -1;
    }

    const int WAIT_TIMEOUT_LOOP = 2000;
    int count = msTimeout / WAIT_TIMEOUT_LOOP;
    if (count < 1) count = 1;
    bool resulOk = false;
    std::string tmp;
    while (count > 0) {
        auto res = proc.wait(WAIT_TIMEOUT_LOOP);
        if (!res && res.error() == "timeout") {
            count --;
            tmp += proc.readAllStandardOutput();
            logTrace("Wait process timeout, count={} tmp.size={}", count, tmp.size());
            continue;
        } else if (!res) {
            logWarn("Cannot wait process, error: {}", res.error());
            break;
        } else {
            tmp += proc.readAllStandardOutput();
            logTrace("Wait process count={} *res={} tmp.size={}", count, *res, tmp.size());
            resulOk = (*res == 0);
            break;
        }
    }

    if (resulOk) {
        stdout = tmp;
    }
    stderr = proc.readAllStandardError();

    if (!stdout.empty()) {
        logTrace("Standard output:\n{}", stdout);
    }
    if (!stderr.empty()) {
        logTrace("Standard error:\n{}", stderr);
    }

    if (!resulOk) {
        if (count < 0) {
            logError("Execution of command {} failed with timeout.", cmd);
            return -2;
        }
        else {
            logError("Execution of command {} failed during waiting", cmd);
            return -3;
        }
    }
    logInfo("Execution of command {} succeeded.", cmd);
    return 0;
}

} // namespace fty::nut::priv
