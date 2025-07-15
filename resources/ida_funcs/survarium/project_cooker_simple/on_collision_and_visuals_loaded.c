void __thiscall survarium::project_cooker_simple::on_collision_and_visuals_loaded(
        survarium::project_cooker_simple *this,
        vostok::resources::queries_result *data,
        survarium::simple_game_project *project)
{
  unsigned int v4; // esi
  vostok::resources::queries_result *v5; // edi
  vostok::resources::query_result *j; // edx
  survarium::static_collision *v7; // eax
  vostok::resources::unmanaged_resource *m_object; // ecx
  vostok::resources::unmanaged_resource *v9; // esi
  vostok::resources::unmanaged_resource *v10; // edi
  vostok::physics::bt_collision_shape *v11; // ecx
  vostok::resources::unmanaged_resource *v12; // edx
  int k; // edx
  survarium::render_visual *v14; // eax
  int v15; // ecx
  vostok::resources::unmanaged_resource *v16; // esi
  vostok::resources::unmanaged_resource *v17; // edi
  vostok::render::static_model_instance *v18; // ecx
  vostok::resources::unmanaged_resource *v19; // edx
  vostok::resources::query_result_for_cook *v20; // ecx
  unsigned int i; // [esp+10h] [ebp-Ch]
  unsigned int request_idx; // [esp+14h] [ebp-8h]
  unsigned int request_idxa; // [esp+14h] [ebp-8h]
  vostok::resources::query_result *v24; // [esp+18h] [ebp-4h]
  int v25; // [esp+18h] [ebp-4h]
  survarium::simple_game_project *projecta; // [esp+24h] [ebp+8h]
  survarium::simple_game_project *projectb; // [esp+24h] [ebp+8h]

  v4 = 0;
  v5 = data;
  i = 0;
  if ( project->m_static_collision_objects_count )
  {
    projecta = 0;
    for ( j = data->m_queries; ; j = v24 )
    {
      v7 = (survarium::static_collision *)((char *)projecta + (unsigned int)project->m_static_collision_objects);
      m_object = j->m_unmanaged_resource.m_object;
      request_idx = v4 + 1;
      v9 = 0;
      v24 = j + 1;
      if ( m_object )
      {
        v9 = j->m_unmanaged_resource.m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      v10 = 0;
      if ( v9 )
      {
        v10 = v9;
        _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
      }
      v11 = 0;
      if ( v10 )
      {
        v11 = (vostok::physics::bt_collision_shape *)v10;
        _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
      }
      v12 = v7->shape_.m_object;
      v7->shape_.m_object = v11;
      if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
      if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
      if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
      projecta = (survarium::simple_game_project *)((char *)projecta + 76);
      v4 = request_idx;
      if ( ++i >= project->m_static_collision_objects_count )
        break;
    }
    v5 = data;
  }
  request_idxa = 0;
  if ( project->m_render_visuals_count )
  {
    projectb = 0;
    for ( k = (int)&v5->m_queries[v4]; ; k = v25 )
    {
      v14 = (survarium::render_visual *)((char *)projectb + (unsigned int)project->m_render_visuals);
      v15 = *(_DWORD *)(k + 220);
      v16 = 0;
      v25 = k + 720;
      if ( v15 )
      {
        v16 = *(vostok::resources::unmanaged_resource **)(k + 220);
        _InterlockedExchangeAdd((volatile signed __int32 *)(v15 + 208), 1u);
      }
      v17 = 0;
      if ( v16 )
      {
        v17 = v16;
        _InterlockedExchangeAdd(&v16->m_reference_count, 1u);
      }
      v18 = 0;
      if ( v17 )
      {
        v18 = (vostok::render::static_model_instance *)v17;
        _InterlockedExchangeAdd(&v17->m_reference_count, 1u);
      }
      v19 = v14->model.m_object;
      v14->model.m_object = v18;
      if ( v19 && !_InterlockedExchangeAdd(&v19->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v19->vostok::resources::unmanaged_intrusive_base, v19);
      if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v17->vostok::resources::unmanaged_intrusive_base, v17);
      if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
      projectb = (survarium::simple_game_project *)((char *)projectb + 68);
      if ( ++request_idxa >= project->m_render_visuals_count )
        break;
    }
    v5 = data;
  }
  project->m_loaded.collision_loaded = 1;
  project->m_loaded.visuals_loaded = 1;
  if ( project->m_loaded.loaded_count == project->m_objects._M_impl._M_finish - project->m_objects._M_impl._M_start
    && project->m_loaded.all_queried )
  {
    project->resolve_links(&project->survarium::base_project);
    _InterlockedExchangeAdd(&project->m_reference_count, 1u);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v5->m_parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)project,
      &vostok::resources::nocache_memory,
      0x1C0u);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v20,
      result_success,
      assert_on_fail_true,
      error_type_unset);
  }
}
