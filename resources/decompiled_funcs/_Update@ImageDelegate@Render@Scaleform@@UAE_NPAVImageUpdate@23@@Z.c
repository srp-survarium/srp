int __thiscall Scaleform::Render::ImageDelegate::Update(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::ImageUpdate *pupdate)
{
  return ((int (__thiscall *)(Scaleform::Render::Image *, Scaleform::Render::ImageUpdate *))this->pImage.pObject->Update)(
           this->pImage.pObject,
           pupdate);
}
