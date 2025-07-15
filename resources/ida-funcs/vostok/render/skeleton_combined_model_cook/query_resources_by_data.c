void __thiscall vostok::render::skeleton_combined_model_cook::query_resources_by_data(
        vostok::render::skeleton_combined_model_cook *this,
        vostok::render::skeleton_combined_model_cook *parent,
        vostok::resources::query_result_for_cook *cook_data,
        vostok::render::skeleton_combined_cook_data *cook_dataa)
{
  vostok::render::skeleton_combined_cook_data *v4; // edi
  unsigned int v5; // esi
  vostok::resources::request *v6; // ebx
  char *m_begin; // eax
  bool v8; // zf
  vostok::resources::request *v9; // ebx
  const char **p_m_begin; // edi
  vostok::strings::detail::tuples *v11; // ecx
  void *v12; // esp
  vostok::strings::detail::tuples *v13; // ecx
  void *v14; // ecx
  vostok::resources::request *v15; // ebx
  vostok::strings::detail::tuples *v16; // ecx
  void *v17; // esp
  vostok::strings::detail::tuples *v18; // ecx
  const char **v19; // edi
  vostok::strings::detail::tuples *v20; // ecx
  void *v21; // esp
  vostok::strings::detail::tuples *v22; // ecx
  vostok::resources::class_id_enum v23; // ecx
  unsigned int v24; // eax
  unsigned int models_count; // ecx
  void (__cdecl *v26)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  char v28[12]; // [esp+0h] [ebp-84h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+Ch] [ebp-78h] BYREF
  __int128 v30; // [esp+40h] [ebp-44h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+50h] [ebp-34h] BYREF
  vostok::resources::request *requests; // [esp+70h] [ebp-14h]
  unsigned int request_count; // [esp+74h] [ebp-10h]
  unsigned int part_idx; // [esp+78h] [ebp-Ch]
  vostok::render::skeleton_combined_cook_data::model_def *i; // [esp+7Ch] [ebp-8h]

  v4 = cook_dataa;
  request_count = 3 * cook_dataa->models_count + 2;
  v5 = request_count;
  v6 = (vostok::resources::request *)vostok::memory::doug_lea_allocator::malloc_impl(
                                       (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                       8 * request_count);
  m_begin = cook_dataa->skeleton_name.m_string.m_begin;
  v6->id = skeleton_class;
  v6->path = m_begin;
  v6[1].path = cook_dataa->bind_pose_name.m_string.m_begin;
  v6[1].id = raw_data_class;
  v8 = cook_dataa->models_count == 0;
  requests = v6;
  part_idx = 0;
  if ( !v8 )
  {
    v9 = v6 + 2;
    p_m_begin = (const char **)&cook_dataa->model_defs[0].base_model_name.m_string.m_begin;
    callback.functor.vostok_pointer_size_alignment[5] = (void *)3;
    HIDWORD(v30) = 34;
    for ( i = cook_dataa->model_defs; ; p_m_begin = (const char **)&i->base_model_name.m_string.m_begin )
    {
      vostok::strings::detail::tuples::tuples(
        &STR_JOINA_tuples_unique_identifier,
        "resources/models/",
        *p_m_begin,
        ".skinned_model/render/",
        p_m_begin[69],
        "/converted_model");
      v12 = alloca(vostok::strings::detail::tuples::size(v11, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
      vostok::strings::detail::tuples::size(v13, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
      vostok::strings::detail::tuples::concat(v28, &STR_JOINA_tuples_unique_identifier);
      v14 = callback.functor.vostok_pointer_size_alignment[5];
      v9->path = v28;
      v9->id = (vostok::resources::class_id_enum)v14;
      v15 = v9 + 1;
      vostok::strings::detail::tuples::tuples(
        &STR_JOINA_tuples_unique_identifier,
        "resources/models/",
        *p_m_begin,
        ".skinned_model/settings");
      v17 = alloca(vostok::strings::detail::tuples::size(v16, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
      vostok::strings::detail::tuples::size(v18, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
      vostok::strings::detail::tuples::concat(v28, &STR_JOINA_tuples_unique_identifier);
      v19 = (const char **)&i->base_model_name.m_string.m_begin;
      v15->path = v28;
      v15->id = binary_config_class_impl;
      ++v15;
      vostok::strings::detail::tuples::tuples(
        &STR_JOINA_tuples_unique_identifier,
        "resources/models/",
        *v19,
        ".skinned_model/render/",
        v19[69],
        "/export_properties");
      v21 = alloca(vostok::strings::detail::tuples::size(v20, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
      vostok::strings::detail::tuples::size(v22, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
      vostok::strings::detail::tuples::concat(v28, &STR_JOINA_tuples_unique_identifier);
      v23 = HIDWORD(v30);
      v24 = part_idx;
      v15->path = v28;
      v15->id = v23;
      models_count = cook_dataa->models_count;
      v9 = v15 + 1;
      part_idx = v24 + 1;
      i = (vostok::render::skeleton_combined_cook_data::model_def *)(v19 + 211);
      if ( v24 + 1 >= models_count )
        break;
    }
    v5 = request_count;
    v6 = requests;
    v4 = cook_dataa;
  }
  *(_QWORD *)(&callback.functor.data + 12) = __PAIR64__((unsigned int)cook_data, (unsigned int)parent);
  callback.functor.vostok_pointer_size_alignment[2] = vostok::render::skeleton_combined_model_cook::on_resources_loaded;
  callback.functor.vostok_pointer_size_alignment[5] = v4;
  v30 = *(_OWORD *)(&callback.functor.data + 8);
  if ( survarium::generate_shaders_world::is_loading() )
  {
    callback.vtable = 0;
  }
  else
  {
    callback.functor.bound_memfunc_ptr.memfunc_ptr = v30;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::skeleton_combined_model_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::skeleton_combined_cook_data *>,boost::_bi::list4<boost::_bi::value<vostok::render::skeleton_combined_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::skeleton_combined_cook_data *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_resources(
    v6,
    v5,
    &callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    0,
    cook_data,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v26 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v26 )
        v26(&callback.functor, &callback.functor, 2);
    }
  }
  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)v6);
}
