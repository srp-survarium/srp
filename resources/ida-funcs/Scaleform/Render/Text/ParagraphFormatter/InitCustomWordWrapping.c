void __thiscall Scaleform::Render::Text::ParagraphFormatter::InitCustomWordWrapping(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::DocView::DocumentListener *pObject; // eax
  bool v3; // al
  unsigned int Length; // eax
  const Scaleform::Render::Text::Paragraph *pParagraph; // ecx
  unsigned int StartIndex; // ebx
  unsigned int v7; // edi
  char v8; // bl
  unsigned __int8 *TextBufForCustomFormat; // ebp
  Scaleform::Render::Text::Allocator *Allocator; // eax
  const Scaleform::Render::Text::Paragraph *v11; // eax
  unsigned __int8 *pText; // ecx
  unsigned int v13; // edi
  unsigned __int8 *v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // [esp-Ch] [ebp-1Ch]
  unsigned int reqBufSize; // [esp+8h] [ebp-8h]
  const wchar_t *paraText; // [esp+Ch] [ebp-4h]

  pObject = this->pDocView->pDocumentListener.pObject;
  v3 = pObject && (pObject->HandlersMask & 1) != 0;
  this->HasLineFormatHandler = v3;
  this->pTextBufForCustomFormat = 0;
  if ( v3 )
  {
    Length = Scaleform::Render::Text::Paragraph::GetLength(this->pParagraph);
    pParagraph = this->pParagraph;
    StartIndex = pParagraph->StartIndex;
    v7 = Length;
    reqBufSize = Length;
    if ( this->LineCursor.ComposStrPosition < StartIndex
      || this->LineCursor.ComposStrPosition > StartIndex + Scaleform::Render::Text::Paragraph::GetLength(pParagraph) )
    {
      v8 = 0;
    }
    else
    {
      v8 = 1;
      reqBufSize = this->LineCursor.ComposStrLength + Scaleform::Render::Text::Paragraph::GetLength(this->pParagraph);
      v7 = reqBufSize;
    }
    if ( v7 >= 0x100 )
    {
      Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this->pDocView->pDocument.pObject);
      TextBufForCustomFormat = (unsigned __int8 *)Allocator->pHeap->Alloc(Allocator->pHeap, 2 * v7 + 2, 0);
    }
    else
    {
      TextBufForCustomFormat = (unsigned __int8 *)this->TextBufForCustomFormat;
    }
    v11 = this->pParagraph;
    pText = (unsigned __int8 *)v11->Text.pText;
    paraText = v11->Text.pText;
    if ( v8 && this->LineCursor.ComposStrLength )
    {
      v13 = this->LineCursor.ComposStrPosition - v11->StartIndex;
      memcpy(TextBufForCustomFormat, pText, 2 * v13);
      v16 = 2 * this->LineCursor.ComposStrLength;
      v14 = (unsigned __int8 *)this->LineCursor.pComposStr.pObject->GetText(this->LineCursor.pComposStr.pObject);
      memcpy(&TextBufForCustomFormat[2 * v13], v14, v16);
      v15 = Scaleform::Render::Text::Paragraph::GetLength(this->pParagraph);
      memcpy(
        &TextBufForCustomFormat[2 * v13 + 2 * this->LineCursor.ComposStrLength],
        (unsigned __int8 *)&paraText[v13],
        2 * (v15 - v13));
      v7 = reqBufSize;
    }
    else
    {
      memcpy(TextBufForCustomFormat, pText, 2 * v7);
    }
    *(_WORD *)&TextBufForCustomFormat[2 * v7] = 0;
    this->TextBufLen = v7;
    this->pTextBufForCustomFormat = (wchar_t *)TextBufForCustomFormat;
  }
}
