bool __fastcall vostok::resources::cook_base::allow_sync_load_from_inline(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  return cook && cook->allow_sync_load_from_inline(cook);
}
