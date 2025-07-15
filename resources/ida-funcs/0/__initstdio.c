int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int v7; // eax

  v0 = _nstream;
  if ( !_nstream )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)_calloc_crt(v0, 4u);
  __piob = v1;
  if ( !v1 )
  {
    _nstream = 20;
    v1 = (void **)_calloc_crt(0x14u, 4u);
    __piob = v1;
    if ( !v1 )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&ctype_loc_style )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_9AE040;
  do
  {
    v7 = *(&__pioinfo[v5 >> 5]->osfhnd + 16 * (v5 & 0x1F));
    if ( v7 == -1 || v7 == -2 || !v7 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_9AE0A0 );
  return 0;
}
