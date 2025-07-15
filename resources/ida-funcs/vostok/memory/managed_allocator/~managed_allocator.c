void __usercall vostok::memory::managed_allocator::~managed_allocator(
        vostok::memory::managed_allocator *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<esi>)
{
  a2->DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&vostok::memory::managed_allocator::`vftable';
  DeleteCriticalSection(a2 + 349);
  DeleteCriticalSection(a2 + 348);
  a2[2].SpinCount = (unsigned int)a2[2].LockSemaphore;
  a2->DebugInfo = (_RTL_CRITICAL_SECTION_DEBUG *)&vostok::memory::base_allocator::`vftable';
}
