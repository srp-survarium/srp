void __thiscall vostok::physics::collision_shape_cook::translate_query(
        vostok::physics::collision_shape_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *requested_path; // eax
  vostok::fixed_string<260> *v4; // ecx
  int v5; // eax
  unsigned int v6; // esi
  vostok::memory::base_allocator *v7; // ebx
  char *v8; // eax
  int v9; // eax
  vostok::fs_new::virtual_path_string *v10; // ecx
  float v11; // xmm0_4
  unsigned int v12; // ebx
  vostok::fs_new::path_string_impl *v13; // eax
  const vostok::fixed_string<260> *v14; // edi
  unsigned int v15; // eax
  vostok::strings::detail::tuples *v16; // ecx
  void *v17; // esp
  vostok::strings::detail::tuples *v18; // ecx
  vostok::buffer_string *v19; // ecx
  unsigned int v20; // eax
  char *v21; // ecx
  vostok::strings::detail::tuples *v22; // ecx
  vostok::strings::detail::tuples *v23; // ecx
  void *v24; // esp
  vostok::strings::detail::tuples *v25; // ecx
  vostok::strings::detail::tuples *v26; // ecx
  vostok::strings::detail::tuples *v27; // ecx
  void *v28; // esp
  vostok::strings::detail::tuples *v29; // ecx
  vostok::strings::detail::tuples *v30; // ecx
  vostok::strings::detail::tuples *v31; // ecx
  void *v32; // esp
  vostok::strings::detail::tuples *v33; // ecx
  bool v34; // zf
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v35; // ecx
  unsigned int v36[3]; // [esp+0h] [ebp-364h] BYREF
  char v37[276]; // [esp+Ch] [ebp-358h] BYREF
  vostok::fixed_string<260> v38; // [esp+120h] [ebp-244h] BYREF
  char v39; // [esp+230h] [ebp-134h]
  vostok::fs_new::path_string_impl str1; // [esp+234h] [ebp-130h] BYREF
  __int64 v41; // [esp+348h] [ebp-1Ch]
  unsigned int v42; // [esp+350h] [ebp-14h]
  vostok::resources::request requests; // [esp+354h] [ebp-10h] BYREF
  char *m_begin; // [esp+35Ch] [ebp-8h]
  int v45; // [esp+360h] [ebp-4h]
  unsigned int *v46; // [esp+364h] [ebp+0h]
  int v47; // [esp+368h] [ebp+4h]
  vostok::particle::particle_action *v48; // [esp+36Ch] [ebp+8h]
  int v49; // [esp+370h] [ebp+Ch]
  unsigned int *v50; // [esp+374h] [ebp+10h]
  int v51; // [esp+378h] [ebp+14h]
  const char *v52; // [esp+37Ch] [ebp+18h]
  int v53; // [esp+380h] [ebp+1Ch]
  vostok::strings::detail::tuples v54; // [esp+384h] [ebp+20h] BYREF
  void (__thiscall *v55)(vostok::physics::collision_shape_cook *, vostok::resources::queries_result *, vostok::physics::collision_shape_cook::cook_data *); // [esp+3B8h] [ebp+54h]
  vostok::physics::collision_shape_cook *v56; // [esp+3BCh] [ebp+58h]
  unsigned int v57; // [esp+3C0h] [ebp+5Ch]
  vostok::physics::collision_shape_cook *v58; // [esp+3C4h] [ebp+60h]
  const char *v59; // [esp+3C8h] [ebp+64h] BYREF
  vostok::particle::particle_action *v60; // [esp+3CCh] [ebp+68h] BYREF
  unsigned int *v61; // [esp+3D0h] [ebp+6Ch] BYREF

  v58 = this;
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fixed_string<260>::fixed_string<260>(v4, &str1.m_string, requested_path);
  str1.m_separator = 47;
  strstr((unsigned __int8 *)str1.m_string.m_begin, "#[");
  if ( v5 )
    v6 = v5 - (unsigned int)str1.m_string.m_begin;
  else
    v6 = -1;
  v7 = vostok::physics::g_allocator;
  v8 = type_info::raw_name(&vostok::physics::collision_shape_cook::cook_data `RTTI Type Descriptor');
  v9 = (int)v7->call_malloc(
              v7,
              296u,
              v8,
              "vostok::physics::collision_shape_cook::translate_query",
              ".\\collision_shape_cook.cpp",
              46u);
  v11 = s_bm_current_air_resistance;
  v12 = v9;
  if ( v9 )
  {
    vostok::fs_new::virtual_path_string::virtual_path_string(v10, v9 + 4);
    v11 = s_bm_current_air_resistance;
    *(float *)(v12 + 280) = s_bm_current_air_resistance;
    *(float *)(v12 + 284) = v11;
    *(float *)(v12 + 288) = v11;
    *(_BYTE *)(v12 + 292) = 1;
  }
  else
  {
    v12 = 0;
  }
  *(_DWORD *)v12 = parent;
  *(_BYTE *)(v12 + 292) = this->m_fill_gmtl;
  if ( v6 == -1 )
  {
    v14 = (const vostok::fixed_string<260> *)(v12 + 4);
    if ( (vostok::fs_new::path_string_impl *)(v12 + 4) != &str1 )
    {
      vostok::buffer_string::operator=(&str1.m_string, (vostok::buffer_string *)(v12 + 4));
      v11 = s_bm_current_air_resistance;
    }
    v15 = v12 + 280;
    *(float *)(v12 + 280) = v11;
    *(float *)(v12 + 284) = v11;
  }
  else
  {
    v13 = vostok::fs_new::path_string_impl::substr(0, (int)v37, &str1, v6);
    v14 = (const vostok::fixed_string<260> *)(v12 + 4);
    vostok::fixed_string<260>::operator=(&v13->m_string, (const vostok::fixed_string<260> *)(v12 + 4));
    sscanf_s(&str1.m_string.m_begin[v6], "#[%f][%f][%f]", &v60, &v61, &v59);
    v15 = v12 + 280;
    *(_DWORD *)(v12 + 280) = v60;
    *(_DWORD *)(v12 + 284) = v61;
    v11 = *(float *)&v59;
  }
  *(float *)(v15 + 8) = v11;
  vostok::strings::detail::tuples::tuples(
    (vostok::strings::detail::tuples *)v10,
    &v54,
    v14->m_begin,
    "/exported_primitives");
  v17 = alloca(vostok::strings::detail::tuples::size(v16, (unsigned int *)&v54));
  v59 = (const char *)v36;
  vostok::strings::detail::tuples::concat(v18, (int)&v54, (char *)v36);
  vostok::fixed_string<260>::fixed_string<260>(&v38, v14);
  v39 = 47;
  v20 = vostok::buffer_string::find(v19, (unsigned __int8 **)&v38, ".model", v36[0]);
  v21 = &v38.m_begin[strlen(".model") + v20];
  v38.m_end = v21;
  *v21 = 0;
  vostok::buffer_string::append((vostok::buffer_string *)v21, (int)&v38, "/settings");
  vostok::strings::detail::tuples::tuples(v22, &v54, v14->m_begin, "/vertices");
  v24 = alloca(vostok::strings::detail::tuples::size(v23, (unsigned int *)&v54));
  v61 = v36;
  vostok::strings::detail::tuples::concat(v25, (int)&v54, (char *)v36);
  vostok::strings::detail::tuples::tuples(v26, &v54, v14->m_begin, "/indices");
  v28 = alloca(vostok::strings::detail::tuples::size(v27, (unsigned int *)&v54));
  v60 = (vostok::particle::particle_action *)v36;
  vostok::strings::detail::tuples::concat(v29, (int)&v54, (char *)v36);
  vostok::strings::detail::tuples::tuples(v30, &v54, v14->m_begin, "/face_data");
  v32 = alloca(vostok::strings::detail::tuples::size(v31, (unsigned int *)&v54));
  vostok::strings::detail::tuples::concat(v33, (int)&v54, (char *)v36);
  requests.path = v59;
  requests.id = binary_config_class_impl;
  v45 = 32;
  m_begin = v38.m_begin;
  v46 = v61;
  v47 = 3;
  v48 = v60;
  v49 = 3;
  v50 = v36;
  v51 = 3;
  v34 = *(_BYTE *)(v12 + 292) == 0;
  v52 = "game_material_manager";
  if ( v34 )
    v52 = "-";
  v53 = *(_BYTE *)(v12 + 292) != 0 ? 0x52 : 0;
  v56 = v58;
  v55 = vostok::physics::collision_shape_cook::on_collision_sources_loaded;
  v57 = v12;
  LODWORD(v41) = vostok::physics::collision_shape_cook::on_collision_sources_loaded;
  HIDWORD(v41) = v58;
  v42 = v12;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v60) )
  {
    v54.m_strings[2].second = 0;
  }
  else
  {
    *(_QWORD *)&v54.m_strings[3].second = v41;
    v54.m_strings[4].second = v42;
    v54.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::physics::collision_shape_cook,vostok::resources::queries_result &,vostok::physics::collision_shape_cook::cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::physics::collision_shape_cook *>,boost::arg<1>,boost::_bi::value<vostok::physics::collision_shape_cook::cook_data *>>>>'::`2'::stored_vtable
                            + 1;
  }
  vostok::resources::query_resources(
    &requests,
    6u,
    vostok::physics::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v35,
    (int *)&v54.m_strings[2].second);
}
