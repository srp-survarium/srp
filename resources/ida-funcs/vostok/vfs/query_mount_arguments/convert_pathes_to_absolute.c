void __thiscall vostok::vfs::query_mount_arguments::convert_pathes_to_absolute(
        vostok::vfs::query_mount_arguments *this,
        int a2)
{
  vostok::fs_new::path_string_impl *v2; // ecx
  vostok::fs_new::native_path_string *v3; // esi
  vostok::fs_new::path_string_impl *v4; // ecx

  vostok::fs_new::path_string_impl::make_lowercase(&this->virtual_path, a2);
  if ( *(_DWORD *)(a2 + 1148) == 1 )
  {
    v3 = (vostok::fs_new::native_path_string *)(a2 + 276);
    vostok::fs_new::path_string_impl::make_lowercase(v2, a2 + 276);
  }
  else
  {
    vostok::fs_new::path_string_impl::make_lowercase(v2, a2 + 552);
    v3 = (vostok::fs_new::native_path_string *)(a2 + 828);
    vostok::fs_new::path_string_impl::make_lowercase(v4, a2 + 828);
    if ( *(_DWORD *)(a2 + 832) == *(_DWORD *)(a2 + 828) )
    {
      vostok::fixed_string<260>::operator=(
        (vostok::fixed_string<260> *)(a2 + 552),
        (const vostok::fixed_string<260> *)(a2 + 828));
    }
    else if ( *(_DWORD *)(a2 + 556) == *(_DWORD *)(a2 + 552) )
    {
      vostok::fixed_string<260>::operator=(
        (vostok::fixed_string<260> *)(a2 + 828),
        (const vostok::fixed_string<260> *)(a2 + 552));
    }
    vostok::fs_new::convert_to_absolute_path_inplace((vostok::fs_new::native_path_string *)(a2 + 552));
  }
  vostok::fs_new::convert_to_absolute_path_inplace(v3);
}
