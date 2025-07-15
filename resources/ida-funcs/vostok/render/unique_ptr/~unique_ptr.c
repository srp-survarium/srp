void __thiscall vostok::render::unique_ptr<vostok::render::lights_db>::~unique_ptr<vostok::render::lights_db>(
        vostok::render::unique_ptr<vostok::render::lights_db> *this,
        vostok::render::lights_db **a2)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  vostok::render::lights_db *v3; // edi
  vostok::memory::doug_lea_allocator *v4; // ecx
  vostok::memory::detail::call_destructor_predicate *v5; // [esp+0h] [ebp-10h]
  const char *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h]

  v2 = vostok::render::g_allocator;
  v3 = *a2;
  if ( *a2 )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::lights_db>(
      v3,
      (vostok::render::light *)this,
      v5);
    vostok::memory::doug_lea_allocator::free_impl(v4, (int)v2, (char *)v3, v6, v7, v8);
    *a2 = 0;
  }
}
