void __userpurge survarium::game::load_cc_script(
        survarium::game *this@<ecx>,
        unsigned int a2@<eax>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> cfg,
        const vostok::variant<32> *create_renderer)
{
  int v5; // ecx
  int v6; // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v8; // [esp-10h] [ebp-90h] BYREF
  int v9; // [esp+0h] [ebp-80h]
  vostok::variant<32> ud; // [esp+8h] [ebp-78h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+38h] [ebp-48h] BYREF
  vostok::resources::creation_request requests; // [esp+58h] [ebp-28h] BYREF
  vostok::memory::reader F; // [esp+68h] [ebp-18h] BYREF
  vostok::mutable_buffer creation_buffer; // [esp+78h] [ebp-8h] BYREF

  if ( cfg.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    creation_buffer.m_size = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&creation_buffer.m_size,
      &cfg);
    *((_DWORD *)&v8.l_ + 1) = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v8.l_
    + 1,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&creation_buffer.m_size);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      (vostok::resources::pinned_ptr_base<unsigned char const > *)&requests.m_data,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)*(&v8.l_ + 1));
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&creation_buffer.m_size);
    F.m_data = (const unsigned __int8 *)requests.m_data.m_size;
    F.m_pointer = (const unsigned __int8 *)requests.m_data.m_size;
    F.m_size = requests.m_id;
    vostok::console_commands::load(&F, execution_filter_general);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&requests.m_data);
  }
  if ( (_BYTE)create_renderer )
  {
    v5 = *(_DWORD *)(a2 + 148);
    ud.m_helper = 0;
    ud.m_type_id = 0;
    v6 = *(_DWORD *)(v5 + 4);
    ud.m_type_id = (unsigned int)vostok::detail::type_to_int<vostok::render::engine::world *>::get();
    requests.m_name = (const char *)survarium::game::on_renderer_created;
    requests.m_data.m_data = 0;
    v8.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, vostok::resources::queries_result *))(unsigned int)survarium::game::on_renderer_created;
    requests.m_data.m_size = a2;
    *(_DWORD *)ud.m_storage = v6;
    *(_DWORD *)ud.m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::engine::world *>::`vftable';
    ud.m_helper = (vostok::detail::abstract_type_helper *)&ud;
    creation_buffer.m_data = (char *)&stru_95AF78;
    creation_buffer.m_size = 1;
    *(_QWORD *)&v8.l_.a1_.t_ = *(_QWORD *)&requests.m_data.m_size;
    boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
      0,
      (int)&callback,
      v6,
      v8,
      v9);
    vostok::const_buffer::const_buffer((vostok::const_buffer *)&F, &creation_buffer);
    requests.m_data.m_data = (const char *)F.m_data;
    requests.m_data.m_size = (unsigned int)F.m_pointer;
    create_renderer = &ud;
    requests.m_name = "renderer";
    requests.m_id = renderer_class;
    vostok::resources::query_create_resources(
      &requests,
      1u,
      &callback,
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      &create_renderer,
      0,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v7 )
          v7(&callback.functor, &callback.functor, 2);
      }
    }
    if ( ud.m_helper )
      ud.m_helper->destroy(ud.m_helper, ud.m_storage);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&cfg);
}
