char __cdecl vostok::fs_new::is_absolute_path<vostok::fs_new::native_path_string>(
        const vostok::fs_new::native_path_string *path)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v1; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  const char *it_end; // [esp+0h] [ebp-8h]
  const vostok::variant<32> **it; // [esp+4h] [ebp-4h]

  it = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v1, (int)path);
  it_end = (const char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(v2);
  while ( it != (const vostok::variant<32> **)it_end )
  {
    if ( *(_BYTE *)it == 58 )
      return 1;
    if ( *(_BYTE *)it == 92 )
      return 0;
    it = (const vostok::variant<32> **)((char *)it + 1);
  }
  return 0;
}
