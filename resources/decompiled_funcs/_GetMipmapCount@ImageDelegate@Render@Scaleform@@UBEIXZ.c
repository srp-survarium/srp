unsigned int __thiscall Scaleform::Render::ImageDelegate::GetMipmapCount(Scaleform::Render::SubImage *this)
{
  return this->pImage.pObject->GetMipmapCount(this->pImage.pObject);
}
