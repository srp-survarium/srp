void __usercall vostok::resources::query_result::prepare_final_resource(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<esi>)
{
  vostok::resources::cook_base *cook; // eax
  unsigned int m_flags; // eax
  vostok::resources::cook_base *v4; // eax
  vostok::resources::query_result *v5; // ecx

  cook = vostok::resources::resources_manager::find_cook(a2->m_class_id);
  if ( cook && (m_flags = cook->m_flags.m_flags, (m_flags & 0x20) != 0) && (m_flags & 0x18) == 0
    || (v4 = vostok::resources::resources_manager::find_cook(a2->m_class_id)) != 0 && (v4->m_flags.m_flags & 0x38) == 0 )
  {
    vostok::resources::allocate_functionality::prepare_final_resource(
      &vostok::resources::g_resources_manager.m_variable->m_allocate_functionality,
      a2);
  }
  else
  {
    vostok::resources::query_result::send_to_create_resource(v5);
  }
}
