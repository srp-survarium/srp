void __thiscall Scaleform::Render::DrawableImage::TextureLost(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Image::TextureLossReason reason)
{
  Scaleform::Render::RenderTarget *pObject; // ecx

  if ( reason == TLR_DeviceLost )
  {
    pObject = this->pRT.pObject;
    if ( pObject )
      pObject->Release(pObject);
    this->pRT.pObject = 0;
  }
}
