void __thiscall Scaleform::Render::DICommand_GetPixel32::DICommand_GetPixel32(
        Scaleform::Render::DICommand_GetPixel32 *this,
        Scaleform::Render::DrawableImage *image,
        unsigned int x,
        unsigned int y,
        Scaleform::Render::Color *result)
{
  this->__vftable = (Scaleform::Render::DICommand_GetPixel32_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->X = x;
  this->__vftable = (Scaleform::Render::DICommand_GetPixel32_vtbl *)&Scaleform::Render::DICommand_GetPixel32::`vftable';
  this->Y = y;
  this->Result = result;
}
