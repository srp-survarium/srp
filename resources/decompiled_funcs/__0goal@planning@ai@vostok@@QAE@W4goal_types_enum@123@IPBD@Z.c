void __thiscall vostok::ai::planning::goal::goal(
        vostok::ai::planning::goal *this,
        vostok::ai::planning::goal_types_enum goal_type,
        unsigned int priority,
        const char *caption)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_next = 0;
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_parameters);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_filters_set,
    &this->m_filters_set.m_size);
  vostok::threading::mutex::mutex(&this->m_filters_set.vostok::threading::mutex);
  this->m_filters_set.m_first = 0;
  this->m_filters_set.m_last = 0;
  this->m_target_state._M_impl._M_start = 0;
  this->m_target_state._M_impl._M_finish = 0;
  this->m_target_state._M_impl._M_end_of_storage._M_data = 0;
  vostok::fixed_string<32>::fixed_string<32>(&this->m_caption, caption);
  this->m_goal_type = goal_type;
  this->m_priority = priority;
  this->m_can_be_executed = 1;
}
