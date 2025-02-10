/***************************************************************\
 *
 *              Copyright (c) 2007 SCFI Automation, Inc.
 * Code taken over by Georges Sancosme after the author (Canh Le) passed away and
 * published under GNU GPLv3
 *
 * Original Author      : Canh Le (Deceased)
 * Current Maintainer   : Georges Sancosme (georges@sancosme.net)
 * Maintained Since     : 13.01.2025
 * Created On           : 04.06.2007
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef INCLUDE_FIRMWARE
#define INCLUDE_FIRMWARE

#define CONTROL_B     0x02
#define CONTROL_M     0x0D
#define CONTROL_O     0x0F
#define CONTROL_R     0x12
#define CONTROL_S     0x13

#define DOWNLOAD_BUFFER_SIZE 64

LONG TurnOnMonitor(HANDLEDMC hdmc);
LONG CheckResult(HANDLEDMC hdmc);
VOID Delay(ULONG ulDelay);

#endif /* INCLUDE_FIRMWARE */
