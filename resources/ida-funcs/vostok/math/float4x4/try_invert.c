char __userpurge vostok::math::float4x4::try_invert@<al>(
        const vostok::math::float4x4 *other@<eax>,
        vostok::math::float4x4 *this)
{
  float z; // xmm3_4
  float y; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm5_4
  float x; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  vostok::math::float4x4 v12; // [esp+10h] [ebp-6Ch] BYREF
  float v13; // [esp+50h] [ebp-2Ch]
  float v14; // [esp+54h] [ebp-28h]
  float v15; // [esp+58h] [ebp-24h]
  float v16; // [esp+5Ch] [ebp-20h]
  float v17; // [esp+60h] [ebp-1Ch]
  float v18; // [esp+64h] [ebp-18h]
  float v19; // [esp+68h] [ebp-14h]
  float v20; // [esp+6Ch] [ebp-10h]
  float v21; // [esp+70h] [ebp-Ch]
  float v22; // [esp+74h] [ebp-8h]

  z = other->k.z;
  y = other->j.y;
  v5 = other->j.z;
  v6 = other->k.y;
  x = other->j.x;
  v8 = other->k.x;
  v20 = other->i.x;
  v19 = other->i.y;
  v21 = other->i.z;
  v22 = (float)((float)((float)((float)(y * z) - (float)(v5 * v6)) * v20)
              - (float)((float)((float)(x * z) - (float)(v8 * v5)) * v19))
      + (float)((float)((float)(x * v6) - (float)(v8 * y)) * v21);
  v13 = fabs(v22);
  if ( v13 < 0.0000001 )
  {
    v9 = other->k.z;
    v14 = y;
    v17 = v5;
    v18 = v9;
    v16 = v6;
    if ( vostok::math::is_relatively_zero((float)(y * v9) - (float)(v5 * v6), v22) )
      return 0;
    if ( vostok::math::is_relatively_zero((float)(v18 * v19) - (float)(v16 * v21), v22) )
      return 0;
    if ( vostok::math::is_relatively_zero((float)(v17 * v19) - (float)(v14 * v21), v22) )
      return 0;
    v10 = other->k.x;
    v13 = other->j.x;
    v15 = v10;
    if ( vostok::math::is_relatively_zero((float)(v13 * v18) - (float)(v10 * v17), v22)
      || vostok::math::is_relatively_zero((float)(v18 * v20) - (float)(v15 * v21), v22)
      || vostok::math::is_relatively_zero((float)(v17 * v20) - (float)(v13 * v21), v22)
      || vostok::math::is_relatively_zero((float)(v13 * v16) - (float)(v15 * v14), v22)
      || vostok::math::is_relatively_zero((float)(v16 * v20) - (float)(v15 * v19), v22)
      || vostok::math::is_relatively_zero((float)(v14 * v20) - (float)(v13 * v19), v22) )
    {
      return 0;
    }
  }
  qmemcpy(this, invert_impl(other, &v12, v22), sizeof(vostok::math::float4x4));
  return 1;
}
