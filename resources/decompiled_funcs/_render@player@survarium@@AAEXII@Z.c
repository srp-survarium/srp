void __userpurge survarium::player::render(
        survarium::player *this@<ecx>,
        int a2@<eax>,
        vostok::render::game::renderer *__formal,
        const unsigned int current_time_in_ms)
{
  vostok::render::base_scene *v5; // eax
  vostok::resources::unmanaged_resource *v6; // ebp
  const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *v7; // eax
  boost::intrusive::rbtree_node<void *>::color color; // edi
  void (*v9)(void); // eax
  float v10; // eax
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v11; // eax
  int v12; // eax
  survarium::player *v13; // ecx
  char v14; // al
  unsigned int v15; // [esp+4h] [ebp-28h]
  unsigned int v16; // [esp+8h] [ebp-24h]
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> scene; // [esp+14h] [ebp-18h] BYREF
  vostok::render::trample_desc trample; // [esp+18h] [ebp-14h] BYREF

  v5 = *(vostok::render::base_scene **)(*(int *)((char *)&dword_10F00 + a2) + 4);
  v6 = 0;
  scene.m_object = 0;
  if ( v5 )
  {
    v6 = v5;
    scene.m_object = v5;
    this = (survarium::player *)_InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  v7 = *(const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_10F00 + a2);
  color = v7[42].m_object->grm_satisfaction_tree_hook.color_;
  if ( BYTE2(survarium::g_allocator.l_.a2_.t_) )
  {
    this = *(survarium::player **)((char *)&dword_10EF8 + a2);
    if ( this->survarium::base_player::survarium::inventory_holder::__vftable )
      survarium::stats_graph::render(
        (survarium::stats_graph *)this,
        (survarium::stats_graph *)this,
        *(vostok::render::ui::renderer **)(color + 12),
        v7 + 2,
        0x1FEu,
        0x100u,
        v15,
        v16);
  }
  if ( byte_10F32[a2] != BYTE1(survarium::g_allocator.l_.a2_.t_) )
  {
    byte_10F32[a2] = BYTE1(survarium::g_allocator.l_.a2_.t_);
    if ( BYTE1(survarium::g_allocator.l_.a2_.t_) )
      vostok::render::scene_renderer::add_model(
        (vostok::render::scene_renderer *)&byte_10D44[a2],
        &scene,
        (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(int *)((char *)&dword_10DC4 + a2) + 264),
        (const vostok::math::float4x4 *)&byte_10D44[a2]);
    else
      vostok::render::scene_renderer::remove_model(
        (vostok::render::scene_renderer *)(*(int *)((char *)&dword_10DC4 + a2) + 264),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(color + 16),
        (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene);
  }
  if ( byte_10F33[a2] != s_show_client_player )
  {
    byte_10F33[a2] = s_show_client_player;
    if ( s_show_client_player )
    {
      vostok::render::scene_renderer::add_model(
        (vostok::render::scene_renderer *)(a2 + 34672),
        &scene,
        (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 34800) + 264),
        (const vostok::math::float4x4 *)(a2 + 34672));
      v9 = *(void (**)(void))(**(_DWORD **)(a2 + 64) + 52);
    }
    else
    {
      vostok::render::scene_renderer::remove_model(
        (vostok::render::scene_renderer *)(*(_DWORD *)(a2 + 34800) + 264),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(color + 16),
        (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene);
      v9 = *(void (**)(void))(**(_DWORD **)(a2 + 64) + 56);
    }
    v9();
  }
  if ( byte_10F34[a2] )
  {
    if ( byte_10F33[a2] )
    {
      vostok::render::scene_renderer::update_model(
        *(vostok::render::scene_renderer **)(color + 16),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(color + 16),
        (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene,
        (const vostok::math::float4x4 *)(*(_DWORD *)(a2 + 34800) + 264));
      if ( !vostok::math::float3_pod::is_similar(
              (vostok::math::float3_pod *)(a2 + 34720),
              (const vostok::math::float3_pod *)(a2 + 34784),
              0.025) )
      {
        v10 = *(float *)(a2 + 34728);
        *(_QWORD *)&trample.position.x = *(_QWORD *)(a2 + 34720);
        trample.position.z = v10;
        v11 = *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(color + 16);
        LODWORD(trample.multiplier) = clear_value;
        trample.radius = FLOAT_0_5;
        vostok::render::scene_renderer::add_vegetation_trample(
          (vostok::render::scene_renderer *)&trample,
          v11,
          (const vostok::render::trample_desc *)&scene);
      }
    }
    if ( byte_10F32[a2] )
      vostok::render::scene_renderer::update_model(
        *(vostok::render::scene_renderer **)(color + 16),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(color + 16),
        (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene,
        (const vostok::math::float4x4 *)(*(int *)((char *)&dword_10DC4 + a2) + 264));
  }
  survarium::player::compute_bones(this, a2, __formal);
  (*(void (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(*(int *)((char *)&dword_10F00 + a2) + 176) + 56))(
    *(_DWORD *)(*(int *)((char *)&dword_10F00 + a2) + 176),
    *(_DWORD *)(*(int *)((char *)&dword_10EF0 + a2) + 36),
    a2 + 34672);
  v12 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F04 + a2) + 952) + 8);
  LOBYTE(v13) = *(_BYTE *)(a2 + 52);
  if ( v12
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && *(_BYTE *)(v12 + 52) == (_BYTE)v13
    && (LOBYTE(survarium::g_allocator.l_.a2_.t_) || !*(_DWORD *)(*(int *)((char *)&dword_10EF4 + a2) + 408)) )
  {
    survarium::player::render_crosshair_info(v13, a2);
    v14 = 0;
  }
  else
  {
    v14 = 1;
  }
  survarium::player::set_head_visibility((survarium::player *)a2, v14);
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  }
}
