void __usercall render_line0(int y1@<eax>, int n, int x0, int x1, int y0, int *d)
{
  int v8; // esi
  unsigned int v9; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // edx
  unsigned int v14; // edi
  int v15; // esi
  int i; // eax
  int base; // [esp+10h] [ebp-4h]
  int sy; // [esp+20h] [ebp+Ch]
  int err; // [esp+24h] [ebp+10h]

  v8 = y1 - y0;
  v9 = abs32(y1 - y0);
  v10 = x1 - x0;
  v11 = (y1 - y0) / (x1 - x0);
  base = v11;
  v12 = v11 - 1;
  if ( v8 >= 0 )
    v12 = v11 + 1;
  sy = v12;
  v13 = n;
  v14 = v9 - abs32(v10 * v11);
  v15 = y0;
  err = 0;
  if ( n > x1 )
    v13 = x1;
  if ( x0 < v13 )
    d[x0] = y0;
  for ( i = x0 + 1; i < v13; ++i )
  {
    err += v14;
    if ( err < v10 )
    {
      v15 += base;
    }
    else
    {
      err -= v10;
      v15 += sy;
    }
    d[i] = v15;
  }
}
