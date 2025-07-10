int *__cdecl floor1_fit(vorbis_block *vb, vorbis_look_floor1 *look, float *logmdct, float *logmask)
{
  vorbis_look_floor1 *v4; // ebx
  vorbis_info_floor1 *vi; // edx
  signed int posts; // esi
  bool v7; // zf
  int v8; // eax
  int v9; // edi
  lsfit_acc *v10; // esi
  int v11; // esi
  int v12; // edi
  int v13; // edx
  int v14; // esi
  vorbis_info_floor1 *v15; // eax
  int v16; // edi
  int v17; // ebx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // eax
  int v23; // edi
  int v24; // eax
  int v25; // ecx
  int v26; // ebx
  int v27; // edx
  int v28; // eax
  int v29; // ecx
  int v30; // ecx
  int v31; // ebx
  int i; // eax
  int v33; // edx
  int v34; // eax
  int v35; // esi
  int v36; // eax
  int *v37; // eax
  int v38; // ecx
  int v39; // ecx
  int *hineighbor; // ebx
  int v41; // eax
  int v42; // edi
  int v43; // esi
  int v44; // ecx
  int v45; // eax
  int v46; // esi
  int v47; // ecx
  int v48; // edx
  int v49; // eax
  int y0; // [esp+10h] [ebp-1358h] BYREF
  int *v52; // [esp+14h] [ebp-1354h]
  int y1; // [esp+18h] [ebp-1350h] BYREF
  int v54; // [esp+1Ch] [ebp-134Ch]
  int v55; // [esp+20h] [ebp-1348h]
  vorbis_info_floor1 *info; // [esp+24h] [ebp-1344h]
  int v57; // [esp+28h] [ebp-1340h]
  int v58; // [esp+2Ch] [ebp-133Ch]
  int x0; // [esp+30h] [ebp-1338h] BYREF
  int x1; // [esp+34h] [ebp-1334h]
  int v61; // [esp+38h] [ebp-1330h] BYREF
  int v62; // [esp+3Ch] [ebp-132Ch] BYREF
  int v63; // [esp+40h] [ebp-1328h] BYREF
  int v64; // [esp+44h] [ebp-1324h]
  int v65; // [esp+148h] [ebp-1220h] BYREF
  int v66; // [esp+14Ch] [ebp-121Ch]
  _DWORD v67[66]; // [esp+250h] [ebp-1118h] BYREF
  _DWORD v68[66]; // [esp+358h] [ebp-1010h] BYREF
  _DWORD v69[66]; // [esp+460h] [ebp-F08h] BYREF
  lsfit_acc a[64]; // [esp+568h] [ebp-E00h] BYREF

  v4 = look;
  vi = look->vi;
  posts = look->posts;
  info = vi;
  v55 = posts;
  y0 = 0;
  v52 = 0;
  if ( posts > 0 )
    memset32(&v65, -200, posts);
  v7 = posts == 0;
  if ( posts > 0 )
  {
    memset32(&v63, -200, posts);
    memset(v68, 0, 4 * posts);
    memset32(v67, 1, posts);
    memset(v69, 0xFFu, 4 * posts);
    v7 = posts == 0;
  }
  if ( v7 )
  {
    v8 = accumulate_fit(0, a, logmask, logmdct, look->n, look->n, vi);
  }
  else
  {
    v9 = 0;
    if ( posts - 1 <= 0 )
      return v52;
    v10 = a;
    while ( 1 )
    {
      y0 += accumulate_fit(look->sorted_index[v9], v10, logmask, logmdct, look->sorted_index[v9 + 1], look->n, vi);
      ++v9;
      ++v10;
      if ( v9 >= v55 - 1 )
        break;
      vi = info;
    }
    v8 = y0;
  }
  if ( v8 )
  {
    v11 = v55;
    y0 = -200;
    y1 = -200;
    fit_line(a, v55 - 1, &y0, &y1);
    v12 = y0;
    v65 = y0;
    v63 = y0;
    v64 = y1;
    v66 = y1;
    v54 = 2;
    if ( v11 > 2 )
    {
      v52 = &look->reverse_index[2];
      do
      {
        v13 = v68[*v52];
        v14 = v67[*v52];
        v57 = v13;
        if ( v69[v13] != v14 )
        {
          v15 = info;
          v16 = v4->reverse_index[v13];
          v17 = v4->reverse_index[v14];
          x0 = info->postlist[v13];
          x1 = info->postlist[v14];
          v18 = *(&v65 + v13);
          v69[v13] = v14;
          v19 = *(&v63 + v13);
          if ( v18 >= 0 )
          {
            if ( v19 >= 0 )
              v18 = (v19 + v18) >> 1;
            v58 = v18;
          }
          else
          {
            v58 = v19;
          }
          v20 = *(&v65 + v14);
          if ( v20 >= 0 )
          {
            v21 = *(&v63 + v14);
            if ( v21 >= 0 )
              v20 = (v21 + v20) >> 1;
          }
          else
          {
            v20 = *(&v63 + v14);
          }
          y1 = v20;
          if ( v58 == -1 || v20 == -1 )
            exit(1);
          if ( !inspect_error(x0, v20, x1, v58, logmask, logmdct, v15) )
            goto LABEL_51;
          v62 = -200;
          v61 = -200;
          y0 = -200;
          x0 = -200;
          v22 = fit_line(&a[v16], *v52 - v16, &v62, &v61);
          v23 = *v52;
          x1 = v22;
          v24 = fit_line(&a[v23], v17 - v23, &y0, &x0);
          v25 = v24;
          if ( x1 )
          {
            v26 = v58;
            v27 = y0;
          }
          else
          {
            v26 = v62;
            v27 = v61;
          }
          if ( v24 )
          {
            v28 = y1;
            y0 = v27;
          }
          else
          {
            v28 = x0;
          }
          if ( x1 && v25 )
          {
LABEL_51:
            v36 = v54;
            *(&v63 + v54) = -200;
            *(&v65 + v36) = -200;
          }
          else
          {
            v29 = v57;
            *(&v63 + v57) = v26;
            if ( !v29 )
              v65 = v26;
            v30 = v54;
            v31 = y0;
            *(&v65 + v54) = v27;
            *(&v63 + v30) = v31;
            *(&v65 + v14) = v28;
            if ( v14 == 1 )
              v64 = v28;
            if ( v27 >= 0 || v31 >= 0 )
            {
              for ( i = v23 - 1; i >= 0; v67[i + 1] = v30 )
              {
                if ( v67[i] != v14 )
                  break;
                --i;
              }
              v33 = v55;
              v34 = *v52 + 1;
              if ( v34 < v55 )
              {
                v35 = v57;
                do
                {
                  if ( v68[v34] != v35 )
                    break;
                  v68[v34++] = v30;
                }
                while ( v34 < v33 );
              }
            }
          }
          v4 = look;
        }
        ++v52;
        ++v54;
      }
      while ( v54 < v55 );
      v12 = v63;
      v11 = v55;
    }
    v37 = (int *)_vorbis_block_alloc(vb, 4 * v11);
    v38 = v65;
    v52 = v37;
    if ( v65 >= 0 )
    {
      if ( v12 >= 0 )
        v38 = (v12 + v65) >> 1;
    }
    else
    {
      v38 = v12;
    }
    *v37 = v38;
    v39 = v66;
    if ( v66 >= 0 )
    {
      if ( v64 >= 0 )
        v39 = (v64 + v66) >> 1;
    }
    else
    {
      v39 = v64;
    }
    v37[1] = v39;
    v54 = 2;
    if ( v55 > 2 )
    {
      hineighbor = v4->hineighbor;
      y1 = (int)&info->postlist[2];
      for ( y0 = (int)hineighbor; ; hineighbor = (int *)y0 )
      {
        v41 = hineighbor[63];
        v42 = *hineighbor;
        v57 = info->postlist[v41];
        v43 = v52[v41] & 0x7FFF;
        v44 = (v52[v42] & 0x7FFF) - v43;
        v45 = (int)((*(_DWORD *)y1 - v57) * abs32(v44)) / (info->postlist[v42] - v57);
        if ( v44 >= 0 )
          v46 = v45 + v43;
        else
          v46 = v43 - v45;
        v47 = v54;
        v48 = *(&v65 + v54);
        v49 = *(&v63 + v54);
        if ( v48 >= 0 )
        {
          if ( v49 >= 0 )
            v49 = (v48 + v49) >> 1;
          else
            v49 = *(&v65 + v54);
        }
        v52[v54] = v49 < 0 || v46 == v49 ? v46 | 0x8000 : v49;
        y0 += 4;
        y1 += 4;
        v54 = v47 + 1;
        if ( v47 + 1 >= v55 )
          break;
      }
    }
  }
  return v52;
}
