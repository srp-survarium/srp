double __cdecl stlp_std::priv::_Stl_atod(int ndigit, int dexp)
{
  char *buffer; // ecx
  char *v3; // ebx
  unsigned __int64 v4; // rdi
  int v6; // ebx
  int v7; // ebp
  int v8; // ebp
  char v9; // bl
  unsigned __int64 v10; // rdi
  int v11; // ecx
  unsigned __int64 v12; // rax
  unsigned int v13; // edi
  unsigned int v14; // ecx
  unsigned int v15; // kr00_4
  stlp_std::priv::_Double_rep drep; // [esp+10h] [ebp-10h] BYREF

  v3 = buffer;
  v4 = 0;
  if ( buffer >= &buffer[ndigit] )
    return 0.0;
  do
    v4 = *v3++ + 10 * v4;
  while ( v3 < &buffer[ndigit] );
  if ( !v4 )
    return 0.0;
  v6 = 0;
  if ( HIDWORD(v4) )
    v6 = 32;
  if ( v4 >> ((unsigned __int8)v6 + 16) )
    v6 += 16;
  if ( v4 >> ((unsigned __int8)v6 + 8) )
    v6 += 8;
  if ( v4 >> ((unsigned __int8)v6 + 4) )
    v6 += 4;
  if ( v4 >> ((unsigned __int8)v6 + 2) )
    v6 += 2;
  if ( v4 >> ((unsigned __int8)v6 + 1) )
    ++v6;
  if ( v4 >> v6 )
    ++v6;
  drep.ival = v4 << (64 - (unsigned __int8)v6);
  stlp_std::priv::_Stl_tenscale(dexp, &drep.ival, &ndigit);
  v7 = ndigit + v6;
  if ( ndigit + v6 > -1022 )
  {
    v13 = drep.ival >> 11;
    v14 = HIDWORD(drep.val) >> 11;
    if ( (LOWORD(drep.val) & 0x400) != 0 && ((LOWORD(drep.val) & 0x800) != 0 || (LOWORD(drep.val) & 0x3FF) != 0) )
    {
      v15 = v13 + 1;
      v14 = (__PAIR64__(v14, v13++) + 1) >> 32;
      if ( (v14 & 0xFFE00000) != 0 )
      {
        v13 = __PAIR64__(v14, v15) >> 1;
        v14 >>= 1;
        ++v7;
      }
    }
    if ( v7 > 1024 )
    {
      drep.val = INFINITY;
      return INFINITY;
    }
    LODWORD(drep.val) = v13;
    HIDWORD(drep.val) = v14 & 0x800FFFFF | ((((_WORD)v7 + 1022) & 0x7FF) << 20);
  }
  else
  {
    v8 = v7 + 1022;
    if ( v8 < -53 || (v9 = 12 - v8, 12 - v8 > 64) )
    {
      drep.val = 0.0;
      return 0.0;
    }
    if ( v8 == -52 )
    {
      v10 = drep.ival & 0x7FFFFFFFFFFFFFFFLL;
      v11 = HIDWORD(drep.val) >> 31;
      v12 = 0;
    }
    else
    {
      v10 = drep.ival & ((1LL << v9) - 2);
      v12 = drep.ival >> v9;
      v11 = ((unsigned __int8)(drep.ival >> v9) - 1) & 1;
    }
    drep.ival = v12;
    if ( v11 && ((v12 & 1) != 0 || v10) )
    {
      drep.ival = v12 + 1;
      if ( v12 == 0xFFFFFFFFFFFFFLL )
      {
        drep.val = 2.225073858507201e-308;
        return 2.225073858507201e-308;
      }
    }
  }
  return drep.val;
}
