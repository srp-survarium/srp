void __thiscall Scaleform::Render::ScreenToWorld::VectorMult(
        Scaleform::Render::ScreenToWorld *this,
        float *po,
        const float *pa,
        float x,
        float y,
        float z,
        float w)
{
  *po = pa[3] * w + pa[2] * z + *pa * x + pa[1] * y;
  po[1] = pa[4] * x + pa[5] * y + pa[6] * z + pa[7] * w;
  po[2] = pa[8] * x + pa[9] * y + pa[10] * z + pa[11] * w;
  po[3] = w * pa[15] + y * pa[13] + x * pa[12] + z * pa[14];
}
