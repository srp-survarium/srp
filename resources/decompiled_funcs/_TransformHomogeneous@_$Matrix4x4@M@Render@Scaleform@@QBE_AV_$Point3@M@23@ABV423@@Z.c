Scaleform::Render::Point3<float> *__thiscall Scaleform::Render::Matrix4x4<float>::TransformHomogeneous(
        Scaleform::Render::Matrix4x4<float> *this,
        Scaleform::Render::Point3<float> *result,
        const Scaleform::Render::Point3<float> *p)
{
  Scaleform::Render::Point3<float> *v4; // eax
  float w; // [esp+0h] [ebp-4h]
  float pa; // [esp+Ch] [ebp+8h]
  float pb; // [esp+Ch] [ebp+8h]
  float pc; // [esp+Ch] [ebp+8h]

  v4 = result;
  w = this->M[3][0] * p->x + this->M[3][1] * p->y + this->M[3][2] * p->z + this->M[3][3];
  pa = this->M[0][1] * p->y + p->x * this->M[0][0] + this->M[0][2] * p->z + this->M[0][3];
  result->x = pa / w;
  pb = this->M[1][0] * p->x + this->M[1][1] * p->y + this->M[1][2] * p->z + this->M[1][3];
  result->y = pb / w;
  pc = this->M[2][0] * p->x + this->M[2][1] * p->y + this->M[2][2] * p->z + this->M[2][3];
  result->z = pc / w;
  return v4;
}
