vostok::memory::managed_allocator *__thiscall vostok::memory::managed_allocator::`vector deleting destructor'(
        vostok::memory::managed_allocator *this,
        char a2)
{
  this->__vftable = (vostok::memory::managed_allocator_vtbl *)&vostok::memory::managed_allocator::`vftable';
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_defragmentation_mutex);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_unmovables_mutex);
  this->m_unmovables.m_end = this->m_unmovables.m_begin;
  this->__vftable = (vostok::memory::managed_allocator_vtbl *)&vostok::memory::base_allocator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
