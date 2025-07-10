vostok::math::float3 *__thiscall survarium::human_npc::get_eyes_position(
        survarium::human_npc *this,
        vostok::math::float3 *result)
{
  vostok::math::float3 *head_bone_center; // eax
  float y; // xmm1_4
  float z; // xmm0_4
  float x; // xmm2_4
  vostok::math::float3 *v7; // eax
  float v8; // xmm4_4
  vostok::math::float3 *v9; // [esp+0h] [ebp-14h]

  head_bone_center = vostok::collision::animated_object::get_head_bone_center(
                       (vostok::collision::animated_object *)this,
                       v9);
  y = head_bone_center->y;
  z = head_bone_center->z;
  x = head_bone_center->x;
  v7 = result;
  v8 = this->m_transform.j.y;
  result->x = (float)((float)((float)(this->m_transform.j.x * y) + (float)(this->m_transform.k.x * z))
                    + (float)(this->m_transform.i.x * x))
            + this->m_transform.c.x;
  result->y = (float)((float)((float)(this->m_transform.i.y * x) + (float)(v8 * y)) + (float)(this->m_transform.k.y * z))
            + this->m_transform.c.y;
  result->z = (float)((float)((float)(this->m_transform.i.z * x) + (float)(this->m_transform.j.z * y))
                    + (float)(this->m_transform.k.z * z))
            + this->m_transform.c.z;
  return v7;
}
