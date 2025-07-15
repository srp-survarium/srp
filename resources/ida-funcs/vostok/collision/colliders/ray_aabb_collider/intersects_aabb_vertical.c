char __userpurge vostok::collision::colliders::ray_aabb_collider::intersects_aabb_vertical@<al>(
        const vostok::math::float3 *center@<edx>,
        const vostok::math::float3 *extents@<ecx>,
        float *distance@<esi>,
        vostok::collision::colliders::ray_aabb_collider *this)
{
  float z; // xmm0_4
  float v6; // xmm2_4
  float y; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // [esp+8h] [ebp+8h]

  if ( this->m_origin.x > (float)(extents->x + center->x) )
    return 0;
  z = center->z;
  v6 = this->m_origin.z;
  if ( v6 > (float)(extents->z + z)
    || (float)(center->x - extents->x) > this->m_origin.x
    || (float)(z - extents->z) > v6 )
  {
    return 0;
  }
  y = extents->y;
  v8 = center->y;
  v9 = this->m_origin.y;
  if ( v9 < (float)(y + v8) )
  {
    if ( (float)(v8 - y) < v9 )
    {
      *distance = 0.0;
      return 1;
    }
    if ( this->m_direction.y > 0.0 )
    {
      v10 = v8 - (float)(v9 + y);
      goto LABEL_12;
    }
    return 0;
  }
  if ( this->m_direction.y >= 0.0 )
    return 0;
  v10 = v9 - (float)(y + v8);
LABEL_12:
  *(_DWORD *)distance = LODWORD(v10) & 0x7FFFFFFF;
  return 1;
}
