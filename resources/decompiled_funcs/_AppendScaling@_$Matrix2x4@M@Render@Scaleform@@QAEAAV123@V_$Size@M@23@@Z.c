Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::AppendScaling(
        Scaleform::Render::Matrix2x4<float> *this,
        Scaleform::Render::Size<float> scale)
{
  Scaleform::Render::Matrix2x4<float> *result; // eax

  result = this;
  this->M[0][0] = this->M[0][0] * scale.Width;
  this->M[0][1] = this->M[0][1] * scale.Width;
  this->M[0][2] = scale.Width * this->M[0][2];
  this->M[0][3] = scale.Width * this->M[0][3];
  this->M[1][0] = scale.Height * this->M[1][0];
  this->M[1][1] = this->M[1][1] * scale.Height;
  this->M[1][2] = this->M[1][2] * scale.Height;
  this->M[1][3] = scale.Height * this->M[1][3];
  return result;
}
