/*  =========================================================================
    fty_common_nut_credentials - class description

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

#pragma once

#include <fty_common_nut_types.h>
#include <fty_security_wallet.h>

namespace fty::nut {

/// @brief Convert 42ity security wallet document to NUT configuration.
/// @param doc Document to configure driver with.
/// @param driver Driver to configure document with.
/// @return NUT configuration values
/// @throw std::runtime_error if the document can't be converted with this driver.
KeyValues convertSecwDocumentToKeyValues(const secw::DocumentPtr& doc, const std::string& driver);

} // namespace fty::nut
