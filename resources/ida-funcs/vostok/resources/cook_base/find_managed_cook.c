vostok::resources::managed_cook *__cdecl vostok::resources::cook_base::find_managed_cook(
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::managed_cook *result; // eax
  unsigned int m_flags; // ecx

  result = (vostok::resources::managed_cook *)vostok::resources::resources_manager::find_cook(resource_class);
  if ( !result )
    return 0;
  m_flags = result->m_flags.m_flags;
  if ( (m_flags & 0x20) == 0 || (m_flags & 0x18) != 0 )
    return 0;
  return result;
}
