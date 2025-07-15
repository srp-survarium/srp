void __userpurge vostok::math::color::get_RGBA(
        vostok::math::color *this@<ecx>,
        unsigned __int8 *a2@<eax>,
        float *r,
        float *g,
        float *b,
        float *a)
{
  *r = (double)*a2 * 0.0039215689;
  *g = (float)a2[1] * 0.0039215689;
  *b = (float)a2[2] * 0.0039215689;
  *a = (float)a2[3] * 0.0039215689;
}
