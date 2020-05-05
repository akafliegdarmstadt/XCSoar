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

#include "FuelFlowSetup.hpp"
#include "Interface.hpp"
#include "Components.hpp"
#include "Blackboard/DeviceBlackboard.hpp"
#include "Form/DataField/Integer.hpp"
#include "Form/DataField/Listener.hpp"
#include "Form/Edit.hpp"
#include "Widget/RowFormWidget.hpp"
#include "Language/Language.hpp"
#include "UIGlobals.hpp"
#include "Operation/MessageOperationEnvironment.hpp"

class FuelFlowSetupPanel : public RowFormWidget,
                            private DataFieldListener {
public:
    FuelFlowSetupPanel():RowFormWidget(UIGlobals::GetDialogLook()) {}

    virtual void Prepare(ContainerWindow &parent,
                        const PixelRect &rc) override;

private:
    virtual void OnModified(DataField &df) override;
};

void
FuelFlowSetupPanel::OnModified(DataField &_df)
{

}

void
FuelFlowSetupPanel::Prepare(ContainerWindow &parent, const PixelRect &rc)
{
    WndProperty *wp;
    wp = AddInteger(_("TPL"),
                    _("Calibration factor for fuel flow. Ticks per liter."),
                    _("%5d"),
                    _("%5d"),
                    10,
                    10000,
                    10,
                    8600,
                    this);

    wp->RefreshDisplay();
}

Widget *
LoadFuelFlowSetupPanel(unsigned id)
{
    return new FuelFlowSetupPanel();
}