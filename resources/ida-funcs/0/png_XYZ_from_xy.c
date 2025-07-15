int __cdecl png_XYZ_from_xy(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v10; // esi
  int v11; // esi
  int v12; // [esp+4h] [ebp-18h] BYREF
  int v13; // [esp+8h] [ebp-14h] BYREF
  int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch] BYREF
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h] BYREF

  if ( a2 < 0 || a2 > (int)&loc_186A0 )
    return 1;
  if ( a3 < 0 || a3 > (int)&loc_186A0 - a2 )
    return 1;
  if ( a4 < 0 || a4 > (int)&loc_186A0 )
    return 1;
  if ( a5 < 0 || a5 > (int)&loc_186A0 - a4 )
    return 1;
  if ( a6 < 0 || a6 > (int)&loc_186A0 )
    return 1;
  if ( a7 < 0 || a7 > (int)&loc_186A0 - a6 )
    return 1;
  if ( a8 < 0 || a8 > (int)&loc_186A0 )
    return 1;
  if ( a9 < 0 || a9 > (int)&loc_186A0 - a8 )
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
  if ( !png_muldiv(a1, a2, &loc_186A0, v12) )
    return 1;
  if ( !png_muldiv(a1 + 4, a3, &loc_186A0, v12) )
    return 1;
  if ( !png_muldiv(a1 + 8, (char *)&loc_186A0 - a2 - a3, &loc_186A0, v12) )
    return 1;
  if ( !png_muldiv(a1 + 12, a4, &loc_186A0, v17) )
    return 1;
  if ( !png_muldiv(a1 + 16, a5, &loc_186A0, v17) )
    return 1;
  if ( !png_muldiv(a1 + 20, (char *)&loc_186A0 - a4 - a5, &loc_186A0, v17) )
    return 1;
  if ( !png_muldiv(a1 + 24, a6, v14, &loc_186A0) )
    return 1;
  if ( png_muldiv(a1 + 28, a7, v14, &loc_186A0) )
    return png_muldiv(a1 + 32, (char *)&loc_186A0 - a6 - a7, v14, &loc_186A0) == 0;
  return 1;
}
