void __thiscall survarium::object_particle_visual::load(
        survarium::object_particle_visual *this,
        const vostok::configs::binary_config_value *t,
        char *project_resources_path,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  const char *pointer; // ebx
  boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v11; // [esp-34h] [ebp-F4h] BYREF
  boost::detail::function::function_buffer *p_functor; // [esp-4h] [ebp-C4h]
  unsigned int v13; // [esp+10h] [ebp-B0h] BYREF
  boost::detail::function::function_buffer functor; // [esp+18h] [ebp-A8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v15; // [esp+30h] [ebp-90h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v16; // [esp+60h] [ebp-60h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > __that; // [esp+90h] [ebp-30h] BYREF

  survarium::game_object_static::load(this, t, project_resources_path, cb);
  pointer = (const char *)vostok::configs::binary_config_value::operator[](t, "lib_name")->data.pointer;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)cb,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&(&v11.l_.a3_.t_.vtable)[1]);
  *((_DWORD *)&v11.l_.boost::_bi::storage2<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1> > + 1) = survarium::object_particle_visual::on_visual_ready;
  v11.l_.a1_.t_ = (survarium::object_vegetation *)(unsigned __int8)1_112;
  boost::bind<void,survarium::object_sound,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sound *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (int)&__that,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)this,
    *(void (__thiscall *__ptr64 *)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *))&v11.l_.a1_.t_,
    0,
    (int)(&v11.l_.a3_.t_.vtable)[1]);
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    &v16,
    &__that);
  v13 = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    &v15,
    &v16);
  p_functor = &functor;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    &v11,
    &v15);
  v13 = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>>(
          v6,
          v11,
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)p_functor) != 0
      ? (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_particle_visual,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_particle_visual *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>>'::`2'::stored_vtable
      : 0;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v15.l_.a3_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v16.l_.a3_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&__that.l_.a3_);
  vostok::resources::query_resource(
    pointer,
    (vostok::variant<32> *)0x3E,
    survarium::g_allocator,
    0,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&v13);
}
