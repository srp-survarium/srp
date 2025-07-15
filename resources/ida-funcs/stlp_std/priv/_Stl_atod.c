double __cdecl stlp_std::priv::_Stl_atod(int ndigit, int dexp)
{
  unsigned int v2; // ecx
  char *v3; // ebx
  unsigned __int64 v4; // rdi
  int v6; // ebx
  int v7; // ebp
  int v8; // ebp
  char v9; // bl
  __int64 v10; // rdi
  int v11; // ecx
  double v12; // rax
  double v13; // rax
  unsigned int v14; // edi
  unsigned int v15; // ecx
  unsigned int v16; // kr00_4
  double v17; // [esp+10h] [ebp-10h] BYREF

  v3 = (char *)v2;
  v4 = 0;
  if ( v2 >= v2 + ndigit )
    return 0.0;
  do
    v4 = *v3++ + 10 * v4;
  while ( (unsigned int)v3 < v2 + ndigit );
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
  *(_QWORD *)&v17 = v4 << (64 - (unsigned __int8)v6);
  stlp_std::priv::_Stl_tenscale(dexp, (unsigned __int64 *)&v17, &ndigit);
  v7 = ndigit + v6;
  if ( ndigit + v6 > -1022 )
  {
    v14 = *(_QWORD *)&v17 >> 11;
    v15 = HIDWORD(v17) >> 11;
    if ( (LOWORD(v17) & 0x400) != 0 && ((LOWORD(v17) & 0x800) != 0 || (LOWORD(v17) & 0x3FF) != 0) )
    {
      v16 = v14 + 1;
      v15 = (__PAIR64__(v15, v14++) + 1) >> 32;
      if ( (v15 & 0xFFE00000) != 0 )
      {
        v14 = __PAIR64__(v15, v16) >> 1;
        v15 >>= 1;
        ++v7;
      }
    }
    if ( v7 > 1024 )
    {
      v17 = INFINITY;
      return INFINITY;
    }
    LODWORD(v17) = v14;
    HIDWORD(v17) = v15 & 0x800FFFFF | ((((_WORD)v7 + 1022) & 0x7FF) << 20);
  }
  else
  {
    v8 = v7 + 1022;
    if ( v8 < -53 || (v9 = 12 - v8, 12 - v8 > 64) )
    {
      v17 = 0.0;
      return 0.0;
    }
    if ( v8 == -52 )
    {
      v10 = *(_QWORD *)&v17 & 0x7FFFFFFFFFFFFFFFLL;
      v11 = HIDWORD(v17) >> 31;
      v12 = 0.0;
    }
    else
    {
      v10 = *(_QWORD *)&v17 & ((1LL << v9) - 2);
      *(_QWORD *)&v12 = *(_QWORD *)&v17 >> v9;
      v11 = ((unsigned __int8)(*(_QWORD *)&v17 >> v9) - 1) & 1;
    }
    v17 = v12;
    if ( v11 && ((LOBYTE(v12) & 1) != 0 || v10) )
    {
      *(_QWORD *)&v13 = *(_QWORD *)&v12 + 1LL;
      v17 = v13;
      if ( *(_QWORD *)&v13 == __PAIR64__(&loc_100000, 0) )
      {
        v17 = COERCE_DOUBLE(__PAIR64__(HIDWORD(v13), 0));
        return COERCE_DOUBLE(__PAIR64__(HIDWORD(v13), 0));
      }
    }
  }
  return v17;
}
