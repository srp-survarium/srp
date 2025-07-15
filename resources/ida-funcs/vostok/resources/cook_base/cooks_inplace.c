bool __cdecl vostok::resources::cook_base::cooks_inplace(vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  return !cook || (cook->m_flags.m_flags & 0x10) == 16;
}
