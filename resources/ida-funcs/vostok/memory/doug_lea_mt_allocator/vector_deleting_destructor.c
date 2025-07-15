vostok::memory::doug_lea_mt_allocator *__thiscall vostok::memory::doug_lea_mt_allocator::`vector deleting destructor'(
        vostok::memory::doug_lea_mt_allocator *this,
        char a2)
{
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_mutex_tasks_unaware);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_mutex);
  this->__vftable = (vostok::memory::doug_lea_mt_allocator_vtbl *)&vostok::memory::base_allocator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
