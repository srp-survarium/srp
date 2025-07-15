vostok::fs_new::native_path_string *__userpurge vostok::vfs::query_mount_arguments::get_physical_path@<eax>(
        vostok::vfs::query_mount_arguments *this@<ecx>,
        int a2@<eax>,
        vostok::fs_new::native_path_string *result)
{
  vostok::fs_new::native_path_string *p_out_result; // eax
  int v5; // eax
  int v6; // edi
  char **v7; // eax
  vostok::fs_new::native_path_string *v8; // eax
  vostok::fixed_string<260> *v9; // [esp-4h] [ebp-238h]
  vostok::fs_new::native_path_string v10; // [esp+Ch] [ebp-228h] BYREF
  vostok::fs_new::native_path_string out_result; // [esp+120h] [ebp-114h] BYREF

  if ( *(_DWORD *)(a2 + 1148) == 1 )
  {
    p_out_result = (vostok::fs_new::native_path_string *)(a2 + 276);
  }
  else
  {
    v5 = *(_DWORD *)(a2 + 1216);
    if ( v5 && (*(_WORD *)(v5 + 48) & 0x1000) == 0x1000 )
    {
      vostok::fs_new::native_path_string::native_path_string(&out_result);
      vostok::fs_new::get_path_without_last_item<vostok::fs_new::native_path_string>(&out_result, *(char **)(a2 + 828));
      v6 = *(_DWORD *)(a2 + 1216);
      if ( v6 )
        v7 = (char **)(v6 - 16);
      else
        v7 = 0;
      vostok::fixed_string<260>::fixed_string<260>(v9, &v10.m_string, *v7);
      v10.m_separator = 92;
      vostok::fs_new::append_relative_path<vostok::fs_new::native_path_string,vostok::fs_new::native_path_string>(
        &out_result,
        &v10);
      p_out_result = &out_result;
    }
    else
    {
      p_out_result = (vostok::fs_new::native_path_string *)(a2 + 828);
    }
  }
  vostok::fixed_string<260>::fixed_string<260>(&result->m_string, &p_out_result->m_string);
  v8 = result;
  result->m_separator = 92;
  return v8;
}
