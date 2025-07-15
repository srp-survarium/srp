vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_animation_end_aware_state::on_animation_end(
        survarium::weapon_core_animation_end_aware_state *this,
        vostok::animation::animation_callback_params *params)
{
  const void *animated_object; // esi
  survarium::weapon_core *m_weapon; // edi
  survarium::weapon_core_animation_end_aware_state_vtbl *v4; // eax

  animated_object = params->animated_object;
  params->interrupt_animation_player_tick = 0;
  m_weapon = this->m_weapon;
  if ( (animated_object == m_weapon || animated_object == m_weapon->m_user)
    && params->animation->m_object == this->m_animations_buffer[this->m_index_of_animation_to_wait].m_object )
  {
    v4 = this->survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable;
    this->m_animation_has_been_ended = 1;
    ((void (__stdcall *)(bool *))v4->on_animation_end_impl)(&params->interrupt_animation_player_tick);
  }
  return 0;
}
