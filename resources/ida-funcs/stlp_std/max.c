const unsigned int *__cdecl stlp_std::max<unsigned int>(const unsigned int *__a, const unsigned int *__b)
{
  const unsigned int *result; // eax

  result = __a;
  if ( *__a < *__b )
    return __b;
  return result;
}


const float *__usercall stlp_std::max<float>@<eax>(const float *__a@<ecx>, const float *__b@<eax>)
{
  if ( *__b <= *__a )
    return __a;
  return __b;
}
