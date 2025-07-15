bool __cdecl vostok::resources::cook_base::does_create_resource(vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  return cook && (cook->m_flags.m_flags & 8) != 8;
}
