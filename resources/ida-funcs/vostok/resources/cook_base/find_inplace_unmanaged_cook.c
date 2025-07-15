vostok::resources::inplace_unmanaged_cook *__cdecl vostok::resources::cook_base::find_inplace_unmanaged_cook(
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::inplace_unmanaged_cook *result; // eax
  vostok::resources::cook_base *v2; // [esp-4h] [ebp-4h]

  result = (vostok::resources::inplace_unmanaged_cook *)vostok::resources::resources_manager::find_cook(resource_class);
  if ( result )
    return vostok::resources::cook_base::cast_inplace_unmanaged_cook(v2, result);
  return result;
}
