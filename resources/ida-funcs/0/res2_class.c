int **__cdecl res2_class(vorbis_block *vb, _DWORD *vl, int **in, int *nonzero, int ch)
{
  int v5; // eax
  int v6; // ecx

  v5 = 0;
  v6 = 0;
  if ( ch <= 0 )
    return 0;
  do
  {
    if ( nonzero[v5] )
      ++v6;
    ++v5;
  }
  while ( v5 < ch );
  if ( v6 )
    return 2class(vb, vl, in, ch);
  else
    return 0;
}
