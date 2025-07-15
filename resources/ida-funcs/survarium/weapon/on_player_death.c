void __thiscall survarium::weapon::on_player_death(survarium::weapon *this)
{
  vostok::sound::sound_instance_proxy *p_m_breath_holding_sound_effect; // esi
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v3; // ecx

  survarium::weapon_core::on_player_death(this);
  p_m_breath_holding_sound_effect = (vostok::sound::sound_instance_proxy *)&this->m_breath_holding_sound_effect;
  if ( p_m_breath_holding_sound_effect->__vftable )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      (*((void (__thiscall **)(vostok::sound::sound_instance_proxy_vtbl *))p_m_breath_holding_sound_effect->play + 3))(p_m_breath_holding_sound_effect->__vftable);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v3,
        p_m_breath_holding_sound_effect);
    }
  }
}
