BOOL __usercall vostok::math::is_similar<float>@<eax>(const float *left@<eax>, const float *right, float epsilon)
{
  return epsilon > fabs(*left - *right);
}
