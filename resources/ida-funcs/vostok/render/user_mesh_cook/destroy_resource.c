void __thiscall vostok::render::user_mesh_cook::destroy_resource(
        vostok::render::user_mesh_cook *this,
        vostok::ai::fsm_state *resource)
{
  vostok::resources::resource_link *v2; // ebx
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // edi
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+0h] [ebp-Ch]
  const char *v8; // [esp+4h] [ebp-8h]
  const char *v9; // [esp+4h] [ebp-8h]
  unsigned int v10; // [esp+8h] [ebp-4h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  v2 = (vostok::resources::resource_link *)resource;
  resource = (vostok::ai::fsm_state *)resource[25].transitions.m_size;
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
    vostok::render::g_allocator,
    &resource,
    v6,
    v8,
    v10);
  v3 = vostok::render::g_allocator;
  v4 = __RTCastToVoid((void **)&v2->resource);
  ((void (__thiscall *)(vostok::resources::resource_link *, _DWORD))v2->resource->__vftable)(v2, 0);
  vostok::memory::doug_lea_allocator::free_impl(v5, (int)v3, v4, v7, v9, v11);
}
