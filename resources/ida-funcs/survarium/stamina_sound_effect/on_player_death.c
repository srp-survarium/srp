void __thiscall survarium::stamina_sound_effect::on_player_death(survarium::stamina_sound_effect *this)
{
  vostok::sound::sound_instance_proxy *p_m_sound_instance; // esi
  vostok::sound::sound_instance_proxy *m_object; // ecx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v3; // ecx

  p_m_sound_instance = (vostok::sound::sound_instance_proxy *)&this->m_sound_instance;
  m_object = this->m_sound_instance.m_object;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_object->stop(m_object);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v3,
        p_m_sound_instance);
    }
  }
}
