void __thiscall survarium::login_menu::query_resources(survarium::login_menu *this, void *render_configuration)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::login_menu,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::login_menu *>,boost::arg<1> > > v3; // [esp-10h] [ebp-A4h]
  int v4; // [esp+0h] [ebp-94h]
  vostok::variant<32> temp_data; // [esp+10h] [ebp-84h] BYREF
  vostok::resources::request requests[4]; // [esp+40h] [ebp-54h] BYREF
  const vostok::variant<32> *data[4]; // [esp+60h] [ebp-34h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+70h] [ebp-24h] BYREF

  temp_data.m_type_id = vostok::detail::type_to_int<vostok::render::scene_configuration>::get();
  temp_data.m_helper = (vostok::detail::abstract_type_helper *)&temp_data;
  requests[2].id = flash_movie_class;
  requests[3].id = flash_movie_class;
  data[0] = &temp_data;
  callback.functor.vostok_pointer_size_alignment[2] = survarium::login_menu::on_resources_ready;
  callback.functor.vostok_pointer_size_alignment[3] = 0;
  v3.f_.f_ = (void (__thiscall *__ptr64)(survarium::login_menu *, vostok::resources::queries_result *))(unsigned int)survarium::login_menu::on_resources_ready;
  callback.functor.bound_memfunc_ptr.obj_ptr = render_configuration;
  temp_data.m_storage[0] = HIBYTE(render_configuration) & 0x80;
  *(_DWORD *)temp_data.m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::`vftable';
  memset(&data[1], 0, 12);
  requests[0].path = (const char *)&stru_96A440.m_projection.lines[0].elements[3];
  requests[0].id = scene_class;
  requests[1].path = (const char *)&stru_96A440.m_projection.lines[1].elements[2];
  requests[1].id = scene_view_class;
  requests[2].path = "resources/flash_movies/login_menu.swf";
  requests[3].path = "resources/flash_movies/cursor.swf";
  *(_QWORD *)&v3.l_.a1_.t_ = *((_QWORD *)&callback.functor.data + 2);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    0,
    v3,
    v4);
  vostok::resources::query_resources(
    requests,
    4u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
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
