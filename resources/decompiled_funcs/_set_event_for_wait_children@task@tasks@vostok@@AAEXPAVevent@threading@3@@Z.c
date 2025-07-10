void __usercall vostok::tasks::task::set_event_for_wait_children(
        vostok::tasks::task *this@<ecx>,
        vostok::threading::event *event@<eax>)
{
  _InterlockedExchange((volatile __int32 *)&this->m_event_wait_for_children, (__int32)event);
}
