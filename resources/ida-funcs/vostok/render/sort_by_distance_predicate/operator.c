BOOL __usercall vostok::render::sort_by_distance_predicate::operator()@<eax>(
        vostok::render::sort_by_distance_predicate *this@<esi>,
        const vostok::render::render_surface_instance *left@<eax>,
        const vostok::render::render_surface_instance *right@<edx>)
{
  vostok::math::float4x4 *m_transform; // eax
  __int64 value; // xmm0_8
  float z; // ecx
  vostok::math::float4x4 *v6; // eax
  signed int v7; // eax
  float v8; // xmm6_4
  float y; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  bool v12; // cc
  float pos0; // [esp+4h] [ebp-18h]
  float pos0_4; // [esp+8h] [ebp-14h]
  float pos0_8; // [esp+Ch] [ebp-10h]
  float pos0_8a; // [esp+Ch] [ebp-10h]
  __int64 pos1; // [esp+10h] [ebp-Ch]
  float pos1_8; // [esp+18h] [ebp-4h]

  m_transform = left->m_transform;
  value = *(_QWORD *)&m_transform->lines[3].x;
  z = m_transform->c.z;
  v6 = right->m_transform;
  pos0_8 = z;
  pos1 = *(_QWORD *)&v6->lines[3].x;
  pos1_8 = v6->c.z;
  pos0 = (float)(int)vostok::math::floor(*(float *)&value);
  pos0_4 = (float)(int)vostok::math::floor(*((float *)&value + 1));
  pos0_8a = (float)(int)vostok::math::floor(pos0_8);
  *(float *)&pos1 = (float)(int)vostok::math::floor(*(float *)&pos1);
  *((float *)&pos1 + 1) = (float)(int)vostok::math::floor(*((float *)&pos1 + 1));
  v7 = vostok::math::floor(pos1_8);
  v8 = this->m_eye_position.z;
  y = this->m_eye_position.y;
  v10 = (float)((float)((float)(pos0 - this->m_eye_position.x) * (float)(pos0 - this->m_eye_position.x))
              + (float)((float)(pos0_8a - v8) * (float)(pos0_8a - v8)))
      + (float)((float)(pos0_4 - y) * (float)(pos0_4 - y));
  v11 = (float)((float)((float)((float)v7 - v8) * (float)((float)v7 - v8))
              + (float)((float)(*((float *)&pos1 + 1) - y) * (float)(*((float *)&pos1 + 1) - y)))
      + (float)((float)(*(float *)&pos1 - this->m_eye_position.x) * (float)(*(float *)&pos1 - this->m_eye_position.x));
  if ( this->m_from_near_to_far )
    v12 = v11 <= v10;
  else
    v12 = v10 <= v11;
  return !v12;
}
