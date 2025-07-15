int **__cdecl res2_class(vorbis_block *vb, _DWORD *vl, int **in, int *nonzero, int ch)
{
  int v5; // edx
  int v6; // eax

  v5 = 0;
  v6 = 0;
  if ( ch <= 0 )
    return 0;
  do
  {
    if ( nonzero[v6] )
      ++v5;
    ++v6;
  }
  while ( v6 < ch );
  if ( v5 )
    return 2class(vb, vl, in, ch);
  else
    return 0;
}
