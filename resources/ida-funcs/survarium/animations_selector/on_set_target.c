void __usercall survarium::animations_selector::on_set_target(
        survarium::animations_selector *this@<ecx>,
        survarium::animations_selector *a2@<eax>)
{
  if ( !a2->m_current_controller )
    survarium::animations_selector::reset_animation_controller(
      a2,
      (vostok::animation::subscribed_channel **)a2->m_game_world->m_game->m_current_time_in_ms);
}
