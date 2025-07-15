void __thiscall survarium::object_vegetation::load(
        survarium::object_vegetation *this,
        const vostok::configs::binary_config_value *t,
        vostok::variant<32> *project_resources_path,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *cb)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  char *v8; // edi
  vostok::variant<32> *v9; // ecx
  boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  vostok::variant<32> *v15; // ecx
  _BYTE v16[52]; // [esp-34h] [ebp-124h] BYREF
  const char *v17; // [esp+0h] [ebp-F0h]
  const char *v18; // [esp+4h] [ebp-ECh]
  unsigned int v19; // [esp+8h] [ebp-E8h]
  survarium::object_vegetation *v20; // [esp+Ch] [ebp-E4h]
  vostok::variant<32> v21; // [esp+10h] [ebp-E0h] BYREF
  unsigned int v22; // [esp+40h] [ebp-B0h] BYREF
  char v23; // [esp+48h] [ebp-A8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v24; // [esp+60h] [ebp-90h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v25; // [esp+90h] [ebp-60h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v26; // [esp+C0h] [ebp-30h] BYREF

  v4 = survarium::g_allocator;
  v20 = this;
  v5 = type_info::raw_name(&vostok::render::grass_loading_data `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0x114u, v5, v17, v18, v19);
  if ( v7 )
  {
    *((_DWORD *)v7 + 1) = v7 + 16;
    *((_DWORD *)v7 + 2) = v7 + 16;
    *((_DWORD *)v7 + 3) = v7 + 276;
    v7[16] = 0;
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  *(_DWORD *)v8 = t;
  v9 = (vostok::variant<32> *)*((_DWORD *)v8 + 1);
  if ( v9 != project_resources_path )
  {
    *((_DWORD *)v8 + 2) = v9;
    v9->m_helper_storage[0] = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v8 + 4), project_resources_path->m_helper_storage);
  }
  v21.m_helper = 0;
  v21.m_type_id = 0;
  vostok::variant<32>::destroy_previous_variable_if_needed(v9, (int)&v21);
  v21.m_type_id = vostok::detail::type_to_int<vostok::render::grass_loading_data *>::get();
  *(_DWORD *)v21.m_storage = v8;
  *(_DWORD *)v21.m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::grass_loading_data *>::`vftable';
  v21.m_helper = (vostok::detail::abstract_type_helper *)&v21;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    cb,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&v16[20]);
  *(_DWORD *)&v16[12] = survarium::object_vegetation::on_grass_loaded;
  *(_DWORD *)&v16[8] = (unsigned __int8)1_115;
  boost::bind<void,survarium::object_sound,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sound *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (int)&v26,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)v20,
    *(void (__thiscall *__ptr64 *)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *))&v16[8],
    0,
    *(boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&v16[20]);
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    &v25,
    &v26);
  v22 = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    &v24,
    &v25);
  *(_DWORD *)&v16[48] = &v23;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)v16,
    &v24);
  v22 = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>>(
          v10,
          *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)v16,
          *(boost::function1<void,vostok::sound::create_sound_propagator_params const &> **)&v16[48]) != 0
      ? (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>>'::`2'::stored_vtable
      : 0;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&v24.l_.a3_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&v25.l_.a3_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v13,
    (int *)&v26.l_.a3_);
  vostok::resources::query_resource(
    "grass",
    (vostok::variant<32> *)0x68,
    survarium::g_allocator,
    &v21,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)&v22);
  vostok::variant<32>::destroy_previous_variable_if_needed(v15, (int)&v21);
}
