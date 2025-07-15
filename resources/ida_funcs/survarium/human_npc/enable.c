void __usercall survarium::human_npc::enable(survarium::human_npc *this@<ecx>, int a2@<esi>)
{
  vostok::sound::world_user *v2; // eax
  int v3; // ecx
  int v4; // edx
  void (__thiscall *v5)(int, int); // eax
  vostok::animation::mixing::n_ary_tree *v6; // ecx
  int v7; // eax
  vostok::memory::doug_lea_allocator *f; // ecx
  survarium::animations_selector *v9; // edi
  int v10; // eax
  vostok::configs::binary_config *v11; // [esp-8h] [ebp-24h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp-4h] [ebp-20h] BYREF
  int v13; // [esp+0h] [ebp-1Ch]
  int v14; // [esp+4h] [ebp-18h]
  __int64 v15; // [esp+14h] [ebp-8h] BYREF
  _UNKNOWN *retaddr; // [esp+1Ch] [ebp+0h]

  v11 = *(vostok::configs::binary_config **)(a2 + 340);
  v12.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v12,
    v11);
  (*(void (__thiscall **)(_DWORD, vostok::configs::binary_config *))(**(_DWORD **)(a2 + 324) + 8))(
    *(_DWORD *)(a2 + 324),
    v12.m_object);
  v2 = (vostok::sound::world_user *)(*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(a2 + 328) + 8))(
                                      *(_DWORD *)(a2 + 328),
                                      a2 + 632,
                                      a2 + 28);
  vostok::sound::world_user::register_receiver(
    v2,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v13,
    (vostok::sound::sound_receiver *)v14);
  retaddr = *(_UNKNOWN **)(a2 + 616);
  v15 = *(_QWORD *)(a2 + 608);
  vostok::sound::sound_receiver::set_position(
    (vostok::sound::sound_receiver *)(a2 + 28),
    (const vostok::math::float3 *)&v15);
  v3 = *(_DWORD *)(a2 + 332);
  v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 348) + 276) + 36);
  v5 = *(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 40);
  v14 = 0xFFFF;
  v13 = 64;
  v5(v3, v4);
  vostok::render::scene_renderer::add_model(
    *(vostok::render::scene_renderer **)(a2 + 344),
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 628),
    (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(*(_DWORD *)(a2 + 348) + 264) + 264),
    (const vostok::math::float4x4 *)(a2 + 560));
  vostok::animation::mixing::n_ary_tree::set_object_transform(v6, 0, (const vostok::math::float4x4 *)(a2 + 560));
  v7 = *(_DWORD *)(a2 + 616);
  f = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  *(_QWORD *)(a2 + 716) = *(_QWORD *)(a2 + 608);
  v12.m_object = (vostok::configs::binary_config *)240;
  *(_DWORD *)(a2 + 724) = v7;
  v9 = (survarium::animations_selector *)vostok::memory::doug_lea_allocator::malloc_impl(f, (unsigned int)v12.m_object);
  if ( v9 )
    survarium::animations_selector::animations_selector(
      v9,
      (survarium::single_position_animation_controller *)(a2 + 712),
      *(const vostok::ai::navigation::world **)(*(_DWORD *)(a2 + 336) + 588),
      *(vostok::animation::animation_player **)(*(_DWORD *)(a2 + 348) + 280),
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 708),
      *(const survarium::game_world **)(a2 + 336),
      (survarium::human_npc *)a2);
  else
    v10 = 0;
  *(_DWORD *)(a2 + 644) = v10;
  v12.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v12,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 340));
  (*(void (__thiscall **)(_DWORD, vostok::configs::binary_config *))(**(_DWORD **)(a2 + 324) + 84))(
    *(_DWORD *)(a2 + 324),
    v12.m_object);
}
