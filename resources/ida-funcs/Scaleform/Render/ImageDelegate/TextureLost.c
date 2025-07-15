void __thiscall Scaleform::Render::ImageDelegate::TextureLost(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::Image::TextureLossReason reason)
{
  this->pImage.pObject->TextureLost(this->pImage.pObject, reason);
}
