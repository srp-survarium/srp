Scaleform::Render::ImageFormat __thiscall Scaleform::Render::ImageDelegate::GetFormat(
        Scaleform::Render::SubImage *this)
{
  return this->pImage.pObject->GetFormat(this->pImage.pObject);
}
