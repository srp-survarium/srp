void __thiscall Scaleform::Render::DICommand_GetPixels::DICommand_GetPixels(
        Scaleform::Render::DICommand_GetPixels *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::Rect<long> srcRect,
        Scaleform::Render::DIPixelProvider *provider,
        bool *result)
{
  this->__vftable = (Scaleform::Render::DICommand_GetPixels_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->__vftable = (Scaleform::Render::DICommand_GetPixels_vtbl *)&Scaleform::Render::DICommand_GetPixels::`vftable';
  this->SourceRect = srcRect;
  this->Provider = provider;
  this->Result = result;
}
