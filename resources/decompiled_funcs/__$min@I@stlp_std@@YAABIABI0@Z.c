const unsigned int *__cdecl stlp_std::min<unsigned int>(const unsigned int *__a, const unsigned int *__b)
{
  const unsigned int *result; // eax

  result = __b;
  if ( *__b >= *__a )
    return __a;
  return result;
}
