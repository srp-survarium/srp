vostok::math::enum_evaluate_type __usercall vostok::math::string_to_evaluate_type@<eax>(const char *name@<esi>)
{
  vostok::math::enum_evaluate_type result; // eax

  result = strcmp(name, "Age");
  if ( result )
    return strcmp(name, "Random") == 0;
  return result;
}
