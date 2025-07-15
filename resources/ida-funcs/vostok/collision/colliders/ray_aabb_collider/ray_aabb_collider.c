void __fastcall vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(
        vostok::collision::colliders::ray_aabb_collider *this,
        const vostok::math::float3 *direction,
        const vostok::math::float3 *origin)
{
  float x; // xmm0_4
  float v4; // xmm1_4
  int v5; // ecx
  int v6; // ecx
  float v7; // xmm0_4
  int v8; // ecx
  float v9; // [esp+8h] [ebp-Ch]
  float v10; // [esp+Ch] [ebp-8h]

  this->m_direction = *direction;
  this->m_origin.vostok::math::float3 = *origin;
  this->m_origin.padding = 0.0;
  x = this->m_direction.x;
  v4 = s_bm_current_air_resistance
     / fsqrt(
         (float)((float)(this->m_direction.y * this->m_direction.y) + (float)(this->m_direction.z * this->m_direction.z))
       + (float)(x * x));
  this->m_direction.x = x * v4;
  this->m_direction.y = v4 * this->m_direction.y;
  this->m_direction.z = this->m_direction.z * v4;
  v9 = invert(this->m_direction.x);
  v10 = invert(*(float *)(v5 + 36));
  v7 = invert(*(float *)(v6 + 40));
  *(float *)(v8 + 16) = v9;
  *(float *)(v8 + 20) = v10;
  *(float *)(v8 + 24) = v7;
  *(_DWORD *)(v8 + 28) = 0;
}
