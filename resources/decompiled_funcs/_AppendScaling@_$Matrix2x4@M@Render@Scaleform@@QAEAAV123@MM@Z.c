Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::AppendScaling(
        Scaleform::Render::Matrix2x4<float> *this,
        float sx,
        float sy)
{
  Scaleform::Render::Matrix2x4<float> *result; // eax

  result = this;
  this->M[0][0] = this->M[0][0] * sx;
  this->M[0][1] = this->M[0][1] * sx;
  this->M[0][2] = this->M[0][2] * sx;
  this->M[0][3] = this->M[0][3] * sx;
  this->M[1][0] = this->M[1][0] * sy;
  this->M[1][1] = this->M[1][1] * sy;
  this->M[1][2] = this->M[1][2] * sy;
  this->M[1][3] = this->M[1][3] * sy;
  return result;
}
