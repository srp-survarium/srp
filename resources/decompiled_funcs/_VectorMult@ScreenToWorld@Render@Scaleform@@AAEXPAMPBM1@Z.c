void __thiscall Scaleform::Render::ScreenToWorld::VectorMult(
        Scaleform::Render::ScreenToWorld *this,
        float *po,
        const float *pa,
        const float *v)
{
  *po = pa[1] * v[1] + *pa * *v + pa[2] * v[2] + pa[3] * v[3];
  po[1] = pa[4] * *v + pa[5] * v[1] + pa[6] * v[2] + pa[7] * v[3];
  po[2] = pa[8] * *v + pa[9] * v[1] + pa[10] * v[2] + pa[11] * v[3];
  po[3] = pa[12] * *v + pa[13] * v[1] + pa[14] * v[2] + pa[15] * v[3];
}
