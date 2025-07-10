const char *__usercall vostok::resources::test_allocator_name@<eax>(vostok::resources::class_id_enum class_id@<eax>)
{
  const char *result; // eax
  bool v2; // zf

  if ( class_id == test_resource_class1 )
    return "A";
  if ( class_id == test_resource_class2 )
    return "B";
  v2 = class_id == test_resource_class3;
  result = "C";
  if ( !v2 )
    return (const char *)&buf;
  return result;
}
