Scaleform::Render::Matrix3x4<float> *__thiscall Scaleform::Render::Matrix4x4<double>::operator Scaleform::Render::Matrix3x4<float>(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Matrix3x4<float> *result)
{
  Scaleform::Render::Matrix3x4<float> *v2; // eax

  v2 = result;
  result->M[0][0] = this->M[0][0];
  result->M[0][1] = this->M[0][1];
  result->M[0][2] = this->M[0][2];
  result->M[0][3] = this->M[0][3];
  result->M[1][0] = this->M[1][0];
  result->M[1][1] = this->M[1][1];
  result->M[1][2] = this->M[1][2];
  result->M[1][3] = this->M[1][3];
  result->M[2][0] = this->M[2][0];
  result->M[2][1] = this->M[2][1];
  result->M[2][2] = this->M[2][2];
  result->M[2][3] = this->M[2][3];
  return v2;
}
