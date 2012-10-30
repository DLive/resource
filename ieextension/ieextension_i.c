

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sun Jan 01 14:02:47 2012
 */
/* Compiler settings for .\ieextension.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_Idlext,0x71B47AE4,0x9577,0x44D0,0xA9,0x7B,0xE3,0x07,0xDE,0x63,0x52,0xBF);


MIDL_DEFINE_GUID(IID, LIBID_ieextensionLib,0x3816CF9A,0x2607,0x4613,0xB7,0x8B,0xCE,0xE6,0x97,0x99,0xE5,0xD2);


MIDL_DEFINE_GUID(IID, DIID__IdlextEvents,0x3D26EA5C,0xA518,0x4B38,0xA0,0x2E,0xE4,0xDA,0x83,0xE3,0x32,0x62);


MIDL_DEFINE_GUID(CLSID, CLSID_dlext,0x2742B128,0xBC1B,0x4254,0xBB,0xBB,0x7E,0x19,0xFF,0xB0,0xF4,0x4B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



