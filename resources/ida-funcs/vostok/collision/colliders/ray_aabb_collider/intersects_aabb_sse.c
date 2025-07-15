bool __userpurge vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse@<al>(
        const vostok::collision::colliders::sse::aabb_a16 *aabb@<eax>,
        vostok::collision::colliders::ray_aabb_collider *this,
        float *distance)
{
  float x; // xmm1_4
  float v4; // xmm0_4
  float y; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  vostok::math::aabb *v8; // ecx
  int v9; // eax
  float v10; // xmm0_4
  vostok::math::float3 origin; // [esp+10h] [ebp-30h] BYREF
  __int64 v13; // [esp+1Ch] [ebp-24h]
  float z; // [esp+24h] [ebp-1Ch]
  vostok::math::float3 v15; // [esp+28h] [ebp-18h] BYREF
  vostok::math::float3 result; // [esp+34h] [ebp-Ch] BYREF

  x = this->m_inverted_direction.x;
  origin = aabb->min.vostok::math::float3;
  v13 = *(_QWORD *)&aabb->max.x;
  z = aabb->max.z;
  v4 = invert(x);
  y = this->m_inverted_direction.y;
  result.x = v4;
  v6 = invert(y);
  v7 = this->m_inverted_direction.z;
  result.y = v6;
  result.z = invert(v7);
  v9 = vostok::math::aabb::intersect(v8, &origin, &this->m_origin, &result, &v15);
  if ( v9 )
  {
    if ( v9 == 1 )
      v10 = 0.0;
    else
      v10 = fsqrt(
              (float)((float)((float)(v15.z - this->m_origin.z) * (float)(v15.z - this->m_origin.z))
                    + (float)((float)(v15.y - this->m_origin.y) * (float)(v15.y - this->m_origin.y)))
            + (float)((float)(v15.x - this->m_origin.x) * (float)(v15.x - this->m_origin.x)));
    *distance = v10;
  }
  return v9 != 0;
}
