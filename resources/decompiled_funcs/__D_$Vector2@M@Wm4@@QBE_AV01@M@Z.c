float *__usercall Wm4::Vector2<float>::operator*@<eax>(float *result@<eax>, float *a2@<ecx>, float a3@<xmm0>)
{
  *result = *a2 * a3;
  result[1] = a2[1] * a3;
  return result;
}
