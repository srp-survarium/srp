void __thiscall Scaleform::GFx::Text::EditorKit::CutToClipboard(
        Scaleform::GFx::Text::EditorKit *this,
        Scaleform::Render::Text::Paragraph *startPos,
        Scaleform::Render::Text::Paragraph *endPos,
        bool useRichClipboard)
{
  Scaleform::Render::Text::Paragraph *v5; // esi
  Scaleform::Render::Text::Paragraph *v6; // edi
  Scaleform::Render::Text::DocView *pObject; // ebx

  if ( this->pClipboard.pObject )
  {
    v5 = endPos;
    v6 = startPos;
    if ( endPos < startPos )
    {
      v5 = startPos;
      v6 = endPos;
    }
    Scaleform::GFx::Text::EditorKit::CopyToClipboard(this, v6, v5, useRichClipboard);
    if ( !this->IsReadOnly(this) )
    {
      pObject = this->pDocView.pObject;
      if ( v5 < v6 )
        Scaleform::Render::Text::StyledText::Remove(pObject->pDocument.pObject, v6, (unsigned int)v6, 0);
      else
        Scaleform::Render::Text::StyledText::Remove(
          pObject->pDocument.pObject,
          v6,
          (unsigned int)v6,
          (char *)v5 - (char *)v6);
    }
  }
}
