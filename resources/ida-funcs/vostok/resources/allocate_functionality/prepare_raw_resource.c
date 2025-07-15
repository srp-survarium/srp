void __userpurge vostok::resources::allocate_functionality::prepare_raw_resource(
        vostok::resources::query_result *query@<edi>,
        vostok::resources::allocate_functionality *this,
        vostok::resources::reallocating_bool reallocating)
{
  vostok::resources::class_id_enum m_class_id; // esi
  vostok::resources::query_result *v4; // [esp-4h] [ebp-Ch]
  vostok::resources::reallocating_bool v5; // [esp+0h] [ebp-8h]

  m_class_id = query->m_class_id;
  if ( vostok::resources::cook_base::find_managed_cook(m_class_id)
    || vostok::resources::cook_base::find_unmanaged_cook(m_class_id) )
  {
    vostok::resources::allocate_functionality::prepare_raw_resource_for_managed_or_unmanaged_cook(query, this, v5);
  }
  else if ( vostok::resources::cook_base::find_inplace_managed_cook(m_class_id)
         || !vostok::resources::resources_manager::find_cook(m_class_id) )
  {
    vostok::resources::allocate_functionality::prepare_raw_resource_for_inplace_managed_cook(query, this, v5);
  }
  else
  {
    vostok::resources::cook_base::find_inplace_unmanaged_cook(m_class_id);
    vostok::resources::allocate_functionality::prepare_raw_resource_for_inplace_unmanaged_cook(query, v4);
  }
}
