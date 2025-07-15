int __cdecl res2_forward(
        oggpack_buffer *opb,
        vorbis_block *vb,
        _DWORD **vl,
        int **in,
        char *nonzero,
        int ch,
        int **partword)
{
  int pcmend; // eax
  int v9; // edi
  char *v10; // eax
  int v11; // ecx
  int v12; // ebx
  char *v13; // ecx
  int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  char *v17; // [esp+14h] [ebp-8h] BYREF
  int v18; // [esp+18h] [ebp-4h]
  int v19; // [esp+28h] [ebp+Ch]

  pcmend = vb->pcmend;
  v19 = 0;
  v9 = pcmend / 2;
  v17 = _vorbis_block_alloc(vb, 4 * ch * (pcmend / 2));
  if ( ch <= 0 )
    return 0;
  v10 = nonzero;
  v11 = v17 - nonzero;
  v16 = v17 - nonzero;
  v18 = ch;
  while ( 1 )
  {
    v12 = 0;
    v15 = *(_DWORD *)&v10[(char *)in - nonzero];
    if ( *(_DWORD *)v10 )
      ++v19;
    if ( v9 > 0 )
    {
      v13 = &v10[v11];
      do
      {
        *(_DWORD *)v13 = *(_DWORD *)(v15 + 4 * v12++);
        v13 += 4 * ch;
      }
      while ( v12 < v9 );
    }
    v10 += 4;
    if ( !--v18 )
      break;
    v11 = v16;
  }
  if ( v19 )
    return 01forward(vl, opb, (vorbis_block *)&v17, (int **)1, (char *)partword);
  else
    return 0;
}
