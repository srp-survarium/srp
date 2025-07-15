vostok::fs_new::virtual_path_string *__fastcall vostok::resources::resource_base::reusable_request_name(
        vostok::resources::resource_base *this,
        int a2,
        vostok::fs_new::virtual_path_string *result)
{
  int v3; // eax
  vostok::fs_new::virtual_path_string *v4; // ecx
  int v5; // edx
  int v7; // [esp+14h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+18h] [ebp-18h]
  int v11; // [esp+20h] [ebp-10h] BYREF
  int v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  vostok::fs_new::virtual_path_string *v14; // [esp+2Ch] [ebp-4h]

  v3 = (unsigned __int8)((*(_DWORD *)(a2 + 8) & 1) - 1) == 0 ? a2 : 0;
  if ( !v3 )
  {
    v3 = (unsigned __int8)((*(_DWORD *)(a2 + 8) & 4) - 4) == 0 ? a2 : 0;
    v4 = *(vostok::fs_new::virtual_path_string **)(v3 + 0xAC);
    v10 = *(_DWORD *)(v3 + 0xA8);
    v8 = *(_DWORD *)(v3 + 0xA4);
    v11 = *(_DWORD *)(v3 + 0xA0);
    v12 = v8;
    v13 = v10;
    v14 = v4;
    if ( v8 )
      goto LABEL_5;
LABEL_7:
    v5 = *(_DWORD *)(a2 + 176);
    if ( v5 )
    {
      vostok::fs_new::virtual_path_string::virtual_path_string(result, (char **)(v5 + 8));
      return result;
    }
LABEL_9:
    vostok::fs_new::virtual_path_string::virtual_path_string(v4, (int)result);
    return result;
  }
  v4 = *(vostok::fs_new::virtual_path_string **)((unsigned __int8)((*(_DWORD *)(a2 + 8) & 1) - 1) == 0 ? a2 + 0xAC : 172);
  v9 = *(_DWORD *)((unsigned __int8)((*(_DWORD *)(a2 + 8) & 1) - 1) == 0 ? a2 + 0xA8 : 168);
  v7 = *(_DWORD *)((unsigned __int8)((*(_DWORD *)(a2 + 8) & 1) - 1) == 0 ? a2 + 0xA4 : 164);
  v11 = *(_DWORD *)((unsigned __int8)((*(_DWORD *)(a2 + 8) & 1) - 1) == 0 ? a2 + 0xA0 : 160);
  v12 = v7;
  v13 = v9;
  v14 = v4;
  if ( !v7 )
    goto LABEL_7;
LABEL_5:
  if ( !vostok::resources::base_of_intrusive_base::is_associated_with_fat(
          (vostok::resources::base_of_intrusive_base *)v4,
          (vostok::vfs::vfs_hashset *)v3) )
    goto LABEL_9;
  vostok::vfs::vfs_iterator::get_virtual_path(
    (vostok::vfs::vfs_iterator *)v4,
    (vostok::fs_new::virtual_path_string *)&v11,
    result);
  return result;
}
