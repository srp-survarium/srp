void __thiscall survarium::profile_character::weapon_resources_ready(
        survarium::profile_character *this,
        vostok::resources::queries_result *data)
{
  survarium::profile_character *v2; // edi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // esi
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_addon; // ebx
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *m_object; // eax
  vostok::resources::unmanaged_resource *v6; // eax
  vostok::resources::unmanaged_resource *v7; // eax
  vostok::resources::unmanaged_resource *v8; // edi
  vostok::resources::unmanaged_resource *v9; // esi
  vostok::resources::unmanaged_resource *v10; // eax
  vostok::render::static_model_instance *v11; // ecx
  vostok::resources::unmanaged_resource *v12; // eax
  vostok::resources::managed_resource *v13; // ecx
  vostok::resources::managed_resource *v14; // eax
  vostok::resources::managed_resource *v15; // ecx
  vostok::render::static_model_instance *v16; // eax
  vostok::resources::unmanaged_resource *v17; // eax
  vostok::resources::unmanaged_resource *v18; // edi
  vostok::resources::unmanaged_resource *v19; // esi
  vostok::resources::unmanaged_resource *v20; // eax
  vostok::render::static_model_instance *v21; // ecx
  vostok::resources::unmanaged_resource *v22; // eax
  bool v23; // zf
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *v24; // [esp+Ch] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v25; // [esp+10h] [ebp-18h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v26; // [esp+14h] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v27; // [esp+18h] [ebp-10h] BYREF
  int v28; // [esp+1Ch] [ebp-Ch]
  survarium::profile_character *v29; // [esp+20h] [ebp-8h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v30; // [esp+24h] [ebp-4h] BYREF

  v2 = this;
  p_m_unmanaged_resource = &data->m_queries[0].m_unmanaged_resource;
  p_m_addon = &this->m_preview_weapon[0].m_addon;
  v29 = this;
  v25 = &data->m_queries[0].m_unmanaged_resource;
  v24 = &this->m_preview_weapon[0].m_addon;
  v28 = 2;
  while ( 1 )
  {
    if ( LOBYTE(p_m_addon[27].m_object) )
    {
      m_object = (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)p_m_addon[-1].m_object;
      if ( m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::render::scene_renderer::remove_model(
          (vostok::render::scene_renderer *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
          v2->m_scene_renderer,
          v2->m_scene,
          m_object + 66);
      }
      if ( p_m_addon->m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::render::scene_renderer::remove_model(
          (vostok::render::scene_renderer *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
          v2->m_scene_renderer,
          v2->m_scene,
          &p_m_addon->m_object->m_render_model);
      }
    }
    v6 = p_m_addon[-1].m_object;
    p_m_addon[-1].m_object = 0;
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    v7 = p_m_addon->m_object;
    p_m_addon->m_object = 0;
    if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
    v27.m_object = (vostok::resources::managed_resource *)p_m_addon[1].m_object;
    p_m_addon[1].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v27);
    LOBYTE(p_m_addon[27].m_object) = 0;
    if ( p_m_unmanaged_resource[-22].m_object )
    {
      v8 = 0;
      if ( p_m_unmanaged_resource->m_object )
      {
        v8 = p_m_unmanaged_resource->m_object;
        _InterlockedExchangeAdd(&p_m_unmanaged_resource->m_object->m_reference_count, 1u);
      }
      v9 = 0;
      if ( v8 )
      {
        v9 = v8;
        _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
      }
      v10 = 0;
      if ( v9 )
      {
        v10 = v9;
        _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
      }
      v11 = (vostok::render::static_model_instance *)v10;
      v12 = p_m_addon[-1].m_object;
      p_m_addon[-1].m_object = v11;
      if ( v12 )
      {
        if ( !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
        p_m_addon = v24;
      }
      if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
      if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
      v13 = (vostok::resources::managed_resource *)v25[179].m_object;
      v14 = 0;
      v27.m_object = 0;
      if ( v13 )
      {
        v14 = v13;
        v27.m_object = v13;
        _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
      }
      v15 = 0;
      v26.m_object = 0;
      if ( v14 )
      {
        v15 = v14;
        v26.m_object = v14;
        _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
      }
      v16 = 0;
      if ( v15 )
      {
        v16 = (vostok::render::static_model_instance *)v15;
        _InterlockedExchangeAdd(&v15->m_reference_count, 1u);
      }
      v30.m_object = (vostok::resources::managed_resource *)p_m_addon[1].m_object;
      p_m_addon[1].m_object = v16;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v30);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v26);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v27);
      p_m_unmanaged_resource = v25;
    }
    if ( p_m_unmanaged_resource[338].m_object )
    {
      v17 = p_m_unmanaged_resource[360].m_object;
      v18 = 0;
      if ( v17 )
      {
        v18 = p_m_unmanaged_resource[360].m_object;
        _InterlockedExchangeAdd(&v17->m_reference_count, 1u);
      }
      v19 = 0;
      if ( v18 )
      {
        v19 = v18;
        _InterlockedExchangeAdd(&v18->m_reference_count, 1u);
      }
      v20 = 0;
      if ( v19 )
      {
        v20 = v19;
        _InterlockedExchangeAdd(&v19->m_reference_count, 1u);
      }
      v21 = (vostok::render::static_model_instance *)v20;
      v22 = p_m_addon->m_object;
      p_m_addon->m_object = v21;
      if ( v22 )
      {
        if ( !_InterlockedExchangeAdd(&v22->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v22->vostok::resources::unmanaged_intrusive_base, v22);
        p_m_addon = v24;
      }
      if ( v19 && !_InterlockedExchangeAdd(&v19->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v19->vostok::resources::unmanaged_intrusive_base, v19);
      if ( v18 )
      {
        if ( !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v18->vostok::resources::unmanaged_intrusive_base, v18);
      }
      p_m_addon[-1].m_object->m_render_model.m_object->get_locator(
        p_m_addon[-1].m_object->m_render_model.m_object,
        "scope_point",
        (vostok::render::model_locator_item *)&p_m_addon[2]);
      p_m_unmanaged_resource = v25;
    }
    p_m_addon += 29;
    p_m_unmanaged_resource += 540;
    v23 = v28-- == 1;
    v24 = p_m_addon;
    v25 = p_m_unmanaged_resource;
    if ( v23 )
      break;
    v2 = v29;
  }
}
