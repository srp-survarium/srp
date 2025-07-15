void __thiscall survarium::game_options::initialize(survarium::game_options *this, survarium::game_options *thisa)
{
  survarium::options_enum v2; // esi
  survarium::options_tab **m_options; // edi
  int v4; // ebp
  int *v5; // eax
  survarium::options_tab *v6; // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-40h] BYREF
  __int64 v9; // [esp+30h] [ebp-20h]
  __int64 v10; // [esp+38h] [ebp-18h]
  vostok::resources::request requests[2]; // [esp+40h] [ebp-10h] BYREF

  v2 = gameplay_options_type;
  m_options = thisa->m_options;
  v4 = 4;
  do
  {
    v5 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
           0x14u);
    if ( v5 )
      survarium::options_tab::options_tab(thisa->m_game, v2, (survarium::options_tab *)v5, &thisa->m_options_ui);
    else
      v6 = 0;
    *m_options = v6;
    ++v2;
    ++m_options;
    --v4;
  }
  while ( v4 );
  requests[0].id = flash_movie_class;
  requests[1].id = flash_movie_class;
  (&callback.vtable)[1] = 0;
  v9 = (unsigned int)survarium::game_options::on_resources_ready;
  callback.functor.obj_ptr = thisa;
  requests[0].path = "resources/flash_movies/main_menu.swf";
  requests[1].path = "resources/flash_movies/cursor.swf";
  v10 = *(_QWORD *)&callback.functor.obj_ptr;
  if ( survarium::generate_shaders_world::is_loading() )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = v9;
    *((_QWORD *)&callback.functor.data + 1) = v10;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_options,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game_options *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_resources(
    requests,
    2u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    0,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v7 )
      v7(&callback.functor, &callback.functor, 2);
  }
}
