void __thiscall vostok::render::skeleton_combined_model_cook::on_material_effects_loaded(
        vostok::render::skeleton_combined_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent,
        vostok::render::skeleton_combined_cook_data *cook_data)
{
  volatile int m_result; // ecx
  char v5; // bl
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::skeleton_combined_cook_data *v8; // ebx
  vostok::render::skeleton_render_model *render_model; // esi
  int v10; // edi
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *p_export_properties_config; // esi
  const void *pointer; // eax
  vostok::render::render_surface *render_surface; // ebx
  vostok::resources::managed_resource *m_object; // ecx
  vostok::resources::unmanaged_resource *v15; // edi
  vostok::resources::managed_resource *v16; // eax
  vostok::configs::binary_config *v17; // eax
  vostok::resources::unmanaged_resource *v18; // eax
  vostok::configs::binary_config *v19; // ecx
  vostok::configs::binary_config *v20; // eax
  vostok::render::material_effects_instance *v21; // eax
  vostok::render::render_surface *v22; // ecx
  const unsigned __int8 *m_data; // eax
  const unsigned __int8 *v24; // ecx
  const unsigned __int8 *v25; // eax
  vostok::resources::query_result_for_cook *v26; // ecx
  vostok::render::skeleton_combined_cook_data *v27; // ecx
  vostok::render::grass_render_model *v28; // esi
  const unsigned __int8 *v29; // eax
  const unsigned __int8 *v30; // ecx
  const unsigned __int8 *v31; // eax
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> v32; // [esp-8h] [ebp-A0h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v33; // [esp-4h] [ebp-9Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // [esp+Ch] [ebp-8Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+10h] [ebp-88h] BYREF
  unsigned int i; // [esp+14h] [ebp-84h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v37; // [esp+18h] [ebp-80h] BYREF
  int v38; // [esp+1Ch] [ebp-7Ch]
  vostok::render::render_surface **surfaces; // [esp+24h] [ebp-74h]
  int parts_count; // [esp+28h] [ebp-70h]
  vostok::render::render_model *result_model; // [esp+2Ch] [ebp-6Ch]
  vostok::resources::pinned_ptr_const<unsigned char> bind_pose_ptr; // [esp+30h] [ebp-68h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> converted_model_ptr; // [esp+3Ch] [ebp-5Ch] BYREF
  unsigned int v44; // [esp+48h] [ebp-50h]
  vostok::memory::reader bones_reader; // [esp+4Ch] [ebp-4Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+58h] [ebp-40h] BYREF
  vostok::memory::chunk_reader model_reader; // [esp+78h] [ebp-20h] BYREF

  m_result = data->m_result;
  v5 = 0;
  parts_count = 0;
  if ( m_result != 1 )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
    {
      v6 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v6 )
      {
        log_callback.functor.obj_ptr = v6;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v5 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\combined_model_cooker.cpp",
        0x109u,
        "void __thiscall vostok::render::skeleton_combined_model_cook::on_material_effects_loaded(class vostok::resources"
        "::queries_result &,class vostok::resources::query_result_for_cook *,struct vostok::render::skeleton_combined_cook_data *)",
        "render_pc_dx11:",
        error,
        "skeleton_combined_model_cook::on_material_effects_loaded : data loading failed");
    }
    if ( (v5 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v7 )
            v7(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
  }
  v8 = cook_data;
  render_model = (vostok::render::skeleton_render_model *)vostok::render::model_factory::create_render_model(0x28u);
  result_model = render_model;
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    &cook_data->bind_pose);
  v33.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v33,
    &object);
  vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
    &bind_pose_ptr,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v33.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  bones_reader.m_data = bind_pose_ptr.m_data;
  bones_reader.m_pointer = bind_pose_ptr.m_data;
  bones_reader.m_size = bind_pose_ptr.m_size;
  vostok::render::skeleton_render_model::load_bones(render_model, &bones_reader);
  LOBYTE(parts_count) = cook_data->models_count;
  v10 = (unsigned __int8)parts_count;
  v44 = (unsigned __int8)parts_count;
  surfaces = (vostok::render::render_surface **)vostok::memory::doug_lea_allocator::malloc_impl(
                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                  4 * (unsigned __int8)parts_count);
  i = 0;
  if ( v10 )
  {
    p_m_unmanaged_resource = &data->m_queries[0].m_unmanaged_resource;
    p_export_properties_config = &cook_data->model_defs[0].export_properties_config;
    do
    {
      pointer = vostok::configs::binary_config_value::operator[](p_export_properties_config->m_object->m_root, "type")->data.pointer;
      v38 = 0;
      render_surface = vostok::render::model_factory::create_render_surface((unsigned __int16)pointer);
      surfaces[i] = render_surface;
      m_object = (vostok::resources::managed_resource *)p_export_properties_config[2].m_object;
      v15 = 0;
      v16 = 0;
      v37.m_object = 0;
      if ( m_object )
      {
        v16 = m_object;
        v37.m_object = m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      v33.m_object = 0;
      if ( v16 )
      {
        v33.m_object = v16;
        _InterlockedExchangeAdd(&v16->m_reference_count, 1u);
      }
      vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
        &converted_model_ptr,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v33.m_object);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v37);
      model_reader.m_reader.m_data = converted_model_ptr.m_data;
      model_reader.m_reader.m_pointer = converted_model_ptr.m_data;
      v17 = p_export_properties_config->m_object;
      model_reader.m_reader.m_size = converted_model_ptr.m_size;
      memset(&model_reader.m_chunks, 0, 16);
      render_surface->load(render_surface, v17->m_root, &model_reader);
      if ( p_m_unmanaged_resource->m_object )
      {
        v15 = p_m_unmanaged_resource->m_object;
        _InterlockedExchangeAdd(&p_m_unmanaged_resource->m_object->m_reference_count, 1u);
      }
      v18 = 0;
      if ( v15 )
      {
        v18 = v15;
        _InterlockedExchangeAdd(&v15->m_reference_count, 1u);
      }
      v19 = (vostok::configs::binary_config *)v18;
      v20 = p_export_properties_config[1].m_object;
      p_export_properties_config[1].m_object = v19;
      if ( v20 )
      {
        v37.m_object = (vostok::resources::managed_resource *)&v20->vostok::resources::unmanaged_intrusive_base;
        if ( !_InterlockedExchangeAdd(&v20->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v20->vostok::resources::unmanaged_intrusive_base, v20);
      }
      if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
      v33.m_object = (vostok::resources::managed_resource *)p_export_properties_config[-70].m_object;
      v21 = (vostok::render::material_effects_instance *)p_export_properties_config[1].m_object;
      v22 = (vostok::render::render_surface *)&v32;
      v32.m_object = 0;
      if ( v21 )
      {
        v32.m_object = v21;
        v22 = (vostok::render::render_surface *)_InterlockedExchangeAdd(&v21->m_reference_count, 1u);
      }
      vostok::render::render_surface::set_material_effects(
        v22,
        (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)render_surface,
        v32,
        (const char *)v33.m_object);
      if ( converted_model_ptr.m_resource.m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          m_data = converted_model_ptr.m_data;
          v24 = converted_model_ptr.m_data - 8;
          _InterlockedExchangeAdd((volatile signed __int32 *)converted_model_ptr.m_data - 2, 0xFFFFFFFF);
          v25 = m_data - 36;
          if ( *(_DWORD *)v25 )
          {
            if ( !*(_DWORD *)v24 )
            {
              _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v25 + 40), 1u);
              *(_DWORD *)v25 = 0;
            }
          }
        }
      }
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&converted_model_ptr.m_resource);
      p_m_unmanaged_resource += 180;
      p_export_properties_config += 211;
      ++i;
    }
    while ( i < v44 );
    v8 = cook_data;
    render_model = (vostok::render::skeleton_render_model *)result_model;
  }
  render_model->set_children(render_model, surfaces, parts_count, 0);
  v33.m_object = (vostok::resources::managed_resource *)312;
  v32.m_object = (vostok::render::material_effects_instance *)&vostok::resources::nocache_memory;
  _InterlockedExchangeAdd(&render_model->m_reference_count, 1u);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)render_model,
    (const vostok::resources::memory_type *)v32.m_object,
    (unsigned int)v33.m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v26,
    result_success,
    assert_on_fail_true,
    error_type_unset);
  if ( v8->owner_is_cook )
  {
    v28 = vostok::render::g_allocator.m_object;
    vostok::render::skeleton_combined_cook_data::~skeleton_combined_cook_data(v27, v8);
    BYTE2(v28->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(v28->m_reconstruction_info_actuality_tick), v8);
  }
  if ( bind_pose_ptr.m_resource.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v29 = bind_pose_ptr.m_data;
      v30 = bind_pose_ptr.m_data - 8;
      _InterlockedExchangeAdd((volatile signed __int32 *)bind_pose_ptr.m_data - 2, 0xFFFFFFFF);
      v31 = v29 - 36;
      if ( *(_DWORD *)v31 )
      {
        if ( !*(_DWORD *)v30 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v31 + 40), 1u);
          *(_DWORD *)v31 = 0;
        }
      }
    }
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&bind_pose_ptr.m_resource);
}
