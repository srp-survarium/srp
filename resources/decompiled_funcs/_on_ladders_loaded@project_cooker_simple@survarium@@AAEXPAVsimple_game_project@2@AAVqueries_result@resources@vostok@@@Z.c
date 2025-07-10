void __thiscall survarium::project_cooker_simple::on_ladders_loaded(
        survarium::project_cooker_simple *this,
        survarium::simple_game_project *project,
        vostok::resources::queries_result *data)
{
  vostok::resources::queries_result *v3; // ebx
  unsigned int m_size; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // esi
  vostok::resources::unmanaged_intrusive_base *m_object; // ecx
  survarium::ladder *v7; // eax
  vostok::resources::unmanaged_resource *v8; // ebx
  vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *M_finish; // eax
  vostok::variant<32> *v10; // esi
  survarium::link_resolver *p_type; // eax
  survarium::base_game_object *v12; // esi
  bool v13; // zf
  vostok::resources::query_result_for_cook *v14; // ecx
  const stlp_std::__false_type *v15; // [esp+0h] [ebp-30h]
  unsigned int v16; // [esp+4h] [ebp-2Ch]
  bool v17; // [esp+8h] [ebp-28h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *j; // [esp+Ch] [ebp-24h]
  vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base> new_ladder; // [esp+10h] [ebp-20h] BYREF
  unsigned int i; // [esp+14h] [ebp-1Ch]
  vostok::configs::binary_config_value cfg; // [esp+18h] [ebp-18h] BYREF

  v3 = data;
  m_size = data->m_size;
  i = 0;
  if ( m_size )
  {
    p_m_unmanaged_resource = &data->m_queries[0].m_unmanaged_resource;
    for ( j = &data->m_queries[0].m_unmanaged_resource; ; p_m_unmanaged_resource = j )
    {
      m_object = (vostok::resources::unmanaged_intrusive_base *)p_m_unmanaged_resource->m_object;
      v7 = 0;
      if ( p_m_unmanaged_resource->m_object )
      {
        v7 = (survarium::ladder *)p_m_unmanaged_resource->m_object;
        m_object += 26;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      v8 = 0;
      new_ladder.m_object = 0;
      if ( v7 )
      {
        v8 = v7;
        m_object = &v7->vostok::resources::unmanaged_intrusive_base;
        new_ladder.m_object = v7;
        _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
        if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(m_object, v7);
      }
      M_finish = (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)project->m_ladders._M_impl._M_finish;
      if ( M_finish == (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)project->m_ladders._M_impl._M_end_of_storage._M_data )
      {
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
          (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)m_object,
          (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *> *)&project->m_ladders,
          M_finish,
          (const vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)&new_ladder,
          v15,
          v16,
          v17);
      }
      else
      {
        if ( M_finish )
        {
          M_finish->m_object = 0;
          if ( v8 )
          {
            M_finish->m_object = (survarium::damage_zone *)v8;
            _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
          }
        }
        ++project->m_ladders._M_impl._M_finish;
      }
      v10 = (vostok::variant<32> *)p_m_unmanaged_resource[28].m_object;
      cfg.data.max_storage = 0;
      vostok::platform_pointer_selector<char const,1>::helper::helper(&cfg.id, 0);
      cfg.id_crc = 0;
      cfg.type = 0;
      cfg.count = 0;
      vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v10, &cfg, 0);
      if ( v8 )
        p_type = (survarium::link_resolver *)&v8[1].type;
      else
        p_type = 0;
      survarium::base_project::register_object_to_resolve(&project->survarium::base_project, p_type, cfg);
      if ( v8 )
        v12 = (survarium::base_game_object *)&v8[1].type;
      else
        v12 = 0;
      new_ladder.m_object = (survarium::ladder *)vostok::configs::binary_config_value::operator[](&cfg, "full_name")->data.pointer;
      *stlp_std::map<vostok::fixed_string<260>,survarium::base_game_object *,stlp_std::less<vostok::fixed_string<260>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::operator[]<char const *>(
         (const char *const *)&new_ladder,
         &project->m_objects_registry) = v12;
      if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
      j += 180;
      if ( ++i >= data->m_size )
        break;
    }
    v3 = data;
  }
  v13 = !project->m_loaded.visuals_loaded;
  project->m_loaded.all_queried = 1;
  if ( !v13
    && project->m_loaded.collision_loaded
    && project->m_loaded.loaded_count == project->m_objects._M_impl._M_finish - project->m_objects._M_impl._M_start )
  {
    project->resolve_links(&project->survarium::base_project);
    _InterlockedExchangeAdd(&project->m_reference_count, 1u);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v3->m_parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)project,
      &vostok::resources::nocache_memory,
      0x1C0u);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v14,
      result_success,
      assert_on_fail_true,
      error_type_unset);
  }
}
