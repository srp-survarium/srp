char *__usercall floor1_interpolate_fit@<eax>(
        vorbis_block *vb@<ecx>,
        vorbis_look_floor1 *look@<eax>,
        char *A,
        char *B,
        int del)
{
  int posts; // edi
  char *v6; // edx
  int v7; // eax
  char *v8; // ecx
  int v9; // edx
  int v11; // [esp+8h] [ebp-10h]
  int v12; // [esp+Ch] [ebp-Ch]
  char *v13; // [esp+14h] [ebp-4h]
  int v14; // [esp+20h] [ebp+8h]

  v13 = 0;
  posts = look->posts;
  if ( A )
  {
    if ( B )
    {
      v13 = _vorbis_block_alloc(vb, 4 * posts);
      if ( posts > 0 )
      {
        v6 = (char *)&_sbh_sizeHeaderList - del;
        v7 = A - B;
        v12 = v13 - B;
        v14 = posts;
        v8 = B;
        v11 = v7;
        while ( 1 )
        {
          v9 = (del * (*(_DWORD *)v8 & 0x7FFF) + (int)v6 * (*(_DWORD *)&v8[v7] & 0x7FFF) + 0x8000) >> 16;
          v7 = v11;
          *(_DWORD *)&v8[v12] = v9;
          if ( (*(_DWORD *)&v8[v11] & 0x8000) != 0 && (*(_DWORD *)v8 & 0x8000) != 0 )
            *(_DWORD *)&v8[v12] = v9 | 0x8000;
          v8 += 4;
          if ( !--v14 )
            break;
          v6 = (char *)&_sbh_sizeHeaderList - del;
        }
      }
    }
  }
  return v13;
}
