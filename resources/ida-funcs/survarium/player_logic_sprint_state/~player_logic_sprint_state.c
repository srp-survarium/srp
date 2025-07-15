void __thiscall survarium::player_logic_sprint_state::~player_logic_sprint_state(
        survarium::player_logic_sprint_state *this)
{
  survarium::game_camera *v1; // ecx

  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_stamina_subscriber);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_finalize_callback);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&this->m_initialize_callback);
  survarium::weapon_user_dead_state::finalize(v1);
}
