int __usercall accumulate_fit@<eax>(
        int x0@<eax>,
        lsfit_acc *a@<esi>,
        const float *flr,
        const float *mdct,
        int x1,
        int n,
        vorbis_info_floor1 *info)
{
  int v7; // ebx
  int v10; // eax
  float *v11; // ebp
  double v12; // st5
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  int result; // eax
  int ya; // [esp+Ch] [ebp-2Ch]
  int x2a; // [esp+10h] [ebp-28h]
  int y2a; // [esp+14h] [ebp-24h]
  int xya; // [esp+18h] [ebp-20h]
  int xb; // [esp+1Ch] [ebp-1Ch]
  int yb; // [esp+20h] [ebp-18h]
  int x2b; // [esp+24h] [ebp-14h]
  int y2b; // [esp+28h] [ebp-10h]
  int xyb; // [esp+2Ch] [ebp-Ch]
  int nb; // [esp+30h] [ebp-8h]
  int xa; // [esp+48h] [ebp+10h]

  v7 = 0;
  xa = 0;
  ya = 0;
  x2a = 0;
  y2a = 0;
  xya = 0;
  xb = 0;
  yb = 0;
  x2b = 0;
  y2b = 0;
  xyb = 0;
  nb = 0;
  memset((int)a, 0, sizeof(lsfit_acc));
  v10 = x1;
  a->x0 = x0;
  a->x1 = x1;
  if ( x1 >= n )
  {
    x1 = n - 1;
    v10 = n - 1;
  }
  if ( x0 <= v10 )
  {
    v11 = (float *)&flr[x0];
    do
    {
      v12 = *v11 * 7.314285755157471 + 1023.5;
      v13 = (int)v12;
      if ( (int)v12 <= 1023 )
      {
        if ( v13 < 0 )
          goto LABEL_12;
        v14 = (int)v12;
        if ( !v13 )
          goto LABEL_12;
      }
      else
      {
        v14 = 1023;
      }
      v15 = v14 * v14;
      if ( *v11 > *(float *)((char *)v11 + (char *)mdct - (char *)flr) + info->twofitatten )
      {
        yb += v14;
        xb += x0;
        x2b += x0 * x0;
        y2b += v15;
        xyb += x0 * v14;
        ++nb;
      }
      else
      {
        ya += v14;
        xa += x0;
        x2a += x0 * x0;
        y2a += v15;
        xya += x0 * v14;
        ++v7;
      }
LABEL_12:
      ++x0;
      ++v11;
    }
    while ( x0 <= x1 );
  }
  a->xa = xa;
  a->ya = ya;
  a->y2a = y2a;
  a->x2a = x2a;
  a->xya = xya;
  a->yb = yb;
  a->xb = xb;
  a->x2b = x2b;
  a->xyb = xyb;
  a->an = v7;
  result = v7;
  a->y2b = y2b;
  a->bn = nb;
  return result;
}
