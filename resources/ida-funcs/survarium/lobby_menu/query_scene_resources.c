void __usercall survarium::lobby_menu::query_scene_resources(survarium::lobby_menu *this@<ecx>, void *a2@<eax>)
{
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::lobby_menu,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::lobby_menu *>,boost::arg<1> > > v4; // [esp-10h] [ebp-148h]
  int v5; // [esp+0h] [ebp-138h]
  vostok::variant<32> temp_data; // [esp+10h] [ebp-128h] BYREF
  vostok::variant<32> lobby_scene_data; // [esp+40h] [ebp-F8h] BYREF
  vostok::variant<32> sound_scene_data; // [esp+70h] [ebp-C8h] BYREF
  vostok::resources::request requests[9]; // [esp+A0h] [ebp-98h] BYREF
  const vostok::variant<32> *data[10]; // [esp+E8h] [ebp-50h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+110h] [ebp-28h] BYREF
  vostok::render::scene_configuration render_configuration; // [esp+137h] [ebp-1h]

  temp_data.m_type_id = vostok::detail::type_to_int<vostok::render::scene_configuration>::get();
  temp_data.m_storage[0] = *(_BYTE *)&render_configuration & 0x80 | 0x22;
  *(_DWORD *)temp_data.m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::`vftable';
  temp_data.m_helper = (vostok::detail::abstract_type_helper *)&temp_data;
  lobby_scene_data.m_helper = 0;
  lobby_scene_data.m_type_id = 0;
  lobby_scene_data.m_type_id = vostok::detail::type_to_int<survarium::base_game_scene *>::get();
  *(_DWORD *)lobby_scene_data.m_storage = a2;
  *(_DWORD *)lobby_scene_data.m_helper_storage = &vostok::detail::concrete_type_helper<survarium::base_game_scene *>::`vftable';
  lobby_scene_data.m_helper = (vostok::detail::abstract_type_helper *)&lobby_scene_data;
  *(_QWORD *)(&callback.functor.data + 12) = 0x500000005LL;
  sound_scene_data.m_helper = 0;
  sound_scene_data.m_type_id = 0;
  sound_scene_data.m_type_id = vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::get();
  data[0] = &temp_data;
  requests[4].id = flash_movie_class;
  requests[5].id = flash_movie_class;
  requests[6].id = flash_movie_class;
  requests[7].id = flash_movie_class;
  callback.functor.vostok_pointer_size_alignment[2] = survarium::lobby_menu::on_render_scenes_ready;
  *(_QWORD *)sound_scene_data.m_storage = *(_QWORD *)(&callback.functor.data + 12);
  callback.functor.vostok_pointer_size_alignment[3] = 0;
  sound_scene_data.m_helper = (vostok::detail::abstract_type_helper *)&sound_scene_data;
  callback.functor.bound_memfunc_ptr.obj_ptr = a2;
  v4.f_.f_ = (void (__thiscall *__ptr64)(survarium::lobby_menu *, vostok::resources::queries_result *))(unsigned int)survarium::lobby_menu::on_render_scenes_ready;
  *(_DWORD *)&sound_scene_data.m_storage[8] = 2;
  *(_DWORD *)sound_scene_data.m_helper_storage = &vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params>::`vftable';
  data[1] = 0;
  data[2] = &sound_scene_data;
  data[3] = &lobby_scene_data;
  memset(&data[4], 0, 24);
  requests[0].path = (const char *)&stru_96A440.m_projection.lines[0].elements[3];
  requests[0].id = scene_class;
  requests[1].path = (const char *)&stru_96A440.m_projection.lines[1].elements[2];
  requests[1].id = scene_view_class;
  requests[2].path = "sound_scene";
  requests[2].id = sound_scene_class;
  requests[3].path = "lobby_scene";
  requests[3].id = client_game_project_class;
  requests[4].path = "resources/flash_movies/cursor.swf";
  requests[5].path = "resources/flash_movies/inventory.swf";
  requests[6].path = "resources/flash_movies/message.swf";
  requests[7].path = "resources/flash_movies/match_making.swf";
  requests[8].path = "resources/gameplay/players/default.player";
  requests[8].id = binary_config_class_impl;
  *(_QWORD *)&v4.l_.a1_.t_ = *((_QWORD *)&callback.functor.data + 2);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    (boost::function1<void,vostok::resources::queries_result &> *)&sound_scene_data,
    (int)&callback,
    0,
    v4,
    v5);
  vostok::resources::query_resources(
    requests,
    9u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    data,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&callback.functor, &callback.functor, 2);
    }
  }
  if ( sound_scene_data.m_helper )
  {
    sound_scene_data.m_helper->destroy(sound_scene_data.m_helper, sound_scene_data.m_storage);
    sound_scene_data.m_helper = 0;
  }
  if ( lobby_scene_data.m_helper )
  {
    lobby_scene_data.m_helper->destroy(lobby_scene_data.m_helper, lobby_scene_data.m_storage);
    lobby_scene_data.m_helper = 0;
  }
  if ( temp_data.m_helper )
    temp_data.m_helper->destroy(temp_data.m_helper, temp_data.m_storage);
}
