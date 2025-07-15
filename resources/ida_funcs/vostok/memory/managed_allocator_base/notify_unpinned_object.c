void __usercall vostok::memory::managed_allocator_base::notify_unpinned_object(
        vostok::memory::managed_allocator_base *this@<ecx>,
        int a2@<eax>)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 40), 1u);
}
