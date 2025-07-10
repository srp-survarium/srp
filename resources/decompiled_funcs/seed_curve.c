void __usercall seed_curve(
        float *seed@<edi>,
        const float **curves,
        float amp,
        int oc,
        int n,
        int linesper,
        float dBoffset)
{
  double v7; // st7
  int v9; // eax
  int v10; // eax
  const float *v11; // esi
  int v12; // ebp
  int v13; // esi
  int v14; // eax
  int v15; // ecx
  float *v16; // edx
  int v17; // esi
  int v18; // esi
  int v19; // esi
  const float *posts; // [esp+8h] [ebp+8h]
  float lin; // [esp+14h] [ebp+14h]
  float lina; // [esp+14h] [ebp+14h]
  float linb; // [esp+14h] [ebp+14h]
  float linc; // [esp+14h] [ebp+14h]
  float lind; // [esp+14h] [ebp+14h]

  v7 = amp;
  v9 = (int)((amp + dBoffset - 30.0) * 0.1000000014901161);
  v10 = v9 <= 0 ? 0 : v9;
  if ( v10 >= 7 )
    v10 = 7;
  v11 = curves[v10];
  posts = v11;
  v12 = (int)v11[1];
  v13 = (int)((*v11 - 16.0) * (double)linesper + (double)oc - (double)(linesper >> 1));
  v14 = (int)*posts;
  v15 = v14;
  if ( v14 < v12 )
  {
    if ( v12 - v14 < 4 )
    {
LABEL_23:
      while ( v15 < v12 )
      {
        if ( v13 > 0 )
        {
          lind = posts[v15 + 2] + v7;
          if ( lind > (double)seed[v13] )
            seed[v13] = lind;
        }
        v13 += linesper;
        if ( v13 >= n )
          break;
        ++v15;
      }
    }
    else
    {
      v16 = (float *)&posts[v14 + 4];
      while ( 1 )
      {
        if ( v13 > 0 )
        {
          lin = *(v16 - 2) + v7;
          if ( lin > (double)seed[v13] )
            seed[v13] = lin;
        }
        v17 = linesper + v13;
        if ( v17 >= n )
          break;
        if ( v17 > 0 )
        {
          lina = *(v16 - 1) + v7;
          if ( lina > (double)seed[v17] )
            seed[v17] = lina;
        }
        v18 = linesper + v17;
        if ( v18 >= n )
          break;
        if ( v18 > 0 )
        {
          linb = *v16 + v7;
          if ( linb > (double)seed[v18] )
            seed[v18] = linb;
        }
        v19 = linesper + v18;
        if ( v19 >= n )
          break;
        if ( v19 > 0 )
        {
          linc = v16[1] + v7;
          if ( linc > (double)seed[v19] )
            seed[v19] = linc;
        }
        v13 = linesper + v19;
        if ( v13 >= n )
          break;
        v15 += 4;
        v16 += 4;
        if ( v15 >= v12 - 3 )
          goto LABEL_23;
      }
    }
  }
}
