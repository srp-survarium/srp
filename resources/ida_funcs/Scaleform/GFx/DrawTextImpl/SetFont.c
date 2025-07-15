void __thiscall Scaleform::GFx::DrawTextImpl::SetFont(
        Scaleform::GFx::DrawTextImpl *this,
        const char *pfontName,
        unsigned int startPos,
        unsigned int endPos)
{
  Scaleform::Render::TreeText::SetFont(this->pTextNode.pObject, pfontName, startPos, endPos);
}
