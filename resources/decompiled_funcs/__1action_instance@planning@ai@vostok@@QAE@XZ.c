void __thiscall vostok::ai::planning::action_instance::~action_instance(vostok::ai::planning::action_instance *this)
{
  vostok::threading::mutex *v1; // ecx
  vostok::ai::planning::action_parameter **i; // [esp+4h] [ebp-4h]

  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_finalize_storage);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_execute_storage);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_initialize_storage);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_filters_set.vostok::threading::mutex);
  for ( i = this->m_parameters.m_begin; i != this->m_parameters.m_end; ++i )
    ;
  this->m_parameters.m_end = this->m_parameters.m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
