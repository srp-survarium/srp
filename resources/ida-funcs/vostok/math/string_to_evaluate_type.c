vostok::math::enum_evaluate_type __cdecl vostok::math::string_to_evaluate_type(char *name)
{
  vostok::math::enum_evaluate_type result; // eax

  result = vostok::strings::compare(name, "Age");
  if ( result )
    return vostok::strings::compare(name, "Random") == 0;
  return result;
}
