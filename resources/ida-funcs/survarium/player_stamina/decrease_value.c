void __thiscall survarium::player_stamina::decrease_value(survarium::player_stamina *this, float amount)
{
  __int128 m_value_low; // xmm1
  survarium::stamina_depletion_predicate pred; // [esp+12Bh] [ebp-1h] BYREF

  m_value_low = LODWORD(this->m_value);
  *(float *)&m_value_low = *(float *)&m_value_low - amount;
  LODWORD(this->m_value) = vostok::math::clamp_r<float>(
                             (__m128)*(unsigned int *)&FLOAT_0_0,
                             m_value_low,
                             this->m_max_value * this->m_max_value_factor).m128_u32[0];
  if ( this->m_regeneration_threshold >= this->m_value )
  {
    this->m_lower_threshold_was_reached = 1;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
    vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<survarium::stamina_depletion_predicate>(
      &this->m_subscribers,
      &pred);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  }
}
