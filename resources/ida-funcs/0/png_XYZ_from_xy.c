int __cdecl png_XYZ_from_xy(
        int a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        int a5,
        unsigned int a6,
        int a7,
        unsigned int a8,
        int a9)
{
  int v10; // esi
  int v11; // esi
  int v12; // [esp+4h] [ebp-18h] BYREF
  int v13; // [esp+8h] [ebp-14h] BYREF
  int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch] BYREF
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h] BYREF

  if ( a2 > 0x186A0 )
    return 1;
  if ( a3 < 0 || a3 > (int)(100000 - a2) )
    return 1;
  if ( a4 > 0x186A0 )
    return 1;
  if ( a5 < 0 || a5 > (int)(100000 - a4) )
    return 1;
  if ( a6 > 0x186A0 )
    return 1;
  if ( a7 < 0 || a7 > (int)(100000 - a6) )
    return 1;
  if ( a8 > 0x186A0 )
    return 1;
  if ( a9 < 0 || a9 > (int)(100000 - a8) )
    return 1;
  if ( !png_muldiv(&v15, a4 - a6, a3 - a7, 7) )
    return 2;
  if ( !png_muldiv(&v13, a5 - a7, a2 - a6, 7) )
    return 2;
  v16 = v15 - v13;
  if ( !png_muldiv(&v15, a4 - a6, a9 - a7, 7) )
    return 2;
  if ( !png_muldiv(&v13, a5 - a7, a8 - a6, 7) )
    return 2;
  if ( !png_muldiv(&v12, a9, v16, v15 - v13) || v12 <= a9 )
    return 1;
  if ( !png_muldiv(&v15, a3 - a7, a8 - a6, 7) )
    return 2;
  if ( !png_muldiv(&v13, a2 - a6, a9 - a7, 7) )
    return 2;
  if ( !png_muldiv(&v17, a9, v16, v15 - v13) || v17 <= a9 )
    return 1;
  v10 = png_reciprocal(a9);
  v11 = v10 - png_reciprocal(v12);
  v14 = v11 - png_reciprocal(v17);
  if ( v14 <= 0 )
    return 1;
  if ( !png_muldiv(a1, a2, 100000, v12) )
    return 1;
  if ( !png_muldiv(a1 + 4, a3, 100000, v12) )
    return 1;
  if ( !png_muldiv(a1 + 8, 100000 - a2 - a3, 100000, v12) )
    return 1;
  if ( !png_muldiv(a1 + 12, a4, 100000, v17) )
    return 1;
  if ( !png_muldiv(a1 + 16, a5, 100000, v17) )
    return 1;
  if ( !png_muldiv(a1 + 20, 100000 - a4 - a5, 100000, v17) )
    return 1;
  if ( !png_muldiv(a1 + 24, a6, v14, 100000) )
    return 1;
  if ( png_muldiv(a1 + 28, a7, v14, 100000) )
    return png_muldiv(a1 + 32, 100000 - a6 - a7, v14, 100000) == 0;
  return 1;
}
