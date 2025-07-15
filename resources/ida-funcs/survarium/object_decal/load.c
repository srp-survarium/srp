void __thiscall survarium::object_decal::load(
        survarium::object_decal *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *cb)
{
  vostok::configs::binary_config_value *v5; // ecx
  bool v6; // al
  vostok::configs::binary_config_value *v7; // ecx
  bool v8; // al
  vostok::configs::binary_config_value *v9; // ecx
  bool v10; // al
  vostok::configs::binary_config_value *v11; // ecx
  bool v12; // al
  vostok::configs::binary_config_value *v13; // ecx
  const vostok::configs::binary_config_value *v14; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v16; // ecx
  const vostok::configs::binary_config_value *v17; // eax
  float v18; // xmm0_4
  vostok::configs::binary_config_value *v19; // ecx
  const vostok::configs::binary_config_value *v20; // eax
  float v21; // xmm0_4
  vostok::configs::binary_config_value *v22; // ecx
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  vostok::configs::binary_config_value *v25; // ecx
  const vostok::configs::binary_config_value *v26; // eax
  float v27; // xmm0_4
  const vostok::configs::binary_config_value *v28; // eax
  float v29; // xmm0_4
  vostok::variant<32> *v30; // ecx
  vostok::render::material_effects_instance_cook_data *v31; // eax
  boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *v32; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v33; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v34; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v35; // ecx
  vostok::fixed_string<260> *v36; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v37; // ecx
  vostok::variant<32> *v38; // ecx
  _BYTE v39[52]; // [esp-34h] [ebp-23Ch] BYREF
  const char *v40; // [esp+0h] [ebp-208h]
  const char *v41; // [esp+4h] [ebp-204h]
  unsigned int v42; // [esp+8h] [ebp-200h]
  vostok::render::material_effects_instance_cook_data *v43; // [esp+10h] [ebp-1F8h] BYREF
  char *v44; // [esp+14h] [ebp-1F4h]
  unsigned int v45; // [esp+18h] [ebp-1F0h] BYREF
  boost::detail::function::function_buffer functor; // [esp+20h] [ebp-1E8h] BYREF
  vostok::variant<32> v47; // [esp+38h] [ebp-1D0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > v48; // [esp+68h] [ebp-1A0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > __that; // [esp+98h] [ebp-170h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > v50; // [esp+C8h] [ebp-140h] BYREF
  vostok::buffer_string v51[22]; // [esp+F8h] [ebp-110h] BYREF

  survarium::load_transform(t, &this->m_transform);
  v6 = !vostok::configs::binary_config_value::value_exists(
          *(vostok::configs::binary_config_value **)&v39[48],
          (int)t,
          (unsigned int)"projection_on_static_geometry")
    || vostok::configs::binary_config_value::operator[](t, "projection_on_static_geometry")->data.pointer != 0;
  this->m_projection_on_static_geometry = v6;
  v8 = !vostok::configs::binary_config_value::value_exists(v5, (int)t, (unsigned int)"projection_on_skeleton_geometry")
    || vostok::configs::binary_config_value::operator[](t, "projection_on_skeleton_geometry")->data.pointer != 0;
  this->m_projection_on_skeleton_geometry = v8;
  v10 = !vostok::configs::binary_config_value::value_exists(v7, (int)t, (unsigned int)"projection_on_terrain_geometry")
     || vostok::configs::binary_config_value::operator[](t, "projection_on_terrain_geometry")->data.pointer != 0;
  this->m_projection_on_terrain_geometry = v10;
  v12 = !vostok::configs::binary_config_value::value_exists(v9, (int)t, (unsigned int)"projection_on_particle_geometry")
     || vostok::configs::binary_config_value::operator[](t, "projection_on_particle_geometry")->data.pointer != 0;
  this->m_projection_on_particle_geometry = v12;
  if ( vostok::configs::binary_config_value::value_exists(v11, (int)t, (unsigned int)"alpha_angle") )
  {
    v14 = vostok::configs::binary_config_value::operator[](t, "alpha_angle");
    if ( v14->type == 2 )
      pointer = *(float *)&v14->data.pointer;
    else
      pointer = (float)(int)v14->data.pointer;
  }
  else
  {
    pointer = FLOAT_N90_0;
  }
  *(_DWORD *)&v39[48] = "clip_angle";
  this->m_alpha_angle = pointer;
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)t, *(unsigned int *)&v39[48]) )
  {
    v17 = vostok::configs::binary_config_value::operator[](t, "clip_angle");
    if ( v17->type == 2 )
      v18 = *(float *)&v17->data.pointer;
    else
      v18 = (float)(int)v17->data.pointer;
  }
  else
  {
    v18 = FLOAT_N90_0;
  }
  *(_DWORD *)&v39[48] = "decal_far_distance";
  this->m_clip_angle = v18;
  if ( vostok::configs::binary_config_value::value_exists(v16, (int)t, *(unsigned int *)&v39[48]) )
  {
    v20 = vostok::configs::binary_config_value::operator[](t, "decal_far_distance");
    if ( v20->type == 2 )
      v21 = *(float *)&v20->data.pointer;
    else
      v21 = (float)(int)v20->data.pointer;
  }
  else
  {
    v21 = s_bm_current_air_resistance;
  }
  *(_DWORD *)&v39[48] = "decal_width";
  this->m_decal_far_distance = v21;
  if ( vostok::configs::binary_config_value::value_exists(v19, (int)t, *(unsigned int *)&v39[48]) )
  {
    v23 = vostok::configs::binary_config_value::operator[](t, "decal_width");
    if ( v23->type == 2 )
      v24 = *(float *)&v23->data.pointer;
    else
      v24 = (float)(int)v23->data.pointer;
  }
  else
  {
    v24 = s_bm_current_air_resistance;
  }
  *(_DWORD *)&v39[48] = "decal_height";
  this->m_decal_width = v24;
  if ( vostok::configs::binary_config_value::value_exists(v22, (int)t, *(unsigned int *)&v39[48]) )
  {
    v26 = vostok::configs::binary_config_value::operator[](t, "decal_height");
    if ( v26->type == 2 )
      v27 = *(float *)&v26->data.pointer;
    else
      v27 = (float)(int)v26->data.pointer;
  }
  else
  {
    v27 = s_bm_current_air_resistance;
  }
  *(_DWORD *)&v39[48] = "draw_priority";
  this->m_decal_height = v27;
  if ( vostok::configs::binary_config_value::value_exists(v25, (int)t, *(unsigned int *)&v39[48]) )
  {
    v28 = vostok::configs::binary_config_value::operator[](t, "draw_priority");
    if ( v28->type == 2 )
      v29 = *(float *)&v28->data.pointer;
    else
      v29 = (float)(int)v28->data.pointer;
  }
  else
  {
    v29 = 0.0;
  }
  this->m_draw_priority = v29;
  v44 = (char *)vostok::configs::binary_config_value::operator[](t, "decal_material")->data.pointer;
  v43 = (vostok::render::material_effects_instance_cook_data *)vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::doug_lea_allocator>(
                                                                 survarium::g_allocator,
                                                                 v40,
                                                                 v41,
                                                                 v42);
  if ( v43 )
  {
    *(_DWORD *)&v39[48] = 0;
    *(_DWORD *)&v39[44] = v30;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v39[44],
      0);
    vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
      decal_vertex_input_type,
      v43,
      *(vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v39[44],
      v39[48],
      (vostok::render::enum_cull_mode)v40);
    v43 = v31;
  }
  else
  {
    v43 = 0;
  }
  v47.m_helper = 0;
  v47.m_type_id = 0;
  vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(v30, &v47, &v43);
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    cb,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&v39[20]);
  *(_DWORD *)&v39[8] = v43;
  *(_DWORD *)&v39[4] = (unsigned __int8)1_110;
  boost::bind<void,survarium::object_decal,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_decal *,boost::arg<1>,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (int)&__that,
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > *)this,
    *(void (__thiscall *__ptr64 *)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *))&v39[4],
    (survarium::game_world *)survarium::object_decal::material_ready,
    0,
    *(boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&v39[20]);
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>(
    &v48,
    &__that);
  v45 = 0;
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>(
    &v50,
    &v48);
  *(_DWORD *)&v39[48] = &functor;
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > *)v39,
    &v50);
  v45 = boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl (vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (vostok::resources::queries_result &)>>>>>(
          v32,
          *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::game_world,vostok::resources::queries_result &,unsigned int,boost::function<void __cdecl(vostok::resources::queries_result &)> const &>,boost::_bi::list4<boost::_bi::value<survarium::game_world *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(vostok::resources::queries_result &)> > > > *)v39,
          *(boost::function1<void,vostok::sound::create_sound_propagator_params const &> **)&v39[48]) != 0
      ? (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::object_decal,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)> &>,boost::_bi::list4<boost::_bi::value<survarium::object_decal *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<boost::function<void __cdecl (survarium::game_object_ &)>>>>>'::`2'::stored_vtable
      : 0;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v33,
    (int *)&v50.l_.a4_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v34,
    (int *)&v48.l_.a4_);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v35,
    (int *)&__that.l_.a4_);
  vostok::fixed_string<260>::fixed_string<260>(v36, v51, v44);
  vostok::resources::query_resource(
    v51[0].m_begin,
    (vostok::variant<32> *)0xF,
    survarium::g_allocator,
    &v47,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v37,
    (int *)&v45);
  vostok::variant<32>::destroy_previous_variable_if_needed(v38, (int)&v47);
}
