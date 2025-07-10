void __thiscall survarium::player_stamina::player_stamina(
        survarium::player_stamina *this,
        const survarium::player_stamina *other)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, this);
  vostok::threading::mutex::mutex(&this->m_subscribers.vostok::threading::mutex);
  this->m_subscribers.m_first = 0;
  this->m_subscribers.m_last = 0;
  survarium::player_stamina::operator=(this, other);
}
