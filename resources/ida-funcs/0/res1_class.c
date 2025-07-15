int **__cdecl res1_class(vorbis_block *vb, _DWORD *vl, int **in, char *nonzero, int ch)
{
  int v5; // edi
  int v6; // esi
  int **v7; // eax

  v5 = ch;
  v6 = 0;
  if ( ch <= 0 )
    return 0;
  v7 = in;
  do
  {
    if ( *(int **)((char *)v7 + nonzero - (char *)in) )
      in[v6++] = *v7;
    ++v7;
    --v5;
  }
  while ( v5 );
  if ( v6 )
    return 01class(vb, vl, in, v6);
  else
    return 0;
}
