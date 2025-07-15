Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::AS3::AvmButton::GetUpStateObject(
        Scaleform::GFx::AS3::AvmButton *this)
{
  if ( this->pDispObj[1].pPerspectiveData )
    return (Scaleform::GFx::DisplayObject *)this->pDispObj[1].pGeomData->X;
  else
    return 0;
}
