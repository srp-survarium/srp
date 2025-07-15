void __userpurge vostok::memory::base_allocator::do_register(
        vostok::memory::base_allocator *this@<ecx>,
        int a2@<eax>,
        unsigned __int64 arena_size,
        const char *description)
{
  int v4; // [esp+0h] [ebp-1Ch] BYREF
  unsigned __int64 v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+10h] [ebp-Ch]
  const char *v7; // [esp+14h] [ebp-8h]

  v6 = 0;
  v4 = a2;
  v5 = arena_size;
  v7 = description;
  vostok::buffer_vector<allocator_data>::push_back(
    (vostok::buffer_vector<allocator_data> *)this,
    (const allocator_data *)s_allocators.m_variable,
    &v4);
}
