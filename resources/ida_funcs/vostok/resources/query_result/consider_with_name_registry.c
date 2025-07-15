int __thiscall vostok::resources::query_result::consider_with_name_registry(
        vostok::resources::query_result *this,
        vostok::resources::query_result *only_try_to_get_associated_resource,
        vostok::resources::query_result::only_try_to_get_associated_resource_bool only_try_to_get_associated_resourcea)
{
  vostok::resources::query_result *v3; // ebx
  vostok::resources::cook_base *cook; // eax
  char *m_request_path; // esi
  void *v6; // esp
  _BYTE *v7; // eax
  _BYTE *v8; // edi
  int v9; // eax
  int v10; // ebx
  char *v12; // edi
  unsigned int v13; // esi
  const char *v14; // [esp-4h] [ebp-18h]
  int v15; // [esp+0h] [ebp-14h] BYREF
  char *_Dst; // [esp+Ch] [ebp-8h]
  unsigned int temp_size; // [esp+10h] [ebp-4h]

  v3 = only_try_to_get_associated_resource;
  cook = vostok::resources::resources_manager::find_cook((int)this, only_try_to_get_associated_resource->m_class_id);
  if ( cook && cook->m_reuse_type != reuse_true )
    return 1;
  m_request_path = only_try_to_get_associated_resource->m_request_path;
  if ( !strlen(m_request_path) )
    return 1;
  temp_size = &only_try_to_get_associated_resource->m_request_path[strlen(only_try_to_get_associated_resource->m_request_path)
                                                                 + 1]
            - m_request_path;
  v6 = alloca(temp_size);
  _Dst = (char *)&v15;
  if ( !m_request_path )
    return 1;
  while ( 1 )
  {
    strchr(m_request_path, 0x7Cu);
    v8 = v7;
    if ( v7 )
      *v7 = 0;
    if ( *m_request_path == 64 )
      goto LABEL_10;
    v9 = vostok::resources::query_result::consider_with_name_registry_impl(
           m_request_path,
           v3,
           only_try_to_get_associated_resourcea);
    v10 = v9;
    if ( v9 != 1 )
      break;
    v3 = only_try_to_get_associated_resource;
LABEL_10:
    if ( v8 )
    {
      m_request_path = v8 + 1;
      *v8 = 124;
      if ( v8 != (_BYTE *)-1 )
        continue;
    }
    return 1;
  }
  if ( v9 && m_request_path != only_try_to_get_associated_resource->m_request_path )
  {
    v12 = _Dst;
    v14 = m_request_path;
    v13 = temp_size;
    strcpy_s(_Dst, temp_size, v14);
    strcpy_s(only_try_to_get_associated_resource->m_request_path, v13, v12);
  }
  return v10;
}
