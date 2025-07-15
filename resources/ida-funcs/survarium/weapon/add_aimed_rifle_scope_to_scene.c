void __userpurge survarium::weapon::add_aimed_rifle_scope_to_scene(
        survarium::weapon *this@<ecx>,
        int a2@<esi>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *scene)
{
  survarium::player *v3; // ecx
  vostok::render::scene_renderer *v4; // ecx

  vostok::render::scene_renderer::remove_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(*(_DWORD *)(a2 + 1668) + 264) + 264),
    *(vostok::render::scene_renderer **)((char *)&dword_200060
                                       + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 1672) + 160) + 172)),
    scene);
  vostok::render::scene_renderer::add_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(*(_DWORD *)(a2 + 1668) + 268) + 264),
    *(vostok::render::scene_renderer **)((char *)&dword_200060
                                       + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 1672) + 160) + 172)),
    scene,
    (const vostok::math::float4x4 *)(a2 + 1216),
    (const vostok::math::float4x4 *)(a2 + 1216));
  if ( *(_BYTE *)(*(_DWORD *)(a2 + 1668) + 284) && survarium::player::is_current(v3, *(_DWORD *)(a2 + 8)) )
  {
    vostok::render::scene_renderer::remove_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(a2 + 1676) + 264),
      *(vostok::render::scene_renderer **)((char *)&dword_200060
                                         + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 1672) + 160) + 172)),
      scene);
    vostok::render::scene_renderer::set_model_visible(
      v4,
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 1672) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 70048) + 264),
      1u,
      (volatile int *)2);
  }
  *(_BYTE *)(a2 + 1689) = 1;
}
