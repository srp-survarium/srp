void __thiscall vostok::render::render_model_cook::finish_model_creation(
        vostok::render::render_model_cook *this,
        vostok::resources::queries_result *data_material_effects,
        vostok::render::cook_intermediate_data *cook_data)
{
  vostok::render::cook_intermediate_data *v3; // ebx
  vostok::resources::query_result_for_cook *v4; // edi
  int v5; // esi
  bool v6; // zf
  vostok::render::cook_intermediate_data *v7; // ecx
  vostok::render::render_surface **v8; // eax
  int v9; // eax
  const void *pointer; // eax
  unsigned __int16 v11; // di
  vostok::resources::managed_resource *v12; // ecx
  vostok::resources::managed_resource *v13; // eax
  vostok::render::render_surface *render_surface; // eax
  vostok::render::cook_intermediate_data *m_end; // ecx
  const char *v16; // esi
  vostok::render::render_surface *v17; // edi
  char *m_begin; // eax
  const char *v19; // eax
  unsigned int material_index; // eax
  vostok::resources::unmanaged_resource *m_object; // ebx
  vostok::resources::unmanaged_resource_vtbl *v22; // esi
  vostok::render::render_surface *v23; // ecx
  vostok::configs::binary_config *v24; // esi
  vostok::resources::unmanaged_resource *v25; // eax
  void (__cdecl *v26)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::resources::query_result_for_cook *v27; // eax
  const char *m_requery_path; // eax
  void (__cdecl *v29)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const unsigned __int8 *m_data; // esi
  const unsigned __int8 *v31; // eax
  vostok::render::render_model *v32; // eax
  vostok::resources::query_result_for_cook *v33; // ecx
  vostok::render::grass_render_model *v34; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v35; // [esp-Ch] [ebp-A4h]
  vostok::configs::binary_config *v36; // [esp-8h] [ebp-A0h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v37; // [esp-4h] [ebp-9Ch]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_material; // [esp-4h] [ebp-9Ch]
  const char *v39; // [esp-4h] [ebp-9Ch]
  bool material_result; // [esp+13h] [ebp-85h]
  int v41; // [esp+14h] [ebp-84h]
  vostok::resources::cook_base::result_enum *p_m_create_resource_result; // [esp+18h] [ebp-80h]
  unsigned int model_index; // [esp+1Ch] [ebp-7Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> prop_config_ptr; // [esp+20h] [ebp-78h]
  int v45; // [esp+24h] [ebp-74h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v46; // [esp+28h] [ebp-70h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v47; // [esp+2Ch] [ebp-6Ch] BYREF
  const char *sg_name[2]; // [esp+30h] [ebp-68h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> m; // [esp+38h] [ebp-60h] BYREF
  vostok::render::render_surface **surfaces; // [esp+3Ch] [ebp-5Ch]
  vostok::render::render_model_cook *v51; // [esp+40h] [ebp-58h]
  const vostok::configs::binary_config_value *properties; // [esp+44h] [ebp-54h]
  vostok::resources::query_result_for_cook *parent_query; // [esp+48h] [ebp-50h]
  vostok::resources::pinned_ptr_const<unsigned char> converted_model_ptr; // [esp+4Ch] [ebp-4Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+58h] [ebp-40h] BYREF
  vostok::memory::chunk_reader model_reader; // [esp+78h] [ebp-20h] BYREF

  v3 = cook_data;
  v4 = cook_data->parent_query;
  v5 = 0;
  v6 = !cook_data->status_failed;
  v51 = this;
  v41 = 0;
  parent_query = v4;
  if ( !v6 )
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
    if ( cook_data->assets )
      vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::model_asset,vostok::memory::detail::call_destructor_predicate>(
        &cook_data->assets,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
    goto LABEL_69;
  }
  v8 = (vostok::render::render_surface **)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            4 * cook_data->m_num_render_models);
  v6 = cook_data->m_num_render_models == 0;
  surfaces = v8;
  model_index = 0;
  if ( v6 )
    goto LABEL_66;
  v45 = 0;
  p_m_create_resource_result = &data_material_effects->m_queries[0].m_create_resource_result;
  while ( 1 )
  {
    v9 = *(int *)((char *)&v3->assets->export_properties_config.m_object + v5);
    prop_config_ptr.m_object = 0;
    if ( v9 )
    {
      prop_config_ptr.m_object = *(vostok::configs::binary_config **)((char *)&v3->assets->export_properties_config.m_object
                                                                    + v5);
      _InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 208), 1u);
    }
    properties = prop_config_ptr.m_object->m_root;
    pointer = vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)properties,
                "type")->data.pointer;
    sg_name[1] = 0;
    v11 = (unsigned __int16)pointer;
    if ( v51->m_class_id == grass_render_model_class )
      v11 = 200;
    v12 = *(vostok::resources::managed_resource **)((char *)&v3->assets->converted_model_buffer.m_object + v5);
    v13 = 0;
    v47.m_object = 0;
    if ( v12 )
    {
      v13 = v12;
      v47.m_object = v12;
      _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
    }
    v37.m_object = 0;
    if ( v13 )
    {
      v37.m_object = v13;
      _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
    }
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &converted_model_ptr,
      v37);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v47);
    render_surface = vostok::render::model_factory::create_render_surface(v11);
    v16 = *(char **)((char *)&v3->assets->m_surface_name.m_string.m_begin + v5);
    v17 = render_surface;
    m_begin = render_surface->m_render_geometry.shading_group_name.m_begin;
    sg_name[0] = v16;
    if ( m_begin != v16 )
    {
      v17->m_render_geometry.shading_group_name.m_end = m_begin;
      *m_begin = 0;
      v19 = v16;
      if ( v16 )
      {
        if ( *v16 )
        {
          do
          {
            m_end = (vostok::render::cook_intermediate_data *)v17->m_render_geometry.shading_group_name.m_end;
            if ( (char *)m_end >= v17->m_render_geometry.shading_group_name.m_max_end )
              break;
            LOBYTE(m_end->root_model_path.m_string.m_begin) = *v19;
            ++v17->m_render_geometry.shading_group_name.m_end;
            ++v19;
          }
          while ( *v19 );
        }
        *v17->m_render_geometry.shading_group_name.m_end = 0;
      }
    }
    material_result = 0;
    if ( v3->material_settings_valid )
    {
      material_index = vostok::render::cook_intermediate_data::find_material_index(m_end, (int)v3, v16);
      if ( material_index != -1 )
      {
        p_material = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v3->assets[material_index].material;
        m.m_object = 0;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
          (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m,
          p_material);
        m_object = m.m_object;
        if ( m.m_object )
        {
          _InterlockedExchangeAdd(&m.m_object->m_reference_count, 1u);
          if ( !*((_DWORD *)p_m_create_resource_result - 1) && *p_m_create_resource_result != result_error )
          {
            v22 = m_object[1].__vftable;
            material_result = 1;
            v46.m_object = 0;
            vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
              &v46,
              (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_create_resource_result
            - 10);
            v39 = (const char *)v22;
            v24 = v46.m_object;
            v36 = 0;
            if ( v46.m_object )
            {
              v36 = v46.m_object;
              v23 = (vostok::render::render_surface *)_InterlockedExchangeAdd(&v46.m_object->m_reference_count, 1u);
            }
            vostok::render::render_surface::set_material_effects(
              v23,
              (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)v17,
              (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base>)v36,
              v39);
            if ( v24 && !_InterlockedExchangeAdd(&v24->m_reference_count, 0xFFFFFFFF) )
              vostok::resources::unmanaged_intrusive_base::destroy(
                &v24->vostok::resources::unmanaged_intrusive_base,
                v24);
          }
          if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(
              &m_object->vostok::resources::unmanaged_intrusive_base,
              m_object);
          if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(
              &m_object->vostok::resources::unmanaged_intrusive_base,
              m_object);
          if ( material_result )
          {
            v3 = cook_data;
            goto LABEL_57;
          }
        }
        v3 = cook_data;
      }
    }
    v25 = v17->m_materail_effects_instance.m_object;
    v17->m_materail_effects_instance.m_object = 0;
    if ( v25 && !_InterlockedExchangeAdd(&v25->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v25->vostok::resources::unmanaged_intrusive_base, v25);
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
    {
      v26 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v26 )
      {
        log_callback.functor.obj_ptr = v26;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v27 = v3->parent_query;
      v41 |= 1u;
      if ( v27->m_requery_path )
        m_requery_path = v27->m_requery_path;
      else
        m_requery_path = v27->m_request_path;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\render_model_cooker.cpp",
        0x348u,
        "void __thiscall vostok::render::render_model_cook::finish_model_creation(class vostok::resources::queries_result"
        " &,struct vostok::render::cook_intermediate_data *)",
        "render_pc_dx11:",
        error,
        "material not loaded for %s : %s",
        m_requery_path,
        sg_name[0]);
    }
    if ( (v41 & 1) != 0 )
    {
      v41 &= ~1u;
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v29 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v29 )
            v29(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
LABEL_57:
    m_data = converted_model_ptr.m_data;
    model_reader.m_reader.m_size = converted_model_ptr.m_size;
    memset(&model_reader.m_chunks, 0, 16);
    model_reader.m_reader.m_data = converted_model_ptr.m_data;
    model_reader.m_reader.m_pointer = converted_model_ptr.m_data;
    v17->load(v17, properties, &model_reader);
    v6 = converted_model_ptr.m_resource.m_object == 0;
    surfaces[model_index] = v17;
    if ( !v6 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        _InterlockedExchangeAdd((volatile signed __int32 *)m_data - 2, 0xFFFFFFFF);
        v31 = m_data - 36;
        if ( *((_DWORD *)m_data - 9) )
        {
          if ( !*((_DWORD *)m_data - 2) )
          {
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v31 + 40), 1u);
            *(_DWORD *)v31 = 0;
          }
        }
      }
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&converted_model_ptr.m_resource);
    if ( !_InterlockedExchangeAdd(&prop_config_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &prop_config_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        prop_config_ptr.m_object);
    v45 += 288;
    p_m_create_resource_result += 180;
    if ( ++model_index >= v3->m_num_render_models )
      break;
    v5 = v45;
  }
  v4 = parent_query;
LABEL_66:
  sg_name[0] = 0;
  vostok::render::arrange_surfaces_by_lod(v3, (vostok::render::model_lods_descriptor **)sg_name);
  v3->result_model.m_object->set_children(
    v3->result_model.m_object,
    surfaces,
    v3->m_num_render_models,
    (vostok::render::model_lods_descriptor *)sg_name[0]);
  v32 = v3->result_model.m_object;
  v35.m_object = 0;
  if ( v32 )
  {
    v35.m_object = v3->result_model.m_object;
    _InterlockedExchangeAdd(&v32->m_reference_count, 1u);
  }
  vostok::resources::query_result_for_cook::set_unmanaged_resource(v4, v35, &vostok::resources::nocache_memory, 0x138u);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v33,
    result_success,
    assert_on_fail_true,
    error_type_unset);
  vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::model_asset,vostok::memory::detail::call_destructor_predicate>(
    &v3->assets,
    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
LABEL_69:
  v34 = vostok::render::g_allocator.m_object;
  vostok::render::cook_intermediate_data::~cook_intermediate_data(v7, (int)v3);
  BYTE2(v34->m_children_resources.m_lock) = 0;
  vostok_mspace_free((void *)HIDWORD(v34->m_reconstruction_info_actuality_tick), v3);
}
