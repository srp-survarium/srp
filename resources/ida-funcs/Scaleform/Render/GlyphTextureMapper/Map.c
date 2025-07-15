Scaleform::Render::ImagePlane *__thiscall Scaleform::Render::GlyphTextureMapper::Map(
        Scaleform::Render::GlyphTextureMapper *this)
{
  unsigned int Method; // eax
  Scaleform::Render::ImagePlane *result; // eax

  Method = this->Method;
  if ( Method )
  {
    if ( Method == 2 )
    {
      if ( this->Mapped )
        return this->Data.pPlanes;
      if ( this->pRawImg.pObject->Map(this->pRawImg.pObject, &this->Data, 0, 0) )
      {
        this->Mapped = 1;
        return this->Data.pPlanes;
      }
    }
  }
  else
  {
    if ( this->Mapped )
      return this->Data.pPlanes;
    if ( this->pTexImg.pObject->Map(this->pTexImg.pObject, &this->Data, 0, 1u) )
    {
      result = this->Data.pPlanes;
      this->Mapped = 1;
      return result;
    }
  }
  return 0;
}
