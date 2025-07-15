vostok::animation::callback_return_type_enum __thiscall survarium::animations_selector::on_animation_interval_end(
        survarium::animations_selector *this,
        vostok::animation::animation_callback_params *params)
{
  params->interrupt_animation_player_tick = 1;
  this->m_current_controller->query_new_target_if_needed(this->m_current_controller);
  survarium::animations_selector::reset_animation_controller(
    this,
    (vostok::animation::subscribed_channel **)params->callback_time_in_ms);
  return 0;
}
