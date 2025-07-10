void __thiscall vostok::ai::pre_perceptors_filter::pre_perceptors_filter(vostok::ai::pre_perceptors_filter *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  vostok::fixed_vector<vostok::console_commands::command_token,12>::fixed_vector<vostok::console_commands::command_token,12>((vostok::fixed_vector<stlp_std::pair<char *,unsigned int>,32> *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &this->m_aux_filters.m_size);
  vostok::threading::mutex::mutex(&this->m_aux_filters.vostok::threading::mutex);
  this->m_aux_filters.m_first = 0;
  this->m_aux_filters.m_last = 0;
}
