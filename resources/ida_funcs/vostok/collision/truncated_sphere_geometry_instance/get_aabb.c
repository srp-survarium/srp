vostok::math::aabb *__thiscall vostok::collision::truncated_sphere_geometry_instance::get_aabb(
        vostok::collision::truncated_sphere_geometry_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax
  vostok::math::aabb v3; // [esp+0h] [ebp-24h]
  __int64 v4; // [esp+18h] [ebp-Ch]

  *(float *)&v4 = this->m_radius;
  HIDWORD(v4) = v4;
  LODWORD(v3.min.x) = v4 ^ 0x80000000;
  LODWORD(v3.min.y) = v4 ^ 0x80000000;
  LODWORD(v3.min.z) = v4 ^ 0x80000000;
  v2 = result;
  *(_QWORD *)&v3.max.x = v4;
  LODWORD(v3.max.z) = v4;
  *result = v3;
  return v2;
}


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


vostok::math::aabb *__thiscall vostok::collision::truncated_sphere_geometry_instance::get_aabb(
        vostok::collision::truncated_sphere_geometry_instance *this,
        vostok::math::aabb *result)
{
  float m_radius; // xmm0_4
  vostok::math::aabb *v3; // eax
  float v4; // edx
  float v5; // xmm1_4
  float v6; // xmm3_4
  __int64 v7; // [esp+0h] [ebp-18h]
  __int64 v8; // [esp+Ch] [ebp-Ch]

  m_radius = this->m_radius;
  *(float *)&v8 = (float)((float)((float)(this->m_matrix.k.x * m_radius) + (float)(this->m_matrix.j.x * m_radius))
                        + (float)(this->m_matrix.i.x * m_radius))
                + this->m_matrix.c.x;
  *((float *)&v8 + 1) = (float)((float)((float)(this->m_matrix.k.y * m_radius) + (float)(this->m_matrix.j.y * m_radius))
                              + (float)(this->m_matrix.i.y * m_radius))
                      + this->m_matrix.c.y;
  v3 = result;
  v4 = (float)((float)((float)(this->m_matrix.k.z * m_radius) + (float)(this->m_matrix.j.z * m_radius))
             + (float)(this->m_matrix.i.z * m_radius))
     + this->m_matrix.c.z;
  v5 = -m_radius;
  *(float *)&v7 = (float)((float)((float)(this->m_matrix.k.x * v5) + (float)(this->m_matrix.j.x * v5))
                        + (float)(this->m_matrix.i.x * v5))
                + this->m_matrix.c.x;
  *((float *)&v7 + 1) = (float)((float)((float)(this->m_matrix.k.y * v5) + (float)(this->m_matrix.j.y * v5))
                              + (float)(this->m_matrix.i.y * v5))
                      + this->m_matrix.c.y;
  v6 = (float)((float)((float)(this->m_matrix.k.z * v5) + (float)(this->m_matrix.j.z * v5))
             + (float)(this->m_matrix.i.z * v5))
     + this->m_matrix.c.z;
  *(_QWORD *)&result->min.x = v7;
  *(_QWORD *)&result->max.x = v8;
  result->min.z = v6;
  result->max.z = v4;
  return v3;
}
