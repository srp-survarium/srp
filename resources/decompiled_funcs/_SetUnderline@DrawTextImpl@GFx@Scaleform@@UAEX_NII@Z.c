void __thiscall Scaleform::GFx::DrawTextImpl::SetUnderline(
        Scaleform::GFx::DrawTextImpl *this,
        bool underline,
        unsigned int startPos,
        unsigned int endPos)
{
  Scaleform::Render::TreeText::SetUnderline(this->pTextNode.pObject, underline, startPos, endPos);
}
