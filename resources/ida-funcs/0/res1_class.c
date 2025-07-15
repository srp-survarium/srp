int **__cdecl res1_class(vorbis_block *vb, vorbis_info_residue0 **vl, int **in, int *nonzero, int ch)
{
  int v5; // esi
  int v6; // ecx
  int **v7; // eax

  v5 = ch;
  v6 = 0;
  if ( ch <= 0 )
    return 0;
  v7 = in;
  do
  {
    if ( *(int **)((char *)v7 + (char *)nonzero - (char *)in) )
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
