int png_XYZ_from_xy_checked(int a1, int a2, ...)
{
  unsigned int v3[8]; // [esp+0h] [ebp-2Ch] BYREF
  int v4; // [esp+28h] [ebp-4h]
  int v5; // [esp+3Ch] [ebp+10h] BYREF
  va_list va; // [esp+3Ch] [ebp+10h]
  int v7; // [esp+40h] [ebp+14h]
  int v8; // [esp+44h] [ebp+18h]
  int v9; // [esp+48h] [ebp+1Ch]
  int v10; // [esp+4Ch] [ebp+20h]
  int v11; // [esp+50h] [ebp+24h]
  int v12; // [esp+54h] [ebp+28h]
  int v13; // [esp+58h] [ebp+2Ch]
  va_list va1; // [esp+5Ch] [ebp+30h] BYREF

  va_start(va1, a2);
  va_start(va, a2);
  v5 = va_arg(va1, _DWORD);
  v7 = va_arg(va1, _DWORD);
  v8 = va_arg(va1, _DWORD);
  v9 = va_arg(va1, _DWORD);
  v10 = va_arg(va1, _DWORD);
  v11 = va_arg(va1, _DWORD);
  v12 = va_arg(va1, _DWORD);
  v13 = va_arg(va1, _DWORD);
  qmemcpy(v3, va, sizeof(v3));
  v4 = png_XYZ_from_xy(a2, v3[0], v3[1], v3[2], v3[3], v3[4], v3[5], v3[6], v3[7]);
  if ( !v4 )
    return 1;
  if ( v4 != 1 )
    png_error(a1, (int)"internal error in png_XYZ_from_xy");
  png_warning(a1, "extreme cHRM chunk cannot be converted to tristimulus values");
  return 0;
}
