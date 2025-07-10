vostok::memory::base_allocator *__usercall vostok::collision::loose_oct_tree::get_allocator@<eax>(
        vostok::collision::loose_oct_tree *this@<ecx>,
        int a2@<eax>)
{
  return **(vostok::memory::base_allocator ***)(a2 + 16);
}
