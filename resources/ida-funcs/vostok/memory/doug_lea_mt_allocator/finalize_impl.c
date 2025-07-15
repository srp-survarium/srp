void __thiscall vostok::memory::doug_lea_mt_allocator::finalize_impl(vostok::memory::doug_lea_mt_allocator *this)
{
  mutex_mt_raii *v2; // ecx
  mutex_mt_raii v3; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii(&v3, this, (vostok::threading::mutex *)this);
  vostok::memory::doug_lea_allocator::finalize_impl(this);
  mutex_mt_raii::~mutex_mt_raii(v2, (int *)&v3);
}
