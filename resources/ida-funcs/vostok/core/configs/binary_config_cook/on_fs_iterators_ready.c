void __thiscall vostok::core::configs::binary_config_cook::on_fs_iterators_ready(
        vostok::core::configs::binary_config_cook *this,
        vostok::resources::queries_result *results)
{
  vostok::resources::query_result_for_cook *m_parent_query; // ebx
  char *m_requery_path; // eax
  vostok::resources::query_result_for_cook *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::core::configs::binary_config_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::core::configs::binary_config_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v5; // [esp-Ch] [ebp-4ECh]
  int v6; // [esp+0h] [ebp-4E0h]
  char *other; // [esp+10h] [ebp-4D0h] BYREF
  __int64 v9; // [esp+14h] [ebp-4CCh]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-4C0h] BYREF
  vostok::fs_new::virtual_path_string source_path; // [esp+40h] [ebp-4A0h] BYREF
  vostok::fs_new::virtual_path_string converted_path; // [esp+158h] [ebp-388h] BYREF
  vostok::fs_new::physical_path_info converted_info; // [esp+270h] [ebp-270h] BYREF
  vostok::fs_new::physical_path_info source_info; // [esp+3A8h] [ebp-138h]

  m_parent_query = results->m_parent_query;
  m_requery_path = m_parent_query->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = m_parent_query->m_request_path;
  other = m_requery_path;
  vostok::fs_new::virtual_path_string::virtual_path_string(&converted_path, (const char **)&other);
  source_path.m_string.m_max_end = &source_path.m_separator;
  source_path.m_string.m_begin = source_path.m_string.m_buffer;
  source_path.m_string.m_end = source_path.m_string.m_buffer;
  source_path.m_string.m_buffer[0] = 0;
  source_path.m_separator = 47;
  vostok::core::configs::make_source_path(&source_path, &converted_path);
  if ( vostok::vfs::vfs_iterator::operator bool(&results->m_queries[1].m_result_iterator) )
  {
    vostok::resources::get_physical_path_info(&results->m_queries[0].m_result_iterator);
    vostok::resources::get_physical_path_info(&results->m_queries[1].m_result_iterator);
    if ( vostok::fs_new::physical_path_info::exists(&converted_info)
      && source_info.data.last_time_of_write < converted_info.data.last_time_of_write )
    {
      HIDWORD(v9) = this;
      LODWORD(v9) = vostok::core::configs::binary_config_cook::on_binary_config_loaded;
      *(_QWORD *)&v5.f_.f_ = v9;
      v5.l_.a3_.t_ = m_parent_query;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        (boost::function<void __cdecl(vostok::resources::queries_result &)> *)m_parent_query,
        (int)&callback,
        (unsigned int)&converted_info,
        v5,
        v6);
      vostok::resources::query_resource(
        converted_path.m_string.m_begin,
        binary_config_class_impl,
        (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
        &vostok::memory::g_resources_helper_allocator,
        0,
        m_parent_query,
        assert_on_fail_true);
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v4,
      result_error,
      assert_on_fail_false,
      error_type_file_not_found);
  }
}
