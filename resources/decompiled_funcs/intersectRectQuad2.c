int __usercall intersectRectQuad2@<eax>(float *p@<edx>, float *h, float *ret)
{
  float *v3; // esi
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // ebp
  int v7; // ebx
  float *v8; // edi
  float v9; // xmm5_4
  float v10; // xmm4_4
  float *v11; // ebp
  float *v12; // esi
  float *v13; // eax
  float *r; // [esp+10h] [ebp-5Ch]
  int nr; // [esp+14h] [ebp-58h]
  float *v17; // [esp+18h] [ebp-54h]
  int i; // [esp+1Ch] [ebp-50h]
  float *v19; // [esp+20h] [ebp-4Ch]
  float *q; // [esp+24h] [ebp-48h]
  int sign; // [esp+28h] [ebp-44h]
  float buffer[16]; // [esp+2Ch] [ebp-40h] BYREF

  v3 = ret;
  v4 = 4;
  q = p;
  r = ret;
  v5 = 0;
  while ( 2 )
  {
    v6 = -1;
    sign = -1;
    do
    {
      v7 = 0;
      v8 = v3;
      nr = 0;
      i = v4;
      if ( v4 > 0 )
      {
        v9 = h[v5 / 4];
        v17 = p + 2;
        v10 = (float)v6;
        v11 = &p[v5 / 4];
        v12 = &v3[v5 / 0xFFFFFFFC + 1];
        v19 = &p[v5 / 4];
        v13 = &p[v5 / 0xFFFFFFFC + 1];
        while ( 1 )
        {
          if ( v9 > (float)(*v11 * v10) )
          {
            ++v7;
            *v8 = v13[v5 / 4 - 1];
            v8 += 2;
            v12 += 2;
            *(v8 - 1) = v13[v5 / 4];
            nr = v7;
            if ( (v7 & 8) != 0 )
              break;
          }
          if ( i > 1 )
            p = v17;
          v7 = nr;
          if ( v9 > (float)(*v11 * v10) != v9 > (float)(p[v5 / 4] * v10) )
          {
            *v12 = (float)((float)((float)(p[v5 / 0xFFFFFFFC + 1] - *v13) / (float)(p[v5 / 4] - *v11))
                         * (float)((float)(v9 * v10) - *v11))
                 + *v13;
            v7 = nr + 1;
            v8[v5 / 4] = v9 * v10;
            v8 += 2;
            v12 += 2;
            nr = v7;
            if ( (v7 & 8) != 0 )
              break;
          }
          v17 += 2;
          v11 = v19 + 2;
          v13 += 2;
          v19 += 2;
          if ( --i <= 0 )
          {
            v3 = r;
            v6 = sign;
            goto LABEL_14;
          }
          p = q;
        }
        p = r;
        goto done_4;
      }
LABEL_14:
      p = v3;
      q = v3;
      if ( v3 == ret )
      {
        v3 = buffer;
        r = buffer;
      }
      else
      {
        v3 = ret;
        r = ret;
      }
      v6 += 2;
      v4 = v7;
      sign = v6;
    }
    while ( v6 <= 1 );
    v5 += 4;
    if ( (int)v5 <= 4 )
      continue;
    break;
  }
done_4:
  if ( p != ret )
    memcpy((unsigned __int8 *)ret, (unsigned __int8 *)p, 8 * v7);
  return v7;
}
