void __thiscall Scaleform::GFx::MovieImpl::SetBackgroundColor(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Color color)
{
  this->BackgroundColor = color;
  Scaleform::Render::TreeRoot::SetBackgroundColor(this->pRenderRoot.pObject, &this->BackgroundColor);
}
