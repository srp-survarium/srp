void __thiscall survarium::breath_holding_sound_effect::on_outro_sound_ended(
        survarium::breath_holding_sound_effect *this)
{
  survarium::breath_holding_sound_effect *v2; // ecx

  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
    &this->m_sound_instance,
    (vostok::sound::sound_instance_proxy *)this);
  if ( this->m_breath_held )
    survarium::breath_holding_sound_effect::play_start_sound(v2, this);
}
