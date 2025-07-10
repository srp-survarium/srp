void __thiscall vostok::render::render_model_cook::query_materail_effects(
        vostok::render::render_model_cook *this,
        vostok::render::cook_intermediate_data *cook_data,
        vostok::render::cook_intermediate_data *cook_dataa)
{
  int v3; // ebp
  vostok::render::cook_intermediate_data *v4; // ecx
  vostok::render::grass_render_model *m_object; // esi
  unsigned int m_num_render_models; // esi
  const vostok::resources::request *v7; // ebx
  const vostok::variant<32> **v8; // edi
  int v9; // esi
  char *m_buffer; // ebx
  unsigned int material_index; // eax
  vostok::resources::unmanaged_resource *v12; // ebp
  vostok::resources::unmanaged_resource *v13; // ecx
  vostok::resources::unmanaged_resource *v14; // eax
  vostok::resources::unmanaged_resource *v15; // ecx
  vostok::fs_new::virtual_path_string *v16; // edi
  vostok::fs_new::virtual_path_string *material_effects_instance_request_path; // eax
  const char *v18; // eax
  vostok::variant<32> *v19; // eax
  _DWORD *v20; // edi
  _DWORD *v21; // esi
  vostok::resources::unmanaged_resource *v22; // edx
  vostok::variant<32> *v23; // esi
  vostok::detail::abstract_type_helper *m_helper; // ecx
  void (__cdecl *v25)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::grass_render_model *v26; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v28; // esi
  void *v29; // esi
  void *v30; // esi
  vostok::resources::unmanaged_resource *v31; // [esp-4h] [ebp-180h]
  unsigned int model_index; // [esp+10h] [ebp-16Ch]
  int v33; // [esp+14h] [ebp-168h]
  vostok::variant<32> *v34; // [esp+18h] [ebp-164h]
  vostok::variant<32> **user_data_variants_ptrs; // [esp+1Ch] [ebp-160h]
  vostok::resources::request *requests; // [esp+20h] [ebp-15Ch]
  vostok::variant<32> *user_data_variants; // [esp+24h] [ebp-158h]
  vostok::fs_new::virtual_path_string *pathes; // [esp+28h] [ebp-154h]
  vostok::render::mesh_type_enum model_type; // [esp+2Ch] [ebp-150h]
  __int64 model_type_4; // [esp+30h] [ebp-14Ch]
  unsigned int num_requests; // [esp+3Ch] [ebp-140h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+40h] [ebp-13Ch] BYREF
  vostok::fs_new::path_string_impl v43; // [esp+64h] [ebp-118h] BYREF

  v3 = (int)cook_dataa;
  if ( cook_dataa->status_failed )
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
    if ( cook_dataa->assets )
      vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,vostok::render::model_asset,vostok::memory::detail::call_destructor_predicate>(
        &cook_dataa->assets,
        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
    m_object = vostok::render::g_allocator.m_object;
    vostok::render::cook_intermediate_data::~cook_intermediate_data(v4, (int)cook_dataa);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), cook_dataa);
  }
  else
  {
    m_num_render_models = cook_dataa->m_num_render_models;
    num_requests = m_num_render_models;
    pathes = (vostok::fs_new::virtual_path_string *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                      (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                      276 * m_num_render_models);
    v7 = (const vostok::resources::request *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               8 * m_num_render_models);
    requests = v7;
    user_data_variants = (vostok::variant<32> *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                  48 * m_num_render_models);
    v8 = (const vostok::variant<32> **)vostok::memory::doug_lea_allocator::malloc_impl(
                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                         4 * m_num_render_models);
    user_data_variants_ptrs = (vostok::variant<32> **)v8;
    model_index = 0;
    if ( cook_dataa->m_num_render_models )
    {
      v9 = 0;
      v33 = 0;
      v34 = user_data_variants;
      m_buffer = pathes->m_string.m_buffer;
      while ( 1 )
      {
        model_type = LOWORD(vostok::configs::binary_config_value::operator[](
                              *(vostok::configs::binary_config_value **)(*(_DWORD *)(*(_DWORD *)(v3 + 288) + v9 + 8)
                                                                       + 264),
                              "type")->data.max_storage);
        if ( cook_data->root_model_path.m_string.m_max_end == (char *)29 )
          model_type = mt_grass_mesh;
        material_index = vostok::render::cook_intermediate_data::find_material_index(
                           cook_data,
                           v3,
                           *(const char **)(*(_DWORD *)(v3 + 288) + v9 + 12));
        v12 = 0;
        if ( material_index != -1 )
        {
          v13 = cook_dataa->assets[material_index].material.m_object;
          v14 = 0;
          if ( v13 )
          {
            v14 = v13;
            _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
          }
          v15 = 0;
          if ( v14 )
          {
            v15 = v14;
            _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
          }
          v12 = v15;
          if ( v14 && !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(&v14->vostok::resources::unmanaged_intrusive_base, v14);
        }
        if ( m_buffer == (char *)12 )
        {
          v16 = 0;
        }
        else
        {
          *((_DWORD *)m_buffer - 3) = m_buffer;
          *((_DWORD *)m_buffer - 2) = m_buffer;
          *((_DWORD *)m_buffer - 1) = m_buffer + 260;
          *m_buffer = 0;
          *m_buffer = 0;
          m_buffer[260] = 47;
          v16 = (vostok::fs_new::virtual_path_string *)(m_buffer - 12);
        }
        v31 = 0;
        if ( v12 )
        {
          v31 = v12;
          _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
        }
        material_effects_instance_request_path = vostok::render::get_material_effects_instance_request_path(&v43, v31);
        vostok::fs_new::virtual_path_string::operator=(v16, material_effects_instance_request_path);
        if ( *((_DWORD *)m_buffer - 2) == *((_DWORD *)m_buffer - 3) )
          v18 = "nomaterial";
        else
          v18 = (const char *)*((_DWORD *)m_buffer - 3);
        requests[model_index].path = v18;
        v19 = v34;
        v20 = 0;
        requests[model_index].id = material_effects_instance_class;
        if ( v34 )
        {
          v34->m_helper = 0;
          v34->m_type_id = 0;
        }
        else
        {
          v19 = 0;
        }
        user_data_variants_ptrs[model_index] = v19;
        v21 = vostok::memory::doug_lea_allocator::malloc_impl(
                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                0x10u);
        if ( v21 )
        {
          if ( v12 )
            _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
          *v21 = vostok::render::mesh_type_to_vertex_input_type_0(model_type);
          v21[1] = 0;
          if ( v22 )
          {
            v21[1] = v22;
            _InterlockedExchangeAdd(&v22->m_reference_count, 1u);
          }
          v21[2] = 2;
          *((_BYTE *)v21 + 12) = 1;
          if ( v22 && !_InterlockedExchangeAdd(&v22->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(&v22->vostok::resources::unmanaged_intrusive_base, v22);
          v20 = v21;
        }
        v23 = user_data_variants_ptrs[model_index];
        m_helper = v23->m_helper;
        if ( m_helper )
        {
          m_helper->destroy(m_helper, v23->m_storage);
          v23->m_helper = 0;
        }
        v23->m_type_id = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
        if ( v23 != (vostok::variant<32> *)-8 )
          *(_DWORD *)v23->m_storage = v20;
        *(_DWORD *)v23->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
        v23->m_helper = (vostok::detail::abstract_type_helper *)v23;
        if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
        v33 += 288;
        ++v34;
        m_buffer += 276;
        ++model_index;
        v3 = (int)cook_dataa;
        if ( model_index >= cook_dataa->m_num_render_models )
          break;
        v9 = v33;
      }
      v8 = (const vostok::variant<32> **)user_data_variants_ptrs;
      m_num_render_models = num_requests;
      v7 = requests;
    }
    HIDWORD(model_type_4) = cook_data;
    LODWORD(model_type_4) = vostok::render::render_model_cook::finish_model_creation;
    if ( survarium::generate_shaders_world::is_loading() )
    {
      callback.vtable = 0;
    }
    else
    {
      *(_QWORD *)&callback.functor.obj_ptr = model_type_4;
      callback.functor.vostok_pointer_size_alignment[2] = (void *)v3;
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::render_model_cook,vostok::resources::queries_result &,vostok::render::cook_intermediate_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::render_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::cook_intermediate_data *>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    vostok::resources::query_resources(
      v7,
      m_num_render_models,
      &callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      v8,
      *(vostok::resources::query_result_for_cook **)(v3 + 276),
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v25 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v25 )
          v25(&callback.functor, &callback.functor, 2);
      }
    }
    v26 = vostok::render::g_allocator.m_object;
    if ( v8 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
      v26 = vostok::render::g_allocator.m_object;
    }
    if ( user_data_variants )
    {
      v28 = (void *)HIDWORD(v26->m_reconstruction_info_actuality_tick);
      BYTE2(v26->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v28, user_data_variants);
      v26 = vostok::render::g_allocator.m_object;
    }
    if ( v7 )
    {
      v29 = (void *)HIDWORD(v26->m_reconstruction_info_actuality_tick);
      BYTE2(v26->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v29, (void *)v7);
      v26 = vostok::render::g_allocator.m_object;
    }
    if ( pathes )
    {
      v30 = (void *)HIDWORD(v26->m_reconstruction_info_actuality_tick);
      BYTE2(v26->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v30, pathes);
    }
  }
}
