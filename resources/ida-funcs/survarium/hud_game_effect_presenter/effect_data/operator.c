survarium::hud_game_effect_presenter::effect_data *__usercall survarium::hud_game_effect_presenter::effect_data::operator=@<eax>(
        survarium::hud_game_effect_presenter::effect_data *this@<esi>,
        const survarium::hud_game_effect_presenter::effect_data *__that@<edi>)
{
  survarium::loose_ptr_data *m_object; // eax
  survarium::loose_ptr_data *v3; // ecx
  survarium::loose_ptr_data *v4; // eax

  m_object = 0;
  if ( __that->effect.m_object )
  {
    m_object = __that->effect.m_object;
    ++__that->effect.m_object->m_reference_count;
  }
  v3 = m_object;
  v4 = this->effect.m_object;
  this->effect.m_object = v3;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      survarium::loose_ptr_data::destroy<survarium::loose_ptr_data>(
        (survarium::loose_ptr_data *)v4->m_reference_count,
        v4);
  }
  this->effect_type = __that->effect_type;
  this->frame_id = __that->frame_id;
  return this;
}
