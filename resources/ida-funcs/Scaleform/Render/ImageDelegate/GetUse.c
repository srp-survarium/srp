unsigned int __thiscall Scaleform::Render::ImageDelegate::GetUse(Scaleform::Render::SubImage *this)
{
  return this->pImage.pObject->GetUse(this->pImage.pObject);
}
