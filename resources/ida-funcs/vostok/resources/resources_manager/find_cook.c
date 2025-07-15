vostok::resources::cook_base *__cdecl vostok::resources::resources_manager::find_cook(
        vostok::resources::class_id_enum resource_class)
{
  vostok::buffer_vector<vostok::resources::cook_base *> *v1; // ecx
  int v2; // esi
  vostok::resources::cook_base *value; // [esp+8h] [ebp-4h] BYREF

  if ( s_cooks_registry.m_begin == s_cooks_registry.m_end )
  {
    value = 0;
    v2 = 518;
    do
    {
      vostok::buffer_vector<vostok::resources::cook_base *>::push_back(v1, &value);
      --v2;
    }
    while ( v2 );
  }
  return s_cooks_registry.m_begin[resource_class];
}
