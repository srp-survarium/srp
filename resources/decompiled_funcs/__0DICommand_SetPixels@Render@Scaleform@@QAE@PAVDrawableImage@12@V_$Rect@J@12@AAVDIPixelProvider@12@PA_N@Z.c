void __thiscall Scaleform::Render::DICommand_SetPixels::DICommand_SetPixels(
        Scaleform::Render::DICommand_SetPixels *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::Rect<long> destRect,
        Scaleform::Render::DIPixelProvider *provider,
        bool *result)
{
  this->__vftable = (Scaleform::Render::DICommand_SetPixels_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->__vftable = (Scaleform::Render::DICommand_SetPixels_vtbl *)&Scaleform::Render::DICommand_SetPixels::`vftable';
  this->DestRect = destRect;
  this->Provider = provider;
  this->Result = result;
}
