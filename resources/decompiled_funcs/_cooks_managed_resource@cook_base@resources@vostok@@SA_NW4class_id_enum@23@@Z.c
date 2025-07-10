bool __fastcall vostok::resources::cook_base::cooks_managed_resource(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  return !cook || (cook->m_flags.m_flags & 0x20) == 32;
}
