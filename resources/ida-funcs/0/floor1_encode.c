int __cdecl floor1_encode(
        oggpack_buffer *opb,
        vorbis_block *vb,
        vorbis_look_floor1 *look,
        unsigned int *post,
        int *ilogmask)
{
  int posts; // edx
  vorbis_info_floor1 *vi; // esi
  unsigned int *v8; // edi
  int v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // ecx
  unsigned int *v13; // eax
  bool v14; // cc
  int *hineighbor; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // ecx
  bool v24; // zf
  int quant_q; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  int v28; // eax
  int v29; // edx
  unsigned int *v30; // ecx
  int v31; // ecx
  int v32; // edi
  int v33; // edi
  int v34; // eax
  codebook *v35; // eax
  int v36; // eax
  int v37; // ecx
  int v38; // edx
  int i; // esi
  unsigned int v41; // [esp-18h] [ebp-190h]
  int v42; // [esp-Ch] [ebp-184h]
  int v43; // [esp-8h] [ebp-180h]
  unsigned int value; // [esp+Ch] [ebp-16Ch] BYREF
  unsigned int v45; // [esp+10h] [ebp-168h]
  _DWORD v46[8]; // [esp+110h] [ebp-68h]
  _DWORD v47[8]; // [esp+130h] [ebp-48h] BYREF
  int codec_setup; // [esp+150h] [ebp-28h]
  int v49; // [esp+154h] [ebp-24h]
  unsigned int v50; // [esp+158h] [ebp-20h]
  int v51; // [esp+15Ch] [ebp-1Ch]
  unsigned int *partitionclass; // [esp+160h] [ebp-18h]
  unsigned int *v53; // [esp+164h] [ebp-14h]
  int *v54; // [esp+168h] [ebp-10h]
  int a; // [esp+16Ch] [ebp-Ch]
  unsigned int *v56; // [esp+170h] [ebp-8h]
  int v57; // [esp+174h] [ebp-4h]
  int *v58; // [esp+188h] [ebp+10h]
  int v59; // [esp+188h] [ebp+10h]
  int v60; // [esp+188h] [ebp+10h]
  int v61; // [esp+188h] [ebp+10h]
  int v62; // [esp+188h] [ebp+10h]
  int *v63; // [esp+18Ch] [ebp+14h]

  posts = look->posts;
  vi = look->vi;
  v8 = post;
  codec_setup = (int)vb->vd->vi->codec_setup;
  v9 = *(_DWORD *)(codec_setup + 2848);
  partitionclass = (unsigned int *)posts;
  v49 = v9;
  if ( post )
  {
    v56 = 0;
    if ( posts > 0 )
    {
      do
      {
        v10 = post[(_DWORD)v56];
        v11 = v10 & 0x7FFF;
        switch ( vi->mult )
        {
          case 1:
            v11 >>= 2;
            break;
          case 2:
            v11 >>= 3;
            break;
          case 3:
            v11 /= 12;
            break;
          case 4:
            v11 >>= 4;
            break;
        }
        posts = (int)partitionclass;
        v12 = v11 | v10 & 0x8000;
        v13 = v56;
        v56 = (unsigned int *)((char *)v56 + 1);
        v14 = (int)v56 < (int)partitionclass;
        post[(_DWORD)v13] = v12;
      }
      while ( v14 );
    }
    value = *post;
    v45 = post[1];
    if ( posts > 2 )
    {
      v57 = (int)(post + 2);
      v54 = &vi->postlist[2];
      hineighbor = look->hineighbor;
      v58 = look->hineighbor;
      a = (char *)&value - (char *)post;
      v53 = (unsigned int *)(posts - 2);
      while ( 1 )
      {
        v16 = hineighbor[63];
        v17 = *hineighbor;
        partitionclass = &post[v17];
        v56 = &post[v16];
        v43 = vi->postlist[v17];
        v50 = *v56;
        v18 = render_point(*partitionclass, *v54, vi->postlist[v16], v43, v50);
        v19 = v57;
        v20 = *(_DWORD *)v57;
        if ( (*(_DWORD *)v57 & 0x8000) != 0 || v18 == v20 )
        {
          *(_DWORD *)v57 = v18 | 0x8000;
          *(_DWORD *)(a + v19) = 0;
        }
        else
        {
          v21 = look->quant_q - v18;
          if ( v21 >= v18 )
            v21 = v18;
          v22 = v20 - v18;
          if ( v22 >= 0 )
            v23 = v22 < v21 ? 2 * v22 : v21 + v22;
          else
            v23 = v22 >= -v21 ? -1 - 2 * v22 : v21 - v22 - 1;
          v19 = v57;
          *(_DWORD *)(a + v57) = v23;
          *v56 = v50 & 0x7FFF;
          *partitionclass &= 0x7FFFu;
        }
        ++v58;
        ++v54;
        v24 = v53 == (unsigned int *)1;
        v53 = (unsigned int *)((char *)v53 - 1);
        v57 = v19 + 4;
        if ( v24 )
          break;
        hineighbor = v58;
      }
    }
    oggpack_write(opb, 1u, 1u);
    quant_q = look->quant_q;
    ++look->frames;
    v26 = _ilog(quant_q - 1);
    v41 = value;
    look->postbits += 2 * v26;
    oggpack_write(opb, v41, v26);
    v27 = _ilog(look->quant_q - 1);
    oggpack_write(opb, v45, v27);
    v56 = 0;
    v14 = vi->partitions <= 0;
    v57 = 2;
    if ( !v14 )
    {
      partitionclass = (unsigned int *)vi->partitionclass;
      do
      {
        v28 = *partitionclass;
        v54 = (int *)vi->class_dim[*partitionclass];
        v29 = 1 << vi->class_subs[v28];
        a = 0;
        v50 = 0;
        v51 = v28;
        memset(v47, 0, sizeof(v47));
        if ( vi->class_subs[v28] )
        {
          v59 = 0;
          if ( v29 > 0 )
          {
            v30 = (unsigned int *)vi->class_subbook[v28];
            v53 = v30;
            do
            {
              if ( (*v30 & 0x80000000) == 0 )
              {
                v46[v59] = *(_DWORD *)(*(_DWORD *)(codec_setup + 4 * *v30 + 1824) + 4);
                v30 = v53;
              }
              else
              {
                v46[v59] = 1;
              }
              ++v59;
              v53 = ++v30;
            }
            while ( v59 < v29 );
          }
          v60 = 0;
          if ( (int)v54 > 0 )
          {
            v53 = &value + v57;
            do
            {
              v31 = 0;
              if ( v29 > 0 )
              {
                while ( (signed int)*v53 >= v46[v31] )
                {
                  if ( ++v31 >= v29 )
                    goto LABEL_45;
                }
                v47[v60] = v31;
              }
LABEL_45:
              v32 = v47[v60];
              ++v53;
              v33 = v32 << v50;
              v50 += vi->class_subs[v28];
              a |= v33;
              ++v60;
            }
            while ( v60 < (int)v54 );
          }
          look->phrasebits += vorbis_book_encode((codebook *)(v49 + 56 * vi->class_book[v28]), a, opb);
          v8 = post;
          v28 = v51;
        }
        v61 = 0;
        if ( (int)v54 > 0 )
        {
          v51 = 8 * v28 + 80;
          a = (int)(&value + v57);
          do
          {
            v34 = *(&vi->partitions + v51 + v47[v61]);
            if ( v34 >= 0 )
            {
              v35 = (codebook *)(v49 + 56 * v34);
              if ( *(_DWORD *)a < v35->entries )
              {
                look->postbits += vorbis_book_encode(v35, *(_DWORD *)a, opb);
                v8 = post;
              }
            }
            ++v61;
            a += 4;
          }
          while ( v61 < (int)v54 );
        }
        v57 += (int)v54;
        v56 = (unsigned int *)((char *)v56 + 1);
        ++partitionclass;
      }
      while ( (int)v56 < vi->partitions );
    }
    v36 = *(_DWORD *)(codec_setup + 4 * vb->W);
    v62 = 0;
    v37 = *v8 * vi->mult;
    v49 = 0;
    v51 = v36 / 2;
    v14 = look->posts <= 1;
    v57 = 1;
    if ( !v14 )
    {
      v63 = &look->forward_index[1];
      do
      {
        v38 = v8[*v63] & 0x7FFF;
        if ( v38 == v8[*v63] )
        {
          v42 = vi->postlist[*v63];
          codec_setup = v38 * vi->mult;
          v62 = v42;
          render_line0(codec_setup, v51, v49, v42, v37, ilogmask);
          v37 = codec_setup;
          v49 = v62;
        }
        ++v57;
        ++v63;
      }
      while ( v57 < look->posts );
    }
    for ( i = v62; i < vb->pcmend / 2; ++i )
      ilogmask[i] = v37;
    return 1;
  }
  else
  {
    oggpack_write(opb, 0, 1u);
    memset((int)ilogmask, 0, 4 * (vb->pcmend / 2));
    return 0;
  }
}
