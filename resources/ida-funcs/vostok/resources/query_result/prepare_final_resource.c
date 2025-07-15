void __usercall vostok::resources::query_result::prepare_final_resource(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result *a2@<eax>)
{
  vostok::resources::class_id_enum *p_m_class_id; // edi
  vostok::resources::query_result *v4; // [esp-4h] [ebp-10h]
  vostok::resources::resources_manager *v5; // [esp+0h] [ebp-Ch]

  p_m_class_id = &a2->m_class_id;
  if ( vostok::resources::cook_base::find_managed_cook(a2->m_class_id)
    || vostok::resources::cook_base::find_unmanaged_cook(*p_m_class_id) )
  {
    vostok::resources::allocate_functionality::prepare_final_resource(
      a2,
      &s_resources_manager_buffer.m_allocate_functionality);
  }
  else
  {
    vostok::resources::query_result::send_to_create_resource(v4, (int)a2, v5);
  }
}
