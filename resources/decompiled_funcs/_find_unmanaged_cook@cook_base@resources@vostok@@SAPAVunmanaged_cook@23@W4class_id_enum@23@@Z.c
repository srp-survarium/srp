vostok::resources::unmanaged_cook *__fastcall vostok::resources::cook_base::find_unmanaged_cook(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::unmanaged_cook *result; // eax

  result = (vostok::resources::unmanaged_cook *)vostok::resources::resources_manager::find_cook(resource_class);
  if ( !result || (result->m_flags.m_flags & 0x38) != 0 )
    return 0;
  return result;
}
