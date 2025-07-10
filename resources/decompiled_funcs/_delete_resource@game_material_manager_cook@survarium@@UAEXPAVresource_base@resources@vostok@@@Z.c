void __thiscall survarium::game_material_manager_cook::delete_resource(
        survarium::game_material_manager_cook *this,
        survarium::game_material_manager *res)
{
  survarium::game_material_manager *mngr; // [esp+14h] [ebp-4h] BYREF

  mngr = res;
  ((void (__thiscall *)(survarium::game_material_manager *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    (vostok::sound::sound_scene **)&mngr);
}
