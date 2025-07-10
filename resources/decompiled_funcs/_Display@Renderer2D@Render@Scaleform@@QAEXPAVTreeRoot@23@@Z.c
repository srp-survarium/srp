void __thiscall Scaleform::Render::Renderer2D::Display(
        Scaleform::Render::Renderer2D *this,
        Scaleform::Render::TreeRoot *node)
{
  Scaleform::Render::Renderer2DImpl::Draw(this->pImpl, node);
}
