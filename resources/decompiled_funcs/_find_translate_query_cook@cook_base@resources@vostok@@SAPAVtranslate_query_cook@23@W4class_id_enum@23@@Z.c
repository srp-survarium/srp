vostok::resources::translate_query_cook *__fastcall vostok::resources::cook_base::find_translate_query_cook(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::translate_query_cook *result; // eax

  result = (vostok::resources::translate_query_cook *)vostok::resources::resources_manager::find_cook(resource_class);
  if ( result )
    return (result->m_flags.m_flags & 8) != 8 ? 0 : result;
  return result;
}
