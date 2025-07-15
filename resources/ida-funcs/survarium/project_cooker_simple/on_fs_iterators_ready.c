void __thiscall survarium::project_cooker_simple::on_fs_iterators_ready(
        survarium::project_cooker_simple *this,
        vostok::resources::queries_result *data,
        const vostok::variant<32> **parent,
        vostok::fs_new::virtual_path_string project_name)
{
  char *requested_path; // eax
  vostok::fixed_string<260> *v5; // ecx
  char *v6; // eax
  vostok::fixed_string<260> *v7; // ecx
  vostok::vfs::base_node<1> *m_link_target; // ecx
  vostok::vfs::vfs_iterator::type_enum m_type; // eax
  char *v10; // eax
  int v11; // esi
  vostok::fs_new::path_string_impl *v12; // eax
  vostok::fs_new::path_string_impl *v13; // eax
  vostok::fs_new::virtual_path_string *p_project_name; // ecx
  vostok::fixed_string<260> *v15; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v16; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  void (__thiscall *__ptr64 v18)(survarium::project_cooker_simple *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *, vostok::fs_new::virtual_path_string); // [esp-24Ch] [ebp-B8Ch]
  survarium::project_cooker_simple *v19; // [esp-244h] [ebp-B84h] BYREF
  boost::arg<1> v20; // [esp-240h] [ebp-B80h]
  vostok::resources::query_result_for_cook *v21; // [esp-23Ch] [ebp-B7Ch]
  _BYTE v22[568]; // [esp-238h] [ebp-B78h] BYREF
  int v23; // [esp+0h] [ebp-940h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::fs_new::virtual_path_string> > > *result; // [esp+Ch] [ebp-934h]
  vostok::vfs::vfs_iterator v25; // [esp+10h] [ebp-930h] BYREF
  vostok::vfs::vfs_iterator v26[2]; // [esp+20h] [ebp-920h] BYREF
  vostok::buffer_string v27; // [esp+40h] [ebp-900h] BYREF
  _BYTE v28[260]; // [esp+4Ch] [ebp-8F4h] BYREF
  char v29; // [esp+150h] [ebp-7F0h] BYREF
  vostok::fixed_string<260> v30; // [esp+158h] [ebp-7E8h] BYREF
  char v31; // [esp+268h] [ebp-6D8h] BYREF
  vostok::buffer_string v32; // [esp+270h] [ebp-6D0h] BYREF
  _BYTE v33[260]; // [esp+27Ch] [ebp-6C4h] BYREF
  char v34; // [esp+380h] [ebp-5C0h] BYREF
  vostok::buffer_string v35[22]; // [esp+388h] [ebp-5B8h] BYREF
  char v36; // [esp+498h] [ebp-4A8h]
  vostok::buffer_string v37[22]; // [esp+4A0h] [ebp-4A0h] BYREF
  char v38; // [esp+5B0h] [ebp-390h]
  _BYTE v39[276]; // [esp+5BCh] [ebp-384h] BYREF
  vostok::fs_new::physical_path_info v40; // [esp+6D0h] [ebp-270h] BYREF
  vostok::fs_new::physical_path_info v41; // [esp+808h] [ebp-138h] BYREF

  result = (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::fs_new::virtual_path_string> > > *)this;
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(&data->m_queries[0]);
  vostok::fixed_string<260>::fixed_string<260>(v5, v35, requested_path);
  v36 = 47;
  v6 = (char *)vostok::resources::query_result_for_user::get_requested_path(&data->m_queries[1]);
  vostok::fixed_string<260>::fixed_string<260>(v7, v37, v6);
  v25.m_hashset = data->m_queries[0].m_result_iterator.m_hashset;
  v25.m_node = data->m_queries[0].m_result_iterator.m_node;
  m_link_target = data->m_queries[0].m_result_iterator.m_link_target;
  v25.m_type = data->m_queries[0].m_result_iterator.m_type;
  v25.m_link_target = m_link_target;
  v26[0].m_hashset = data->m_queries[1].m_result_iterator.m_hashset;
  v26[0].m_node = data->m_queries[1].m_result_iterator.m_node;
  m_type = data->m_queries[1].m_result_iterator.m_type;
  v26[0].m_link_target = data->m_queries[1].m_result_iterator.m_link_target;
  v26[0].m_type = m_type;
  v38 = 47;
  vostok::resources::get_physical_path_info(&v25, &v40);
  vostok::resources::get_physical_path_info(v26, &v41);
  v27.m_begin = v28;
  v27.m_end = v28;
  v27.m_max_end = &v29;
  v30.m_begin = v30.m_buffer;
  v30.m_end = v30.m_buffer;
  v30.m_max_end = &v31;
  v32.m_begin = v33;
  v32.m_end = v33;
  v32.m_max_end = &v34;
  v28[0] = 0;
  v29 = 47;
  v30.m_buffer[0] = 0;
  v31 = 47;
  v33[0] = 0;
  v34 = 47;
  if ( v40.data.type != type_file )
  {
    vostok::buffer_string::operator=(v37, &v32);
    if ( v27.m_begin != "default" )
    {
      v27.m_end = v27.m_begin;
      *v27.m_begin = 0;
      vostok::buffer_string::operator+=(&v27, "default");
    }
    p_project_name = &project_name;
    v15 = &v30;
    goto LABEL_19;
  }
  vostok::buffer_string::operator=(v35, &v32);
  vostok::buffer_string::operator=(&project_name.m_string, &v30);
  if ( v27.m_begin != "default" )
  {
    v27.m_end = v27.m_begin;
    *v27.m_begin = 0;
    vostok::buffer_string::operator+=(&v27, "default");
  }
  v10 = project_name.m_string.m_end - 1;
  if ( project_name.m_string.m_end - 1 >= project_name.m_string.m_begin )
  {
    while ( 1 )
    {
      if ( *v10 == 47 )
      {
        v11 = v10 - project_name.m_string.m_begin;
        goto LABEL_11;
      }
      if ( v10 == project_name.m_string.m_begin )
        break;
      --v10;
    }
    v11 = -1;
LABEL_11:
    if ( v11 != -1 )
    {
      v12 = vostok::fs_new::path_string_impl::substr(0, (int)v39, &project_name, (char *)v11);
      if ( &v30 != (vostok::fixed_string<260> *)v12 )
        vostok::buffer_string::operator=(&v12->m_string, &v30);
      v13 = vostok::fs_new::path_string_impl::substr(
              v11 + 1,
              (int)v39,
              &project_name,
              (char *)(project_name.m_string.m_end - project_name.m_string.m_begin - v11 - 1));
      if ( &v27 != (vostok::buffer_string *)v13 )
      {
        p_project_name = (vostok::fs_new::virtual_path_string *)v13;
        v15 = (vostok::fixed_string<260> *)&v27;
LABEL_19:
        vostok::buffer_string::operator=(&p_project_name->m_string, v15);
      }
    }
  }
  *(_DWORD *)&v22[268] = 0;
  *(_DWORD *)&v22[264] = survarium::project_cooker_simple::on_game_project_loaded;
  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)&v19, &v30);
  HIDWORD(v18) = parent;
  v22[260] = 47;
  LODWORD(v18) = (unsigned __int8)1_85;
  boost::bind<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string,survarium::project_cooker_simple *,boost::arg<1>,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string>(
    (int)&v22[272],
    result,
    v18,
    v19,
    v20,
    v21,
    *(vostok::fs_new::virtual_path_string *)v22);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v16,
    v26,
    *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::fs_new::virtual_path_string> > > *)&v22[272],
    v23);
  vostok::resources::query_resource(
    v32.m_begin,
    (vostok::variant<32> *)0x20,
    survarium::g_allocator,
    0,
    parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v17,
    (int *)v26);
}
