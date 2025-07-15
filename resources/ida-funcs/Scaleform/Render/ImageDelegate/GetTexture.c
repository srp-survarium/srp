Scaleform::Render::Texture *__thiscall Scaleform::Render::ImageDelegate::GetTexture(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::TextureManager *pm)
{
  return this->pImage.pObject->GetTexture(this->pImage.pObject, pm);
}
