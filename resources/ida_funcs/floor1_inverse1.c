_DWORD *__cdecl floor1_inverse1(vorbis_block *vb, _DWORD *in)
{
  _DWORD *v2; // ebp
  vorbis_info_floor1 *v3; // ebx
  oggpack_buffer *p_opb; // edi
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  _DWORD *v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  int v11; // esi
  int v12; // ecx
  int v13; // edi
  int v14; // ebp
  codebook *v15; // ebp
  int v16; // eax
  int v17; // edx
  int *v18; // edi
  int v19; // eax
  codebook *v20; // esi
  int v21; // eax
  int v22; // eax
  _DWORD *v23; // ebp
  int v24; // eax
  int v25; // edi
  int v26; // esi
  __int64 v27; // rax
  int v28; // eax
  int v29; // esi
  int v30; // edx
  int v31; // ebx
  int v32; // edi
  int v33; // eax
  int i; // [esp+10h] [ebp-2Ch]
  int ia; // [esp+10h] [ebp-2Ch]
  int j; // [esp+14h] [ebp-28h]
  int *partitionclass; // [esp+18h] [ebp-24h]
  int *v39; // [esp+18h] [ebp-24h]
  codebook *books; // [esp+1Ch] [ebp-20h]
  oggpack_buffer *b; // [esp+20h] [ebp-1Ch]
  int cdim; // [esp+24h] [ebp-18h]
  int k; // [esp+28h] [ebp-14h]
  vorbis_info_floor1 *info; // [esp+2Ch] [ebp-10h]
  int v45; // [esp+30h] [ebp-Ch]
  int v46; // [esp+34h] [ebp-8h]
  char csubbits; // [esp+38h] [ebp-4h]
  int *fit_value; // [esp+40h] [ebp+4h]

  v2 = in;
  v3 = (vorbis_info_floor1 *)in[324];
  books = (codebook *)*((_DWORD *)vb->vd->vi->codec_setup + 712);
  p_opb = &vb->opb;
  info = v3;
  b = &vb->opb;
  if ( oggpack_read(&vb->opb, 1u) != 1 )
    return 0;
  v5 = _vorbis_block_alloc(vb, 4 * in[321]);
  v6 = in[323] - 1;
  v7 = v5;
  fit_value = v5;
  v8 = 0;
  if ( in[323] != 1 )
  {
    do
    {
      ++v8;
      v6 >>= 1;
    }
    while ( v6 );
  }
  *v7 = oggpack_read(p_opb, v8);
  v9 = in[323] - 1;
  v10 = 0;
  if ( in[323] != 1 )
  {
    do
    {
      ++v10;
      v9 >>= 1;
    }
    while ( v9 );
  }
  v7[1] = oggpack_read(p_opb, v10);
  i = 0;
  j = 2;
  if ( v3->partitions > 0 )
  {
    partitionclass = v3->partitionclass;
    while ( 1 )
    {
      v11 = *partitionclass;
      v12 = v3->class_subs[*partitionclass];
      v13 = 1 << v12;
      v14 = 0;
      cdim = v3->class_dim[*partitionclass];
      csubbits = v12;
      if ( v12 )
      {
        v15 = &books[v3->class_book[v11]];
        if ( v15->used_entries <= 0 )
          return 0;
        v16 = decode_packed_entry_number(v15, b);
        if ( v16 < 0 )
          return 0;
        v14 = v15->dec_index[v16];
        if ( v14 == -1 )
          return 0;
      }
      v17 = cdim;
      k = 0;
      if ( cdim > 0 )
      {
        v46 = 8 * v11 + 80;
        v45 = v13 - 1;
        v18 = &fit_value[j];
        do
        {
          v19 = *(&v3->partitions + v46 + (v14 & v45));
          v14 >>= csubbits;
          if ( v19 < 0 )
          {
            *v18 = 0;
          }
          else
          {
            v20 = &books[v19];
            if ( v20->used_entries <= 0 || (v21 = decode_packed_entry_number(&books[v19], b), v21 < 0) )
              v22 = -1;
            else
              v22 = v20->dec_index[v21];
            *v18 = v22;
            if ( v22 == -1 )
              return 0;
            v17 = cdim;
          }
          ++v18;
          ++k;
        }
        while ( k < v17 );
      }
      j += v17;
      ++partitionclass;
      if ( ++i >= v3->partitions )
      {
        v7 = fit_value;
        v2 = in;
        break;
      }
    }
  }
  ia = 2;
  if ( (int)v2[321] > 2 )
  {
    v23 = v2 + 195;
    v39 = &v3->postlist[2];
    while ( 1 )
    {
      v24 = v23[63];
      v25 = v3->postlist[v24];
      v26 = v7[v24] & 0x7FFF;
      v27 = (fit_value[*v23] & 0x7FFF) - v26;
      v28 = (int)((*v39 - v25) * ((HIDWORD(v27) ^ v27) - HIDWORD(v27))) / (info->postlist[*v23] - v25);
      if ( (fit_value[*v23] & 0x7FFF) - v26 >= 0 )
        v29 = v28 + v26;
      else
        v29 = v26 - v28;
      v30 = in[323] - v29;
      v31 = v30;
      if ( v30 >= v29 )
        v31 = v29;
      v32 = ia;
      v33 = fit_value[ia];
      if ( v33 )
      {
        if ( v33 < 2 * v31 )
        {
          if ( (v33 & 1) != 0 )
            v33 = -((v33 + 1) >> 1);
          else
            v33 >>= 1;
        }
        else
        {
          LOWORD(v33) = v30 <= v29 ? v30 - v33 - 1 : v33 - v29;
        }
        fit_value[ia] = ((_WORD)v29 + (_WORD)v33) & 0x7FFF;
        fit_value[v23[63]] &= 0x7FFFu;
        fit_value[*v23] &= 0x7FFFu;
      }
      else
      {
        fit_value[ia] = v29 | 0x8000;
      }
      ++v39;
      v7 = fit_value;
      ++v23;
      ++ia;
      if ( v32 + 1 >= in[321] )
        break;
      v3 = info;
    }
  }
  return v7;
}
