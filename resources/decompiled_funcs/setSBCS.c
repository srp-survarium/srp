void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  unsigned __int8 *mbctype; // eax
  int v3; // ecx
  int v4; // edi
  unsigned __int8 *mbcasemap; // eax
  int v6; // esi

  memset((int)ptmbci->mbctype, 0, sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  mbctype = ptmbci->mbctype;
  v3 = (char *)&__initialmbcinfo - (char *)ptmbci;
  v4 = 257;
  do
  {
    *mbctype = mbctype[v3];
    ++mbctype;
    --v4;
  }
  while ( v4 );
  mbcasemap = ptmbci->mbcasemap;
  v6 = 256;
  do
  {
    *mbcasemap = mbcasemap[v3];
    ++mbcasemap;
    --v6;
  }
  while ( v6 );
}
