char *__usercall floor1_interpolate_fit@<eax>(
        vorbis_look_floor1 *look@<eax>,
        char *A@<ecx>,
        vorbis_block *vb,
        int *B,
        int del)
{
  int posts; // ebp
  char *result; // eax
  int v8; // esi
  int *v9; // ecx
  int v10; // edi
  int v11; // edx

  posts = look->posts;
  result = 0;
  if ( A )
  {
    if ( B )
    {
      result = (char *)_vorbis_block_alloc(vb, 4 * posts);
      if ( posts > 0 )
      {
        v8 = A - (char *)B;
        v9 = B;
        v10 = result - (char *)B;
        do
        {
          v11 = (del * (*v9 & 0x7FFF) + ((int)&_sbh_sizeHeaderList - del) * (*(int *)((char *)v9 + v8) & 0x7FFF) + 0x8000) >> 16;
          *(int *)((char *)v9 + v10) = v11;
          if ( (*(int *)((char *)v9 + v8) & 0x8000) != 0 && (*v9 & 0x8000) != 0 )
            *(int *)((char *)v9 + v10) = v11 | 0x8000;
          ++v9;
          --posts;
        }
        while ( posts );
      }
    }
  }
  return result;
}
