void __thiscall vostok::collision::truncated_sphere_geometry_instance::get_aabb(
        vostok::collision::truncated_sphere_geometry_instance *this,
        vostok::math::aabb *bbox,
        const vostok::math::float4x4 *self_transform)
{
  float m_radius; // xmm3_4
  float x; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm5_4
  float v9; // [esp+0h] [ebp-40h]
  float y; // [esp+4h] [ebp-3Ch]
  float z; // [esp+8h] [ebp-38h]
  float v12; // [esp+Ch] [ebp-34h]
  __int64 v13; // [esp+10h] [ebp-30h]
  __int64 v14; // [esp+1Ch] [ebp-24h]
  float v15; // [esp+30h] [ebp-10h]
  __int128 v16; // [esp+30h] [ebp-10h]
  float self_transforma; // [esp+48h] [ebp+8h]

  m_radius = this->m_radius;
  x = self_transform->k.x;
  v6 = self_transform->j.x;
  self_transforma = self_transform->i.x;
  *(float *)&v14 = (float)((float)((float)(v6 * m_radius) + (float)(x * m_radius)) + (float)(self_transforma * m_radius))
                 + self_transform->c.x;
  y = self_transform->i.y;
  v9 = self_transform->k.y;
  *((float *)&v14 + 1) = (float)((float)((float)(self_transform->j.y * m_radius) + (float)(v9 * m_radius))
                               + (float)(y * m_radius))
                       + self_transform->c.y;
  z = self_transform->k.z;
  v7 = self_transform->j.z;
  v12 = self_transform->i.z;
  v8 = self_transform->c.z;
  v15 = -m_radius;
  *(float *)&v13 = (float)((float)((float)(v6 * v15) + (float)(x * v15)) + (float)(self_transforma * v15))
                 + self_transform->c.x;
  *((float *)&v13 + 1) = (float)((float)((float)(self_transform->j.y * v15) + (float)(v9 * v15)) + (float)(y * v15))
                       + self_transform->c.y;
  *(float *)&v16 = (float)((float)((float)(v7 * v15) + (float)(z * v15)) + (float)(v12 * v15)) + v8;
  *(_QWORD *)&bbox->min.x = v13;
  *(_QWORD *)((char *)&v16 + 4) = v14;
  *((float *)&v16 + 3) = (float)((float)((float)(v7 * m_radius) + (float)(z * m_radius)) + (float)(v12 * m_radius)) + v8;
  *(_OWORD *)&bbox->min.elements[2] = v16;
}
