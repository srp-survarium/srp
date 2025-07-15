void __usercall vostok::fs_new::get_path_without_last_item_inplace<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *in_out_path@<esi>)
{
  const char *v1; // eax
  char *v2; // eax
  vostok::fs_new::path_string_impl *v3; // [esp-4h] [ebp-ACh]
  vostok::buffer_string v4; // [esp+0h] [ebp-A8h] BYREF
  _BYTE v5[260]; // [esp+Ch] [ebp-9Ch] BYREF
  char v6; // [esp+110h] [ebp+68h] BYREF
  char *m_begin; // [esp+114h] [ebp+6Ch] BYREF
  const char *v8; // [esp+118h] [ebp+70h] BYREF

  strrchr(in_out_path->m_string.m_begin, 0x2Fu);
  v8 = v1;
  if ( v1 )
  {
    v4.m_begin = v5;
    v4.m_end = v5;
    v4.m_max_end = &v6;
    m_begin = in_out_path->m_string.m_begin;
    v5[0] = 0;
    v6 = 47;
    vostok::fs_new::path_string_impl::assign<char const *>(v3, &v4, &m_begin, &v8);
    if ( in_out_path != (vostok::fs_new::virtual_path_string *)&v4 )
      vostok::buffer_string::operator=(&v4, &in_out_path->m_string);
  }
  else
  {
    v2 = in_out_path->m_string.m_begin;
    in_out_path->m_string.m_end = in_out_path->m_string.m_begin;
    *v2 = 0;
  }
}
