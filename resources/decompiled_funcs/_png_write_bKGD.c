int __cdecl png_write_bKGD(int a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 buf[2]; // [esp+0h] [ebp-Ch] BYREF
  _BYTE v5[2]; // [esp+2h] [ebp-Ah] BYREF
  _BYTE v6[4]; // [esp+4h] [ebp-8h] BYREF

  if ( a3 == 3 )
  {
    if ( !*(_WORD *)(a1 + 300) && (*(_DWORD *)(a1 + 600) & 1) != 0 || *a2 < (int)*(unsigned __int16 *)(a1 + 300) )
    {
      buf[0] = *a2;
      return sub_36AEC0((_DWORD *)a1, 1649100612, buf, 1);
    }
    else
    {
      return png_warning(a1, "Invalid background palette index");
    }
  }
  else if ( (a3 & 2) != 0 )
  {
    png_save_uint_16(buf, *((_WORD *)a2 + 1));
    png_save_uint_16(v5, *((_WORD *)a2 + 2));
    png_save_uint_16(v6, *((_WORD *)a2 + 3));
    if ( *(_BYTE *)(a1 + 316) == 8 && v6[0] | v5[0] | buf[0] )
      return png_warning(a1, "Ignoring attempt to write 16-bit bKGD chunk when bit_depth is 8");
    else
      return sub_36AEC0((_DWORD *)a1, 1649100612, buf, 6);
  }
  else if ( *((unsigned __int16 *)a2 + 4) < 1 << *(_BYTE *)(a1 + 316) )
  {
    png_save_uint_16(buf, *((_WORD *)a2 + 4));
    return sub_36AEC0((_DWORD *)a1, 1649100612, buf, 2);
  }
  else
  {
    return png_warning(a1, "Ignoring attempt to write bKGD chunk out-of-range for bit_depth");
  }
}
