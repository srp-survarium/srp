vostok::math::color *__usercall vostok::math::color::operator*@<eax>(
        vostok::math::color *this@<ecx>,
        unsigned int *a2@<edi>,
        unsigned __int8 *a3@<esi>)
{
  int v3; // ebx
  unsigned int v4; // ebx
  unsigned __int8 v5; // al

  v3 = (unsigned __int8)vostok::math::floor((float)a3[2] * 0.40000001);
  v4 = ((vostok::math::floor((float)a3[3] * 0.40000001) << 8) | v3) << 8;
  v5 = vostok::math::floor((float)a3[1] * 0.40000001);
  *a2 = (unsigned __int8)vostok::math::floor((float)*a3 * 0.40000001) | ((v5 | v4) << 8);
  return (vostok::math::color *)a2;
}
