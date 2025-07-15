vostok::resources::cook_base::reuse_enum __cdecl vostok::resources::cook_base::reuse_type(
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  if ( cook )
    return cook->m_reuse_type;
  else
    return 1;
}
