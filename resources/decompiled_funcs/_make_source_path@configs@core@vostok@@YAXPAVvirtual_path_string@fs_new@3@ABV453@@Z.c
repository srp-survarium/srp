void __usercall vostok::core::configs::make_source_path(
        vostok::fs_new::virtual_path_string *out_sources_path@<eax>,
        vostok::fs_new::virtual_path_string *in_converted_path@<esi>)
{
  int v3; // eax
  int v4; // eax
  char *m_begin; // eax
  const char *v6; // [esp-4h] [ebp-Ch]

  vostok::fs_new::virtual_path_string::operator=(out_sources_path, in_converted_path);
  strstr((unsigned __int8 *)in_converted_path->m_string.m_begin, (unsigned __int8 *)resources_converted_string);
  if ( !v3 || v3 - (unsigned int)in_converted_path->m_string.m_begin == -1 )
  {
    strstr((unsigned __int8 *)in_converted_path->m_string.m_begin, (unsigned __int8 *)mounts_converted_string);
    if ( !v4 || v4 - (unsigned int)in_converted_path->m_string.m_begin == -1 )
    {
      m_begin = out_sources_path->m_string.m_begin;
      if ( out_sources_path->m_string.m_begin != resources_sources_string )
      {
        v6 = resources_sources_string;
        out_sources_path->m_string.m_end = m_begin;
        *m_begin = 0;
        vostok::buffer_string::operator+=(&out_sources_path->m_string, v6);
      }
      vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(
        out_sources_path,
        &in_converted_path->m_string);
    }
    else
    {
      vostok::buffer_string::replace(mounts_converted_string, (const char *)mounts_converted_string, "mounts.sources/");
    }
  }
  else
  {
    vostok::buffer_string::replace(
      resources_converted_string,
      (const char *)resources_converted_string,
      resources_sources_string);
  }
}
