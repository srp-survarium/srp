bool __fastcall vostok::resources::cook_base::does_create_resource_if_no_file(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  return cook && vostok::resources::cook_base::does_create_resource_if_no_file(cook);
}
