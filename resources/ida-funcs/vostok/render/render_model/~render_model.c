void __thiscall vostok::render::render_model::~render_model(
        vostok::render::render_model *this,
        vostok::resources::unmanaged_resource *a2)
{
  bool v3; // zf
  char **p_m_reconstruction_size; // edi
  vostok::render::render_model *v5; // [esp-4h] [ebp-18h]
  const char *v6; // [esp+0h] [ebp-14h]
  const char *v7; // [esp+4h] [ebp-10h]
  unsigned int v8; // [esp+8h] [ebp-Ch]
  vostok::ai::fsm_state *pointer; // [esp+10h] [ebp-4h] BYREF
  unsigned __int8 v10; // [esp+1Fh] [ebp+Bh]

  v3 = LOBYTE(a2[1].m_children_resources.m_lock) == 0;
  a2->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::render::render_model::`vftable';
  v10 = 0;
  if ( !v3 )
  {
    do
    {
      pointer = *(vostok::ai::fsm_state **)(a2[1].m_children_resources.m_size + 4 * v10);
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
        vostok::render::g_allocator,
        &pointer,
        v6,
        v7,
        v8);
      ++v10;
      this = v5;
    }
    while ( v10 < LOBYTE(a2[1].m_children_resources.m_lock) );
  }
  p_m_reconstruction_size = (char **)&a2[1].m_reconstruction_size;
  if ( a2[1].m_reconstruction_size )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      *p_m_reconstruction_size,
      v6,
      v7,
      v8);
    *p_m_reconstruction_size = 0;
  }
  if ( a2[1].m_uid )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      (char *)a2[1].m_uid,
      v6,
      v7,
      v8);
    a2[1].m_uid = 0;
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(a2);
}
