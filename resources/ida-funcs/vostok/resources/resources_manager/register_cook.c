void __usercall vostok::resources::resources_manager::register_cook(
        vostok::resources::cook_base *cook@<esi>,
        vostok::buffer_vector<vostok::resources::cook_base *> *a2@<ecx>)
{
  int v2; // edi
  vostok::resources::cook_base *value; // [esp+4h] [ebp-4h] BYREF

  if ( s_cooks_registry.m_begin == s_cooks_registry.m_end )
  {
    value = 0;
    v2 = 518;
    do
    {
      vostok::buffer_vector<vostok::resources::cook_base *>::push_back(a2, &value);
      --v2;
    }
    while ( v2 );
  }
  s_cooks_registry.m_begin[cook->m_class_id] = cook;
}
