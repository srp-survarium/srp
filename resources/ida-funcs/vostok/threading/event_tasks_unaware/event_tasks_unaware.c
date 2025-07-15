void __usercall vostok::threading::event_tasks_unaware::event_tasks_unaware(
        vostok::threading::event_tasks_unaware *this@<esi>,
        bool initial_state@<al>)
{
  *(_DWORD *)this->m_event = CreateEventA(0, 0, initial_state, 0);
}
