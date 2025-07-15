Scaleform::Render::Point<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GetProjectionCenter(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *result)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // eax
  double x; // st7
  Scaleform::Render::Point<float> *p_ProjectionCenter; // ecx
  Scaleform::Render::Point<float> *v5; // eax

  pPerspectiveData = this->pPerspectiveData;
  if ( pPerspectiveData )
  {
    x = pPerspectiveData->ProjectionCenter.x;
    p_ProjectionCenter = &pPerspectiveData->ProjectionCenter;
    v5 = result;
    result->x = x;
    result->y = p_ProjectionCenter->y;
  }
  else
  {
    v5 = result;
    result->x = 0.0;
    result->y = 0.0;
  }
  return v5;
}
