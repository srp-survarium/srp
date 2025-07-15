BOOL __usercall planeBoxOverlap@<eax>(
        const vostok::math::float3 *maxbox@<eax>,
        const vostok::math::float3 *normal,
        const vostok::math::float3 *vert)
{
  int v3; // edx
  int v4; // esi
  int v5; // edi
  float *v6; // ecx
  float *v7; // edx
  float v8; // xmm2_4
  float x; // xmm0_4
  float v10; // xmm4_4
  bool v11; // zf
  float v13[3]; // [esp+0h] [ebp-20h] BYREF
  float v14[3]; // [esp+Ch] [ebp-14h] BYREF
  int v15; // [esp+18h] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-4h]

  v3 = (char *)normal - (char *)v14;
  v4 = (char *)v14 - (char *)maxbox;
  v15 = (char *)normal - (char *)v14;
  v5 = (char *)v13 - (char *)maxbox;
  v16 = 3;
  while ( 1 )
  {
    v6 = (float *)((char *)&maxbox->x + v4);
    v7 = (float *)((char *)&maxbox->x + v4 + v3);
    v8 = *(float *)((char *)v7 + (char *)vert - (char *)normal);
    x = maxbox->x;
    v10 = maxbox->x;
    if ( *v7 <= 0.0 )
      LODWORD(x) ^= _mask__NegFloat_;
    else
      LODWORD(v10) ^= _mask__NegFloat_;
    *(float *)((char *)&maxbox->x + v5) = x - v8;
    maxbox = (const vostok::math::float3 *)((char *)maxbox + 4);
    v11 = v16-- == 1;
    *v6 = v10 - v8;
    if ( v11 )
      break;
    v3 = v15;
  }
  return (float)((float)((float)(normal->x * v14[0]) + (float)(normal->z * v14[2])) + (float)(normal->y * v14[1])) <= 0.0
      && (float)((float)((float)(normal->x * v13[0]) + (float)(normal->z * v13[2])) + (float)(normal->y * v13[1])) >= 0.0;
}
