void __thiscall survarium::stamina_sound_effect::on_finish_sound_ended(survarium::stamina_sound_effect *this)
{
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
    &this->m_sound_instance,
    (vostok::sound::sound_instance_proxy *)&this->m_sound_instance);
}
