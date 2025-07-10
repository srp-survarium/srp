void __thiscall Scaleform::Render::Matrix2x4<float>::TransformByInverse(
        Scaleform::Render::Matrix2x4<float> *this,
        Scaleform::Render::Point<float> *result,
        const Scaleform::Render::Point<float> *p)
{
  float *v3; // eax
  Scaleform::Render::Matrix2x4<float> v4; // [esp+0h] [ebp-20h] BYREF

  v4.M[0][0] = this->M[0][0];
  v4.M[0][1] = this->M[0][1];
  v4.M[0][2] = this->M[0][2];
  v4.M[0][3] = this->M[0][3];
  v4.M[1][0] = this->M[1][0];
  v4.M[1][1] = this->M[1][1];
  v4.M[1][2] = this->M[1][2];
  v4.M[1][3] = this->M[1][3];
  v3 = (float *)Scaleform::Render::Matrix2x4<float>::Invert(&v4);
  result->x = v3[1] * p->y + *v3 * p->x + v3[3];
  result->y = v3[5] * p->y + v3[4] * p->x + v3[7];
}
