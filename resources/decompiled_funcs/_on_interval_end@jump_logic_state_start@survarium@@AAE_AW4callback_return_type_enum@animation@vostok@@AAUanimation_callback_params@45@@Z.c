vostok::animation::callback_return_type_enum __thiscall survarium::jump_logic_state_start::on_interval_end(
        survarium::jump_logic_state_start *this,
        vostok::animation::animation_callback_params *params)
{
  bool v3; // [esp+0h] [ebp-18h]
  survarium::game_camera_vtbl *v5; // [esp+10h] [ebp-8h]
  survarium::game_camera *m_jump_logic; // [esp+14h] [ebp-4h]

  m_jump_logic = (survarium::game_camera *)this->m_jump_logic;
  v5 = m_jump_logic->__vftable;
  survarium::weapon_user_dead_state::finalize(m_jump_logic);
  if ( params->animated_object == v5[3].on_deactivate )
  {
    v3 = vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator==(
           &params->animation->vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>,
           &this->m_animation)
      && params->animation_interval_id == this->m_interval_id_to_wait_for;
    this->m_jump_interval_ended = v3;
    this->m_preface_interval_ended = vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator==(
                                       &params->animation->vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>,
                                       &this->m_preface_animation);
    params->interrupt_animation_player_tick = 1;
  }
  return 0;
}
