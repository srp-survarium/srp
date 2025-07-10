double __thiscall Scaleform::GFx::DisplayObjectBase::GetFocalLength(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // eax

  pPerspectiveData = this->pPerspectiveData;
  if ( pPerspectiveData )
    return pPerspectiveData->FocalLength;
  else
    return 0.0;
}
