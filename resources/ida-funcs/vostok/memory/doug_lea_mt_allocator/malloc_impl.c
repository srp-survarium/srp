char *__userpurge vostok::memory::doug_lea_mt_allocator::malloc_impl@<eax>(
        vostok::memory::doug_lea_mt_allocator *this@<ecx>,
        const vostok::memory::doug_lea_mt_allocator *a2@<eax>,
        unsigned int size,
        char *description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // esi
  mutex_mt_raii *v10; // ecx
  const char *v12; // [esp+0h] [ebp-10h]
  const char *v13; // [esp+4h] [ebp-Ch]
  mutex_mt_raii v14; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii(&v14, a2, (vostok::threading::mutex *)this);
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(
         v8,
         (int)a2,
         size,
         description,
         v12,
         v13,
         (const unsigned int)v14.m_instance);
  mutex_mt_raii::~mutex_mt_raii(v10, (int *)&v14);
  return v9;
}
