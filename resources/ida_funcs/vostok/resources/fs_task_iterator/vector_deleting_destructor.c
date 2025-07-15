vostok::resources::fs_task_iterator *__thiscall vostok::resources::fs_task_iterator::`vector deleting destructor'(
        vostok::resources::fs_task_iterator *this,
        char a2)
{
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&this->m_iterator);
  vtable = this->m_callback.vtable;
  if ( vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&this->m_callback.functor, &this->m_callback.functor, 2);
    }
    this->m_callback.vtable = 0;
  }
  this->__vftable = (vostok::resources::fs_task_iterator_vtbl *)&vostok::resources::fs_task::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
