void __thiscall vostok::render::skeleton_combined_model_cook::on_resources_loaded(
        vostok::render::skeleton_combined_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *parent,
        vostok::render::skeleton_combined_cook_data *cook_data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::configs::binary_config *m_object; // ebx
  vostok::configs::binary_config *v6; // edi
  vostok::configs::binary_config *v7; // eax
  vostok::render::skeleton_combined_cook_data *v8; // esi
  vostok::animation::skeleton *v9; // ecx
  vostok::animation::skeleton *v10; // eax
  vostok::resources::managed_resource *v11; // eax
  unsigned int models_count; // edi
  const vostok::resources::request *v13; // ebx
  vostok::variant<32> **v14; // eax
  bool v15; // zf
  vostok::resources::managed_resource *v16; // ebx
  char **p_m_end; // esi
  vostok::resources::managed_resource *m_allocator; // ecx
  vostok::resources::managed_resource *v19; // eax
  vostok::resources::managed_resource *v20; // ebx
  char *v21; // ecx
  vostok::configs::binary_config *m_reference_count; // eax
  vostok::resources::managed_resource *v23; // ebx
  vostok::configs::binary_config *v24; // edi
  vostok::configs::binary_config *v25; // eax
  char *v26; // edx
  vostok::resources::managed_resource *v27; // ecx
  vostok::resources::managed_resource *v28; // ecx
  vostok::resources::unmanaged_resource *v29; // eax
  vostok::resources::unmanaged_resource *v30; // ebx
  vostok::resources::unmanaged_resource *v31; // edi
  vostok::resources::unmanaged_resource *v32; // eax
  char *v33; // ecx
  char *v34; // eax
  char **v35; // edi
  vostok::configs::binary_config_value *v36; // eax
  vostok::configs::binary_config_value *v37; // eax
  char *pointer; // eax
  char *v39; // ecx
  vostok::render::mesh_type_enum max_storage_low; // edi
  const vostok::resources::request *v41; // ecx
  vostok::variant<32> *v42; // eax
  int v43; // ebx
  vostok::render::enum_vertex_input_type v44; // eax
  int v45; // edx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v46; // edi
  vostok::resources::managed_resource *v47; // ecx
  unsigned int v48; // eax
  vostok::variant<32> **v49; // esi
  void (__cdecl *v50)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::grass_render_model *v51; // eax
  vostok::render::grass_render_model *v52; // ecx
  vostok::resources::managed_resource *v53; // edx
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v55; // esi
  const char *v56; // [esp+298h] [ebp-A8h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v57; // [esp+2ACh] [ebp-94h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v58; // [esp+2B0h] [ebp-90h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v59; // [esp+2B4h] [ebp-8Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v60; // [esp+2B8h] [ebp-88h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v61; // [esp+2BCh] [ebp-84h] BYREF
  const vostok::resources::request *v62; // [esp+2C0h] [ebp-80h]
  vostok::variant<32> **user_data; // [esp+2C4h] [ebp-7Ch]
  vostok::resources::managed_resource *v64; // [esp+2C8h] [ebp-78h]
  int v65; // [esp+2D0h] [ebp-70h]
  const vostok::resources::request *v66; // [esp+2D4h] [ebp-6Ch]
  vostok::render::skeleton_combined_model_cook *v67; // [esp+2D8h] [ebp-68h]
  _QWORD v68[4]; // [esp+2DCh] [ebp-64h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+300h] [ebp-40h] BYREF
  unsigned __int64 v70; // [esp+324h] [ebp-1Ch]
  _DWORD v71[5]; // [esp+32Ch] [ebp-14h]

  v67 = this;
  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v57.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v57,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v57.m_object;
    v6 = 0;
    if ( v57.m_object )
    {
      v6 = v57.m_object;
      _InterlockedExchangeAdd(&v57.m_object->m_reference_count, 1u);
    }
    v7 = 0;
    if ( v6 )
    {
      v7 = v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    v8 = cook_data;
    v9 = (vostok::animation::skeleton *)v7;
    v10 = cook_data->skeleton.m_object;
    cook_data->skeleton.m_object = v9;
    if ( v10 )
    {
      if ( !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
      m_object = v57.m_object;
    }
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v58.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v58,
      &data->m_queries[1].m_managed_resource);
    v11 = 0;
    if ( v58.m_object )
    {
      v11 = v58.m_object;
      _InterlockedExchangeAdd(&v58.m_object->m_reference_count, 1u);
    }
    v61.m_object = cook_data->bind_pose.m_object;
    cook_data->bind_pose.m_object = v11;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v61);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v58);
    models_count = cook_data->models_count;
    LODWORD(v68[0]) = models_count;
    v13 = (const vostok::resources::request *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                8 * models_count);
    v66 = v13;
    v61.m_object = (vostok::resources::managed_resource *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                            48 * models_count);
    v14 = (vostok::variant<32> **)vostok::memory::doug_lea_allocator::malloc_impl(
                                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                    4 * models_count);
    v15 = cook_data->models_count == 0;
    user_data = v14;
    v65 = 0;
    if ( !v15 )
    {
      v62 = v13;
      v16 = (vostok::resources::managed_resource *)&data->m_queries[2];
      v64 = v61.m_object;
      p_m_end = &cook_data->model_defs[0].material_name.m_string.m_end;
      while ( 1 )
      {
        m_allocator = (vostok::resources::managed_resource *)v16->m_allocator;
        v19 = 0;
        v20 = v16 + 3;
        v60.m_object = 0;
        if ( m_allocator )
        {
          v19 = m_allocator;
          v60.m_object = m_allocator;
          _InterlockedExchangeAdd(&m_allocator->m_reference_count, 1u);
        }
        v21 = 0;
        if ( v19 )
        {
          v21 = (char *)v19;
          _InterlockedExchangeAdd(&v19->m_reference_count, 1u);
        }
        v59.m_object = (vostok::resources::managed_resource *)p_m_end[71];
        p_m_end[71] = v21;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v59);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v60);
        m_reference_count = (vostok::configs::binary_config *)v20->m_reference_count;
        v23 = v20 + 3;
        v24 = 0;
        if ( m_reference_count )
        {
          v24 = m_reference_count;
          _InterlockedExchangeAdd(&m_reference_count->m_reference_count, 1u);
        }
        v25 = 0;
        v57.m_object = 0;
        if ( v24 )
        {
          v57.m_object = v24;
          _InterlockedExchangeAdd(&v24->m_reference_count, 1u);
          v25 = v24;
        }
        v26 = 0;
        if ( v25 )
        {
          v58.m_object = (vostok::resources::managed_resource *)v25;
          _InterlockedExchangeAdd(&v25->m_reference_count, 1u);
          v26 = (char *)v25;
        }
        v58.m_object = (vostok::resources::managed_resource *)p_m_end[68];
        v27 = v58.m_object;
        p_m_end[68] = v26;
        if ( v27 )
        {
          v28 = (vostok::resources::managed_resource *)&v27->vostok::memory::managed_node_owner;
          v59.m_object = v28;
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v28, 0xFFFFFFFF) )
          {
            vostok::resources::unmanaged_intrusive_base::destroy(
              (vostok::resources::unmanaged_intrusive_base *)v28,
              (vostok::resources::unmanaged_resource *)v58.m_object);
            v25 = v57.m_object;
          }
        }
        if ( v25 )
        {
          v59.m_object = (vostok::resources::managed_resource *)&v25->vostok::resources::unmanaged_intrusive_base;
          if ( !_InterlockedExchangeAdd(&v25->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(&v25->vostok::resources::unmanaged_intrusive_base, v25);
        }
        if ( v24 && !_InterlockedExchangeAdd(&v24->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v24->vostok::resources::unmanaged_intrusive_base, v24);
        v29 = (vostok::resources::unmanaged_resource *)v23->m_reference_count;
        v59.m_object = v23 + 3;
        v30 = 0;
        if ( v29 )
        {
          v30 = v29;
          _InterlockedExchangeAdd(&v29->m_reference_count, 1u);
        }
        v31 = 0;
        if ( v30 )
        {
          v31 = v30;
          _InterlockedExchangeAdd(&v30->m_reference_count, 1u);
        }
        v32 = 0;
        if ( v31 )
        {
          v32 = v31;
          _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
        }
        v33 = (char *)v32;
        v34 = p_m_end[69];
        p_m_end[69] = v33;
        if ( v34 )
        {
          v60.m_object = (vostok::resources::managed_resource *)(v34 + 208);
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v34 + 52, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(
              (vostok::resources::unmanaged_intrusive_base *)v34 + 26,
              (vostok::resources::unmanaged_resource *)v34);
        }
        if ( v31 && !_InterlockedExchangeAdd(&v31->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v31->vostok::resources::unmanaged_intrusive_base, v31);
        if ( v30 && !_InterlockedExchangeAdd(&v30->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v30->vostok::resources::unmanaged_intrusive_base, v30);
        *(vostok::configs::binary_config_value *)((char *)v68 + 4) = *(vostok::configs::binary_config_value *)*((_DWORD *)p_m_end[68] + 66);
        v35 = p_m_end - 1;
        if ( vostok::buffer_string::empty((vostok::fs_new::path_string_impl *)(p_m_end - 1)) )
        {
          v56 = *(p_m_end - 70);
          v36 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          (vostok::configs::binary_config_value *)((char *)v68 + 4),
                                                          "material_settings");
          v37 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v36, v56);
          pointer = (char *)vostok::configs::binary_config_value::operator[](v37, "material_name")->data.pointer;
          v39 = *v35;
          *p_m_end = *v35;
          *v39 = 0;
          if ( pointer )
          {
            for ( ; *pointer; *(*p_m_end)++ = *pointer++ )
            {
              if ( *p_m_end >= p_m_end[1] )
                break;
            }
            **p_m_end = 0;
          }
        }
        max_storage_low = LOWORD(vostok::configs::binary_config_value::operator[](
                                   *((vostok::configs::binary_config_value **)p_m_end[69] + 66),
                                   "type")->data.max_storage);
        v41 = v62;
        v62->path = *(p_m_end - 1);
        v41->id = material_effects_instance_class;
        v42 = (vostok::variant<32> *)v64;
        if ( v64 )
        {
          v64->m_children_resources.m_lock = 0;
          v42->m_type_id = 0;
        }
        else
        {
          v42 = 0;
        }
        v43 = v65;
        user_data[v65] = v42;
        if ( vostok::memory::doug_lea_allocator::malloc_impl(
               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
               0x10u) )
        {
          v44 = vostok::render::mesh_type_to_vertex_input_type(max_storage_low);
          *(_DWORD *)v45 = v44;
          *(_DWORD *)(v45 + 4) = 0;
          *(_DWORD *)(v45 + 8) = 2;
          *(_BYTE *)(v45 + 12) = 1;
          v60.m_object = (vostok::resources::managed_resource *)v45;
        }
        else
        {
          v60.m_object = 0;
        }
        v46 = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)user_data[v43];
        v47 = v46[10].m_object;
        if ( v47 )
        {
          v47->log_string(v47, (vostok::fixed_string<512> *)&v46[2]);
          v46[10].m_object = 0;
        }
        v46[11].m_object = (vostok::resources::managed_resource *)vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
        if ( v46 != (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)-8 )
          v46[2].m_object = v60.m_object;
        ++v62;
        v64 = (vostok::resources::managed_resource *)((char *)v64 + 48);
        v46->m_object = (vostok::resources::managed_resource *)&vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
        v46[10].m_object = (vostok::resources::managed_resource *)v46;
        v48 = cook_data->models_count;
        p_m_end += 211;
        v65 = v43 + 1;
        if ( v43 + 1 >= v48 )
          break;
        v16 = v59.m_object;
      }
      v13 = v66;
      models_count = v68[0];
      v8 = cook_data;
    }
    v70 = __PAIR64__((unsigned int)parent, (unsigned int)v67);
    v68[1] = __PAIR64__((unsigned int)parent, (unsigned int)v67);
    HIDWORD(v68[0]) = vostok::render::skeleton_combined_model_cook::on_material_effects_loaded;
    LODWORD(v68[2]) = v8;
    *(__m128i *)&v71[1] = _mm_load_si128((const __m128i *)((char *)v68 + 4));
    if ( survarium::generate_shaders_world::is_loading() )
    {
      callback.vtable = 0;
    }
    else
    {
      *(_QWORD *)&callback.functor.obj_ptr = *(_QWORD *)&v71[1];
      *((_QWORD *)&callback.functor.data + 1) = *(_QWORD *)&v71[3];
      callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::skeleton_combined_model_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::render::skeleton_combined_cook_data *>,boost::_bi::list4<boost::_bi::value<vostok::render::skeleton_combined_model_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::render::skeleton_combined_cook_data *>>>>'::`2'::stored_vtable
                                                               + 1);
    }
    v49 = user_data;
    vostok::resources::query_resources(
      v13,
      models_count,
      &callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)user_data,
      parent,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v50 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v50 )
          v50(&callback.functor, &callback.functor, 2);
      }
    }
    v51 = vostok::render::g_allocator.m_object;
    v52 = vostok::render::g_allocator.m_object;
    if ( v49 )
    {
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v52->m_reconstruction_info_actuality_tick), v49);
      v51 = vostok::render::g_allocator.m_object;
    }
    v53 = v61.m_object;
    if ( v61.m_object )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(v51->m_reconstruction_info_actuality_tick);
      BYTE2(v51->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v53);
      v51 = vostok::render::g_allocator.m_object;
    }
    if ( v13 )
    {
      v55 = (void *)HIDWORD(v51->m_reconstruction_info_actuality_tick);
      BYTE2(v51->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v55, (void *)v13);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
