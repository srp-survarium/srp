void __thiscall survarium::player_input_handler::on_after_processing(
        survarium::player_input_handler *this,
        vostok::input::world *input_world)
{
  survarium::input_mode_type_enum m_input_mode; // eax

  if ( this->m_is_enabled )
  {
    m_input_mode = this->m_input_mode;
    if ( m_input_mode && m_input_mode != third_person_mode )
    {
      if ( m_input_mode == warmup_mode )
        survarium::player_input_handler::process_warmup_mode(this, (float *)this);
    }
    else
    {
      survarium::player_input_handler::process_first_person_mode(this, (survarium::game_action_id)this, 1);
    }
  }
  else
  {
    this->m_current_input.rotation_delta = 0;
  }
}
