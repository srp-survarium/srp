void __thiscall survarium::player::remove_models_from_scene(survarium::player *this, int a2)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v2; // [esp+Ch] [ebp-4h] BYREF

  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v2,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(int *)((char *)&dword_11410 + a2) + 4));
  vostok::render::scene_renderer::remove_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + a2 + 2) + 264),
    *(vostok::render::scene_renderer **)((char *)&dword_200060
                                       + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + a2) + 160) + 172)),
    &v2);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v2);
}
