void __thiscall survarium::weapon_core_throw_grenade_base_substate::finalize(
        survarium::weapon_core_throw_grenade_base_substate *this)
{
  if ( this->m_playback_type )
    survarium::base_player::unsubscribe_animation_player(
      (survarium::base_player *)this,
      (vostok::animation::reserved_channel_ids_enum)this->m_weapon->m_user,
      (const void *)1,
      (int)this);
}
