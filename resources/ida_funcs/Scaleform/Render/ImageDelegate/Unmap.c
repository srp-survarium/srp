int __thiscall Scaleform::Render::ImageDelegate::Unmap(Scaleform::Render::ImageDelegate *this)
{
  return ((int (__thiscall *)(Scaleform::Render::Image *))this->pImage.pObject->Unmap)(this->pImage.pObject);
}
