void __thiscall vostok::ai::planning::base_filter::base_filter(
        vostok::ai::planning::base_filter *this,
        bool need_to_be_inverted)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->__vftable = (vostok::ai::planning::base_filter_vtbl *)&vostok::ai::planning::base_filter::`vftable';
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_subfilters,
    &this->m_subfilters.m_size);
  survarium::weapon_user_dead_state::finalize(v2);
  this->m_subfilters.m_first = 0;
  this->m_subfilters.m_last = 0;
  this->m_is_inverted = need_to_be_inverted;
}
