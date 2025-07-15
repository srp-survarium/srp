void __thiscall vostok::network::http_client::on_content_downloaded(vostok::network::http_client *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  vostok::network::response *v3; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > f; // [esp+2Ch] [ebp-48h]
  int *_Where; // [esp+34h] [ebp-40h]
  char v7; // [esp+40h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+44h] [ebp-30h] BYREF
  boost::function1<void,char const *> v9; // [esp+4Ch] [ebp-28h] BYREF
  vostok::network::string_response *v10; // [esp+70h] [ebp-4h]

  v7 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v1, 0x78u);
  v10 = (vostok::network::string_response *)operator new(0x78u, _Where);
  if ( v10 )
  {
    f = *boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
           (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::http_client::on_content_downloaded_impl,
           (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &v9);
    boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,char const *>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
      &v9,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,char const *>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1> > >)f);
    v7 = 1;
    vostok::network::string_response::string_response(
      v10,
      vostok::network::g_allocator,
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&v9,
      this->m_client->m_result_content._M_start_of_storage._M_data);
    vostok::network::network_world::add_response(this->m_world, v3);
  }
  else
  {
    vostok::network::network_world::add_response(this->m_world, 0);
  }
  if ( (v7 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v7 & 1),
      (int *)&v9);
}
