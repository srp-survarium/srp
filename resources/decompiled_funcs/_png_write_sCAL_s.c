int __cdecl png_write_sCAL_s(_DWORD *a1, char a2, char *lpString, char *a4)
{
  int count; // [esp+0h] [ebp-54h]
  unsigned __int8 buf; // [esp+4h] [ebp-50h] BYREF
  unsigned __int8 dst[67]; // [esp+5h] [ebp-4Fh] BYREF
  int v8; // [esp+4Ch] [ebp-8h]
  int v9; // [esp+50h] [ebp-4h]

  v9 = lstrlenA(lpString);
  count = lstrlenA(a4);
  v8 = v9 + count + 2;
  if ( (unsigned int)v8 > 0x40 )
    return png_warning((int)a1, "Can't write sCAL (buffer too small)");
  buf = a2;
  memcpy(dst, (unsigned __int8 *)lpString, v9 + 1);
  memcpy(&dst[v9 + 1], (unsigned __int8 *)a4, count);
  return sub_36AEC0(a1, 1933787468, &buf, v8);
}
