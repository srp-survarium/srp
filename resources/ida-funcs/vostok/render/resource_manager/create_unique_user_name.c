vostok::fs_new::virtual_path_string *__usercall vostok::render::resource_manager::create_unique_user_name@<eax>(
        vostok::fs_new::virtual_path_string *a1@<ecx>,
        _DWORD *a2@<edi>)
{
  unsigned int m_seed; // ecx
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // ebp
  int v7; // eax

  vostok::fs_new::virtual_path_string::virtual_path_string(a1, (int)a2);
  if ( (_S6_2 & 1) != 0 )
  {
    m_seed = r.m_seed;
  }
  else
  {
    _S6_2 |= 1u;
    m_seed = 0;
  }
  v3 = 134775813 * m_seed + 1;
  v4 = (10000 * (unsigned __int64)(unsigned int)v3) >> 32;
  v5 = 134775813 * v3 + 1;
  v6 = (10000 * (unsigned __int64)(unsigned int)v5) >> 32;
  v7 = 134775813 * v5 + 1;
  r.m_seed = 134775813 * v7 + 1;
  vostok::fs_new::path_string_impl::assignf(
    a2,
    (vostok::buffer_string *)(134775813 * v7 + 1),
    (vostok::buffer_string *)"$user$%d%d%d%d",
    (const char *)((10000 * (unsigned __int64)r.m_seed) >> 32),
    (_DWORD)((10000 * (unsigned __int64)(unsigned int)v7) >> 32),
    v6,
    v4);
  return (vostok::fs_new::virtual_path_string *)a2;
}
