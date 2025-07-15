double __thiscall Scaleform::GFx::DisplayObjectBase::GetFOV(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // eax

  pPerspectiveData = this->pPerspectiveData;
  if ( pPerspectiveData )
    return pPerspectiveData->FieldOfView;
  else
    return 0.0;
}
