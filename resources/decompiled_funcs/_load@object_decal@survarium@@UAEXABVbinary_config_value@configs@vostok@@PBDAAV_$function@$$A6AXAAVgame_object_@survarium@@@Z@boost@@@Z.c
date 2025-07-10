void __thiscall survarium::object_decal::load(
        survarium::object_decal *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function4<void,unsigned int,float,float,char const *> *cb)
{
  bool v5; // al
  bool v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // al
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  __int64 pointer; // rax
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  __int64 v15; // rax
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  __int64 v18; // rax
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  __int64 v21; // rax
  const vostok::configs::binary_config_value *v22; // eax
  float v23; // xmm0_4
  __int64 v24; // rax
  const vostok::configs::binary_config_value *v25; // eax
  float v26; // xmm0_4
  __int64 v27; // rax
  int *v28; // esi
  survarium::game_world *v29; // eax
  survarium::game_world *v30; // edi
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v31; // ecx
  void (__cdecl *v32)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__thiscall *__ptr64 v33)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *); // [esp+24h] [ebp-D4h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> v34; // [esp+38h] [ebp-C0h] BYREF
  vostok::variant<32> user_data; // [esp+58h] [ebp-A0h] BYREF
  int v36; // [esp+88h] [ebp-70h]
  vostok::resources::request result; // [esp+98h] [ebp-60h] BYREF
  vostok::variant<32> *v38; // [esp+A0h] [ebp-58h] BYREF
  int v39; // [esp+A4h] [ebp-54h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+A8h] [ebp-50h] BYREF
  _DWORD v41[2]; // [esp+C8h] [ebp-30h] BYREF
  survarium::game_world *v42; // [esp+D0h] [ebp-28h] BYREF
  _DWORD *v43; // [esp+F0h] [ebp-8h]
  int v44; // [esp+F4h] [ebp-4h]

  survarium::load_transform(t, &this->m_transform);
  v5 = !vostok::configs::binary_config_value::value_exists(t, "projection_on_static_geometry")
    || vostok::configs::binary_config_value::operator[](t, "projection_on_static_geometry")->data.pointer != 0;
  user_data.m_type_id = (unsigned int)"projection_on_skeleton_geometry";
  this->m_projection_on_static_geometry = v5;
  v6 = !vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id)
    || vostok::configs::binary_config_value::operator[](t, "projection_on_skeleton_geometry")->data.pointer != 0;
  user_data.m_type_id = (unsigned int)"projection_on_terrain_geometry";
  this->m_projection_on_skeleton_geometry = v6;
  v7 = !vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id)
    || vostok::configs::binary_config_value::operator[](t, "projection_on_terrain_geometry")->data.pointer != 0;
  user_data.m_type_id = (unsigned int)"projection_on_speedtree_geometry";
  this->m_projection_on_terrain_geometry = v7;
  v8 = !vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id)
    || vostok::configs::binary_config_value::operator[](t, "projection_on_speedtree_geometry")->data.pointer != 0;
  user_data.m_type_id = (unsigned int)"projection_on_particle_geometry";
  this->m_projection_on_speedtree_geometry = v8;
  v9 = !vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id)
    || vostok::configs::binary_config_value::operator[](t, "projection_on_particle_geometry")->data.pointer != 0;
  user_data.m_type_id = (unsigned int)"alpha_angle";
  this->m_projection_on_particle_geometry = v9;
  if ( vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id) )
  {
    v10 = vostok::configs::binary_config_value::operator[](t, "alpha_angle");
    if ( v10->type == 2 )
    {
      v11 = *(float *)&v10->data.pointer;
    }
    else
    {
      pointer = (int)v10->data.pointer;
      v39 = HIDWORD(pointer);
      v11 = (float)(int)pointer;
    }
  }
  else
  {
    v11 = -90.0;
  }
  user_data.m_type_id = (unsigned int)"clip_angle";
  this->m_alpha_angle = v11;
  if ( vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id) )
  {
    v13 = vostok::configs::binary_config_value::operator[](t, "clip_angle");
    if ( v13->type == 2 )
    {
      v14 = *(float *)&v13->data.pointer;
    }
    else
    {
      v15 = (int)v13->data.pointer;
      v39 = HIDWORD(v15);
      v14 = (float)(int)v15;
    }
  }
  else
  {
    v14 = -90.0;
  }
  user_data.m_type_id = (unsigned int)"decal_far_distance";
  this->m_clip_angle = v14;
  if ( vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id) )
  {
    v16 = vostok::configs::binary_config_value::operator[](t, "decal_far_distance");
    if ( v16->type == 2 )
    {
      v17 = *(float *)&v16->data.pointer;
    }
    else
    {
      v18 = (int)v16->data.pointer;
      v39 = HIDWORD(v18);
      v17 = (float)(int)v18;
    }
  }
  else
  {
    v17 = *(float *)&clear_value;
  }
  user_data.m_type_id = (unsigned int)"decal_width";
  this->m_decal_far_distance = v17;
  if ( vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id) )
  {
    v19 = vostok::configs::binary_config_value::operator[](t, "decal_width");
    if ( v19->type == 2 )
    {
      v20 = *(float *)&v19->data.pointer;
    }
    else
    {
      v21 = (int)v19->data.pointer;
      v39 = HIDWORD(v21);
      v20 = (float)(int)v21;
    }
  }
  else
  {
    v20 = *(float *)&clear_value;
  }
  user_data.m_type_id = (unsigned int)"decal_height";
  this->m_decal_width = v20;
  if ( vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id) )
  {
    v22 = vostok::configs::binary_config_value::operator[](t, "decal_height");
    if ( v22->type == 2 )
    {
      v23 = *(float *)&v22->data.pointer;
    }
    else
    {
      v24 = (int)v22->data.pointer;
      v39 = HIDWORD(v24);
      v23 = (float)(int)v24;
    }
  }
  else
  {
    v23 = *(float *)&clear_value;
  }
  user_data.m_type_id = (unsigned int)"draw_priority";
  this->m_decal_height = v23;
  if ( vostok::configs::binary_config_value::value_exists(t, (char *)user_data.m_type_id) )
  {
    v25 = vostok::configs::binary_config_value::operator[](t, "draw_priority");
    if ( v25->type == 2 )
    {
      v26 = *(float *)&v25->data.pointer;
    }
    else
    {
      v27 = (int)v25->data.pointer;
      v39 = HIDWORD(v27);
      v26 = (float)(int)v27;
    }
  }
  else
  {
    v26 = 0.0;
  }
  user_data.m_type_id = (unsigned int)"decal_material";
  this->m_draw_priority = v26;
  v38 = (vostok::variant<32> *)vostok::configs::binary_config_value::operator[](t, (char *)user_data.m_type_id)->data.pointer;
  v28 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          0x10u);
  if ( v28 )
  {
    vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
      (vostok::render::material_effects_instance_cook_data *)v28,
      decal_vertex_input_type,
      0,
      0,
      cull_mode_back);
    v30 = v29;
  }
  else
  {
    v30 = 0;
  }
  v44 = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
  v42 = v30;
  v41[0] = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
  v43 = v41;
  result.path = (const char *)&user_data;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(cb, (int)&v34);
  HIDWORD(v33) = (unsigned __int8)1_134;
  LODWORD(v33) = this;
  boost::bind<void,survarium::object_sky,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sky *,boost::arg<1>,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl (survarium::game_object_ &)>>(
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::object_sky,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list4<boost::_bi::value<survarium::object_sky *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)result.path,
    v33,
    v30,
    (void (__thiscall *__ptr64)(survarium::game_world *, vostok::resources::queries_result *, unsigned int, const boost::function<void __cdecl(vostok::resources::queries_result &)> *))(unsigned int)survarium::object_decal::material_ready,
    v34);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v31,
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::object_decal,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list4<boost::_bi::value<survarium::object_decal *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > >)user_data,
    v36);
  result.path = (const char *)v38;
  v38 = (vostok::variant<32> *)v41;
  result.id = material_effects_instance_class;
  vostok::resources::query_resources(
    &result,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&v38,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v32 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v32 )
        v32(&callback.functor, &callback.functor, 2);
    }
  }
  if ( v43 )
    (*(void (__thiscall **)(_DWORD *, survarium::game_world **))(*v43 + 4))(v43, &v42);
}
