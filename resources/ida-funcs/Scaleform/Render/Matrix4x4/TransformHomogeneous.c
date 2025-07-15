Scaleform::Render::Point3<float> *__thiscall Scaleform::Render::Matrix4x4<float>::TransformHomogeneous(
        Scaleform::Render::Matrix4x4<float> *this,
        Scaleform::Render::Point3<float> *result,
        const Scaleform::Render::Point3<float> *p)
{
  Scaleform::Render::Point3<float> *v4; // eax
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+Ch] [ebp+8h]
  float v7; // [esp+Ch] [ebp+8h]
  float v8; // [esp+Ch] [ebp+8h]

  v4 = result;
  v5 = this->M[3][0] * p->x + this->M[3][1] * p->y + this->M[3][2] * p->z + this->M[3][3];
  v6 = this->M[0][1] * p->y + p->x * this->M[0][0] + this->M[0][2] * p->z + this->M[0][3];
  result->x = v6 / v5;
  v7 = this->M[1][0] * p->x + this->M[1][1] * p->y + this->M[1][2] * p->z + this->M[1][3];
  result->y = v7 / v5;
  v8 = this->M[2][0] * p->x + this->M[2][1] * p->y + this->M[2][2] * p->z + this->M[2][3];
  result->z = v8 / v5;
  return v4;
}
