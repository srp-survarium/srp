int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // cl
  unsigned int j; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned __int16 *mbulinfo; // eax
  int v12; // ecx
  unsigned __int16 *v13; // ecx
  int v14; // edx
  unsigned __int8 *v15; // eax
  int v16; // ecx
  int v17; // edx
  unsigned int irg; // [esp+Ch] [ebp-20h]
  unsigned int icp; // [esp+10h] [ebp-1Ch]
  unsigned int icpa; // [esp+10h] [ebp-1Ch]
  _cpinfo cpinfo; // [esp+14h] [ebp-18h] BYREF
  int codepagea; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(codepage);
  codepagea = SystemCP;
  if ( SystemCP )
  {
    icp = 0;
    for ( i = 0; i < 5; ++i )
    {
      if ( _rgcode_page_info[i].code_page == SystemCP )
      {
        memset((int)ptmbci->mbctype, 0, sizeof(ptmbci->mbctype));
        irg = 0;
        v8 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v8;
        do
        {
          while ( *v8 )
          {
            LOBYTE(v9) = v8[1];
            if ( !(_BYTE)v9 )
              break;
            v10 = *v8;
            v9 = (unsigned __int8)v9;
            while ( v10 <= v9 )
            {
              ptmbci->mbctype[v10 + 1] |= _rgctypeflag[irg];
              v9 = v8[1];
              ++v10;
            }
            SystemCP = codepagea;
            v8 += 2;
          }
          ++irg;
          v8 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v13 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v12);
        v14 = 6;
        do
        {
          *mbulinfo++ = *v13++;
          --v14;
        }
        while ( v14 );
LABEL_26:
        setSBUpLow(ptmbci);
        return 0;
      }
      ++icp;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage((unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(SystemCP, &cpinfo) )
    {
      memset((int)ptmbci->mbctype, 0, sizeof(ptmbci->mbctype));
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( cpinfo.MaxCharSize <= 1 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] )
        {
          v5 = &cpinfo.LeadByte[1];
          do
          {
            v6 = *v5;
            if ( !*v5 )
              break;
            for ( j = *(v5 - 1); j <= v6; ++j )
              ptmbci->mbctype[j + 1] |= 4u;
            v5 += 2;
          }
          while ( *(v5 - 1) );
        }
        v15 = &ptmbci->mbctype[2];
        v16 = 254;
        do
        {
          *v15++ |= 8u;
          --v16;
        }
        while ( v16 );
        ptmbci->mblcid = CPtoLCID(ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v17;
      }
      *(_DWORD *)ptmbci->mbulinfo = 0;
      *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
      *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
      goto LABEL_26;
    }
    if ( !fSystemSet )
      return -1;
  }
  setSBCS(ptmbci);
  return 0;
}
