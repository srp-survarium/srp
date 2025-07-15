void __thiscall survarium::damage_sound_effect::on_player_death(
        survarium::damage_sound_effect *this,
        unsigned int current_time_in_ms)
{
  vostok::sound::sound_instance_proxy *m_object; // ecx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v4; // ecx
  vostok::sound::sound_instance_proxy *v5; // ecx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v6; // ecx
  vostok::sound::sound_instance_proxy *v7; // ecx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v8; // ecx

  if ( !survarium::base_player::is_in_past((survarium::base_player *)this, (int)this->m_user, current_time_in_ms) )
  {
    m_object = this->m_poisoning_sound_instance.m_object;
    if ( m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_object->stop(m_object);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v4,
        (vostok::sound::sound_instance_proxy *)&this->m_poisoning_sound_instance);
    }
    v5 = this->m_poisoning_outro_sound_instance.m_object;
    if ( v5
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v5->stop(v5);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v6,
        (vostok::sound::sound_instance_proxy *)&this->m_poisoning_outro_sound_instance);
    }
    v7 = this->m_toxic_damage_sound_instance.m_object;
    if ( v7 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v7->stop(v7);
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
          v8,
          (vostok::sound::sound_instance_proxy *)&this->m_toxic_damage_sound_instance);
      }
    }
    this->m_is_poisoned = 0;
  }
}
