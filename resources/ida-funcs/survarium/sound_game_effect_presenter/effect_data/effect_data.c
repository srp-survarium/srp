void __thiscall survarium::sound_game_effect_presenter::effect_data::effect_data(
        survarium::sound_game_effect_presenter::effect_data *this,
        const survarium::sound_game_effect_presenter::effect_data *__that)
{
  survarium::loose_ptr_data *m_object; // eax

  __that->effect.m_object = 0;
  m_object = this->effect.m_object;
  if ( this->effect.m_object )
  {
    __that->effect.m_object = m_object;
    ++m_object->m_reference_count;
  }
  __that->offset = this->offset;
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>(
    &__that->sound,
    &this->sound);
}
