int __cdecl png_write_tRNS(int a1, unsigned __int8 *buf, __int16 *a3, int a4, int a5)
{
  unsigned __int8 v6[2]; // [esp+0h] [ebp-Ch] BYREF
  _BYTE v7[2]; // [esp+2h] [ebp-Ah] BYREF
  _BYTE v8[4]; // [esp+4h] [ebp-8h] BYREF

  if ( a5 == 3 )
  {
    if ( a4 > 0 && a4 <= *(unsigned __int16 *)(a1 + 300) )
      return sub_477B80((_DWORD *)a1, 1951551059, buf, a4);
    else
      return png_warning(a1, "Invalid number of transparent colors specified");
  }
  else if ( a5 )
  {
    if ( a5 == 2 )
    {
      png_save_uint_16(v6, a3[1]);
      png_save_uint_16(v7, a3[2]);
      png_save_uint_16(v8, a3[3]);
      if ( *(_BYTE *)(a1 + 316) == 8 && v8[0] | v7[0] | v6[0] )
        return png_warning(a1, "Ignoring attempt to write 16-bit tRNS chunk when bit_depth is 8");
      else
        return sub_477B80((_DWORD *)a1, 1951551059, v6, 6);
    }
    else
    {
      return png_warning(a1, "Can't write tRNS with an alpha channel");
    }
  }
  else if ( (unsigned __int16)a3[4] < 1 << *(_BYTE *)(a1 + 316) )
  {
    png_save_uint_16(v6, a3[4]);
    return sub_477B80((_DWORD *)a1, 1951551059, v6, 2);
  }
  else
  {
    return png_warning(a1, "Ignoring attempt to write tRNS chunk out-of-range for bit_depth");
  }
}
