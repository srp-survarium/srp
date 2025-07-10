vostok::animation::callback_return_type_enum __thiscall survarium::weapon::on_foot_step(
        survarium::weapon *this,
        vostok::animation::animation_callback_params *params)
{
  const survarium::player *m_user; // edx
  unsigned __int8 domain_data; // al
  vostok::math::float4x4 *p_m_left_toe_transform; // eax

  m_user = (const survarium::player *)this->m_user;
  if ( params->animated_object == m_user )
  {
    domain_data = params->domain_data;
    if ( domain_data == 5 )
    {
      p_m_left_toe_transform = &this->m_left_toe_transform;
    }
    else
    {
      if ( domain_data != 6 )
        return 0;
      p_m_left_toe_transform = &this->m_right_toe_transform;
    }
    if ( !byte_10F80[(_DWORD)m_user] )
      survarium::step_manager::on_step(
        (survarium::step_manager *)this->m_game_scene[3].survarium::engine::__vftable,
        m_user,
        (const vostok::math::float3 *)&p_m_left_toe_transform->lines[3],
        (const vostok::math::float3 *)&p_m_left_toe_transform->lines[2],
        (survarium::game_world *)this->m_game_scene);
  }
  return 0;
}
