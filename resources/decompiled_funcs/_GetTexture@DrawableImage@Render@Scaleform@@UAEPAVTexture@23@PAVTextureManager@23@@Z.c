Scaleform::Render::Texture *__thiscall Scaleform::Render::DrawableImage::GetTexture(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::ImageBase *pObject; // ecx

  pObject = this->pDelegateImage.pObject;
  if ( pObject
    && pObject->GetImageType(pObject)
    && this->pDelegateImage.pObject->GetImageType(this->pDelegateImage.pObject) != Type_Other )
  {
    return (Scaleform::Render::Texture *)((int (__thiscall *)(Scaleform::Render::ImageBase *, Scaleform::Render::TextureManager *))this->pDelegateImage.pObject->__vftable[1].IsDelegate)(
                                           this->pDelegateImage.pObject,
                                           pmanager);
  }
  else
  {
    return this->pTexture.Value;
  }
}
