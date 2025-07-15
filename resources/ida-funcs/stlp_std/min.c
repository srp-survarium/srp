const unsigned int *__cdecl stlp_std::min<unsigned int>(const unsigned int *__a, const unsigned int *__b)
{
  const unsigned int *result; // eax

  result = __b;
  if ( *__b >= *__a )
    return __a;
  return result;
}


const float *__usercall stlp_std::min<float>@<eax>(const float *__a@<ecx>, const float *__b@<eax>)
{
  if ( *__a <= *__b )
    return __a;
  return __b;
}
