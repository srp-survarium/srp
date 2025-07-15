vostok::math::float3 *__thiscall survarium::human_npc::get_eyes_direction(
        survarium::human_npc *this,
        vostok::math::float3 *result)
{
  vostok::math::float3 *eyes_direction; // eax
  float z; // xmm3_4
  float y; // xmm4_4
  unsigned int v6; // xmm0_4
  unsigned int v7; // xmm1_4
  float v8; // xmm0_4
  vostok::math::float3 *v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // [esp+8h] [ebp-10h]
  vostok::math::float3 v13; // [esp+Ch] [ebp-Ch] BYREF

  eyes_direction = vostok::collision::animated_object::get_eyes_direction(
                     (vostok::collision::animated_object *)&v13,
                     &v13);
  z = eyes_direction->z;
  y = eyes_direction->y;
  *(float *)&v6 = (float)((float)(this->m_transform.j.x * y) + (float)(this->m_transform.k.x * z))
                + (float)(this->m_transform.i.x * eyes_direction->x);
  *(float *)&v7 = (float)((float)(this->m_transform.i.y * eyes_direction->x) + (float)(this->m_transform.j.y * y))
                + (float)(this->m_transform.k.y * z);
  v13.z = (float)((float)(this->m_transform.i.z * eyes_direction->x) + (float)(this->m_transform.j.z * y))
        + (float)(this->m_transform.k.z * z);
  *(_QWORD *)&v13.x = __PAIR64__(v7, v6);
  v12 = sqrtf(
          (float)((float)(v13.z * v13.z) + (float)(*(float *)&v6 * *(float *)&v6))
        + (float)(*(float *)&v7 * *(float *)&v7));
  v8 = *(float *)&clear_value / v12;
  v9 = result;
  result->x = (float)(*(float *)&clear_value / v12) * v13.x;
  v10 = v8 * v13.y;
  v11 = v8 * v13.z;
  result->y = v10;
  result->z = v11;
  return v9;
}
