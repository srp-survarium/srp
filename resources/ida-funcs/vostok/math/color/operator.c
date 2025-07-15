vostok::math::color *__userpurge vostok::math::color::operator*@<eax>(
        vostok::math::color *this@<ecx>,
        unsigned __int8 *a2@<esi>,
        vostok::math::color *result,
        const float intensity)
{
  int v4; // ebx
  unsigned int v5; // ebx
  unsigned __int8 v6; // al
  unsigned int v7; // ebx
  vostok::math::color *v8; // eax

  v4 = (unsigned __int8)vostok::math::floor((float)a2[2] * 0.40000001);
  v5 = ((vostok::math::floor((float)a2[3] * 0.40000001) << 8) | v4) << 8;
  v6 = vostok::math::floor((float)a2[1] * 0.40000001);
  v7 = (unsigned __int8)vostok::math::floor((float)*a2 * 0.40000001) | ((v6 | v5) << 8);
  v8 = result;
  result->m_value = v7;
  return v8;
}
