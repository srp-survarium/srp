int __thiscall Scaleform::Render::ImageDelegate::Update(Scaleform::Render::ImageDelegate *this)
{
  return ((int (__thiscall *)(Scaleform::Render::Image *))this->pImage.pObject->Update)(this->pImage.pObject);
}
