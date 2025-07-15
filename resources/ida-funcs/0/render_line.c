void __usercall render_line(int y1@<eax>, int n, int x0, int x1, int y0, float *d)
{
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // esi
  int v9; // eax
  bool v10; // sf
  int v11; // edi
  unsigned int v12; // esi
  int v13; // edx
  int v14; // ebx
  float *v15; // eax
  float *v16; // edi
  int v17; // [esp+Ch] [ebp-4h]
  int v18; // [esp+20h] [ebp+10h]

  v6 = x1 - x0;
  v7 = y1 - y0;
  v8 = abs32(y1 - y0);
  v9 = (y1 - y0) / (x1 - x0);
  v10 = v7 < 0;
  v11 = v9 - 1;
  if ( !v10 )
    v11 = v9 + 1;
  v17 = 0;
  v12 = v8 - abs32(v6 * v9);
  if ( n > x1 )
    n = x1;
  if ( x0 < n )
    d[x0] = FLOOR1_fromdB_LOOKUP[y0] * d[x0];
  v13 = x0 + 1;
  if ( x0 + 1 < n )
  {
    v18 = 4 * v9;
    v14 = 4 * v11;
    v15 = (float *)&FLOOR1_fromdB_LOOKUP[y0];
    do
    {
      v17 += v12;
      if ( v17 < v6 )
      {
        v15 = (float *)((char *)v15 + v18);
      }
      else
      {
        v17 -= v6;
        v15 = (float *)((char *)v15 + v14);
      }
      v16 = &d[v13++];
      *v16 = *v16 * *v15;
    }
    while ( v13 < n );
  }
}
