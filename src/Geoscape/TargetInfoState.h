/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM_TARGETINFOSTATE_H
#define OPENXCOM_TARGETINFOSTATE_H

#include <string>
#include "../Engine/State.h"
#include "../Resource/LangString.h"

class TextButton;
class Window;
class Text;
class Target;

/**
 * Generic window used to display all the
 * crafts targeting a certain point on the map.
 */
class TargetInfoState : public State
{
private:
	Target *_target;

	TextButton *_btnOk;
	Window *_window;
	Text *_txtTitle, *_txtTargetted, *_txtFollowers;
public:
	/// Creates the Target Info state.
	TargetInfoState(Game *game, Target *target);
	/// Cleans up the Target Info state.
	~TargetInfoState();
	/// Handler for clicking the OK button.
	void btnOkClick(SDL_Event *ev, int scale);
};

#endif
