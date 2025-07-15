void __usercall vostok::render::world::enable_logic_thread_safety(vostok::render::world *this@<ecx>, bool value@<al>)
{
  _InterlockedExchange(&this->m_is_logic_enabled, value);
  if ( !value )
    _InterlockedExchange(&this->m_is_logic_frame_ended, 1);
}
