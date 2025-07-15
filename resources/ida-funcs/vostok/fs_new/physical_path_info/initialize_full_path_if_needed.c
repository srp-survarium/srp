void __thiscall vostok::fs_new::physical_path_info::initialize_full_path_if_needed(
        vostok::fs_new::physical_path_info *this)
{
  vostok::fs_new::physical_path_info *parent; // esi
  vostok::fs_new::path_string_impl v3; // [esp+10h] [ebp-118h] BYREF

  if ( this->data.path_type != path_type_contains_full_path )
  {
    vostok::fixed_string<260>::fixed_string<260>(&v3.m_string, &this->data.path.m_string);
    parent = (vostok::fs_new::physical_path_info *)this->parent;
    v3.m_separator = 92;
    vostok::fs_new::physical_path_info::initialize_full_path_if_needed(parent);
    vostok::fixed_string<260>::operator=(&parent->data.path.m_string, &this->data.path.m_string);
    *this->data.path.m_string.m_end++ = 92;
    *this->data.path.m_string.m_end = 0;
    vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(&v3, &this->data.path.m_string);
    this->data.path_type = path_type_contains_full_path;
  }
}
