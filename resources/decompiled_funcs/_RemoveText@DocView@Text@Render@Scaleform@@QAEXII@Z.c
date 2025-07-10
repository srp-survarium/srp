void __thiscall Scaleform::Render::Text::DocView::RemoveText(
        Scaleform::Render::Text::DocView *this,
        unsigned int startPos,
        unsigned int endPos)
{
  if ( endPos < startPos )
    Scaleform::Render::Text::StyledText::Remove(this->pDocument.pObject, startPos, 0);
  else
    Scaleform::Render::Text::StyledText::Remove(this->pDocument.pObject, startPos, endPos - startPos);
}
