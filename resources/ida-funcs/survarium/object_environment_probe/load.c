void __thiscall survarium::object_environment_probe::load(
        survarium::object_environment_probe *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *cb)
{
  vostok::configs::binary_config_value *v4; // esi
  unsigned int pointer; // eax
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  char *v13; // edx
  char *m_begin; // ecx
  vostok::configs::binary_config_value *v15; // ecx
  const void *v16; // eax
  vostok::configs::binary_config_value *v17; // ecx
  const vostok::configs::binary_config_value *v18; // eax
  float v19; // xmm0_4
  vostok::configs::binary_config_value *v20; // ecx
  bool v21; // al
  vostok::configs::binary_config_value *v22; // ecx
  const char ***v23; // eax
  const char **v24; // esi
  vostok::configs::binary_config_value *v25; // ecx
  const char ***v26; // eax
  const char **v27; // esi
  vostok::configs::binary_config_value *v28; // ecx
  const char ***v29; // eax
  const char **v30; // esi
  vostok::configs::binary_config_value *v31; // ecx
  const char ***v32; // eax
  const char **v33; // esi
  vostok::configs::binary_config_value *v34; // ecx
  const char ***v35; // eax
  const char **v36; // esi
  const char ***v37; // eax
  const char **v38; // esi
  vostok::buffer_string *v39; // ecx
  vostok::variant<32> *v40; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v41; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v42; // ecx
  vostok::variant<32> *v43; // ecx
  vostok::variant<32> *v44; // ecx
  void (__thiscall *__ptr64 v45)(survarium::object_vegetation *, vostok::resources::queries_result *, boost::function<void __cdecl(survarium::game_object_ &)> *); // [esp-5Ch] [ebp-334h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v46; // [esp-50h] [ebp-328h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > v47; // [esp-30h] [ebp-308h] BYREF
  const char *v48; // [esp+0h] [ebp-2D8h]
  vostok::resources::request v49; // [esp+10h] [ebp-2C8h] BYREF
  __int32 v50; // [esp+18h] [ebp-2C0h]
  int v51; // [esp+1Ch] [ebp-2BCh]
  _DWORD v52[2]; // [esp+20h] [ebp-2B8h] BYREF
  char v53; // [esp+28h] [ebp-2B0h]
  char v54; // [esp+29h] [ebp-2AFh]
  char v55; // [esp+2Ah] [ebp-2AEh]
  char v56; // [esp+2Bh] [ebp-2ADh]
  char v57; // [esp+2Ch] [ebp-2ACh]
  const vostok::variant<32> *v58[2]; // [esp+30h] [ebp-2A8h] BYREF
  int v59[2]; // [esp+38h] [ebp-2A0h] BYREF
  char v60; // [esp+40h] [ebp-298h]
  char v61; // [esp+41h] [ebp-297h]
  char v62; // [esp+42h] [ebp-296h]
  char v63; // [esp+43h] [ebp-295h]
  char v64; // [esp+44h] [ebp-294h]
  vostok::render::render_texture_cook_parameters v65[2]; // [esp+58h] [ebp-280h] BYREF
  int v66; // [esp+80h] [ebp-258h]
  int v67; // [esp+84h] [ebp-254h]
  vostok::render::render_texture_cook_parameters v68[2]; // [esp+88h] [ebp-250h] BYREF
  int v69; // [esp+B0h] [ebp-228h]
  int v70; // [esp+B4h] [ebp-224h]
  vostok::fixed_string<260> v71; // [esp+B8h] [ebp-220h] BYREF
  vostok::fixed_string<260> v72; // [esp+1C8h] [ebp-110h] BYREF

  v4 = t;
  survarium::load_transform(t, &this->m_transform);
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v47.l_.a3_.t_.functor.vostok_pointer_size_alignment[5],
         (int)t,
         (unsigned int)"cubemap_resolution_index") )
  {
    pointer = (unsigned int)vostok::configs::binary_config_value::operator[](t, "cubemap_resolution_index")->data.pointer;
  }
  else
  {
    pointer = 2;
  }
  this->m_cubemap_resolution_index = pointer;
  v7 = vostok::configs::binary_config_value::operator[](t, "radius");
  if ( v7->type == 2 )
    v8 = *(float *)&v7->data.pointer;
  else
    v8 = (float)(int)v7->data.pointer;
  this->m_outer_radius = v8;
  v9 = vostok::configs::binary_config_value::operator[](t, "diffuse_multiplier");
  if ( v9->type == 2 )
    v10 = *(float *)&v9->data.pointer;
  else
    v10 = (float)(int)v9->data.pointer;
  this->m_diffuse_multiplier = v10;
  v11 = vostok::configs::binary_config_value::operator[](t, "specular_multiplier");
  if ( v11->type == 2 )
    v12 = *(float *)&v11->data.pointer;
  else
    v12 = (float)(int)v11->data.pointer;
  this->m_specular_multiplier = v12;
  this->m_enabled = vostok::configs::binary_config_value::operator[](t, "enabled")->data.pointer != 0;
  v13 = (char *)vostok::configs::binary_config_value::operator[](t, "texture")->data.pointer;
  m_begin = this->m_texture_name.m_begin;
  if ( m_begin != v13 )
  {
    this->m_texture_name.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_texture_name, v13);
  }
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)m_begin,
         (int)t,
         (unsigned int)"geometry") )
  {
    v16 = vostok::configs::binary_config_value::operator[](t, "geometry")->data.pointer;
  }
  else
  {
    v16 = 0;
  }
  this->m_geometry = (unsigned int)v16;
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)t, (unsigned int)"probe_side_width") )
  {
    v18 = vostok::configs::binary_config_value::operator[](t, "probe_side_width");
    if ( v18->type == 2 )
      v19 = *(float *)&v18->data.pointer;
    else
      v19 = (float)(int)v18->data.pointer;
  }
  else
  {
    v19 = c_anim_center;
  }
  v47.l_.a3_.t_.functor.vostok_pointer_size_alignment[5] = "smart_attenuation";
  this->m_probe_side_width = v19;
  v21 = vostok::configs::binary_config_value::value_exists(
          v17,
          (int)t,
          (unsigned int)v47.l_.a3_.t_.functor.vostok_pointer_size_alignment[5])
     && vostok::configs::binary_config_value::operator[](t, "smart_attenuation")->data.pointer != 0;
  this->m_smart_attenuation = v21;
  if ( vostok::configs::binary_config_value::value_exists(v20, (int)t, (unsigned int)"face_average_color_0") )
  {
    v23 = (const char ***)vostok::configs::binary_config_value::operator[](t, "face_average_color_0");
    v24 = *v23;
    v49.path = **v23;
    v49.id = (vostok::resources::class_id_enum)*++v24;
    v50 = (__int32)*++v24;
    v51 = (int)v24[1];
    *(vostok::resources::request *)&this->m_face_average_colors[0].x = v49;
    LODWORD(this->m_face_average_colors[0].z) = v50;
    LODWORD(this->m_face_average_colors[0].w) = v51;
    v4 = t;
  }
  if ( vostok::configs::binary_config_value::value_exists(v22, (int)v4, (unsigned int)"face_average_color_1") )
  {
    v26 = (const char ***)vostok::configs::binary_config_value::operator[](v4, "face_average_color_1");
    v27 = *v26;
    v49.path = **v26;
    v49.id = (vostok::resources::class_id_enum)*++v27;
    v50 = (__int32)*++v27;
    v51 = (int)v27[1];
    *(vostok::resources::request *)&this->m_face_average_colors[1].x = v49;
    LODWORD(this->m_face_average_colors[1].z) = v50;
    LODWORD(this->m_face_average_colors[1].w) = v51;
    v4 = t;
  }
  if ( vostok::configs::binary_config_value::value_exists(v25, (int)v4, (unsigned int)"face_average_color_2") )
  {
    v29 = (const char ***)vostok::configs::binary_config_value::operator[](v4, "face_average_color_2");
    v30 = *v29;
    v49.path = **v29;
    v49.id = (vostok::resources::class_id_enum)*++v30;
    v50 = (__int32)*++v30;
    v51 = (int)v30[1];
    *(vostok::resources::request *)&this->m_face_average_colors[2].x = v49;
    LODWORD(this->m_face_average_colors[2].z) = v50;
    LODWORD(this->m_face_average_colors[2].w) = v51;
    v4 = t;
  }
  if ( vostok::configs::binary_config_value::value_exists(v28, (int)v4, (unsigned int)"face_average_color_3") )
  {
    v32 = (const char ***)vostok::configs::binary_config_value::operator[](v4, "face_average_color_3");
    v33 = *v32;
    v49.path = **v32;
    v49.id = (vostok::resources::class_id_enum)*++v33;
    v50 = (__int32)*++v33;
    v51 = (int)v33[1];
    *(vostok::resources::request *)&this->m_face_average_colors[3].x = v49;
    LODWORD(this->m_face_average_colors[3].z) = v50;
    LODWORD(this->m_face_average_colors[3].w) = v51;
    v4 = t;
  }
  if ( vostok::configs::binary_config_value::value_exists(v31, (int)v4, (unsigned int)"face_average_color_4") )
  {
    v35 = (const char ***)vostok::configs::binary_config_value::operator[](v4, "face_average_color_4");
    v36 = *v35;
    v49.path = **v35;
    v49.id = (vostok::resources::class_id_enum)*++v36;
    v50 = (__int32)*++v36;
    v51 = (int)v36[1];
    *(vostok::resources::request *)&this->m_face_average_colors[4].x = v49;
    LODWORD(this->m_face_average_colors[4].z) = v50;
    LODWORD(this->m_face_average_colors[4].w) = v51;
    v4 = t;
  }
  if ( vostok::configs::binary_config_value::value_exists(v34, (int)v4, (unsigned int)"face_average_color_5") )
  {
    v37 = (const char ***)vostok::configs::binary_config_value::operator[](v4, "face_average_color_5");
    v38 = *v37;
    v49.path = **v37;
    v49.id = (vostok::resources::class_id_enum)*++v38;
    v50 = (__int32)*++v38;
    v51 = (int)v38[1];
    *(vostok::resources::request *)&this->m_face_average_colors[5].x = v49;
    LODWORD(this->m_face_average_colors[5].z) = v50;
    LODWORD(this->m_face_average_colors[5].w) = v51;
  }
  if ( this->m_texture_name.m_end == this->m_texture_name.m_begin )
  {
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      0,
      cb,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
  }
  else
  {
    vostok::fixed_string<260>::fixed_string<260>(&v72, &this->m_texture_name);
    vostok::fixed_string<260>::fixed_string<260>(&v71, &this->m_texture_name);
    vostok::buffer_string::appendf(&v71, v39, (vostok::buffer_string *)"_diffuse", v48);
    v52[1] = -1;
    v59[1] = -1;
    v49.path = v72.m_begin;
    v49.id = render_texture_class;
    v51 = 101;
    v50 = (__int32)v71.m_begin;
    v52[0] = 0;
    v53 = 0;
    v54 = 1;
    v55 = 1;
    v56 = 0;
    v57 = 0;
    v59[0] = 0;
    v60 = 0;
    v61 = 1;
    v62 = 1;
    v63 = 0;
    v64 = 0;
    v69 = 0;
    v70 = 0;
    vostok::variant<32>::set<vostok::render::render_texture_cook_parameters>(
      (vostok::variant<32> *)v71.m_begin,
      v68,
      v52);
    v66 = 0;
    v67 = 0;
    vostok::variant<32>::set<vostok::render::render_texture_cook_parameters>(v40, v65, v59);
    v58[0] = (const vostok::variant<32> *)v68;
    v58[1] = (const vostok::variant<32> *)v65;
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(cb, &v46);
    HIDWORD(v45) = survarium::object_environment_probe::on_textures_loaded;
    LODWORD(v45) = (unsigned __int8)1_111;
    boost::bind<void,survarium::object_sound,vostok::resources::queries_result &,boost::function<void __cdecl (survarium::game_object_ &)> &,survarium::object_sound *,boost::arg<1>,boost::function<void __cdecl (survarium::game_object_ &)>>(
      (int)&v47,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_vegetation,vostok::resources::queries_result &,boost::function<void __cdecl(survarium::game_object_ &)> &>,boost::_bi::list3<boost::_bi::value<survarium::object_vegetation *>,boost::arg<1>,boost::_bi::value<boost::function<void __cdecl(survarium::game_object_ &)> > > > *)this,
      v45,
      0,
      (int)v46.vtable);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v41,
      (int)v59,
      v47,
      (int)v48);
    vostok::resources::query_resources(&v49, 2u, survarium::g_allocator, v58, 0, assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v42, v59);
    vostok::variant<32>::destroy_previous_variable_if_needed(v43, (int)v65);
    vostok::variant<32>::destroy_previous_variable_if_needed(v44, (int)v68);
  }
}
