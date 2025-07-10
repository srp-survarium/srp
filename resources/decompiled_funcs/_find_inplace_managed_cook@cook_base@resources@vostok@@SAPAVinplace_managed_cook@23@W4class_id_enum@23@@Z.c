vostok::resources::inplace_managed_cook *__fastcall vostok::resources::cook_base::find_inplace_managed_cook(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::inplace_managed_cook *result; // eax
  unsigned int m_flags; // ecx

  result = (vostok::resources::inplace_managed_cook *)vostok::resources::resources_manager::find_cook(resource_class);
  if ( !result )
    return 0;
  m_flags = result->m_flags.m_flags;
  if ( (m_flags & 0x20) == 0 || (m_flags & 0x10) == 0 || (m_flags & 8) != 0 )
    return 0;
  return result;
}
