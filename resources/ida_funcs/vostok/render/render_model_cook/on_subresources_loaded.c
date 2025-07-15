void __thiscall vostok::render::render_model_cook::on_subresources_loaded(
        vostok::render::render_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::cook_intermediate_data *cook_data)
{
  volatile int m_result; // edx
  vostok::render::cook_intermediate_data *v4; // ebx
  vostok::resources::managed_resource *m_num_render_models; // edi
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config_value *m_root; // esi
  unsigned __int16 pointer; // ax
  vostok::render::render_model *render_model; // eax
  vostok::render::render_model_vtbl *v10; // edx
  int v11; // ecx
  char *p_m_managed_resource; // esi
  vostok::resources::managed_resource *v13; // eax
  vostok::resources::managed_resource *v14; // ecx
  vostok::resources::managed_resource **p_m_object; // eax
  vostok::resources::managed_resource *v16; // edx
  vostok::resources::managed_resource *v17; // ecx
  vostok::resources::managed_resource *v18; // edx
  vostok::resources::unmanaged_resource *v19; // eax
  vostok::resources::unmanaged_resource *v20; // esi
  vostok::resources::unmanaged_resource *v21; // edi
  vostok::resources::unmanaged_resource **v22; // ecx
  vostok::resources::unmanaged_resource *v23; // eax
  vostok::resources::unmanaged_resource *v24; // edx
  vostok::resources::unmanaged_resource *v25; // eax
  vostok::render::cook_intermediate_data *v26; // esi
  vostok::resources::managed_resource *v27; // ecx
  vostok::resources::managed_resource *v28; // eax
  bool v29; // zf
  vostok::resources::query_result_for_cook *parent_query; // eax
  void (__cdecl *v31)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v32; // eax
  vostok::resources::unmanaged_intrusive_base *v33; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v34; // [esp-4h] [ebp-19Ch]
  const char *m_begin; // [esp-4h] [ebp-19Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v36; // [esp+Ch] [ebp-18Ch] BYREF
  unsigned int request_index; // [esp+10h] [ebp-188h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // [esp+14h] [ebp-184h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v39; // [esp+18h] [ebp-180h] BYREF
  vostok::render::render_model *model; // [esp+1Ch] [ebp-17Ch] BYREF
  unsigned int v41; // [esp+20h] [ebp-178h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+24h] [ebp-174h] BYREF
  vostok::render::cook_intermediate_data *v43; // [esp+28h] [ebp-170h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v44; // [esp+2Ch] [ebp-16Ch] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> bind_pose_ptr; // [esp+30h] [ebp-168h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v46[3]; // [esp+3Ch] [ebp-15Ch] BYREF
  vostok::render::cook_intermediate_data *v47; // [esp+48h] [ebp-150h]
  vostok::resources::request requests; // [esp+4Ch] [ebp-14Ch] BYREF
  vostok::memory::reader bones_reader; // [esp+54h] [ebp-144h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+60h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string material_settings_path; // [esp+80h] [ebp-118h] BYREF

  m_result = data->m_result;
  v43 = (vostok::render::cook_intermediate_data *)this;
  if ( m_result == 1 )
  {
    v4 = cook_data;
    m_num_render_models = (vostok::resources::managed_resource *)cook_data->m_num_render_models;
    v36.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v36,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    config_ptr.m_object = 0;
    m_object = v36.m_object;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &config_ptr,
      v36.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    m_root = config_ptr.m_object->m_root;
    request_index = 1;
    pointer = (unsigned __int16)vostok::configs::binary_config_value::operator[](m_root, "type")->data.pointer;
    if ( v43->root_model_path.m_string.m_max_end == (char *)29 )
      pointer = 200;
    render_model = vostok::render::model_factory::create_render_model(pointer);
    v10 = render_model->__vftable;
    model = render_model;
    v10->load_properties(render_model, m_root);
    vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *)model,
      &cook_data->result_model.m_object);
    if ( m_num_render_models )
    {
      v41 = 0;
      p_m_unmanaged_resource = &data->m_queries[1].m_unmanaged_resource;
      p_m_managed_resource = (char *)&data->m_queries[1].m_managed_resource;
      v39.m_object = m_num_render_models;
      while ( 1 )
      {
        v13 = *(vostok::resources::managed_resource **)p_m_managed_resource;
        v14 = 0;
        v44.m_object = 0;
        if ( v13 )
        {
          v14 = v13;
          v44.m_object = v13;
          _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
        }
        p_m_object = &v4->assets[v41 / 0x120].converted_model_buffer.m_object;
        v16 = 0;
        if ( v14 )
        {
          v16 = v14;
          _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
        }
        v17 = v16;
        v18 = *p_m_object;
        *p_m_object = v17;
        v46[0].m_object = v18;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v46);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v44);
        p_m_unmanaged_resource += 180;
        v19 = p_m_unmanaged_resource->m_object;
        ++request_index;
        v36.m_object = (vostok::configs::binary_config *)(p_m_managed_resource + 720);
        v20 = 0;
        if ( v19 )
        {
          v20 = v19;
          _InterlockedExchangeAdd(&v19->m_reference_count, 1u);
        }
        v21 = 0;
        if ( v20 )
        {
          v21 = v20;
          _InterlockedExchangeAdd(&v20->m_reference_count, 1u);
        }
        v22 = &v4->assets[v41 / 0x120].export_properties_config.m_object;
        v23 = 0;
        if ( v21 )
        {
          v23 = v21;
          _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
          v4 = cook_data;
        }
        v24 = v23;
        v25 = *v22;
        *v22 = v24;
        if ( v25 )
        {
          if ( !_InterlockedExchangeAdd(&v25->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(&v25->vostok::resources::unmanaged_intrusive_base, v25);
          v4 = cook_data;
        }
        if ( v21 && !_InterlockedExchangeAdd(&v21->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v21->vostok::resources::unmanaged_intrusive_base, v21);
        if ( v20 && !_InterlockedExchangeAdd(&v20->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v20->vostok::resources::unmanaged_intrusive_base, v20);
        v41 += 288;
        v11 = 1;
        ++request_index;
        v36.m_object = (vostok::configs::binary_config *)((char *)v36.m_object + 720);
        p_m_unmanaged_resource += 180;
        if ( !--v39.m_object )
          break;
        p_m_managed_resource = (char *)v36.m_object;
      }
    }
    v26 = v43;
    if ( v43->root_model_path.m_string.m_max_end == (char *)23 )
    {
      v27 = data->m_queries[request_index].m_managed_resource.m_object;
      v28 = 0;
      v39.m_object = 0;
      if ( v27 )
      {
        v28 = v27;
        v39.m_object = v27;
        _InterlockedExchangeAdd(&v27->m_reference_count, 1u);
      }
      v34.m_object = 0;
      if ( v28 )
      {
        v34.m_object = v28;
        _InterlockedExchangeAdd(&v28->m_reference_count, 1u);
      }
      vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(&bind_pose_ptr, v34);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v39);
      bones_reader.m_data = bind_pose_ptr.m_data;
      bones_reader.m_pointer = bind_pose_ptr.m_data;
      bones_reader.m_size = bind_pose_ptr.m_size;
      vostok::render::skeleton_render_model::load_bones((vostok::render::skeleton_render_model *)model, &bones_reader);
      vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&bind_pose_ptr);
    }
    v29 = !v4->material_data_ready;
    v4->render_model_data_ready = 1;
    if ( !v29 )
      vostok::render::render_model_cook::query_materail_effects((vostok::render::render_model_cook *)v11, v26, v4);
    material_settings_path.m_string.m_begin = material_settings_path.m_string.m_buffer;
    m_begin = v4->root_model_path.m_string.m_begin;
    material_settings_path.m_string.m_end = material_settings_path.m_string.m_buffer;
    material_settings_path.m_string.m_max_end = &material_settings_path.m_separator;
    material_settings_path.m_string.m_buffer[0] = 0;
    material_settings_path.m_separator = 47;
    vostok::fs_new::path_string_impl::assignf(&material_settings_path, "resources/models/%s/settings", m_begin);
    bind_pose_ptr.m_resource.m_object = (vostok::resources::managed_resource *)vostok::render::render_model_cook::on_model_settings_loaded;
    bind_pose_ptr.m_data = (const unsigned __int8 *)v26;
    *(_QWORD *)&v46[1].m_object = *(_QWORD *)&bind_pose_ptr.m_resource.m_object;
    v47 = v4;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      callback.vtable = 0;
    }
    else
    {
      *(_QWORD *)&callback.functor.obj_ptr = *(_QWORD *)&v46[1].m_object;
      callback.functor.vostok_pointer_size_alignment[2] = v47;
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    parent_query = v4->parent_query;
    requests.path = material_settings_path.m_string.m_begin;
    requests.id = binary_config_class_impl;
    model = 0;
    vostok::resources::query_resources(
      &requests,
      1u,
      &callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)&model,
      parent_query,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v31 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v31 )
          v31(&callback.functor, &callback.functor, 2);
      }
    }
    v32 = config_ptr.m_object;
    v33 = &config_ptr.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&config_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v33, v32);
  }
  else
  {
    cook_data->status_failed = 1;
    vostok::render::render_model_cook::query_materail_effects(
      this,
      (vostok::render::cook_intermediate_data *)this,
      cook_data);
  }
}
