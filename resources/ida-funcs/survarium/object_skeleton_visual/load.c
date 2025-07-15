void __thiscall survarium::object_skeleton_visual::load(
        survarium::object_skeleton_visual *this,
        const vostok::configs::binary_config_value *t,
        char *project_resources_path,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  const vostok::configs::binary_config_value *v14; // eax
  float v15; // xmm0_4
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v17; // [esp-34h] [ebp-214h] BYREF
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *p_functor; // [esp-4h] [ebp-1E4h]
  int v19; // [esp+10h] [ebp-1D0h]
  const char *pointer; // [esp+14h] [ebp-1CCh]
  survarium::object_vegetation *v21; // [esp+18h] [ebp-1C8h] BYREF
  int v22; // [esp+1Ch] [ebp-1C4h]
  boost::detail::function::function_buffer functor; // [esp+20h] [ebp-1C0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v24; // [esp+38h] [ebp-1A8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v25; // [esp+68h] [ebp-178h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > __that; // [esp+98h] [ebp-148h] BYREF
  const char *v27[3]; // [esp+C8h] [ebp-118h] BYREF
  _BYTE v28[260]; // [esp+D4h] [ebp-10Ch] BYREF
  _BYTE v29[8]; // [esp+1D8h] [ebp-8h] BYREF

  survarium::game_object_static::load(this, t, project_resources_path, cb);
  pointer = (const char *)vostok::configs::binary_config_value::operator[](t, "lib_name")->data.pointer;
  v19 = 17;
  if ( vostok::configs::binary_config_value::value_exists(v5, (int)t, (unsigned int)"is_combined") )
  {
    v19 = (vostok::configs::binary_config_value::operator[](t, "is_combined")->data.pointer != 0) + 17;
  }
  else if ( vostok::configs::binary_config_value::value_exists(v6, (int)t, (unsigned int)"resource_id") )
  {
    v19 = (int)vostok::configs::binary_config_value::operator[](t, "resource_id")->data.pointer;
  }
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)cb,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&(&v17.l_.a3_.t_.vtable)[1]);
  *((_DWORD *)&v17.l_.boost::_bi::storage2<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1> > + 1) = survarium::object_skeleton_visual::on_model_loaded;
  v17.l_.a1_.t_ = (survarium::object_vegetation *)(unsigned __int8)1_112;
  boost::bind<void,survarium::object_sound,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sound *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (int)&__that,
    (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)this,
    *(void (__thiscall *__ptr64 *)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *))&v17.l_.a1_.t_,
    0,
    (int)(&v17.l_.a3_.t_.vtable)[1]);
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    &v25,
    &__that);
  v21 = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    &v24,
    &v25);
  p_functor = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&functor;
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>::bind_t<void,boost::_mfi::mf2<void,survarium::object_wire,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_wire *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>(
    &v17,
    &v24);
  v21 = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>>(
          v7,
          v17,
          p_functor) != 0
      ? (survarium::object_vegetation *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_skeleton_visual,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_skeleton_visual *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>>'::`2'::stored_vtable
      : 0;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v24.l_.a3_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&v25.l_.a3_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&__that.l_.a3_);
  vostok::resources::query_resource(
    pointer,
    (vostok::variant<32> *)v19,
    survarium::g_allocator,
    0,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&v21);
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)t, (unsigned int)"bind_weapon") )
    this->m_bind_weapon = (const char *)vostok::configs::binary_config_value::operator[](t, "bind_weapon")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)t, (unsigned int)"bind_as_weapon_to") )
    this->m_bind_as_weapon_to = (const char *)vostok::configs::binary_config_value::operator[](t, "bind_as_weapon_to")->data.pointer;
  v14 = vostok::configs::binary_config_value::operator[](t, "animation_timescale");
  if ( v14->type == 2 )
    v15 = *(float *)&v14->data.pointer;
  else
    v15 = (float)(int)v14->data.pointer;
  this->m_animation_timescale = v15;
  this->m_animation_cyclic = vostok::configs::binary_config_value::operator[](t, "animation_cyclic")->data.pointer != 0;
  this->m_animation_target_id = (unsigned int)vostok::configs::binary_config_value::operator[](t, "animation_target_id")->data.pointer;
  p_functor = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)vostok::configs::binary_config_value::operator[](
                                                                                                t,
                                                                                                "animation")->data.pointer;
  v27[0] = v28;
  v27[1] = v28;
  v27[2] = v29;
  v28[0] = 0;
  v29[0] = 47;
  vostok::fs_new::path_string_impl::assignf(
    v27,
    (vostok::buffer_string *)v29,
    (vostok::buffer_string *)"resources/animations/%s",
    (const char *)p_functor);
  LODWORD(v24.f_.f_) = survarium::object_skeleton_visual::on_animation_loaded;
  HIDWORD(v24.f_.f_) = 0;
  v24.l_.a1_.t_ = (survarium::object_vegetation *)this;
  v21 = (survarium::object_vegetation *)survarium::object_skeleton_visual::on_animation_loaded;
  v22 = 0;
  *(_QWORD *)&functor.obj_ptr = __PAIR64__(
                                  *((unsigned int *)&v24.l_.boost::_bi::storage2<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1> >
                                  + 1),
                                  (unsigned int)this);
  v17.l_.a3_.t_.functor.bound_memfunc_ptr.obj_ptr = &v21;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    LODWORD(v24.f_.f_) = 0;
  }
  else
  {
    v24.l_.a1_.t_ = v21;
    *((_DWORD *)&v24.l_.boost::_bi::storage2<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1> > + 1) = v22;
    *(_QWORD *)&v24.l_.a3_.t_.vtable = *(_QWORD *)&functor.obj_ptr;
    LODWORD(v24.f_.f_) = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::object_skeleton_visual,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::object_skeleton_visual *>,boost::arg<1>>>>'::`2'::stored_vtable
                       + 1;
  }
  vostok::resources::query_resource(
    v27[0],
    (vostok::variant<32> *)0x33,
    survarium::g_allocator,
    0,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v16,
    (int *)&v24);
}
