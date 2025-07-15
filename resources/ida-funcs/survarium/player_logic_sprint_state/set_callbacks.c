void __thiscall survarium::player_logic_sprint_state::set_callbacks(
        survarium::player_logic_sprint_state *this,
        const boost::function<void __cdecl(void)> *initialize_callback,
        const boost::function<void __cdecl(void)> *finalize_callback)
{
  boost::function<void __cdecl (void)>::operator=(&this->m_initialize_callback, initialize_callback);
  boost::function<void __cdecl (void)>::operator=(&this->m_finalize_callback, finalize_callback);
}
