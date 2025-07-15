void __usercall survarium::hud_game_effect_presenter::effect_data::effect_data(
        survarium::hud_game_effect_presenter::effect_data *this@<eax>,
        const survarium::hud_game_effect_presenter::effect_data *__that@<edx>)
{
  survarium::loose_ptr_data *m_object; // ecx

  this->effect.m_object = 0;
  m_object = __that->effect.m_object;
  if ( __that->effect.m_object )
  {
    this->effect.m_object = m_object;
    ++m_object->m_reference_count;
  }
  this->effect_type = __that->effect_type;
  this->frame_id = __that->frame_id;
}
