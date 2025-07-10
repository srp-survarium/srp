char __userpurge vostok::math::float4x4::try_invert@<al>(
        const vostok::math::float4x4 *other@<eax>,
        vostok::math::float4x4 *this)
{
  float y; // xmm4_4
  float z; // xmm6_4
  float v5; // xmm5_4
  float determinant; // [esp+14h] [ebp-68h]
  float v8; // [esp+18h] [ebp-64h]
  __int64 v9; // [esp+1Ch] [ebp-60h]
  float v10; // [esp+24h] [ebp-58h]
  float v11; // [esp+30h] [ebp-4Ch]
  float x; // [esp+38h] [ebp-44h]
  vostok::math::float4x4 v13; // [esp+3Ch] [ebp-40h] BYREF

  y = other->j.y;
  z = other->j.z;
  v5 = other->k.y;
  v9 = *(_QWORD *)&other->i.x;
  v8 = other->i.z;
  determinant = (float)((float)((float)((float)(y * other->k.z) - (float)(z * v5)) * other->i.x)
                      - (float)((float)((float)(other->j.x * other->k.z) - (float)(other->k.x * z)) * other->i.y))
              + (float)((float)((float)(other->j.x * v5) - (float)(other->k.x * y)) * v8);
  if ( fabs(determinant) < 0.0000001 )
  {
    v10 = other->k.z;
    if ( vostok::math::is_relatively_zero((float)(y * v10) - (float)(z * v5), determinant, 0.0000001) )
      return 0;
    if ( vostok::math::is_relatively_zero((float)(v10 * *((float *)&v9 + 1)) - (float)(v5 * v8), determinant, 0.0000001) )
      return 0;
    if ( vostok::math::is_relatively_zero((float)(z * *((float *)&v9 + 1)) - (float)(y * v8), determinant, 0.0000001) )
      return 0;
    x = other->j.x;
    v11 = other->k.x;
    if ( vostok::math::is_relatively_zero((float)(x * v10) - (float)(v11 * z), determinant, 0.0000001)
      || vostok::math::is_relatively_zero((float)(v10 * *(float *)&v9) - (float)(v11 * v8), determinant, 0.0000001)
      || vostok::math::is_relatively_zero((float)(z * *(float *)&v9) - (float)(x * v8), determinant, 0.0000001)
      || vostok::math::is_relatively_zero((float)(x * v5) - (float)(v11 * y), determinant, 0.0000001)
      || vostok::math::is_relatively_zero(
           (float)(v5 * *(float *)&v9) - (float)(v11 * *((float *)&v9 + 1)),
           determinant,
           0.0000001)
      || vostok::math::is_relatively_zero(
           (float)(y * *(float *)&v9) - (float)(x * *((float *)&v9 + 1)),
           determinant,
           0.0000001) )
    {
      return 0;
    }
  }
  qmemcpy((void *)this, invert_impl(other, &v13, determinant), sizeof(vostok::math::float4x4));
  return 1;
}
