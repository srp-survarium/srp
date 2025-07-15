double __thiscall Scaleform::GFx::AS2::BitmapFilterObject::GetDistance(Scaleform::GFx::AS2::BitmapFilterObject *this)
{
  Scaleform::Render::Filter *pObject; // eax

  pObject = this->pFilter.pObject;
  if ( pObject && pObject->Type <= (unsigned int)Filter_GradientBevel )
    return *(float *)&pObject[3].RefCount;
  else
    return 0.0;
}
