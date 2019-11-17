/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2016 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#include "Device/Driver/DKMCH.hpp"
#include "Device/Driver.hpp"
#include "Device/Util/NMEAWriter.hpp"
#include "NMEA/Checksum.hpp"
#include "NMEA/Info.hpp"
#include "NMEA/Derived.hpp"
#include "NMEA/InputLine.hpp"
#include "Units/System.hpp"
#include "Operation/Operation.hpp"
#include "LogFile.hpp"

constexpr int CALIBRATION_FACTOR = 8600;

class DKMCHDevice : public AbstractDevice {
  __attribute__((unused)) Port &port;

public:
  DKMCHDevice(Port &_port):port(_port) {}

  bool ParseNMEA(const char *line, NMEAInfo &info) override;
  static bool PFLO(NMEAInputLine &line, NMEAInfo &info);
};

bool
DKMCHDevice::ParseNMEA(const char *_line, NMEAInfo &info)
{
  if (!VerifyNMEAChecksum(_line))
    return false;

  NMEAInputLine line(_line);
  if (line.ReadCompare("$PFLO"))
    return PFLO(line, info);

  return false;
}

bool
DKMCHDevice::PFLO(NMEAInputLine &line, NMEAInfo &info)
{
  info.fuel_flow = 42 * CALIBRATION_FACTOR;
  info.fuel_flow_available.Update(info.clock);

  return true;
}

static Device *
DKMCHCreateOnPort(const DeviceConfig &config, Port &com_port)
{
  return new DKMCHDevice(com_port);
}

const struct DeviceRegister dkmch_driver = {
  _T("D-KMCH"),
  _T("D-KMCH"),
  DeviceRegister::SEND_SETTINGS,
  DKMCHCreateOnPort,
};
