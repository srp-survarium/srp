unsigned __int8 *__userpurge vostok::memory::doug_lea_mt_allocator::realloc_impl@<eax>(
        vostok::memory::doug_lea_mt_allocator *this@<ecx>,
        const vostok::memory::doug_lea_mt_allocator *pointer,
        vostok::memory::doug_lea_allocator *new_size,
        const char *const description,
        char *function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::doug_lea_allocator *v7; // ecx
  unsigned __int8 *v8; // esi
  mutex_mt_raii *v9; // ecx
  const char *v11; // [esp+0h] [ebp-10h]
  const char *v12; // [esp+4h] [ebp-Ch]
  mutex_mt_raii v13; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii(&v13, pointer, (vostok::threading::mutex *)this);
  v8 = vostok::memory::doug_lea_allocator::realloc_impl(
         v7,
         (int)pointer,
         new_size,
         (unsigned int)description,
         function,
         v11,
         v12,
         (const unsigned int)v13.m_instance);
  mutex_mt_raii::~mutex_mt_raii(v9, (int *)&v13);
  return v8;
}
