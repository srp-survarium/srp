void __usercall survarium::booby_trap_set::remove_current_ghost_model(
        survarium::booby_trap_set *this@<ecx>,
        int a2@<esi>)
{
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v2; // ecx
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v3; // eax
  vostok::resources::unmanaged_resource *v4; // eax
  vostok::render::scene_renderer *v5; // [esp-Ch] [ebp-10h]

  v2 = *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)(a2 + 380);
  if ( v2
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v3 = *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(a2 + 384);
    v5 = *(vostok::render::scene_renderer **)(v3[42].m_object->grm_satisfaction_tree_hook.color_ + 16);
    vostok::render::scene_renderer::remove_model(v5, v5, v3 + 1, v2 + 66);
    v4 = *(vostok::resources::unmanaged_resource **)(a2 + 380);
    *(_DWORD *)(a2 + 380) = 0;
    if ( v4 )
    {
      if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
    }
    survarium::scheduler::unregister(
      *(survarium::scheduler **)(*(_DWORD *)(*(_DWORD *)(a2 + 268) + 344) + 4),
      (survarium::scheduler::identifier *)(a2 + 368));
  }
}
