void __thiscall Scaleform::GFx::DrawTextImpl::SetColor(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Color c,
        unsigned int startPos,
        unsigned int endPos)
{
  Scaleform::Render::TreeText::SetColor(this->pTextNode.pObject, c, startPos, endPos);
}
