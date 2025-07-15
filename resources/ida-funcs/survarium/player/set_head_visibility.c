void __userpurge survarium::player::set_head_visibility(survarium::player *this@<ecx>, int a2@<esi>, bool is_visible)
{
  unsigned int v3; // ebx
  vostok::render::scene_renderer *v4; // ecx
  vostok::render::scene_renderer *v5; // ecx
  vostok::render::scene_renderer *v6; // ecx
  vostok::render::scene_renderer *v7; // ecx
  vostok::render::scene_renderer *v8; // ecx
  int v9; // eax
  survarium::weapon *v10; // ecx

  LOBYTE(this) = is_visible;
  if ( *((_BYTE *)&loc_11439 + a2) != is_visible )
  {
    *((_BYTE *)&loc_11439 + a2) = is_visible;
    v3 = 2;
    if ( is_visible )
      v3 = 3;
    vostok::render::scene_renderer::set_model_visible(
      (vostok::render::scene_renderer *)this,
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + a2) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + a2 + 2) + 264),
      0,
      (volatile int *)v3);
    vostok::render::scene_renderer::set_model_visible(
      v4,
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + a2) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + a2 + 2) + 264),
      6u,
      (volatile int *)v3);
    vostok::render::scene_renderer::set_model_visible(
      v5,
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + a2) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + a2 + 2) + 264),
      7u,
      (volatile int *)v3);
    vostok::render::scene_renderer::set_model_visible(
      v6,
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + a2) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + a2 + 2) + 264),
      5u,
      (volatile int *)v3);
    LOBYTE(v3) = !is_visible;
    vostok::render::scene_renderer::set_model_foreground(
      v7,
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + a2) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + a2 + 2) + 264),
      1u,
      v3);
    vostok::render::scene_renderer::set_model_foreground(
      v8,
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + a2) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + a2 + 2) + 264),
      2u,
      v3);
    v9 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 320) + 96))(*(_DWORD *)(a2 + 320));
    v10 = *(survarium::weapon **)(a2 + 320);
    if ( v9 )
    {
      survarium::weapon::set_foreground(v10, v3);
      survarium::weapon::set_movable_static(*(survarium::weapon **)(a2 + 320));
    }
    else if ( v10->cast_carryable_object(v10) )
    {
      *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 320) + 476) + 264) + 276) = v3;
      *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 320) + 476) + 264) + 277) = 1;
    }
  }
}
