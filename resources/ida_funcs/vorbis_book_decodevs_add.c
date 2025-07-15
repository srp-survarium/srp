int __cdecl vorbis_book_decodevs_add(codebook *book, float *a, oggpack_buffer *b, int n)
{
  codebook *v4; // ebx
  int v5; // edi
  void *v6; // esp
  void *v7; // esp
  float **v8; // esi
  int v9; // eax
  float *v10; // ecx
  int v11; // eax
  int v12; // edx
  bool v13; // cc
  int v14; // esi
  int *v15; // eax
  float **v16; // ecx
  unsigned int v17; // edi
  int v18; // ebx
  double v19; // st7
  double v20; // st7
  int v21; // ebx
  double v22; // st7
  int v23; // ebx
  float *v24; // eax
  float *v25; // ecx
  double v26; // st7
  _BYTE v28[12]; // [esp+0h] [ebp-20h] BYREF
  int step; // [esp+Ch] [ebp-14h]
  float **t; // [esp+10h] [ebp-10h]
  int *entry; // [esp+14h] [ebp-Ch]
  int o; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v4 = book;
  if ( book->used_entries <= 0 )
    return 0;
  step = n / book->dim;
  v5 = step;
  v6 = alloca(4 * step);
  entry = (int *)v28;
  v7 = alloca(4 * step);
  v8 = (float **)v28;
  t = (float **)v28;
  i = 0;
  if ( step <= 0 )
  {
LABEL_6:
    v12 = 0;
    v13 = book->dim <= 0;
    i = 0;
    o = 0;
    if ( !v13 )
    {
      entry = (int *)a;
      do
      {
        v14 = 0;
        if ( v5 >= 4 )
        {
          v15 = entry;
          v16 = t + 2;
          v17 = ((unsigned int)(v5 - 4) >> 2) + 1;
          v14 = 4 * v17;
          do
          {
            v18 = (int)*(v16 - 1);
            v19 = (*(v16 - 2))[v12] + *(float *)v15;
            v15 += 4;
            v16 += 4;
            --v17;
            *((float *)v15 - 4) = v19;
            v20 = *(float *)(v18 + v12 * 4);
            v21 = (int)*(v16 - 4);
            *((float *)v15 - 3) = v20 + *((float *)v15 - 3);
            v22 = *(float *)(v12 * 4 + v21);
            v23 = (int)*(v16 - 3);
            *((float *)v15 - 2) = v22 + *((float *)v15 - 2);
            *((float *)v15 - 1) = *(float *)(v23 + v12 * 4) + *((float *)v15 - 1);
          }
          while ( v17 );
          v4 = book;
          v5 = step;
        }
        if ( v14 < v5 )
        {
          v24 = &a[v14 + o];
          do
          {
            v25 = t[v14++];
            v26 = v25[v12] + *v24++;
            *(v24 - 1) = v26;
          }
          while ( v14 < v5 );
        }
        o += v5;
        entry += v5;
        ++v12;
        v13 = ++i < v4->dim;
      }
      while ( v13 );
    }
    return 0;
  }
  entry = (int *)((char *)entry - v28);
  while ( 1 )
  {
    v9 = decode_packed_entry_number(book, b);
    *(float **)((char *)v8 + (_DWORD)entry) = (float *)v9;
    if ( v9 == -1 )
      return -1;
    v10 = &book->valuelist[v9 * book->dim];
    v11 = i + 1;
    *v8++ = v10;
    i = v11;
    if ( v11 >= v5 )
      goto LABEL_6;
  }
}
