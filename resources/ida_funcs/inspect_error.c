BOOL __usercall inspect_error@<eax>(
        int x0@<eax>,
        int y1@<ecx>,
        int x1,
        int y0,
        const float *mask,
        const float *mdct,
        vorbis_info_floor1 *info)
{
  int v7; // ecx
  unsigned int v9; // ebp
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // esi
  vorbis_info_floor1 *v16; // ecx
  int v18; // ebp
  int v20; // edi
  float *v21; // esi
  int v22; // edi
  int v23; // eax
  int v24; // eax
  int v25; // ecx
  int y; // [esp+10h] [ebp-1Ch]
  int val; // [esp+14h] [ebp-18h]
  int n; // [esp+18h] [ebp-14h]
  int err; // [esp+1Ch] [ebp-10h]
  int sy; // [esp+20h] [ebp-Ch]
  int base; // [esp+24h] [ebp-8h]
  int ady; // [esp+28h] [ebp-4h]
  float x1a; // [esp+30h] [ebp+4h]
  float x; // [esp+34h] [ebp+8h]
  int xa; // [esp+34h] [ebp+8h]
  float maska; // [esp+38h] [ebp+Ch]
  float maskb; // [esp+38h] [ebp+Ch]
  float mdcta; // [esp+3Ch] [ebp+10h]

  v7 = y1 - y0;
  v9 = abs32(v7);
  v10 = x1 - x0;
  v11 = v7 / (x1 - x0);
  base = v11;
  if ( v7 >= 0 )
    v12 = v11 + 1;
  else
    v12 = v11 - 1;
  sy = v12;
  y = y0;
  err = 0;
  v13 = (int)(mask[x0] * 7.314285755157471 + 1023.5);
  if ( v13 <= 1023 )
    v14 = v13 < 0 ? 0 : v13;
  else
    v14 = 1023;
  v15 = y0 - v14;
  val = v14;
  v16 = info;
  ady = v9 - abs32(v10 * base);
  v18 = v15 * v15;
  n = 1;
  if ( mask[x0] <= mdct[x0] + info->twofitatten )
  {
    x = (float)y0;
    maska = (float)val;
    if ( maska > info->maxover + x || x - info->maxunder > maska )
      return 1;
  }
  v20 = x0 + 1;
  xa = v20;
  if ( v20 < x1 )
  {
    v21 = (float *)&mask[v20];
    v22 = (char *)mdct - (char *)mask;
    while ( 1 )
    {
      v23 = ady + err;
      err += ady;
      if ( err < v10 )
      {
        y += base;
      }
      else
      {
        y += sy;
        err = v23 - v10;
      }
      v24 = (int)(*v21 * 7.314285755157471 + 1023.5);
      v25 = v24 <= 1023 ? (v24 < 0 ? 0 : v24) : 1023;
      ++n;
      v18 += (y - v25) * (y - v25);
      if ( *v21 <= *(float *)((char *)v21 + v22) + info->twofitatten )
      {
        if ( v25 )
        {
          mdcta = (float)y;
          maskb = (float)v25;
          if ( maskb > info->maxover + mdcta || mdcta - info->maxunder > maskb )
            return 1;
        }
      }
      ++v21;
      if ( ++xa >= x1 )
      {
        v16 = info;
        break;
      }
    }
  }
  x1a = (float)n;
  if ( v16->maxerr < v16->maxover * v16->maxover / x1a )
    return 0;
  return v16->maxerr >= v16->maxunder * v16->maxunder / x1a && v16->maxerr < (double)(v18 / n);
}
