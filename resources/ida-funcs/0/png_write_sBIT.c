int __cdecl png_write_sBIT(int a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 v4; // [esp+0h] [ebp-10h]
  unsigned __int8 buf[4]; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h]

  if ( (a3 & 2) != 0 )
  {
    if ( a3 == 3 )
      v4 = 8;
    else
      v4 = *(_BYTE *)(a1 + 317);
    if ( !*a2 || *a2 > (int)v4 || !a2[1] || a2[1] > (int)v4 || !a2[2] || a2[2] > (int)v4 )
      return png_warning(a1, "Invalid sBIT depth specified");
    buf[0] = *a2;
    buf[1] = a2[1];
    buf[2] = a2[2];
    v6 = 3;
  }
  else
  {
    if ( !a2[3] || a2[3] > (int)*(unsigned __int8 *)(a1 + 317) )
      return png_warning(a1, "Invalid sBIT depth specified");
    buf[0] = a2[3];
    v6 = 1;
  }
  if ( (a3 & 4) != 0 )
  {
    if ( !a2[4] || a2[4] > (int)*(unsigned __int8 *)(a1 + 317) )
      return png_warning(a1, "Invalid sBIT depth specified");
    buf[v6++] = a2[4];
  }
  return sub_36AEC0((_DWORD *)a1, 1933723988, buf, v6);
}
