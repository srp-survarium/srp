void __thiscall Scaleform::GFx::DrawTextImpl::SetCxform(
        Scaleform::GFx::DrawTextImpl *this,
        const Scaleform::Render::Cxform *cx)
{
  qmemcpy(&Scaleform::Render::ContextImpl::Entry::getWritableData(this->pTextNode.pObject, 2u)[10], cx, 0x20u);
}
