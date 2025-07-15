void __thiscall vostok::tasks::task::on_child_task_ended(vostok::tasks::task *this)
{
  vostok::threading::event *m_event_wait_for_children; // eax

  _InterlockedExchangeAdd(&this->m_child_counter, 0xFFFFFFFF);
  if ( !this->m_child_counter )
  {
    m_event_wait_for_children = this->m_event_wait_for_children;
    if ( m_event_wait_for_children )
      SetEvent(*(HANDLE *)m_event_wait_for_children->m_event.m_event);
  }
}
