/*  ========================================================================
    Copyright (C) 2020 Eaton
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
    ========================================================================
*/

#include <catch2/catch.hpp>
#include "fty_common_nut.h"

#define SELFTEST_RO "tests/selftest-ro"

TEST_CASE("common nut convert test")
{
    // clang-format off
    const static std::vector<std::pair<std::string, std::string>> invalidTestCases = {
        {SELFTEST_RO "/nosuchfile.conf",        "noSuchMapping"},
        {SELFTEST_RO "/mappingInvalid.conf",    "noSuchMapping"},
        {SELFTEST_RO "/mappingValid.conf",      "noSuchMapping"},
        {SELFTEST_RO "/mappingValid.conf",      "emptyMapping"},
        {SELFTEST_RO "/mappingValid.conf",      "badMapping"}
    };
    // clang-format on

    // Test invalid mapping cases.
    for (const auto& i : invalidTestCases) {
        bool caughtException = false;
        try {
            fty::nut::KeyValues mapping = fty::nut::loadMapping(i.first, i.second);
        } catch (...) {
            caughtException = true;
        }
        CHECK(caughtException);
    }

    // Test valid mapping cases.
    const auto physicsMapping   = fty::nut::loadMapping(SELFTEST_RO "/mappingValid.conf", "physicsMapping");
    const auto inventoryMapping = fty::nut::loadMapping(SELFTEST_RO "/mappingValid.conf", "inventoryMapping");
    CHECK(!physicsMapping.empty());
    CHECK(!inventoryMapping.empty());
}
