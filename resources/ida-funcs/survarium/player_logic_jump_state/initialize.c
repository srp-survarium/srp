void __thiscall survarium::player_logic_jump_state::initialize(survarium::player_logic_jump_state *this)
{
  int v2; // ecx

  this->m_is_sprinting = 0;
  survarium::jump_logic::initialize((survarium::jump_logic *)this, &this->m_logic);
  if ( this->m_is_sprinting )
  {
    v2 = -(this->m_sprint_initialize_callback.vtable != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v2) != 0 )
      boost::function0<void>::operator()((boost::function0<bool> *)v2, &this->m_sprint_initialize_callback.vtable);
  }
}
