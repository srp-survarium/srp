void __userpurge survarium::booby_trap::on_new_state(
        survarium::booby_trap *this@<ecx>,
        int a2@<esi>,
        survarium::booby_trap_state old_state)
{
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **v3; // edi
  int v4; // ecx
  int v5; // ecx
  survarium::booby_trap *v6; // ecx

  v3 = (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)(a2 + 4 * *(_DWORD *)(a2 + 368) + 440);
  if ( *(_DWORD *)(a2 + 4 * old_state + 440)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::render::scene_renderer::remove_model(
      *(vostok::render::scene_renderer **)(*(_DWORD *)(*(_DWORD *)(a2 + 464) + 168) + 148),
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 464) + 168) + 148) + 16),
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 464) + 4));
  }
  if ( *v3
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::render::scene_renderer::add_model(
      (vostok::render::scene_renderer *)(*(_DWORD *)(a2 + 464) + 4),
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 464) + 4),
      *v3 + 66,
      (const vostok::math::float4x4 *)(a2 + 372));
  }
  if ( old_state == booby_trap_state_armed )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 464) + 168) + 952);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4) )
    {
      survarium::usable_object::remove((survarium::usable_object *)(a2 + 328));
      survarium::collision_sensor::remove((survarium::collision_sensor *)(a2 + 292));
      if ( *(_BYTE *)(*(_DWORD *)(a2 + 364) + 320) )
        survarium::hittable_object::remove((survarium::hittable_object *)(a2 + 272));
    }
  }
  v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 464) + 168) + 952);
  if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5) && *(_DWORD *)(a2 + 368) == 2 )
    survarium::booby_trap::play_fired_effects(v6, a2);
}
