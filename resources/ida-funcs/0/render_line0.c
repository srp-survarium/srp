void __usercall render_line0(int y1@<eax>, int n, int x0, int x1, int y0, int *d)
{
  int v6; // ecx
  int v7; // ebx
  int v8; // edi
  unsigned int v9; // esi
  int v10; // eax
  int v11; // edx
  unsigned int v12; // esi
  int v13; // eax
  int v14; // [esp+Ch] [ebp-8h]
  int v15; // [esp+28h] [ebp+14h]

  v6 = x1 - x0;
  v7 = y0;
  v8 = y1 - y0;
  v9 = abs32(y1 - y0);
  v10 = (y1 - y0) / (x1 - x0);
  v14 = v10;
  v11 = v10 - 1;
  if ( v8 >= 0 )
    v11 = v10 + 1;
  v15 = 0;
  v12 = v9 - abs32(v6 * v10);
  if ( n > x1 )
    n = x1;
  v13 = x0;
  if ( x0 >= n )
    goto LABEL_11;
  while ( 1 )
  {
    d[v13] = v7;
LABEL_11:
    if ( ++v13 >= n )
      break;
    v15 += v12;
    if ( v15 < v6 )
    {
      v7 += v14;
    }
    else
    {
      v15 -= v6;
      v7 += v11;
    }
  }
}
