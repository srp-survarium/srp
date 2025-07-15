void __userpurge vostok::memory::doug_lea_mt_allocator::free_impl(
        vostok::memory::doug_lea_mt_allocator *this@<ecx>,
        const vostok::memory::doug_lea_mt_allocator *a2@<eax>,
        char *pointer,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::doug_lea_allocator *v7; // ecx
  mutex_mt_raii *v8; // ecx
  const char *v9; // [esp+0h] [ebp-10h]
  const char *v10; // [esp+4h] [ebp-Ch]
  mutex_mt_raii v11; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii(&v11, a2, (vostok::threading::mutex *)this);
  vostok::memory::doug_lea_allocator::free_impl(v7, (int)a2, pointer, v9, v10, (const unsigned int)v11.m_instance);
  mutex_mt_raii::~mutex_mt_raii(v8, (int *)&v11);
}
