void __cdecl render_line(int n, int x0, int x1, int y0, float *d)
{
  int y1; // ecx
  int v6; // esi
  int v7; // edi
  int v8; // ecx
  unsigned int v9; // ebx
  int v10; // eax
  int v11; // ebp
  unsigned int v12; // ebx
  int v13; // ecx
  int v14; // edx
  float *v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // ecx
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  bool v22; // zf
  float *v23; // edi
  double v24; // st7
  int sy; // [esp+10h] [ebp-8h]
  int base; // [esp+14h] [ebp-4h]
  int x1a; // [esp+24h] [ebp+Ch]

  v6 = x1 - x0;
  v7 = y0;
  v8 = y1 - y0;
  v9 = abs32(v8);
  v10 = v8 / (x1 - x0);
  v11 = n;
  base = v10;
  if ( v8 >= 0 )
    sy = v10 + 1;
  else
    sy = v10 - 1;
  v12 = v9 - abs32(v6 * v10);
  v13 = 0;
  if ( n > x1 )
  {
    v11 = x1;
    n = x1;
  }
  if ( x0 < v11 )
    d[x0] = FLOOR1_fromdB_LOOKUP[y0] * d[x0];
  v14 = x0 + 1;
  if ( x0 + 1 < v11 )
  {
    if ( v11 - v14 >= 4 )
    {
      v15 = &d[v14 + 2];
      x1a = ((unsigned int)(v11 - v14 - 4) >> 2) + 1;
      v14 += 4 * x1a;
      do
      {
        v16 = v12 + v13;
        if ( v16 < v6 )
        {
          v17 = base + v7;
        }
        else
        {
          v16 -= v6;
          v17 = sy + v7;
        }
        v18 = v12 + v16;
        *(v15 - 2) = FLOOR1_fromdB_LOOKUP[v17] * *(v15 - 2);
        if ( v18 < v6 )
        {
          v19 = base + v17;
        }
        else
        {
          v18 -= v6;
          v19 = sy + v17;
        }
        v20 = v12 + v18;
        *(v15 - 1) = FLOOR1_fromdB_LOOKUP[v19] * *(v15 - 1);
        if ( v20 < v6 )
        {
          v21 = base + v19;
        }
        else
        {
          v20 -= v6;
          v21 = sy + v19;
        }
        v13 = v12 + v20;
        *v15 = FLOOR1_fromdB_LOOKUP[v21] * *v15;
        if ( v13 < v6 )
        {
          v7 = base + v21;
        }
        else
        {
          v13 -= v6;
          v7 = sy + v21;
        }
        v15 += 4;
        v22 = x1a-- == 1;
        *(v15 - 3) = FLOOR1_fromdB_LOOKUP[v7] * *(v15 - 3);
      }
      while ( !v22 );
      v11 = n;
    }
    if ( v14 < v11 )
    {
      v23 = (float *)&FLOOR1_fromdB_LOOKUP[v7];
      do
      {
        v13 += v12;
        if ( v13 < v6 )
        {
          v23 += base;
        }
        else
        {
          v13 -= v6;
          v23 += sy;
        }
        v24 = *v23 * d[v14++];
        d[v14 - 1] = v24;
      }
      while ( v14 < v11 );
    }
  }
}
