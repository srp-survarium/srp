void __thiscall vostok::ai::planning::action_instance::action_instance(
        vostok::ai::planning::action_instance *this,
        const vostok::ai::planning::generalized_action *const prototype)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v3; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &this->m_filters_set.m_size);
  vostok::threading::mutex::mutex(&this->m_filters_set.vostok::threading::mutex);
  this->m_filters_set.m_first = 0;
  this->m_filters_set.m_last = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_filters_set,
    &this->m_initialize_storage.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, &this->m_execute_storage.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &this->m_finalize_storage.vtable);
  this->m_initialize_binder = 0;
  this->m_execute_binder = 0;
  this->m_finalize_binder = 0;
  this->m_prototype = prototype;
}
