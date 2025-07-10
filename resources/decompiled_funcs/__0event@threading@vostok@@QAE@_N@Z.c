void __usercall vostok::threading::event::event(vostok::threading::event *this@<esi>, bool initial_state@<al>)
{
  *(_DWORD *)this->m_event.m_event = CreateEventA(0, 0, initial_state, 0);
}
