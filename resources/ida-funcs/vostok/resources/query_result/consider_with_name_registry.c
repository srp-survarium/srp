int __thiscall vostok::resources::query_result::consider_with_name_registry(
        vostok::resources::query_result *this,
        vostok::resources::query_result *only_try_to_get_associated_resource,
        int a3)
{
  char *m_request_path; // esi
  unsigned int v4; // ebx
  void *v5; // esp
  _BYTE *v6; // eax
  _BYTE *v7; // edi
  int v8; // eax
  vostok::resources::query_result *v10; // [esp-4h] [ebp-1Ch]
  int v11; // [esp+0h] [ebp-18h] BYREF
  int v12; // [esp+10h] [ebp-8h]
  char *v13; // [esp+14h] [ebp-4h]

  if ( vostok::resources::cook_base::reuse_type(only_try_to_get_associated_resource->m_class_id) == reuse_true )
  {
    m_request_path = only_try_to_get_associated_resource->m_request_path;
    if ( strlen(m_request_path) )
    {
      v4 = strlen(m_request_path) + 1;
      v5 = alloca(v4);
      v13 = (char *)&v11;
      while ( m_request_path )
      {
        strchr(m_request_path, 0x7Cu);
        v7 = v6;
        if ( v6 )
          *v6 = 0;
        if ( *m_request_path != 64 )
        {
          v8 = vostok::resources::query_result::consider_with_name_registry_impl(
                 v10,
                 only_try_to_get_associated_resource,
                 m_request_path,
                 a3);
          v12 = v8;
          if ( v8 != 1 )
          {
            if ( v8 )
            {
              if ( m_request_path != only_try_to_get_associated_resource->m_request_path )
              {
                vostok::strings::copy(v13, v4, m_request_path);
                vostok::strings::copy(only_try_to_get_associated_resource->m_request_path, v4, v13);
              }
            }
            return v12;
          }
        }
        if ( !v7 )
          return 1;
        *v7 = 124;
        m_request_path = v7 + 1;
      }
    }
  }
  return 1;
}
