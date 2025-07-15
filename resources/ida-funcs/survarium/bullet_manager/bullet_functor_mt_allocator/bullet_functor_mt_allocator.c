void __userpurge survarium::bullet_manager::bullet_functor_mt_allocator::bullet_functor_mt_allocator(
        survarium::bullet_manager::bullet_functor *buffer@<ecx>,
        const unsigned int buffer_size@<eax>,
        survarium::bullet_manager::bullet_functor_mt_allocator *this)
{
  survarium::bullet_manager::bullet_functor *v3; // ebx
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *v4; // edi

  this->m_bullet_functors.m_top.whole = 0;
  this->m_buffer = buffer;
  v3 = buffer;
  v4 = (vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *)&buffer[buffer_size / 0x60];
  if ( buffer != (survarium::bullet_manager::bullet_functor *)v4 )
  {
    do
      vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76>::push(
        (vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *)buffer,
        (int)this,
        v3++);
    while ( v3 != (survarium::bullet_manager::bullet_functor *)v4 );
  }
}
