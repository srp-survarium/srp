void __usercall survarium::human_npc::render_model(survarium::human_npc *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  vostok::animation::animation_player *v3; // ecx
  vostok::animation::skeleton *v4; // eax
  vostok::animation::skeleton *v5; // edi
  int v6; // ebx
  void *v7; // esp
  const vostok::math::float4x4 *v8; // ebx
  unsigned int v9; // [esp-4h] [ebp-14h]
  vostok::math::float4x4 *v10[2]; // [esp+0h] [ebp-10h] BYREF
  const vostok::math::float4x4 *matrices; // [esp+8h] [ebp-8h]
  vostok::animation::animation_player *animation_player; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 348);
  v3 = *(vostok::animation::animation_player **)(v2 + 280);
  v4 = *(vostok::animation::skeleton **)(*(_DWORD *)(v2 + 268) + 264);
  v5 = 0;
  animation_player = v3;
  if ( v4 )
  {
    v5 = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  v6 = v5->m_bones_count
     - (v5[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
      - (int)&v5[1])
     / 20;
  v7 = alloca(v6 << 6);
  matrices = (const vostok::math::float4x4 *)v10;
  vostok::animation::mixing::n_ary_tree::compute_bones_matrices(
    &animation_player->m_mixing_tree,
    0,
    v5,
    (vostok::math::float4x4 *const)v10,
    v10[0],
    0);
  vostok::render::scene_renderer::update_model(
    (vostok::render::scene_renderer *)(a2 + 628),
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(*(_DWORD *)(a2 + 344) + 16),
    (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(a2 + 628),
    (const vostok::math::float4x4 *)(*(_DWORD *)(*(_DWORD *)(a2 + 348) + 264) + 264));
  v9 = v6;
  v8 = matrices;
  vostok::render::scene_renderer::update_skeleton(
    *(vostok::render::scene_renderer **)(a2 + 348),
    (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(*(_DWORD *)(a2 + 348) + 264) + 264),
    matrices,
    v9);
  vostok::collision::animated_object::update(
    *(vostok::collision::animated_object **)(a2 + 348),
    *(const vostok::math::float4x4 *const *)(*(_DWORD *)(a2 + 348) + 276),
    v8);
  if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
}
