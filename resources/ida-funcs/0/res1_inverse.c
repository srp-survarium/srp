int __cdecl res1_inverse(vorbis_block *vb, _DWORD **vl, float **in, char *nonzero, int ch)
{
  int v5; // edi
  int v6; // esi
  float **v7; // eax

  v5 = ch;
  v6 = 0;
  if ( ch <= 0 )
    return 0;
  v7 = in;
  do
  {
    if ( *(float **)((char *)v7 + nonzero - (char *)in) )
      in[v6++] = *v7;
    ++v7;
    --v5;
  }
  while ( v5 );
  if ( v6 )
    return 01inverse(vb, vl, in, v6, vorbis_book_decodev_add);
  else
    return 0;
}
