Scaleform::Render::Point3<double> *__thiscall Scaleform::Render::Matrix4x4<double>::Transform(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Point3<double> *result,
        const Scaleform::Render::Point3<double> *p)
{
  Scaleform::Render::Point3<double> *v3; // eax

  v3 = result;
  result->x = this->M[0][1] * p->y + p->x * this->M[0][0] + this->M[0][2] * p->z + this->M[0][3];
  result->y = this->M[1][0] * p->x + this->M[1][1] * p->y + this->M[1][2] * p->z + this->M[1][3];
  result->z = this->M[2][0] * p->x + this->M[2][1] * p->y + this->M[2][2] * p->z + this->M[2][3];
  return v3;
}
