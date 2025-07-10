Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::HAL::GetOrientationMatrix(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Matrix2x4<float> *result)
{
  Scaleform::Render::Matrix2x4<float> *v2; // eax
  float *pObject; // ecx
  double v4; // st7

  v2 = result;
  pObject = (float *)this->Matrices.pObject;
  v4 = pObject[88];
  pObject += 88;
  result->M[0][0] = v4;
  result->M[0][1] = pObject[1];
  result->M[0][2] = pObject[2];
  result->M[0][3] = pObject[3];
  result->M[1][0] = pObject[4];
  result->M[1][1] = pObject[5];
  result->M[1][2] = pObject[6];
  result->M[1][3] = pObject[7];
  return v2;
}
