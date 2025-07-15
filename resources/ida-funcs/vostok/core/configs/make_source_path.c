void __usercall vostok::core::configs::make_source_path(
        vostok::fs_new::virtual_path_string *out_sources_path@<ecx>,
        vostok::fs_new::virtual_path_string *in_converted_path@<eax>)
{
  vostok::buffer_string *v4; // ecx
  vostok::buffer_string *v5; // ecx
  vostok::buffer_string *v6; // ecx
  char *m_begin; // eax
  char *v8; // edx
  unsigned int v9; // [esp+0h] [ebp-10h]
  unsigned int v10; // [esp+0h] [ebp-10h]

  vostok::fixed_string<260>::operator=(&in_converted_path->m_string, &out_sources_path->m_string);
  if ( vostok::buffer_string::find(v4, (unsigned __int8 **)in_converted_path, (char *)resources_converted_string, v9) == -1 )
  {
    if ( vostok::buffer_string::find(v5, (unsigned __int8 **)in_converted_path, (char *)mounts_converted_string, v10) == -1 )
    {
      m_begin = out_sources_path->m_string.m_begin;
      v8 = (char *)resources_sources_string;
      if ( out_sources_path->m_string.m_begin != resources_sources_string )
      {
        out_sources_path->m_string.m_end = m_begin;
        *m_begin = 0;
        vostok::buffer_string::operator+=(&out_sources_path->m_string, v8);
      }
      vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(
        in_converted_path,
        &out_sources_path->m_string);
    }
    else
    {
      vostok::buffer_string::replace(
        v6,
        &out_sources_path->m_string,
        (char *)mounts_converted_string,
        "mounts.sources/");
    }
  }
  else
  {
    vostok::buffer_string::replace(
      v5,
      &out_sources_path->m_string,
      (char *)resources_converted_string,
      (char *)resources_sources_string);
  }
}
