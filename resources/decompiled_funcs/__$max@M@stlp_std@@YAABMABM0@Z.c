const float *__usercall stlp_std::max<float>@<eax>(const float *__a@<ecx>, const float *__b@<eax>)
{
  if ( *__b <= *__a )
    return __a;
  return __b;
}
