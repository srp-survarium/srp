void __usercall vostok::tasks::task::on_child_task_added(vostok::tasks::task *this@<ecx>, int a2@<eax>)
{
  this->m_next_task_in_child_queue = 0;
  ++*(_DWORD *)(a2 + 16);
  if ( *(_DWORD *)(a2 + 24) )
    **(_DWORD **)(a2 + 28) = this;
  else
    *(_DWORD *)(a2 + 24) = this;
  *(_DWORD *)(a2 + 28) = this;
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 32), 1u);
}
