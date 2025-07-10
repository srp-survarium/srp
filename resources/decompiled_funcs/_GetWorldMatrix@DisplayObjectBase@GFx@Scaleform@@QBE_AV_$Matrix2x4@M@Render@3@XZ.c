Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix2x4<float> *result)
{
  result->M[0][0] = 1.0;
  result->M[0][1] = 0.0;
  result->M[0][2] = 0.0;
  result->M[0][3] = 0.0;
  result->M[1][0] = 0.0;
  result->M[1][2] = 0.0;
  result->M[1][3] = 0.0;
  result->M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, result);
  return result;
}
