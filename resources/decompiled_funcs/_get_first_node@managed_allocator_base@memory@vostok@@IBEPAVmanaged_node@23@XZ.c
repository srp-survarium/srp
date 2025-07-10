vostok::memory::managed_node *__usercall vostok::memory::managed_allocator_base::get_first_node@<eax>(
        vostok::memory::managed_allocator_base *this@<ecx>,
        int a2@<eax>)
{
  return *(vostok::memory::managed_node **)(a2 + 24);
}
