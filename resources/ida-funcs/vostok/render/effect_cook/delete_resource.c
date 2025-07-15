void __thiscall vostok::render::effect_cook::delete_resource(
        vostok::render::effect_cook *this,
        vostok::render::res_effect *resource_to_destroy)
{
  vostok::render::effect_manager::effect_holder_struct *m_end; // ebx
  vostok::fixed_vector<vostok::render::effect_manager::effect_holder_struct,8192> *p_m_effects; // esi
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // ebx
  vostok::memory::doug_lea_allocator *v6; // ecx
  const char *v7; // [esp+0h] [ebp-10h]
  const char *v8; // [esp+4h] [ebp-Ch]
  unsigned int v9; // [esp+8h] [ebp-8h]
  vostok::render::effect_manager::effect_holder_struct *i; // [esp+Ch] [ebp-4h] BYREF

  m_end = vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_effects.m_end;
  p_m_effects = &vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_effects;
  for ( i = vostok::quasi_singleton<vostok::render::effect_manager>::pinst->m_effects.m_begin; i != m_end; ++i )
  {
    if ( i->effect == resource_to_destroy )
      vostok::buffer_vector<vostok::render::effect_manager::effect_holder_struct>::erase(
        (vostok::buffer_vector<vostok::render::effect_manager::effect_holder_struct> *)this,
        p_m_effects,
        &i);
  }
  v4 = vostok::render::g_allocator;
  if ( resource_to_destroy )
  {
    v5 = __RTCastToVoid((void **)&resource_to_destroy->__vftable);
    ((void (__thiscall *)(vostok::render::res_effect *, _DWORD))resource_to_destroy->~vostok::render::res_effect)(
      resource_to_destroy,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v6, (int)v4, v5, v7, v8, v9);
  }
}
