int *__userpurge vostok::math::color::color@<eax>(
        vostok::math::color *this@<ecx>,
        int *a2@<esi>,
        float a3@<xmm0>,
        vostok::math *r,
        float g,
        float a,
        float a7)
{
  *a2 = vostok::math::color_rgba(a3, r, g, a);
  return a2;
}
