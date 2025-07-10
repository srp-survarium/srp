Scaleform::Render::Matrix3x4<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *result)
{
  memset((int)result, 0, sizeof(Scaleform::Render::Matrix3x4<float>));
  result->M[0][0] = 1.0;
  result->M[1][1] = 1.0;
  result->M[2][2] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(this, result);
  return result;
}
