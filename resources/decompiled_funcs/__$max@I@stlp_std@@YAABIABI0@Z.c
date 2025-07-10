const unsigned int *__cdecl stlp_std::max<unsigned int>(const unsigned int *__a, const unsigned int *__b)
{
  const unsigned int *result; // eax

  result = __a;
  if ( *__a < *__b )
    return __b;
  return result;
}
