void __thiscall Scaleform::GFx::DrawTextImpl::SetFontStyle(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::FontStyle fontStyle,
        unsigned int startPos,
        unsigned int endPos)
{
  Scaleform::Render::TreeText::SetFontStyle(this->pTextNode.pObject, fontStyle, startPos, endPos);
}
