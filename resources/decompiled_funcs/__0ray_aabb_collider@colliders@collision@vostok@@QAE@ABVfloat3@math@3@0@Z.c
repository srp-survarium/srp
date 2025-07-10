void __usercall vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(
        vostok::collision::colliders::ray_aabb_collider *this@<esi>,
        const vostok::math::float3 *origin@<ecx>,
        const vostok::math::float3 *direction@<eax>)
{
  long double v3; // st7
  const vostok::math::float4x4 *v4; // xmm1_4
  long double v5; // st6
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float x; // [esp+4h] [ebp-14h]
  float v10; // [esp+8h] [ebp-10h]

  this->m_direction = *direction;
  this->m_origin.vostok::math::float3 = *origin;
  this->m_origin.padding = 0.0;
  x = this->m_direction.x;
  v3 = 1.0
     / sqrtf(
         (float)((float)(this->m_direction.y * this->m_direction.y) + (float)(this->m_direction.z * this->m_direction.z))
       + (float)(x * x));
  v4 = clear_value;
  v10 = v3;
  v5 = v3 * this->m_direction.y;
  this->m_direction.x = x * v10;
  this->m_direction.y = v5;
  this->m_direction.z = v3 * this->m_direction.z;
  if ( COERCE_FLOAT(LODWORD(this->m_direction.z) & 0x7FFFFFFF) >= 0.0000099999997 )
    v6 = *(float *)&v4 / this->m_direction.z;
  else
    v6 = 0.0;
  if ( COERCE_FLOAT(LODWORD(this->m_direction.y) & 0x7FFFFFFF) >= 0.0000099999997 )
    v7 = *(float *)&v4 / this->m_direction.y;
  else
    v7 = 0.0;
  if ( COERCE_FLOAT(LODWORD(this->m_direction.x) & 0x7FFFFFFF) >= 0.0000099999997 )
    v8 = *(float *)&v4 / this->m_direction.x;
  else
    v8 = 0.0;
  *(_QWORD *)&this->m_inverted_direction.x = __PAIR64__(LODWORD(v7), LODWORD(v8));
  this->m_inverted_direction.z = v6;
  this->m_inverted_direction.padding = 0.0;
}
