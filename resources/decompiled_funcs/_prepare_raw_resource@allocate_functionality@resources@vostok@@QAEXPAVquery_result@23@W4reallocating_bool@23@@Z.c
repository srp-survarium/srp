void __usercall vostok::resources::allocate_functionality::prepare_raw_resource(
        vostok::resources::query_result *query@<esi>,
        vostok::resources::allocate_functionality *reallocating@<edi>,
        vostok::resources::allocate_functionality *a3@<ecx>,
        vostok::resources::allocate_functionality *this)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::class_id_enum v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  vostok::resources::cook_base *v8; // eax
  vostok::resources::class_id_enum v9; // edx
  int v10; // ecx
  vostok::resources::cook_base *v11; // eax
  vostok::resources::class_id_enum v12; // edx
  int v13; // ecx
  unsigned int m_flags; // eax
  vostok::resources::class_id_enum v15; // edx
  int v16; // ecx

  cook = vostok::resources::resources_manager::find_cook((int)a3, query->m_class_id);
  if ( cook && (v7 = cook->m_flags.m_flags, (v7 & 0x20) != 0) && (v7 & 0x18) == 0
    || (v8 = vostok::resources::resources_manager::find_cook(v6, v5)) != 0 && (v8->m_flags.m_flags & 0x38) == 0 )
  {
    vostok::resources::allocate_functionality::prepare_raw_resource_for_managed_or_unmanaged_cook(
      query,
      reallocating,
      (vostok::resources::reallocating_bool)a3);
  }
  else
  {
    v11 = vostok::resources::resources_manager::find_cook(v10, v9);
    if ( v11 && (m_flags = v11->m_flags.m_flags, (m_flags & 0x20) != 0) && (m_flags & 0x10) != 0 && (m_flags & 8) == 0
      || !vostok::resources::resources_manager::find_cook(v13, v12) )
    {
      vostok::resources::allocate_functionality::prepare_raw_resource_for_inplace_managed_cook(
        query,
        reallocating,
        (vostok::resources::reallocating_bool)a3);
    }
    else
    {
      vostok::resources::cook_base::find_inplace_unmanaged_cook(v16, v15);
      vostok::resources::allocate_functionality::prepare_raw_resource_for_inplace_unmanaged_cook(query, a3);
    }
  }
}
