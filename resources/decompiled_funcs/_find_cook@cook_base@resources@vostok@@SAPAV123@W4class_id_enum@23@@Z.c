// attributes: thunk
vostok::resources::cook_base *__fastcall vostok::resources::cook_base::find_cook(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  return vostok::resources::resources_manager::find_cook(resource_class);
}
