void __thiscall survarium::game_material_manager_cook::delete_resource(
        survarium::game_material_manager_cook *this,
        vostok::resources::resource_base *res)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v3; // ebx
  vostok::memory::doug_lea_allocator *v4; // ecx
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+4h] [ebp-8h]
  unsigned int v7; // [esp+8h] [ebp-4h]

  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  v2 = survarium::g_allocator;
  v3 = __RTCastToVoid((void **)&res->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  vostok::memory::doug_lea_allocator::free_impl(v4, (int)v2, v3, v5, v6, v7);
}
