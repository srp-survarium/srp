void __thiscall Scaleform::GFx::Text::EditorKit::CopyToClipboard(
        Scaleform::GFx::Text::EditorKit *this,
        const Scaleform::Render::Text::Paragraph *startPos,
        const Scaleform::Render::Text::Paragraph *endPos,
        bool useRichClipboard)
{
  Scaleform::Render::Text::DocView *pObject; // ecx
  const Scaleform::Render::Text::Paragraph *v6; // esi
  const Scaleform::Render::Text::Paragraph *v7; // edi
  Scaleform::Render::Text::StyledText *v8; // esi
  wchar_t *pText; // eax
  wchar_t *v10; // eax
  Scaleform::WStringBuffer pBuffer; // [esp+8h] [ebp-10h] BYREF

  if ( this->pClipboard.pObject )
  {
    pObject = this->pDocView.pObject;
    if ( (pObject->Flags & 0x10) == 0 )
    {
      v6 = endPos;
      v7 = startPos;
      if ( endPos < startPos )
      {
        v6 = startPos;
        v7 = endPos;
      }
      memset(&pBuffer, 0, sizeof(pBuffer));
      Scaleform::Render::Text::StyledText::GetText(
        pObject->pDocument.pObject,
        &pBuffer,
        (unsigned int)v7,
        (unsigned int)v6);
      if ( useRichClipboard )
      {
        v8 = Scaleform::Render::Text::StyledText::CopyStyledText(
               this->pDocView.pObject->pDocument.pObject,
               (unsigned int)v7,
               v6);
        pText = pBuffer.pText;
        if ( !pBuffer.pText )
          pText = (wchar_t *)&unk_6E53BC;
        Scaleform::GFx::TextClipboard::SetTextAndStyledText(this->pClipboard.pObject, pText, pBuffer.Length, v8);
        if ( v8 )
        {
          Scaleform::RefCountNTSImpl::Release(v8);
          Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
          return;
        }
      }
      else
      {
        v10 = pBuffer.pText;
        if ( !pBuffer.pText )
          v10 = (wchar_t *)&unk_6E53BC;
        Scaleform::GFx::TextClipboard::SetText(this->pClipboard.pObject, v10, pBuffer.Length);
      }
      Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
    }
  }
}
