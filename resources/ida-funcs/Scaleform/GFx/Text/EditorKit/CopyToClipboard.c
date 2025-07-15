void __thiscall Scaleform::GFx::Text::EditorKit::CopyToClipboard(
        Scaleform::GFx::Text::EditorKit *this,
        Scaleform::Render::Text::Paragraph *startPos,
        Scaleform::Render::Text::Paragraph *endPos,
        bool useRichClipboard)
{
  Scaleform::Render::Text::DocView *pObject; // ecx
  Scaleform::Render::Text::Paragraph *v6; // esi
  unsigned int v7; // edi
  Scaleform::Render::Text::Paragraph *v8; // esi
  wchar_t *pText; // eax
  wchar_t *v10; // eax
  Scaleform::WStringBuffer wbuf; // [esp+8h] [ebp-10h] BYREF

  if ( this->pClipboard.pObject )
  {
    pObject = this->pDocView.pObject;
    if ( (pObject->Flags & 0x10) == 0 )
    {
      v6 = endPos;
      v7 = (unsigned int)startPos;
      if ( endPos < startPos )
      {
        v6 = startPos;
        v7 = (unsigned int)endPos;
      }
      memset(&wbuf, 0, sizeof(wbuf));
      Scaleform::Render::Text::StyledText::GetText(pObject->pDocument.pObject, &wbuf, v7, (unsigned int)v6);
      if ( useRichClipboard )
      {
        v8 = Scaleform::Render::Text::StyledText::CopyStyledText(this->pDocView.pObject->pDocument.pObject, v7, v6);
        pText = wbuf.pText;
        if ( !wbuf.pText )
          pText = (wchar_t *)&word_96B534;
        Scaleform::GFx::TextClipboard::SetTextAndStyledText(
          this->pClipboard.pObject,
          pText,
          wbuf.Length,
          (Scaleform::Render::Text::StyledText *)v8);
        if ( v8 )
        {
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v8);
          Scaleform::WStringBuffer::~WStringBuffer(&wbuf);
          return;
        }
      }
      else
      {
        v10 = wbuf.pText;
        if ( !wbuf.pText )
          v10 = (wchar_t *)&word_96B534;
        Scaleform::GFx::TextClipboard::SetText(this->pClipboard.pObject, v10, wbuf.Length);
      }
      Scaleform::WStringBuffer::~WStringBuffer(&wbuf);
    }
  }
}
