void __usercall vostok::resources::query_result::translate_request_path(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::cook_base *cook; // edx
  vostok::resources::cook_base_vtbl *v4; // esi
  const char *requested_path; // eax
  vostok::resources::cook_base *v6; // edx
  const char *v7; // eax
  int v8; // esi
  int v9; // ebx
  char *v10; // eax
  char *v11; // eax
  unsigned int v12; // [esp-8h] [ebp-130h]
  char *v13; // [esp-4h] [ebp-12Ch]
  char *v14; // [esp+10h] [ebp-118h] BYREF
  _BYTE *v15; // [esp+14h] [ebp-114h]
  char *v16; // [esp+18h] [ebp-110h]
  _BYTE v17[260]; // [esp+1Ch] [ebp-10Ch] BYREF
  char v18; // [esp+120h] [ebp-8h] BYREF

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( cook )
  {
    v14 = v17;
    v15 = v17;
    v16 = &v18;
    v17[0] = 0;
    v18 = 47;
    v4 = cook->__vftable;
    requested_path = vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)a2);
    v4->translate_request_path(v6, requested_path, (vostok::fs_new::virtual_path_string *)&v14);
    v7 = vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)a2);
    if ( vostok::detail::strcmp_s(v14, v7) )
    {
      v8 = v15 - v14;
      v9 = *(_DWORD *)(a2 + 340);
      v10 = type_info::raw_name(&char `RTTI Type Descriptor');
      v11 = (char *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v9 + 16))(
                      v9,
                      v8 + 1,
                      v10,
                      "vostok::resources::query_result::translate_request_path",
                      ".\\resources_query_result_path.cpp",
                      38);
      v13 = v14;
      v12 = v15 - v14 + 1;
      *(_DWORD *)(a2 + 248) = v11;
      vostok::strings::copy(v11, v12, v13);
      _InterlockedOr((volatile signed __int32 *)(a2 + 704), 0x400u);
    }
  }
}
