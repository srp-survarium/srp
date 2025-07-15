BOOL __userpurge vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse@<eax>(
        vostok::collision::colliders::ray_aabb_collider *this@<esi>,
        const vostok::collision::colliders::sse::aabb_a16 *aabb@<eax>,
        float *distance)
{
  float z; // ecx
  float v4; // edx
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  int v9; // eax
  int v10; // edi
  float v11; // xmm0_4
  float v13; // [esp+8h] [ebp-34h]
  vostok::math::float3 result; // [esp+Ch] [ebp-30h] BYREF
  vostok::math::float3 intersection_point; // [esp+18h] [ebp-24h] BYREF
  vostok::math::aabb bbox; // [esp+24h] [ebp-18h] BYREF

  z = aabb->min.z;
  v4 = aabb->max.z;
  *(_QWORD *)&bbox.min.x = *(_QWORD *)&aabb->min.x;
  *(_QWORD *)&bbox.max.x = *(_QWORD *)&aabb->max.x;
  v5 = this->m_inverted_direction.z;
  bbox.min.z = z;
  bbox.max.z = v4;
  if ( COERCE_FLOAT(LODWORD(v5) & 0x7FFFFFFF) >= 0.0000099999997 )
    v6 = *(float *)&clear_value / v5;
  else
    v6 = 0.0;
  if ( COERCE_FLOAT(LODWORD(this->m_inverted_direction.y) & 0x7FFFFFFF) >= 0.0000099999997 )
    v7 = *(float *)&clear_value / this->m_inverted_direction.y;
  else
    v7 = 0.0;
  if ( COERCE_FLOAT(LODWORD(this->m_inverted_direction.x) & 0x7FFFFFFF) >= 0.0000099999997 )
    v8 = *(float *)&clear_value / this->m_inverted_direction.x;
  else
    v8 = 0.0;
  result.x = v8;
  result.y = v7;
  result.z = v6;
  v9 = vostok::math::aabb::intersect(
         (vostok::math::aabb *)&result,
         &bbox.min,
         &this->m_origin,
         (int)&result,
         &intersection_point);
  v10 = v9;
  if ( v9 )
  {
    if ( v9 == 1 )
    {
      v11 = 0.0;
    }
    else
    {
      v13 = sqrtf(
              (float)((float)((float)(intersection_point.z - this->m_origin.z)
                            * (float)(intersection_point.z - this->m_origin.z))
                    + (float)((float)(intersection_point.y - this->m_origin.y)
                            * (float)(intersection_point.y - this->m_origin.y)))
            + (float)((float)(intersection_point.x - this->m_origin.x) * (float)(intersection_point.x - this->m_origin.x)));
      v11 = v13;
    }
    *distance = v11;
  }
  return v10 != 0;
}
