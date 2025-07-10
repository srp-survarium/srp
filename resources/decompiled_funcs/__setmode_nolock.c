int __cdecl _setmode_nolock(int fh, HINSTANCE__ *mode)
{
  stlp_std::ioinfo **v2; // edx
  int v3; // esi
  char *v4; // ecx
  int v5; // edi
  int v6; // eax
  _BYTE *v7; // ecx
  char v8; // dl

  v2 = &__pioinfo[fh >> 5];
  v3 = (fh & 0x1F) << 6;
  v4 = (char *)*v2 + v3;
  v5 = v4[4] & 0x80;
  v6 = (char)(2 * v4[36]) >> 1;
  if ( mode == (HINSTANCE__ *)0x4000 )
  {
    v4[4] |= 0x80u;
    *((_BYTE *)&(*v2)[1].osfhnd + v3) &= 0x80u;
  }
  else if ( mode == (HINSTANCE__ *)0x8000 )
  {
    v4[4] &= ~0x80u;
  }
  else
  {
    if ( mode == &_sbh_sizeHeaderList || mode == (HINSTANCE__ *)&loc_20000 )
    {
      v4[4] |= 0x80u;
      v7 = (char *)&(*v2)[1] + v3;
      v8 = *v7 & 0x80 | 2;
    }
    else
    {
      if ( mode != (HINSTANCE__ *)((char *)&loc_3FFFF + 1) )
        goto LABEL_11;
      v4[4] |= 0x80u;
      v7 = (char *)&(*v2)[1] + v3;
      v8 = *v7 & 0x80 | 1;
    }
    *v7 = v8;
  }
LABEL_11:
  if ( v5 )
    return v6 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000;
}
