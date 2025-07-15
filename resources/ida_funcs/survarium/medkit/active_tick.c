void __thiscall survarium::medkit::active_tick(survarium::medkit *this, unsigned int frame_time_ms)
{
  survarium::inventory *v2; // ecx
  int v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // eax
  survarium::inventory_holder *v6; // [esp+4h] [ebp-40h]
  int v7; // [esp+10h] [ebp-34h]
  survarium::inventory_holder *v8; // [esp+14h] [ebp-30h]
  float health_amount; // [esp+28h] [ebp-1Ch]
  survarium::medkit::item_influence *infl; // [esp+2Ch] [ebp-18h]
  unsigned int i; // [esp+30h] [ebp-14h]
  survarium::player_stamina *stamina; // [esp+34h] [ebp-10h]
  unsigned int delay_time; // [esp+38h] [ebp-Ch]
  unsigned int medkit_time; // [esp+3Ch] [ebp-8h]
  unsigned int time_left_ms; // [esp+40h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  time_left_ms = frame_time_ms;
  if ( !this->m_delay_ms
    || (delay_time = vostok::math::min(this->m_delay_ms, frame_time_ms), (this->m_delay_ms -= delay_time) == 0)
    && (time_left_ms = frame_time_ms - delay_time, frame_time_ms != delay_time) )
  {
    if ( this->m_activity_time_ms == this->m_config_activity_time_ms )
    {
      survarium::medkit::remove_affects(this);
      v8 = survarium::inventory::holder(v2, (int)this->m_inventory);
      v7 = (int)v8->cast_to_base_player(v8);
      stamina = (survarium::player_stamina *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 52))(v7);
      survarium::player_stamina::set_regeneration_speed(
        stamina,
        stamina->m_regeneration_speed + this->m_add_stamina_regen);
    }
    medkit_time = vostok::math::min(this->m_activity_time_ms, time_left_ms);
    this->m_activity_time_ms -= medkit_time;
    for ( i = 0; i < this->m_influences_count; ++i )
    {
      infl = &this->m_influences[i];
      health_amount = (double)medkit_time / 1000.0 * infl->health_amount;
      v6 = survarium::inventory::holder((survarium::inventory *)infl, (int)this->m_inventory);
      v3 = (int)v6->damage_model(v6);
      v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, v3);
      survarium::damage_model::apply_med_kit((survarium::damage_model *)v5, infl->body_part_name, health_amount);
    }
    if ( !this->m_activity_time_ms )
      survarium::medkit::set_active(this, 0);
  }
}
