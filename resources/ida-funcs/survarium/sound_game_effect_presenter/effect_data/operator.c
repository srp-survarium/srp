survarium::sound_game_effect_presenter::effect_data *__usercall survarium::sound_game_effect_presenter::effect_data::operator=@<eax>(
        survarium::sound_game_effect_presenter::effect_data *this@<esi>,
        const survarium::sound_game_effect_presenter::effect_data *__that@<eax>)
{
  survarium::loose_ptr_data *m_object; // ecx
  survarium::loose_ptr_data *v4; // eax
  survarium::loose_ptr_data *v5; // ecx
  survarium::loose_ptr_data *v6; // eax

  m_object = __that->effect.m_object;
  v4 = 0;
  if ( m_object )
  {
    v4 = m_object;
    ++m_object->m_reference_count;
  }
  v5 = v4;
  v6 = this->effect.m_object;
  this->effect.m_object = v5;
  if ( v6 )
  {
    if ( v6->m_reference_count-- == 1 )
      survarium::loose_ptr_data::destroy<survarium::loose_ptr_data>(
        (survarium::loose_ptr_data *)v6->m_reference_count,
        v6);
  }
  this->offset = __that->offset;
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
    &__that->sound,
    &this->sound);
  return this;
}
