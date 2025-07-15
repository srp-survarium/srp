void __thiscall survarium::project_cooker_simple::translate_query(
        survarium::project_cooker_simple *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *requested_path; // eax
  vostok::fixed_string<260> *v3; // ecx
  vostok::buffer_string *v4; // ecx
  vostok::buffer_string *v5; // ecx
  char *v6; // eax
  int v7; // eax
  vostok::fs_new::path_string_impl *v8; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  void (__thiscall *__ptr64 v11)(survarium::project_cooker_simple *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *, vostok::fs_new::virtual_path_string); // [esp-24Ch] [ebp-804h]
  survarium::project_cooker_simple *v12; // [esp-244h] [ebp-7FCh] BYREF
  boost::arg<1> v13; // [esp-240h] [ebp-7F8h]
  vostok::resources::query_result_for_cook *v14; // [esp-23Ch] [ebp-7F4h]
  _BYTE v15[568]; // [esp-238h] [ebp-7F0h] BYREF
  int v16; // [esp+0h] [ebp-5B8h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::fs_new::virtual_path_string> > > *result; // [esp+Ch] [ebp-5ACh]
  vostok::resources::request v18; // [esp+10h] [ebp-5A8h] BYREF
  int v19; // [esp+18h] [ebp-5A0h]
  int v20; // [esp+1Ch] [ebp-59Ch]
  int v21[8]; // [esp+20h] [ebp-598h] BYREF
  vostok::fs_new::path_string_impl v22; // [esp+40h] [ebp-578h] BYREF
  _DWORD v23[3]; // [esp+158h] [ebp-460h] BYREF
  _BYTE v24[260]; // [esp+164h] [ebp-454h] BYREF
  char v25; // [esp+268h] [ebp-350h] BYREF
  _DWORD v26[3]; // [esp+270h] [ebp-348h] BYREF
  _BYTE v27[260]; // [esp+27Ch] [ebp-33Ch] BYREF
  char v28; // [esp+380h] [ebp-238h] BYREF
  vostok::fixed_string<260> v29; // [esp+388h] [ebp-230h] BYREF
  char v30; // [esp+498h] [ebp-120h]
  _BYTE v31[276]; // [esp+4A4h] [ebp-114h] BYREF

  result = (boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::fs_new::virtual_path_string> > > *)this;
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fixed_string<260>::fixed_string<260>(v3, &v22.m_string, requested_path);
  v26[0] = v27;
  v26[1] = v27;
  v26[2] = &v28;
  v22.m_separator = 47;
  v27[0] = 0;
  v28 = 47;
  vostok::fs_new::path_string_impl::assignf(
    v26,
    v4,
    (vostok::buffer_string *)"%sprojects/%s/client_project",
    "resources/",
    v22.m_string.m_begin);
  v23[0] = v24;
  v23[1] = v24;
  v23[2] = &v25;
  v24[0] = 0;
  v25 = 47;
  vostok::fs_new::path_string_impl::assignf(
    v23,
    v5,
    (vostok::buffer_string *)"%sprojects/%s/default/client_project",
    "resources/",
    v22.m_string.m_begin);
  vostok::fixed_string<260>::fixed_string<260>(&v29, &v22.m_string);
  v6 = v22.m_string.m_end - 1;
  v30 = 47;
  if ( v22.m_string.m_end - 1 >= v22.m_string.m_begin )
  {
    while ( 1 )
    {
      if ( *v6 == 47 )
      {
        v7 = v6 - v22.m_string.m_begin;
        goto LABEL_8;
      }
      if ( v6 == v22.m_string.m_begin )
        break;
      --v6;
    }
    v7 = -1;
LABEL_8:
    if ( v7 != -1 )
    {
      v8 = vostok::fs_new::path_string_impl::substr(0, (int)v31, &v22, (char *)v7);
      if ( &v29 != (vostok::fixed_string<260> *)v8 )
        vostok::buffer_string::operator=(&v8->m_string, &v29);
    }
  }
  v18.path = (const char *)v26[0];
  v19 = v23[0];
  *(_DWORD *)&v15[268] = 0;
  *(_DWORD *)&v15[264] = survarium::project_cooker_simple::on_fs_iterators_ready;
  v18.id = fs_iterator_class;
  v20 = 1;
  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)&v12, &v22.m_string);
  HIDWORD(v11) = parent;
  v15[260] = 47;
  LODWORD(v11) = (unsigned __int8)1_85;
  boost::bind<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string,survarium::project_cooker_simple *,boost::arg<1>,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string>(
    (int)&v15[272],
    result,
    v11,
    v12,
    v13,
    v14,
    *(vostok::fs_new::virtual_path_string *)v15);
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v9,
    v21,
    *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::project_cooker_simple,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *,vostok::fs_new::virtual_path_string>,boost::_bi::list4<boost::_bi::value<survarium::project_cooker_simple *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>,boost::_bi::value<vostok::fs_new::virtual_path_string> > > *)&v15[272],
    v16);
  vostok::resources::query_resources(
    &v18,
    2u,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v10, v21);
}
