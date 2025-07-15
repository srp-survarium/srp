void __thiscall vostok::tasks::task_manager::collector::operator()(
        vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *ecx0,
        vostok::tasks::task_manager::collector *this)
{
  vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *v3; // ecx
  vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *v4; // ecx
  vostok::tasks::task *v5; // esi
  vostok::tasks::task_allocator *m_reference_counter; // ecx

  if ( !vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::empty(ecx0) )
  {
    do
    {
      v5 = vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::front(v3);
      if ( v5->m_state == 1 )
        break;
      vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::pop_front(v4);
      if ( this->m_tasks_freed_count )
      {
        m_reference_counter = (vostok::tasks::task_allocator *)v5->m_reference_counter;
        if ( m_reference_counter == (vostok::tasks::task_allocator *)1 )
          ++*this->m_tasks_freed_count;
      }
      if ( !_InterlockedDecrement(&v5->m_reference_counter) )
        vostok::tasks::task_allocator::deallocate(m_reference_counter, v5);
    }
    while ( !vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex>::empty((vostok::intrusive_queue<vostok::tasks::task,vostok::tasks::task,8,vostok::threading::mutex> *)m_reference_counter) );
  }
}
