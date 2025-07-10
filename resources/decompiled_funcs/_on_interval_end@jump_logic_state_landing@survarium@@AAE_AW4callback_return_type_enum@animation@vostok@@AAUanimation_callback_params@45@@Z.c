vostok::animation::callback_return_type_enum __thiscall survarium::jump_logic_state_landing::on_interval_end(
        survarium::jump_logic_state_landing *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::game_camera *m_owner; // [esp+14h] [ebp-8h]

  if ( params->animation_interval_id == this->m_interval_id_to_wait_for )
  {
    m_owner = (survarium::game_camera *)this->m_jump_logic->m_owner;
    survarium::weapon_user_dead_state::finalize(m_owner);
    if ( params->animated_object == m_owner->m_game_scene )
    {
      if ( vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator==(
             &params->animation->vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>,
             &this->m_animation) )
      {
        params->interrupt_animation_player_tick = 1;
        survarium::weapon_user_animations_selector::remove_animation_callback(
          this->m_jump_logic->m_owner,
          channel_id_on_animation_interval_end,
          this);
        this->m_is_jump_finished = 1;
      }
    }
  }
  return 0;
}
