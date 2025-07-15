int __cdecl floor1_encode(oggpack_buffer *opb, vorbis_block *vb, vorbis_look_floor1 *look, char *post, int *ilogmask)
{
  int posts; // ebp
  int k; // edi
  int v7; // esi
  int v8; // ecx
  int v9; // edx
  int v10; // ebp
  int v11; // ebx
  int v12; // esi
  __int64 v13; // rax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // eax
  bool v20; // zf
  int quant_q; // eax
  unsigned int v22; // edx
  unsigned int v23; // eax
  int m; // ecx
  unsigned int n; // eax
  unsigned int v26; // esi
  unsigned int v27; // eax
  int v28; // ebp
  int v29; // esi
  int v30; // ebx
  int v31; // eax
  int *v32; // edx
  int v33; // edx
  int v34; // eax
  int v35; // eax
  char v36; // cl
  codebook *v37; // esi
  const static_codebook *c; // eax
  int v39; // ebx
  int v40; // ebx
  int *v41; // ebp
  int v42; // eax
  int v43; // esi
  codebook *v44; // edi
  const static_codebook *v45; // eax
  int v46; // esi
  int v47; // ecx
  vorbis_block *v48; // esi
  __int64 v49; // rax
  int v50; // edi
  int v51; // ebp
  int v52; // ebx
  int v53; // eax
  int v54; // esi
  vorbis_info_floor1 *info; // [esp+Ch] [ebp-16Ch]
  int *j; // [esp+10h] [ebp-168h]
  int ja; // [esp+10h] [ebp-168h]
  int jb; // [esp+10h] [ebp-168h]
  int v60; // [esp+14h] [ebp-164h]
  int *partitionclass; // [esp+14h] [ebp-164h]
  int *v62; // [esp+14h] [ebp-164h]
  int *cdim; // [esp+18h] [ebp-160h]
  int cdima; // [esp+18h] [ebp-160h]
  int *v65; // [esp+1Ch] [ebp-15Ch]
  int v66; // [esp+1Ch] [ebp-15Ch]
  int v67; // [esp+1Ch] [ebp-15Ch]
  int v68; // [esp+20h] [ebp-158h]
  int *v69; // [esp+20h] [ebp-158h]
  int i; // [esp+24h] [ebp-154h]
  int cshift; // [esp+28h] [ebp-150h]
  codebook *books; // [esp+2Ch] [ebp-14Ch]
  codec_setup_info *ci; // [esp+30h] [ebp-148h]
  int bookas[8]; // [esp+34h] [ebp-144h] BYREF
  int maxval[8]; // [esp+54h] [ebp-124h]
  int out[65]; // [esp+74h] [ebp-104h] BYREF

  posts = look->posts;
  info = look->vi;
  ci = (codec_setup_info *)vb->vd->vi->codec_setup;
  books = ci->fullbooks;
  if ( post )
  {
    for ( k = 0; k < posts; ++k )
    {
      v7 = *(_DWORD *)&post[4 * k];
      v8 = v7 & 0x7FFF;
      switch ( info->mult )
      {
        case 1:
          v8 >>= 2;
          break;
        case 2:
          v8 >>= 3;
          break;
        case 3:
          v8 /= 12;
          break;
        case 4:
          v8 >>= 4;
          break;
        default:
          break;
      }
      *(_DWORD *)&post[4 * k] = v8 | v7 & 0x8000;
    }
    v9 = *((_DWORD *)post + 1);
    out[0] = *(_DWORD *)post;
    out[1] = v9;
    if ( posts > 2 )
    {
      v65 = (int *)(post + 8);
      cdim = look->hineighbor;
      j = &info->postlist[2];
      v60 = (char *)out - post;
      v68 = posts - 2;
      do
      {
        v10 = cdim[63];
        v11 = *cdim;
        v12 = *(_DWORD *)&post[4 * v10] & 0x7FFF;
        v13 = (*(_DWORD *)&post[4 * *cdim] & 0x7FFF) - v12;
        v14 = (int)((*j - info->postlist[v10]) * ((HIDWORD(v13) ^ v13) - HIDWORD(v13)))
            / (info->postlist[*cdim] - info->postlist[v10]);
        if ( (*(_DWORD *)&post[4 * *cdim] & 0x7FFF) - v12 >= 0 )
          v15 = v14 + v12;
        else
          v15 = v12 - v14;
        v16 = *v65;
        if ( (*v65 & 0x8000) != 0 || v15 == v16 )
        {
          *v65 = v15 | 0x8000;
          *(int *)((char *)v65 + v60) = 0;
        }
        else
        {
          v17 = look->quant_q - v15;
          if ( v17 >= v15 )
            v17 = v15;
          v18 = v16 - v15;
          if ( v18 >= 0 )
          {
            if ( v18 < v17 )
              v19 = 2 * v18;
            else
              v19 = v17 + v18;
          }
          else if ( v18 >= -v17 )
          {
            v19 = -1 - 2 * v18;
          }
          else
          {
            v19 = v17 - v18 - 1;
          }
          *(int *)((char *)v65 + v60) = v19;
          *(_DWORD *)&post[4 * v10] = v12;
          *(_DWORD *)&post[4 * v11] &= 0x7FFFu;
        }
        ++cdim;
        ++j;
        v20 = v68-- == 1;
        ++v65;
      }
      while ( !v20 );
    }
    oggpack_write(opb, 1u, 1u);
    quant_q = look->quant_q;
    ++look->frames;
    v22 = quant_q - 1;
    v23 = quant_q - 1;
    for ( m = 0; v23; v23 >>= 1 )
      ++m;
    look->postbits += 2 * m;
    for ( n = 0; v22; v22 >>= 1 )
      ++n;
    oggpack_write(opb, out[0], n);
    v26 = look->quant_q - 1;
    v27 = 0;
    if ( look->quant_q != 1 )
    {
      do
      {
        ++v27;
        v26 >>= 1;
      }
      while ( v26 );
    }
    oggpack_write(opb, out[1], v27);
    i = 0;
    ja = 2;
    if ( info->partitions > 0 )
    {
      partitionclass = info->partitionclass;
      do
      {
        v28 = info->class_subs[*partitionclass];
        v29 = 1 << v28;
        v30 = 0;
        v66 = *partitionclass;
        cdima = info->class_dim[*partitionclass];
        memset(bookas, 0, sizeof(bookas));
        cshift = 0;
        if ( v28 )
        {
          v31 = 0;
          if ( v29 > 0 )
          {
            v32 = info->class_subbook[v66];
            do
            {
              if ( *v32 >= 0 )
                maxval[v31] = ci->book_param[*v32]->entries;
              else
                maxval[v31] = 1;
              ++v31;
              ++v32;
            }
            while ( v31 < v29 );
          }
          v33 = 0;
          if ( cdima > 0 )
          {
            v69 = &out[ja];
            do
            {
              v34 = 0;
              if ( v29 > 0 )
              {
                while ( *v69 >= maxval[v34] )
                {
                  if ( ++v34 >= v29 )
                    goto LABEL_50;
                }
                bookas[v33] = v34;
              }
LABEL_50:
              v35 = bookas[v33];
              v36 = cshift;
              cshift += v28;
              ++v69;
              ++v33;
              v30 |= v35 << v36;
            }
            while ( v33 < cdima );
          }
          v37 = &books[info->class_book[v66]];
          if ( v30 < 0 || (c = v37->c, v30 >= c->entries) )
          {
            v39 = 0;
          }
          else
          {
            oggpack_write(opb, v37->codelist[v30], c->lengthlist[v30]);
            v39 = v37->c->lengthlist[v30];
          }
          look->phrasebits += v39;
        }
        v40 = 0;
        if ( cdima > 0 )
        {
          v67 = 8 * v66 + 80;
          v41 = &out[ja];
          do
          {
            v42 = *(&info->partitions + v67 + bookas[v40]);
            if ( v42 >= 0 )
            {
              v43 = *v41;
              v44 = &books[v42];
              if ( *v41 < v44->entries )
              {
                if ( v43 < 0 || (v45 = v44->c, v43 >= v45->entries) )
                {
                  v46 = 0;
                }
                else
                {
                  oggpack_write(opb, v44->codelist[v43], v45->lengthlist[v43]);
                  v46 = v44->c->lengthlist[v43];
                }
                look->postbits += v46;
              }
            }
            ++v40;
            ++v41;
          }
          while ( v40 < cdima );
        }
        ja += cdima;
        ++partitionclass;
        ++i;
      }
      while ( i < info->partitions );
    }
    v47 = *(_DWORD *)post * info->mult;
    v48 = vb;
    v49 = ci->blocksizes[vb->W];
    v50 = 0;
    v51 = 0;
    v52 = ((int)v49 - HIDWORD(v49)) >> 1;
    jb = 1;
    if ( look->posts > 1 )
    {
      v62 = &look->forward_index[1];
      do
      {
        v53 = *(_DWORD *)&post[4 * *v62] & 0x7FFF;
        if ( v53 == *(_DWORD *)&post[4 * *v62] )
        {
          v50 = info->postlist[*v62];
          v54 = v53 * info->mult;
          render_line0(v54, v52, v51, v50, v47, ilogmask);
          v51 = v50;
          v47 = v54;
        }
        ++v62;
        ++jb;
      }
      while ( jb < look->posts );
      v48 = vb;
    }
    for ( ; v50 < v48->pcmend / 2; ++v50 )
      ilogmask[v50] = v47;
    return 1;
  }
  else
  {
    oggpack_write(opb, 0, 1u);
    memset((int)ilogmask, 0, 4 * (vb->pcmend / 2));
    return 0;
  }
}
