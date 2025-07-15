void __thiscall vostok::render::speedtree_cook::on_speedtree_raw_data_loaded(
        vostok::render::speedtree_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::speedtree_data *creation_data)
{
  bool v3; // zf
  vostok::render::grass_render_model *v4; // edi
  vostok::render::speedtree_data *v5; // ecx
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  int *v7; // eax
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *v8; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config_value *m_root; // esi
  vostok::configs::binary_config_value *v12; // eax
  vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // eax
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  vostok::configs::binary_config_value *v18; // eax
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  void (__cdecl *v22)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v23; // eax
  vostok::resources::unmanaged_intrusive_base *v24; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::speedtree_cook,vostok::resources::queries_result &,vostok::render::speedtree_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::speedtree_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::speedtree_data *> > > v25; // [esp-Ch] [ebp-84h] BYREF
  int v26; // [esp+0h] [ebp-78h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> model_config; // [esp+Ch] [ebp-6Ch] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+10h] [ebp-68h] BYREF
  vostok::render::speedtree_cook *v29; // [esp+14h] [ebp-64h]
  vostok::resources::pinned_ptr_const<unsigned char> raw_data_ptr; // [esp+18h] [ebp-60h] BYREF
  __int64 v31; // [esp+24h] [ebp-54h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+30h] [ebp-48h] BYREF
  vostok::resources::request materials_request[5]; // [esp+50h] [ebp-28h] BYREF

  v3 = data->m_queries[0].m_error_type == error_type_unset;
  v29 = this;
  if ( v3 && data->m_queries[0].m_create_resource_result != result_error )
  {
    model_config.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&model_config,
      &data->m_queries[0].m_managed_resource);
    v25.l_.a3_.t_ = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v25.l_.a3_,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&model_config);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &raw_data_ptr,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v25.l_.a3_.t_);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&model_config);
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0xF88u);
    if ( v7 )
      vostok::render::speedtree_tree::speedtree_tree(
        (vostok::render::speedtree_tree *)raw_data_ptr.m_size,
        (int)v7,
        (unsigned __int8 *)raw_data_ptr.m_data,
        raw_data_ptr.m_size);
    else
      v8 = 0;
    vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>::operator=(
      v8,
      &creation_data->m_model.m_object);
    if ( data->m_queries[1].m_error_type || data->m_queries[1].m_create_resource_result == result_error )
    {
      vostok::resources::query_result_for_cook::finish_query_impl(
        v9,
        (int)creation_data->m_parent_query,
        result_error,
        assert_on_fail_true,
        (vostok::resources::query_result_for_cook *)0xB);
      vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&raw_data_ptr);
    }
    else
    {
      v28.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v28,
        (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
      model_config.m_object = 0;
      m_object = v28.m_object;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &model_config,
        v28.m_object);
      if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
      m_root = model_config.m_object->m_root;
      v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
      v12 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "branch");
      if ( strlen((const char *)vostok::configs::binary_config_value::operator[](v12, (char *)v25.l_.a3_.t_)->data.pointer) )
      {
        v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
        v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "branch");
        materials_request[0].path = (const char *)vostok::configs::binary_config_value::operator[](
                                                    v13,
                                                    (char *)v25.l_.a3_.t_)->data.pointer;
      }
      else
      {
        materials_request[0].path = "nomaterial";
      }
      v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
      materials_request[0].id = material_class;
      v14 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "frond");
      if ( strlen((const char *)vostok::configs::binary_config_value::operator[](v14, (char *)v25.l_.a3_.t_)->data.pointer) )
      {
        v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
        v15 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "frond");
        materials_request[1].path = (const char *)vostok::configs::binary_config_value::operator[](
                                                    v15,
                                                    (char *)v25.l_.a3_.t_)->data.pointer;
      }
      else
      {
        materials_request[1].path = "nomaterial";
      }
      v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
      materials_request[1].id = material_class;
      v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "leafmesh");
      if ( strlen((const char *)vostok::configs::binary_config_value::operator[](v16, (char *)v25.l_.a3_.t_)->data.pointer) )
      {
        v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
        v17 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "leafmesh");
        materials_request[2].path = (const char *)vostok::configs::binary_config_value::operator[](
                                                    v17,
                                                    (char *)v25.l_.a3_.t_)->data.pointer;
      }
      else
      {
        materials_request[2].path = "nomaterial";
      }
      v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
      materials_request[2].id = material_class;
      v18 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "leafcard");
      if ( strlen((const char *)vostok::configs::binary_config_value::operator[](v18, (char *)v25.l_.a3_.t_)->data.pointer) )
      {
        v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
        v19 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "leafcard");
        materials_request[3].path = (const char *)vostok::configs::binary_config_value::operator[](
                                                    v19,
                                                    (char *)v25.l_.a3_.t_)->data.pointer;
      }
      else
      {
        materials_request[3].path = "nomaterial";
      }
      v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
      materials_request[3].id = material_class;
      v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      m_root,
                                                      "billboard");
      if ( strlen((const char *)vostok::configs::binary_config_value::operator[](v20, (char *)v25.l_.a3_.t_)->data.pointer) )
      {
        v25.l_.a3_.t_ = (vostok::render::speedtree_data *)"material";
        v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "billboard");
        materials_request[4].path = (const char *)vostok::configs::binary_config_value::operator[](
                                                    v21,
                                                    (char *)v25.l_.a3_.t_)->data.pointer;
      }
      else
      {
        materials_request[4].path = "nomaterial";
      }
      HIDWORD(v31) = v29;
      materials_request[4].id = material_class;
      LODWORD(v31) = vostok::render::speedtree_cook::on_model_materials_loaded;
      *(_QWORD *)&v25.f_.f_ = v31;
      v25.l_.a3_.t_ = creation_data;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        (boost::function<void __cdecl(vostok::resources::queries_result &)> *)creation_data,
        (int)&callback,
        (unsigned int)m_root,
        v25,
        v26);
      vostok::resources::query_resources(
        materials_request,
        5u,
        (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
        (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
        0,
        creation_data->m_parent_query,
        assert_on_fail_true);
      if ( callback.vtable )
      {
        if ( ((int)callback.vtable & 1) == 0 )
        {
          v22 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
          if ( v22 )
            v22(&callback.functor, &callback.functor, 2);
        }
      }
      v23 = model_config.m_object;
      v24 = &model_config.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&model_config.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v24, v23);
      vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&raw_data_ptr);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)creation_data->m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
    v4 = vostok::render::g_allocator.m_object;
    vostok::render::speedtree_data::~speedtree_data(v5, (vostok::resources::unmanaged_resource **)creation_data);
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(v4->m_reconstruction_info_actuality_tick);
    BYTE2(v4->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (char *)creation_data);
  }
}
