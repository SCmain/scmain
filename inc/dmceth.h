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

#ifndef INCLUDE_ETHERNET
#define INCLUDE_ETHERNET

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#ifndef SOCKET
   #define SOCKET int
#endif

#ifndef SOCKADDR_IN
   #define SOCKADDR_IN struct sockaddr_in
#endif

#ifndef SOCKET_ERROR
   #define SOCKET_ERROR -1
#endif

#define MAKEWORD(a, b) ((WORD)(((UCHAR)(a)) | ((WORD)((UCHAR)(b))) << 8))

#define MAX_WINSOCK_UDP_WRITE       400
#define MAX_WINSOCK_TCP_WRITE       400
#define MULTICAST_IPADDRESS         "239.255.19.56"
#define GALIL_TCPIP_PORT            5000
#define GALIL_TCPIP_PORT_MESSAGES   5005

extern long ETHERNETReadData(int iIndex, PCHAR pchResponse, ULONG cbResponse, PULONG pulBytesRead);
extern long ETHERNETWriteData(int iIndex, PCHAR pchCommand, ULONG cbCommand, PULONG pulBytesWritten);
extern long ETHERNETClear(int iIndex);
extern int ETHERNETCharAvailableInput(int iIndex);
extern long OpenSocket(int iIndex);
extern long CloseSocket(int iIndex);

long ReadSocket(int iIndex, PCHAR pchResponse, ULONG cbResponse, PULONG pulBytesRead);
long ReadSocketMulticast(int iIndex, PCHAR pchResponse, ULONG cbResponse, PULONG pulBytesRead);
long WriteSocket(int iIndex, PCHAR pchCommand, ULONG cbCommand, PULONG pulBytesWritten);
long WriteSocketMulticast(int iIndex, PCHAR pchCommand, ULONG cbCommand, PULONG pulBytesWritten);
int FillBootpRep(unsigned char* data, int length, ULONG ulIPAddress, PUSHORT pusModel, PUSHORT pusSerialNumber);
int WillReadBlock(SOCKET sock);

#endif /* INCLUDE_ETHERNET */
