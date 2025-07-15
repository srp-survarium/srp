void __userpurge vostok::render::render_model_cook::delete_resource(
        vostok::render::material_effects_instance_cook *this@<ecx>,
        const char *a2@<ebx>,
        vostok::resources::resource_base *resource)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // ebx
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v7; // [esp+0h] [ebp-8h]
  unsigned int v8; // [esp+4h] [ebp-4h]

  v3 = vostok::render::g_allocator;
  if ( resource )
  {
    v4 = __RTCastToVoid((void **)&resource->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
      resource,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v5, (int)v3, v4, a2, v7, v8);
  }
}
