void __thiscall survarium::hit_animations_selector::on_damage(
        survarium::hit_animations_selector *this,
        const char *part_name,
        float amount,
        unsigned int current_time_in_ms,
        const survarium::bullet *the_bullet)
{
  const vostok::math::float4x4 *v6; // eax
  float z; // xmm2_4
  float x; // xmm0_4
  float y; // xmm1_4
  int body_part_id_by_name; // eax
  survarium::hit_animations_selector::hit_body_part *v11; // ecx
  survarium::hit_animations_selector::hit_body_part *v12; // esi
  bool v13; // al
  survarium::hit_animations_selector::hit_body_part *amounta; // [esp+0h] [ebp-5Ch]
  vostok::math::float3 v15; // [esp+10h] [ebp-4Ch] BYREF
  vostok::math::float4x4 v16; // [esp+1Ch] [ebp-40h] BYREF

  if ( the_bullet )
  {
    v6 = this->m_user->transform(&this->m_user->survarium::collision_user);
    vostok::math::float4x4::try_invert(v6, &v16);
    z = the_bullet->m_position.z;
    x = the_bullet->m_position.x;
    y = the_bullet->m_position.y;
    v15.x = (float)((float)((float)(x * v16.i.x) + (float)(z * v16.k.x)) + (float)(y * v16.j.x)) + v16.c.x;
    v15.y = (float)((float)((float)(x * v16.i.y) + (float)(z * v16.k.y)) + (float)(y * v16.j.y)) + v16.c.y;
    v15.z = (float)((float)((float)(x * v16.i.z) + (float)(z * v16.k.z)) + (float)(y * v16.j.z)) + v16.c.z;
    body_part_id_by_name = survarium::get_body_part_id_by_name(part_name, &v15);
    v11 = amounta;
    if ( body_part_id_by_name != 8 )
    {
      v12 = &this->m_hit_body_parts[body_part_id_by_name];
      v13 = this->m_need_to_select_animations
         || !survarium::hit_animations_selector::hit_body_part::has_hit(v12, current_time_in_ms);
      this->m_need_to_select_animations = v13;
      survarium::hit_animations_selector::hit_body_part::hit(v11, v12, current_time_in_ms, amount);
    }
  }
}
