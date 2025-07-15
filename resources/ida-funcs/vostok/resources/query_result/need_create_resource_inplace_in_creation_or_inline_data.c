bool __usercall vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  bool v3; // zf
  int *v4; // edx
  int v5; // eax
  _DWORD *v6; // eax
  bool v7; // al
  vostok::resources::query_result *v8; // [esp-4h] [ebp-Ch]
  _BYTE v9[8]; // [esp+0h] [ebp-8h] BYREF

  if ( !vostok::resources::query_result::has_uncompressed_inline_data(this, (vostok::vfs::vfs_iterator *)a2)
    && !*(_DWORD *)(a2 + 208)
    && !*(_DWORD *)(a2 + 212)
    || !vostok::resources::cook_base::find_inplace_unmanaged_cook(*(vostok::resources::class_id_enum *)(a2 + 132)) )
  {
    return 0;
  }
  v3 = !vostok::resources::query_result::has_uncompressed_inline_data(v8, (vostok::vfs::vfs_iterator *)a2);
  v5 = *v4;
  if ( v3 )
    v6 = (_DWORD *)(*(int (__thiscall **)(int *, _BYTE *))(v5 + 36))(v4, v9);
  else
    v6 = (_DWORD *)(*(int (__thiscall **)(int *, _BYTE *))(v5 + 32))(v4, v9);
  v7 = !*v6 && !v6[1];
  return !v7;
}
