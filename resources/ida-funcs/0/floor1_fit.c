int *__usercall floor1_fit@<eax>(
        __int128 a1@<xmm6>,
        vorbis_block *vb,
        vorbis_look_floor1 *look,
        const float *logmdct,
        const float *logmask)
{
  vorbis_look_floor1 *v5; // ebx
  signed int posts; // edx
  int n; // esi
  bool v8; // zf
  int v9; // edi
  lsfit_acc *v10; // esi
  int *v11; // ebx
  int v12; // edi
  int v13; // ebx
  int *v14; // eax
  int v15; // esi
  int *v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // esi
  int v20; // edi
  int v21; // eax
  int v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // edi
  int v26; // eax
  int i; // ecx
  int *v28; // eax
  int j; // ecx
  int *v30; // eax
  int v31; // eax
  int v32; // edi
  char *v33; // esi
  int *v34; // edx
  vorbis_info_floor1 *v35; // edi
  int *hineighbor; // ebx
  int v37; // esi
  int v38; // eax
  int v40; // [esp+10h] [ebp-1358h]
  int v41; // [esp+10h] [ebp-1358h]
  int v42; // [esp+14h] [ebp-1354h]
  int *v43; // [esp+14h] [ebp-1354h]
  int v44; // [esp+18h] [ebp-1350h] BYREF
  int v45; // [esp+1Ch] [ebp-134Ch] BYREF
  int v46; // [esp+20h] [ebp-1348h]
  int v47; // [esp+24h] [ebp-1344h]
  vorbis_info_floor1 *vi; // [esp+28h] [ebp-1340h]
  int v49; // [esp+2Ch] [ebp-133Ch] BYREF
  int v50; // [esp+30h] [ebp-1338h] BYREF
  int v51; // [esp+34h] [ebp-1334h] BYREF
  int v52; // [esp+38h] [ebp-1330h] BYREF
  int v53; // [esp+3Ch] [ebp-132Ch]
  int v54[66]; // [esp+40h] [ebp-1328h] BYREF
  int v55; // [esp+148h] [ebp-1220h] BYREF
  int v56; // [esp+14Ch] [ebp-121Ch]
  _DWORD v57[66]; // [esp+250h] [ebp-1118h] BYREF
  _DWORD v58[66]; // [esp+358h] [ebp-1010h] BYREF
  _DWORD v59[66]; // [esp+460h] [ebp-F08h] BYREF
  lsfit_acc v60[64]; // [esp+568h] [ebp-E00h] BYREF

  v42 = 0;
  v44 = 0;
  v5 = look;
  posts = look->posts;
  n = look->n;
  vi = look->vi;
  v47 = posts;
  v8 = posts == 0;
  if ( posts > 0 )
  {
    memset32(v54, -200, posts);
    memset32(&v55, -200, posts);
    memset(v57, 0, 4 * posts);
    memset32(v58, 1, posts);
    memset(v59, 0xFFu, 4 * posts);
    v8 = posts == 0;
  }
  if ( v8 )
  {
    v42 = accumulate_fit(0, v60, logmask, logmdct, n, n, vi);
  }
  else
  {
    v9 = 0;
    v46 = posts - 1;
    if ( posts - 1 <= 0 )
      return (int *)v44;
    v10 = v60;
    do
    {
      v42 += accumulate_fit(look->sorted_index[v9], v10, logmask, logmdct, look->sorted_index[v9 + 1], look->n, vi);
      ++v9;
      ++v10;
    }
    while ( v9 < v46 );
  }
  if ( v42 )
  {
    v45 = -200;
    v44 = -200;
    fit_line(v60, &v45, &v44, a1, v47 - 1, vi);
    v54[0] = v45;
    v55 = v45;
    v56 = v44;
    v54[1] = v44;
    v40 = 2;
    if ( v47 > 2 )
    {
      v11 = &look->reverse_index[2];
      v43 = &look->reverse_index[2];
      do
      {
        v46 = *v11;
        v12 = v57[v46];
        v13 = v58[v46];
        v14 = &v59[v12];
        v53 = v12;
        if ( *v14 != v13 )
        {
          v15 = look->reverse_index[v12];
          *v14 = v13;
          v44 = post_Y(v12, &v55, v54);
          v17 = post_Y(v13, v16, v54);
          v45 = v17;
          if ( v44 == -1 || v17 == -1 )
            exit(1);
          if ( inspect_error(v45, vi->postlist[v12], vi->postlist[v13], v44, logmask, logmdct, vi) )
          {
            v51 = -200;
            v49 = -200;
            v52 = -200;
            v50 = -200;
            v46 = fit_line(&v60[v15], &v51, &v49, a1, v46 - v15, vi);
            v18 = fit_line(&v60[*v43], &v52, &v50, a1, look->reverse_index[v13] - *v43, vi);
            v19 = v52;
            v20 = v18;
            if ( v46 )
            {
              v21 = v44;
              v22 = v52;
            }
            else
            {
              v21 = v51;
              v22 = v49;
            }
            if ( v20 )
            {
              v23 = v45;
              v19 = v22;
            }
            else
            {
              v23 = v50;
            }
            if ( v46 && v20 )
            {
              v24 = v40;
              v54[v24] = -200;
              *(int *)((char *)&v55 + v24 * 4) = -200;
            }
            else
            {
              v25 = v53;
              *(&v55 + v53) = v21;
              if ( !v25 )
                v54[0] = v21;
              v26 = v40;
              v54[v26] = v22;
              *(int *)((char *)&v55 + v26 * 4) = v19;
              v54[v13] = v23;
              if ( v13 == 1 )
                v56 = v23;
              if ( v22 >= 0 || v19 >= 0 )
              {
                for ( i = *v43 - 1; i >= 0; *v28 = v40 )
                {
                  v28 = &v58[i];
                  if ( *v28 != v13 )
                    break;
                  --i;
                }
                for ( j = *v43 + 1; j < v47; ++j )
                {
                  v30 = &v57[j];
                  if ( *v30 != v25 )
                    break;
                  *v30 = v40;
                }
              }
            }
          }
          else
          {
            v31 = v40;
            v54[v31] = -200;
            *(int *)((char *)&v55 + v31 * 4) = -200;
          }
        }
        ++v40;
        v11 = ++v43;
      }
      while ( v40 < v47 );
      v5 = look;
    }
    v32 = v47;
    v33 = _vorbis_block_alloc(vb, 4 * v47);
    v44 = (int)v33;
    *(_DWORD *)v33 = post_Y(0, &v55, v54);
    *((_DWORD *)v33 + 1) = post_Y(1, v34, v54);
    v41 = 2;
    if ( v32 > 2 )
    {
      v35 = vi;
      v45 = (int)&vi->postlist[2];
      hineighbor = v5->hineighbor;
      do
      {
        v37 = v44;
        v46 = render_point(
                *(_DWORD *)(v44 + 4 * *hineighbor),
                *(_DWORD *)v45,
                v35->postlist[hineighbor[63]],
                v35->postlist[*hineighbor],
                *(_DWORD *)(v44 + 4 * hineighbor[63]));
        v38 = post_Y(v41, &v55, v54);
        if ( v38 < 0 || v46 == v38 )
          *(_DWORD *)(v37 + 4 * v41) = v46 | 0x8000;
        else
          *(_DWORD *)(v37 + 4 * v41) = v38;
        ++v41;
        v45 += 4;
        ++hineighbor;
      }
      while ( v41 < v47 );
    }
  }
  return (int *)v44;
}
