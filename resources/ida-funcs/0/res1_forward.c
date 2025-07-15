int __cdecl res1_forward(
        oggpack_buffer *opb,
        vorbis_block *vb,
        vorbis_block *vl,
        int **in,
        int *nonzero,
        int ch,
        int **partword)
{
  int v7; // esi
  int **v8; // ecx
  int **v9; // eax

  v7 = ch;
  v8 = 0;
  if ( ch <= 0 )
    return 0;
  v9 = in;
  do
  {
    if ( *(int **)((char *)v9 + (char *)nonzero - (char *)in) )
    {
      in[(_DWORD)v8] = *v9;
      v8 = (int **)((char *)v8 + 1);
    }
    ++v9;
    --v7;
  }
  while ( v7 );
  if ( v8 )
    return 01forward(opb, vl, in, v8, partword);
  else
    return 0;
}
