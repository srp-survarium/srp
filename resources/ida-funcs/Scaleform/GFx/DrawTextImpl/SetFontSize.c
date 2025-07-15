void __thiscall Scaleform::GFx::DrawTextImpl::SetFontSize(
        Scaleform::GFx::DrawTextImpl *this,
        float fontSize,
        unsigned int startPos,
        unsigned int endPos)
{
  Scaleform::Render::TreeText::SetFontSize(this->pTextNode.pObject, fontSize, startPos, endPos);
}
