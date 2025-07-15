vostok::fixed_string<512> *__cdecl vostok::resources::logging_name_for_query(vostok::buffer_string *a1)
{
  int v1; // ecx
  bool v2; // zf
  const char *v3; // edi
  int v4; // eax
  const char *v5; // eax
  const char *requested_path; // eax
  vostok::buffer_string *v7; // ecx
  vostok::fixed_string<512> *v8; // ecx
  const char *v10; // [esp-Ch] [ebp-220h]
  int v11; // [esp-4h] [ebp-218h]
  char *v12[3]; // [esp+8h] [ebp-20Ch] BYREF
  _BYTE v13[512]; // [esp+14h] [ebp-200h] BYREF
  char vars0; // [esp+214h] [ebp+0h] BYREF

  v2 = *(_DWORD *)(v1 + 108) == 1;
  v12[0] = v13;
  v12[1] = v13;
  v12[2] = &vars0;
  v13[0] = 0;
  v3 = "Q";
  if ( v2 )
    v3 = uri;
  v4 = *(_DWORD *)(v1 + 132);
  if ( v4 == 36 )
  {
    v5 = "A";
  }
  else if ( v4 == 37 )
  {
    v5 = "B";
  }
  else
  {
    v2 = v4 == 38;
    v5 = "C";
    if ( !v2 )
      v5 = uri;
  }
  v11 = *(_DWORD *)(v1 + 32);
  v10 = v5;
  requested_path = vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)v1);
  vostok::fs_new::path_string_impl::assignf(
    v12,
    v7,
    (vostok::buffer_string *)"'%s%s %s' [quid %d]",
    requested_path,
    v10,
    v3,
    v11);
  vostok::fixed_string<512>::fixed_string<512>(v8, a1, v12[0]);
  return (vostok::fixed_string<512> *)a1;
}
