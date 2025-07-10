void __thiscall survarium::main_menu::query_resources(survarium::main_menu *this, void *render_configuration)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::main_menu,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::main_menu *>,boost::arg<1> > > v3; // [esp-10h] [ebp-94h]
  int v4; // [esp+0h] [ebp-84h]
  vostok::variant<32> temp_data; // [esp+10h] [ebp-74h] BYREF
  vostok::resources::request requests[2]; // [esp+40h] [ebp-44h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+50h] [ebp-34h] BYREF
  const vostok::variant<32> *data[3]; // [esp+74h] [ebp-10h] BYREF

  temp_data.m_type_id = vostok::detail::type_to_int<vostok::render::scene_configuration>::get();
  temp_data.m_helper = (vostok::detail::abstract_type_helper *)&temp_data;
  data[0] = &temp_data;
  callback.functor.vostok_pointer_size_alignment[2] = survarium::main_menu::on_resources_ready;
  callback.functor.vostok_pointer_size_alignment[3] = 0;
  v3.f_.f_ = (void (__thiscall *__ptr64)(survarium::main_menu *, vostok::resources::queries_result *))(unsigned int)survarium::main_menu::on_resources_ready;
  callback.functor.bound_memfunc_ptr.obj_ptr = render_configuration;
  temp_data.m_storage[0] = HIBYTE(render_configuration) & 0x80;
  *(_DWORD *)temp_data.m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::`vftable';
  data[1] = 0;
  data[2] = 0;
  requests[0].path = (const char *)&stru_96A440.m_projection.lines[0].elements[3];
  requests[0].id = scene_class;
  requests[1].path = (const char *)&stru_96A440.m_projection.lines[1].elements[2];
  requests[1].id = scene_view_class;
  *(_QWORD *)&v3.l_.a1_.t_ = *((_QWORD *)&callback.functor.data + 2);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    0,
    v3,
    v4);
  vostok::resources::query_resources(
    requests,
    2u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    data,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v2 )
        v2(&callback.functor, &callback.functor, 2);
    }
  }
  if ( temp_data.m_helper )
    temp_data.m_helper->destroy(temp_data.m_helper, temp_data.m_storage);
}
