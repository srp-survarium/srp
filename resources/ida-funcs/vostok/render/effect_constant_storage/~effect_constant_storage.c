void __thiscall vostok::render::effect_constant_storage::~effect_constant_storage(
        vostok::render::effect_constant_storage *this,
        _DWORD *a2)
{
  char *v2; // edi
  char *v3; // eax
  const char *v4; // [esp+0h] [ebp-10h]
  const char *v5; // [esp+4h] [ebp-Ch]
  unsigned int v6; // [esp+8h] [ebp-8h]

  v2 = (char *)a2[4099];
  while ( v2 )
  {
    v3 = v2;
    v2 = *(char **)v2;
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      v3,
      v4,
      v5,
      v6);
  }
  a2[4099] = 0;
  vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.x = 0.0;
  a2[1] = *a2;
}
