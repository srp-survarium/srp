void __thiscall vostok::physics::collision_shape_cook::translate_query(
        vostok::physics::collision_shape_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  int v3; // eax
  int v4; // esi
  vostok::physics::collision_shape_cook::cook_data *v5; // eax
  vostok::fs_new::path_string_impl *m_buffer; // ecx
  vostok::physics::collision_shape_cook::cook_data *v7; // edi
  vostok::fs_new::virtual_path_string *v8; // eax
  vostok::fs_new::virtual_path_string *p_model_path; // ebx
  boost::_bi::value<survarium::animated_model_instance *> *v10; // xmm0_4
  vostok::strings::detail::tuples *v11; // ecx
  void *v12; // esp
  vostok::strings::detail::tuples *v13; // ecx
  char *m_begin; // ecx
  unsigned int v15; // esi
  int v16; // eax
  int v17; // esi
  vostok::strings::detail::tuples *v18; // ecx
  void *v19; // esp
  vostok::strings::detail::tuples *v20; // ecx
  vostok::strings::detail::tuples *v21; // ecx
  void *v22; // esp
  vostok::strings::detail::tuples *v23; // ecx
  vostok::strings::detail::tuples *v24; // ecx
  void *v25; // esp
  vostok::strings::detail::tuples *v26; // ecx
  void (__cdecl *v27)(unsigned int *, unsigned int *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v28; // [esp-8h] [ebp-35Ch] BYREF
  unsigned int v29; // [esp+4h] [ebp-350h]
  char v30[276]; // [esp+Ch] [ebp-348h] BYREF
  vostok::fs_new::virtual_path_string req_path; // [esp+120h] [ebp-234h] BYREF
  vostok::fs_new::virtual_path_string model_config_path; // [esp+234h] [ebp-120h] BYREF
  void (__userpurge *v33)(vostok::physics::collision_shape_cook *@<ecx>, float@<xmm4>, vostok::resources::queries_result *, vostok::physics::collision_shape_cook::cook_data *); // [esp+348h] [ebp-Ch]
  void (__thiscall *v34)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *); // [esp+34Ch] [ebp-8h]
  vostok::resources::request requests[5]; // [esp+354h] [ebp+0h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+37Ch] [ebp+28h] BYREF
  void (__thiscall *v37)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *); // [esp+3B0h] [ebp+5Ch]
  boost::_bi::value<survarium::animated_model_instance *> *sz; // [esp+3B4h] [ebp+60h] BYREF
  unsigned int found; // [esp+3B8h] [ebp+64h]
  boost::_bi::value<survarium::animated_model_instance *> *sy; // [esp+3BCh] [ebp+68h] BYREF
  boost::_bi::value<survarium::animated_model_instance *> *sx; // [esp+3C0h] [ebp+6Ch] BYREF
  vostok::physics::collision_shape_cook::cook_data *cd; // [esp+3C4h] [ebp+70h] BYREF

  m_requery_path = parent->m_requery_path;
  v37 = (void (__thiscall *)(survarium::animated_model_instance_cook *, vostok::resources::queries_result *, survarium::animated_model_instance *))this;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  cd = (vostok::physics::collision_shape_cook::cook_data *)m_requery_path;
  vostok::fs_new::virtual_path_string::virtual_path_string(&req_path, (const char **)&cd);
  strstr((unsigned __int8 *)req_path.m_string.m_begin, "#[");
  if ( v3 )
  {
    v4 = v3 - (unsigned int)req_path.m_string.m_begin;
    found = v3 - (unsigned int)req_path.m_string.m_begin;
  }
  else
  {
    found = -1;
    v4 = -1;
  }
  v5 = (vostok::physics::collision_shape_cook::cook_data *)vostok::physics::g_ph_allocator->call_malloc(
                                                             vostok::physics::g_ph_allocator,
                                                             292);
  if ( v5 )
  {
    m_buffer = (vostok::fs_new::path_string_impl *)v5->model_path.m_string.m_buffer;
    v5->model_path.m_string.m_begin = v5->model_path.m_string.m_buffer;
    v5->model_path.m_string.m_end = v5->model_path.m_string.m_buffer;
    v5->model_path.m_string.m_max_end = &v5->model_path.m_separator;
    v5->model_path.m_string.m_buffer[0] = 0;
    v7 = v5;
    v5->model_path.m_string.m_buffer[0] = 0;
    v5->model_path.m_separator = 47;
    cd = v5;
  }
  else
  {
    cd = 0;
    v7 = 0;
  }
  v7->parent_query = parent;
  if ( v4 == -1 )
  {
    p_model_path = &v7->model_path;
    vostok::fs_new::virtual_path_string::operator=(&v7->model_path, &req_path);
    v10 = (boost::_bi::value<survarium::animated_model_instance *> *)clear_value;
    LODWORD(v7->scale_.x) = clear_value;
    LODWORD(v7->scale_.y) = v10;
  }
  else
  {
    v8 = (vostok::fs_new::virtual_path_string *)vostok::fs_new::path_string_impl::substr(
                                                  m_buffer,
                                                  (int)&req_path,
                                                  (int)v30,
                                                  (vostok::fs_new::path_string_impl *)v4,
                                                  (unsigned int)v28.l_.a3_.t_,
                                                  v29);
    p_model_path = &v7->model_path;
    vostok::fs_new::virtual_path_string::operator=(&v7->model_path, v8);
    sscanf_s(&req_path.m_string.m_begin[found], "#[%f][%f][%f]", &sx, &sy, &sz);
    LODWORD(v7->scale_.x) = sx;
    LODWORD(v7->scale_.y) = sy;
    v10 = sz;
  }
  LODWORD(v7->scale_.z) = v10;
  vostok::strings::detail::tuples::tuples(
    &STR_JOINA_tuples_unique_identifier,
    p_model_path->m_string.m_begin,
    "/exported_primitives");
  v12 = alloca(vostok::strings::detail::tuples::size(v11, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  sz = &v28.l_.a3_;
  vostok::strings::detail::tuples::size(v13, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat((char *)&v28.l_.a3_, &STR_JOINA_tuples_unique_identifier);
  m_begin = p_model_path->m_string.m_begin;
  v15 = p_model_path->m_string.m_end - p_model_path->m_string.m_begin;
  model_config_path.m_string.m_begin = model_config_path.m_string.m_buffer;
  model_config_path.m_string.m_end = model_config_path.m_string.m_buffer;
  model_config_path.m_string.m_max_end = &model_config_path.m_separator;
  memcpy((unsigned __int8 *)model_config_path.m_string.m_buffer, (unsigned __int8 *)m_begin, v15);
  model_config_path.m_string.m_end += v15;
  *model_config_path.m_string.m_end = 0;
  model_config_path.m_separator = 47;
  strstr((unsigned __int8 *)model_config_path.m_string.m_begin, ".model");
  if ( v16 )
    v17 = v16 - (unsigned int)model_config_path.m_string.m_begin;
  else
    v17 = -1;
  model_config_path.m_string.m_end = &model_config_path.m_string.m_begin[strlen(".model") + v17];
  *model_config_path.m_string.m_end = 0;
  *(_QWORD *)model_config_path.m_string.m_end = *(_QWORD *)aSetting;
  model_config_path.m_string.m_end[8] = 115;
  model_config_path.m_string.m_end += 9;
  *model_config_path.m_string.m_end = 0;
  vostok::strings::detail::tuples::tuples(&STR_JOINA_tuples_unique_identifier, p_model_path->m_string.m_begin, aVertice);
  v19 = alloca(vostok::strings::detail::tuples::size(v18, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  sy = &v28.l_.a3_;
  vostok::strings::detail::tuples::size(v20, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat((char *)&v28.l_.a3_, &STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::tuples(
    &STR_JOINA_tuples_unique_identifier,
    p_model_path->m_string.m_begin,
    "/indices");
  v22 = alloca(vostok::strings::detail::tuples::size(v21, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  sx = &v28.l_.a3_;
  vostok::strings::detail::tuples::size(v23, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat((char *)&v28.l_.a3_, &STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::tuples(
    &STR_JOINA_tuples_unique_identifier,
    p_model_path->m_string.m_begin,
    "/face_data");
  v25 = alloca(vostok::strings::detail::tuples::size(v24, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  vostok::strings::detail::tuples::size(v26, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat((char *)&v28.l_.a3_, &STR_JOINA_tuples_unique_identifier);
  requests[0].path = (const char *)sz;
  requests[1].path = model_config_path.m_string.m_begin;
  requests[0].id = binary_config_class_impl;
  requests[1].id = binary_config_class_impl;
  requests[2].path = (const char *)sy;
  requests[3].path = (const char *)sx;
  requests[2].id = raw_data_class;
  requests[3].id = raw_data_class;
  requests[4].path = (const char *)&v28.l_.a3_;
  requests[4].id = raw_data_class;
  v33 = vostok::physics::collision_shape_cook::on_collision_sources_loaded;
  v34 = v37;
  STR_JOINA_tuples_unique_identifier.m_strings[2].second = 0;
  v28.f_.f_ = v37;
  v28.l_.a1_.t_ = (survarium::animated_model_instance_cook *)cd;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         (boost::detail::function::function_buffer *)&STR_JOINA_tuples_unique_identifier.m_strings[3].second,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::physics::collision_shape_cook::on_collision_sources_loaded,
         v28) )
  {
    STR_JOINA_tuples_unique_identifier.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::physics::collision_shape_cook,vostok::resources::queries_result &,vostok::physics::collision_shape_cook::cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::physics::collision_shape_cook *>,boost::arg<1>,boost::_bi::value<vostok::physics::collision_shape_cook::cook_data *>>>>'::`2'::stored_vtable
                                                           + 1;
  }
  else
  {
    STR_JOINA_tuples_unique_identifier.m_strings[2].second = 0;
  }
  vostok::resources::query_resources(
    requests,
    5u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&STR_JOINA_tuples_unique_identifier.m_strings[2].second,
    vostok::physics::g_ph_allocator,
    0,
    parent,
    assert_on_fail_true);
  if ( STR_JOINA_tuples_unique_identifier.m_strings[2].second
    && (STR_JOINA_tuples_unique_identifier.m_strings[2].second & 1) == 0 )
  {
    v27 = *(void (__cdecl **)(unsigned int *, unsigned int *, int))(STR_JOINA_tuples_unique_identifier.m_strings[2].second
                                                                  & 0xFFFFFFFE);
    if ( v27 )
      v27(
        &STR_JOINA_tuples_unique_identifier.m_strings[3].second,
        &STR_JOINA_tuples_unique_identifier.m_strings[3].second,
        2);
  }
}
