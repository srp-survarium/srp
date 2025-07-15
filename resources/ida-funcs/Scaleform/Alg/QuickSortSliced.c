void __cdecl Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<unsigned int,4,16>,Scaleform::Render::Tessellator::CmpScanbeams>(
        Scaleform::Render::ArrayPaged<unsigned int,4,16> *arr,
        unsigned int start,
        unsigned int end,
        Scaleform::Render::Tessellator::CmpScanbeams less)
{
  unsigned int v4; // esi
  Scaleform::Render::ArrayPaged<unsigned int,4,16> *v5; // ebp
  int *v6; // ebx
  unsigned int **Pages; // edx
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int *v10; // ecx
  unsigned int v11; // edi
  unsigned int *v12; // eax
  int v13; // ebx
  unsigned int *v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // esi
  int v18; // edi
  unsigned int v19; // ecx
  unsigned int **v20; // ebp
  unsigned int *v21; // eax
  unsigned int *v22; // esi
  unsigned int *v23; // edi
  unsigned int v24; // eax
  unsigned int *v25; // esi
  unsigned int v26; // eax
  unsigned int **v27; // esi
  unsigned int v28; // eax
  unsigned int **v29; // esi
  int v30; // edi
  unsigned int *v31; // eax
  unsigned int *v32; // esi
  int v33; // ebp
  unsigned int v34; // edi
  unsigned int **v35; // eax
  unsigned int *v36; // ebx
  unsigned int *v37; // esi
  unsigned int v38; // eax
  unsigned int *v39; // esi
  unsigned int v40; // edi
  unsigned int **v41; // ebp
  unsigned int *v42; // eax
  unsigned int v43; // ecx
  Scaleform::Render::Tessellator::SrcVertexType **v44; // ebx
  double y; // st7
  unsigned int *v46; // eax
  int v47; // ecx
  unsigned int v48; // edx
  int v49; // edx
  unsigned int **v50; // [esp+4h] [ebp-168h]
  unsigned int *v51; // [esp+4h] [ebp-168h]
  unsigned int *v52; // [esp+4h] [ebp-168h]
  int limit; // [esp+8h] [ebp-164h]
  unsigned int v54; // [esp+Ch] [ebp-160h]
  unsigned int *v55; // [esp+10h] [ebp-15Ch]
  unsigned int *v56; // [esp+10h] [ebp-15Ch]
  unsigned int *v57; // [esp+10h] [ebp-15Ch]
  int *top; // [esp+14h] [ebp-158h]
  int i; // [esp+18h] [ebp-154h]
  unsigned int v60; // [esp+1Ch] [ebp-150h]
  int v61; // [esp+20h] [ebp-14Ch]
  unsigned int *v62; // [esp+24h] [ebp-148h]
  int base; // [esp+28h] [ebp-144h]
  int stack[80]; // [esp+2Ch] [ebp-140h] BYREF

  v4 = start;
  if ( end - start >= 2 )
  {
    v5 = arr;
    v6 = stack;
    for ( limit = end; ; limit = v49 )
    {
      base = v4;
      while ( 1 )
      {
        top = v6;
        if ( (int)(limit - v4) <= 9 )
          break;
        Pages = v5->Pages;
        v8 = v4 + (int)(limit - v4) / 2;
        v9 = v8 & 0xF;
        v10 = Pages[v8 >> 4];
        v11 = v10[v9];
        v12 = &v10[v9];
        v13 = v4 >> 4;
        v14 = &Pages[v13][v4 & 0xF];
        v61 = v4 & 0xF;
        v15 = *v14;
        *v14 = v11;
        *v12 = v15;
        v16 = v4 + 1;
        v50 = v5->Pages;
        v17 = (v4 + 1) >> 4;
        v18 = v16 & 0xF;
        v62 = &v50[v17][v18];
        v19 = limit - 1;
        v60 = (unsigned int)(limit - 1) >> 4;
        v55 = &v50[v60][((_BYTE)limit - 1) & 0xF];
        if ( less.Ver->Pages[*v62 >> 4][*v62 & 0xF].y > (double)less.Ver->Pages[*v55 >> 4][*v55 & 0xF].y )
        {
          v54 = *v55;
          *v55 = *v62;
          *v62 = v54;
        }
        v20 = arr->Pages;
        v21 = v20[v17];
        v22 = v20[v13];
        v23 = &v21[v18];
        v24 = *v23;
        v62 = v23;
        v51 = &v22[v61];
        if ( less.Ver->Pages[v24 >> 4][v24 & 0xF].y > (double)less.Ver->Pages[v22[v61] >> 4][v22[v61] & 0xF].y )
        {
          v25 = v62;
          v26 = *v51;
          *v51 = *v62;
          *v25 = v26;
        }
        v27 = arr->Pages;
        v56 = &v27[v60][((_BYTE)limit - 1) & 0xF];
        v52 = &v27[v13][v61];
        if ( less.Ver->Pages[*v52 >> 4][*v52 & 0xF].y > (double)less.Ver->Pages[*v56 >> 4][*v56 & 0xF].y )
        {
          v28 = *v56;
          *v56 = *v52;
          *v52 = v28;
        }
        while ( 1 )
        {
          v29 = arr->Pages;
          do
            ++v16;
          while ( less.Ver->Pages[v29[v13][v61] >> 4][v29[v13][v61] & 0xF].y > (double)less.Ver->Pages[v29[v16 >> 4][v16 & 0xF] >> 4][v29[v16 >> 4][v16 & 0xF] & 0xF].y );
          do
            --v19;
          while ( less.Ver->Pages[v29[v19 >> 4][v19 & 0xF] >> 4][v29[v19 >> 4][v19 & 0xF] & 0xF].y > (double)less.Ver->Pages[v29[v13][v61] >> 4][v29[v13][v61] & 0xF].y );
          v30 = v19 & 0xF;
          if ( (int)v16 > (int)v19 )
            break;
          v31 = &v29[v19 >> 4][v30];
          v32 = v29[v16 >> 4];
          v33 = v16 & 0xF;
          v34 = v32[v33];
          v32[v33] = *v31;
          *v31 = v34;
        }
        v5 = arr;
        v35 = arr->Pages;
        v36 = &v35[v13][v61];
        v37 = v35[v19 >> 4];
        v38 = *v36;
        v39 = &v37[v30];
        *v36 = *v39;
        *v39 = v38;
        v4 = base;
        if ( (int)(v19 - base) <= (int)(limit - v16) )
        {
          *top = v16;
          top[1] = limit;
          limit = v19;
        }
        else
        {
          *top = base;
          v4 = v16;
          top[1] = v19;
          base = v16;
        }
        v6 = top + 2;
      }
      v40 = v4;
      i = v4 + 1;
      if ( (int)(v4 + 1) < limit )
      {
        do
        {
          while ( 1 )
          {
            v41 = v5->Pages;
            v42 = &v41[v40 >> 4][v40 & 0xF];
            v43 = v40 + 1;
            v44 = less.Ver->Pages;
            y = v44[v41[(v40 + 1) >> 4][((_BYTE)v40 + 1) & 0xF] >> 4][v41[(v40 + 1) >> 4][((_BYTE)v40 + 1) & 0xF] & 0xF].y;
            v5 = arr;
            v57 = v42;
            if ( v44[*v42 >> 4][*v42 & 0xF].y <= y )
              break;
            v46 = arr->Pages[v43 >> 4];
            v47 = v43 & 0xF;
            v48 = v46[v47];
            v46[v47] = *v57;
            *v57 = v48;
            if ( v40 == v4 )
              break;
            --v40;
          }
          v40 = i++;
        }
        while ( i < limit );
        v6 = top;
      }
      if ( v6 <= stack )
        break;
      v49 = *(v6 - 1);
      v4 = *(v6 - 2);
      v6 -= 2;
    }
  }
}
