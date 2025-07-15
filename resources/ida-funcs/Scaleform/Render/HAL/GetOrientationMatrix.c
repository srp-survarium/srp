Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::HAL::GetOrientationMatrix(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Matrix2x4<float> *result)
{
  Scaleform::Render::Matrix2x4<float>::SetMatrix(result, &this->Matrices.pObject->Orient2D);
  return result;
}
