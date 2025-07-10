void __thiscall vostok::render::skeleton_combined_model_instance_cook::translate_query(
        vostok::render::skeleton_combined_model_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  vostok::render::skeleton_combined_cook_data *v3; // ebx
  char *m_requery_path; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v6; // [esp+178h] [ebp-90h]
  vostok::render::skeleton_combined_cook_data *out_value; // [esp+18Ch] [ebp-7Ch] BYREF
  vostok::variant<32> *v8; // [esp+190h] [ebp-78h]
  vostok::variant<32> *user_data[5]; // [esp+194h] [ebp-74h] BYREF
  vostok::resources::request requests; // [esp+1A8h] [ebp-60h] BYREF
  const char *m_begin; // [esp+1B0h] [ebp-58h]
  int v12; // [esp+1B4h] [ebp-54h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+1B8h] [ebp-50h] BYREF
  _DWORD v14[2]; // [esp+1D8h] [ebp-30h] BYREF
  _DWORD v15[8]; // [esp+1E0h] [ebp-28h] BYREF
  _DWORD *v16; // [esp+200h] [ebp-8h]
  int v17; // [esp+204h] [ebp-4h]

  m_user_data = parent->m_user_data;
  v3 = 0;
  v8 = (vostok::variant<32> *)this;
  v16 = 0;
  v17 = 0;
  out_value = 0;
  if ( m_user_data )
  {
    vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>(
      (vostok::variant<32> *)this,
      (int)m_user_data,
      &out_value);
    if ( v16 )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD *))(*v16 + 4))(v16, v15);
      v16 = 0;
    }
    v3 = out_value;
  }
  v17 = vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::get();
  v16 = v14;
  m_requery_path = parent->m_requery_path;
  v15[0] = v3;
  v14[0] = &vostok::detail::concrete_type_helper<vostok::render::skeleton_combined_cook_data *>::`vftable';
  user_data[0] = (vostok::variant<32> *)v14;
  user_data[1] = 0;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  requests.path = m_requery_path;
  requests.id = skeleton_combined_render_model_instance_class;
  if ( v3 )
    m_begin = v3->skeleton_name.m_string.m_begin;
  else
    m_begin = "resources/animations/skeletons/scavengers_01";
  user_data[3] = v8;
  user_data[2] = (vostok::variant<32> *)vostok::render::skeleton_combined_model_instance_cook::on_resources_loaded;
  v6.f_.f_ = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *))v8;
  v12 = 56;
  callback.vtable = 0;
  v6.l_.a1_.t_ = (survarium::animated_model_instance_cook *)parent;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &callback.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::render::skeleton_combined_model_instance_cook::on_resources_loaded,
         v6) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::skeleton_combined_model_instance_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::render::skeleton_combined_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::resources::query_resources(
    &requests,
    2u,
    &callback,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    (const vostok::variant<32> **)user_data,
    parent,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&callback.functor, &callback.functor, 2);
    }
  }
  if ( v16 )
    (*(void (__thiscall **)(_DWORD *, _DWORD *))(*v16 + 4))(v16, v15);
}
