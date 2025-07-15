unsigned int __thiscall vostok::memory::doug_lea_mt_allocator::total_size(vostok::memory::doug_lea_mt_allocator *this)
{
  unsigned int v2; // esi
  mutex_mt_raii *v3; // ecx
  mutex_mt_raii v5; // [esp+8h] [ebp-8h] BYREF

  mutex_mt_raii::mutex_mt_raii(&v5, this, (vostok::threading::mutex *)this);
  v2 = vostok::memory::doug_lea_allocator::total_size(this);
  mutex_mt_raii::~mutex_mt_raii(v3, (int *)&v5);
  return v2;
}
