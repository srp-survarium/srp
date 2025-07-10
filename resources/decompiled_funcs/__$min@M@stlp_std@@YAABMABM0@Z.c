const float *__usercall stlp_std::min<float>@<eax>(const float *__a@<ecx>, const float *__b@<eax>)
{
  if ( *__a <= *__b )
    return __a;
  return __b;
}
