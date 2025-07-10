int __cdecl res2_forward(
        oggpack_buffer *opb,
        vorbis_block *vb,
        vorbis_block *vl,
        int **in,
        int *nonzero,
        int ch,
        int **partword)
{
  int v7; // ebp
  int v9; // edi
  int *v10; // eax
  int *v11; // esi
  int v12; // edx
  int v13; // ecx
  int v14; // ebx
  int v15; // eax
  _DWORD *v16; // ecx
  int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+14h] [ebp-8h]
  int *work; // [esp+18h] [ebp-4h] BYREF
  int used; // [esp+24h] [ebp+8h]

  v7 = ch;
  v9 = vb->pcmend / 2;
  used = 0;
  v10 = (int *)_vorbis_block_alloc(vb, 4 * ch * v9);
  work = v10;
  if ( ch <= 0 )
    return 0;
  v11 = nonzero;
  v12 = (char *)in - (char *)nonzero;
  v13 = (char *)v10 - (char *)nonzero;
  v19 = (char *)v10 - (char *)nonzero;
  v18 = ch;
  do
  {
    v14 = *(int *)((char *)v11 + v12);
    if ( *v11 )
      ++used;
    v15 = 0;
    if ( v9 > 0 )
    {
      v16 = (int *)((char *)v11 + v13);
      do
      {
        *v16 = *(_DWORD *)(v14 + 4 * v15++);
        v16 += v7;
      }
      while ( v15 < v9 );
      v7 = ch;
      v12 = (char *)in - (char *)nonzero;
      v13 = v19;
    }
    ++v11;
    --v18;
  }
  while ( v18 );
  if ( used )
    return 01forward(opb, vl, &work, (int **)1, partword);
  else
    return 0;
}
