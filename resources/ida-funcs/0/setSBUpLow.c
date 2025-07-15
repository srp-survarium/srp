void __usercall setSBUpLow(threadmbcinfostruct *ptmbci@<esi>)
{
  unsigned int i; // eax
  unsigned __int8 v2; // al
  unsigned __int8 *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned __int8 *v6; // ebx
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int8 v9; // cl
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // dl
  int v13; // [esp+8h] [ebp-51Ch]
  _cpinfo CPInfo; // [esp+Ch] [ebp-518h] BYREF
  unsigned __int16 CharType[256]; // [esp+20h] [ebp-504h] BYREF
  char v16[256]; // [esp+220h] [ebp-304h] BYREF
  char DestStr[256]; // [esp+320h] [ebp-204h] BYREF
  char SrcStr[256]; // [esp+420h] [ebp-104h] BYREF

  if ( GetCPInfo(ptmbci->mbcodepage, &CPInfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      SrcStr[i] = i;
    v2 = CPInfo.LeadByte[0];
    SrcStr[0] = 32;
    if ( CPInfo.LeadByte[0] )
    {
      v3 = &CPInfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset((int)&SrcStr[v4], 32, v5 - v4 + 1);
        v6 = v3 + 1;
        v2 = *v6;
        v3 = v6 + 1;
      }
      while ( v2 );
    }
    __crtGetStringTypeA(0, 1u, SrcStr, 256, CharType, ptmbci->mbcodepage, ptmbci->mblcid, 0);
    __crtLCMapStringA(0, ptmbci->mblcid, 0x100u, SrcStr, 256, (wchar_t *)DestStr, 256, ptmbci->mbcodepage, 0);
    __crtLCMapStringA(0, ptmbci->mblcid, 0x200u, SrcStr, 256, (wchar_t *)v16, 256, ptmbci->mbcodepage, 0);
    v7 = 0;
    while ( 1 )
    {
      v8 = CharType[v7];
      if ( (v8 & 1) != 0 )
      {
        ptmbci->mbctype[v7 + 1] |= 0x10u;
        v9 = DestStr[v7];
      }
      else
      {
        if ( (v8 & 2) == 0 )
        {
          ptmbci->mbcasemap[v7] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v7 + 1] |= 0x20u;
        v9 = v16[v7];
      }
      ptmbci->mbcasemap[v7] = v9;
LABEL_16:
      if ( (unsigned int)++v7 >= 0x100 )
        return;
    }
  }
  v10 = 0;
  v13 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v11 = &ptmbci->mbcasemap[v10];
    if ( (unsigned int)&v11[v13 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x10u;
      v12 = v10 + 32;
LABEL_23:
      *v11 = v12;
      goto LABEL_25;
    }
    if ( (unsigned int)&v11[v13] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x20u;
      v12 = v10 - 32;
      goto LABEL_23;
    }
    *v11 = 0;
LABEL_25:
    ++v10;
  }
  while ( v10 < 0x100 );
}
