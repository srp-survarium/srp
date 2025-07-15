int __usercall 01forward@<eax>(_DWORD **vl@<esi>, oggpack_buffer *opb, vorbis_block *vb, int **in, char *ch)
{
  _DWORD *v5; // ebx
  int v6; // ecx
  int v7; // eax
  bool v8; // cc
  int v9; // edx
  int *v10; // eax
  int v11; // ecx
  _DWORD *v12; // eax
  codebook *v13; // edi
  int v14; // ecx
  int v15; // eax
  char *v16; // edi
  unsigned __int8 *v17; // ecx
  int v18; // ecx
  codebook *v19; // ecx
  int v20; // eax
  unsigned __int8 *v21; // ecx
  unsigned __int8 dst[512]; // [esp+8h] [ebp-430h] BYREF
  unsigned __int8 v24[512]; // [esp+208h] [ebp-230h] BYREF
  int v25; // [esp+408h] [ebp-30h]
  int v26; // [esp+40Ch] [ebp-2Ch]
  int v27; // [esp+410h] [ebp-28h]
  int v28; // [esp+414h] [ebp-24h]
  int **v29; // [esp+418h] [ebp-20h]
  int v30; // [esp+41Ch] [ebp-1Ch]
  int v31; // [esp+420h] [ebp-18h]
  int v32; // [esp+424h] [ebp-14h]
  int v33; // [esp+428h] [ebp-10h]
  int v34; // [esp+42Ch] [ebp-Ch]
  int i; // [esp+430h] [ebp-8h]
  int v36; // [esp+434h] [ebp-4h]

  v5 = *vl;
  v6 = (*vl)[2];
  v25 = (*vl)[3];
  v32 = *vl[4];
  v7 = (v5[1] - *v5) / v6;
  v33 = v6;
  v31 = v7;
  memset((int)dst, 0, sizeof(dst));
  memset((int)v24, 0, sizeof(v24));
  v8 = (int)vl[2] <= 0;
  v34 = 0;
  if ( !v8 )
  {
    do
    {
      v36 = 0;
      if ( v31 > 0 )
      {
        while ( 1 )
        {
          if ( !v34 )
          {
            for ( i = 0; i < (int)in; ++i )
            {
              v9 = 1;
              v10 = (int *)(*(_DWORD *)&ch[4 * i] + 4 * v36);
              v11 = *v10;
              if ( v32 > 1 )
              {
                v12 = v10 + 1;
                do
                {
                  v11 *= v25;
                  if ( v9 + v36 < v31 )
                    v11 += *v12;
                  ++v9;
                  ++v12;
                }
                while ( v9 < v32 );
              }
              v13 = (codebook *)vl[4];
              if ( v11 < v13->entries )
                vl[9] = (_DWORD *)((char *)vl[9] + vorbis_book_encode(v13, v11, opb));
            }
          }
          v30 = 0;
          if ( v32 > 0 )
            break;
LABEL_25:
          if ( v36 >= v31 )
            goto LABEL_26;
        }
        v14 = v33 * v36;
        v28 = v33 * v36;
        while ( v36 < v31 )
        {
          v15 = v14 + *v5;
          v26 = v15;
          if ( (int)in > 0 )
          {
            v16 = ch;
            i = 1 << v34;
            v27 = (char *)vb - ch;
            v29 = in;
            do
            {
              if ( !v34 )
              {
                v17 = &v24[4 * *(_DWORD *)(*(_DWORD *)v16 + 4 * v36)];
                *(_DWORD *)v17 += v33;
              }
              v18 = *(_DWORD *)(*(_DWORD *)v16 + 4 * v36);
              if ( (i & v5[v18 + 6]) != 0 )
              {
                v19 = *(codebook **)(vl[5][v18] + 4 * v34);
                if ( v19 )
                {
                  v20 = encodepart(opb, (char *)(*(_DWORD *)&v16[v27] + 4 * v15), v33, v19);
                  vl[8] = (_DWORD *)((char *)vl[8] + v20);
                  v21 = &dst[4 * *(_DWORD *)(*(_DWORD *)v16 + 4 * v36)];
                  *(_DWORD *)v21 += v20;
                  v15 = v26;
                }
              }
              v16 += 4;
              v29 = (int **)((char *)v29 - 1);
            }
            while ( v29 );
          }
          ++v30;
          v14 = v33 + v28;
          ++v36;
          v28 += v33;
          if ( v30 >= v32 )
            goto LABEL_25;
        }
      }
LABEL_26:
      ++v34;
    }
    while ( v34 < (int)vl[2] );
  }
  return 0;
}
