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
  wchar_t *TextBufForCustomFormat; // ebp
  Scaleform::Render::Text::Allocator *Allocator; // eax
  const Scaleform::Render::Text::Paragraph *v11; // eax
  const __m128i *pText; // ecx
  unsigned int v13; // edi
  const __m128i *v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // [esp-Ch] [ebp-1Ch]
  unsigned int v17; // [esp+8h] [ebp-8h]
  wchar_t *v18; // [esp+Ch] [ebp-4h]

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
    v17 = Length;
    if ( this->LineCursor.ComposStrPosition < StartIndex
      || this->LineCursor.ComposStrPosition > StartIndex + Scaleform::Render::Text::Paragraph::GetLength(pParagraph) )
    {
      v8 = 0;
    }
    else
    {
      v8 = 1;
      v17 = this->LineCursor.ComposStrLength + Scaleform::Render::Text::Paragraph::GetLength(this->pParagraph);
      v7 = v17;
    }
    if ( v7 >= 0x100 )
    {
      Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this->pDocView->pDocument.pObject);
      TextBufForCustomFormat = (wchar_t *)Allocator->pHeap->Alloc(Allocator->pHeap, 2 * v7 + 2, 0);
    }
    else
    {
      TextBufForCustomFormat = this->TextBufForCustomFormat;
    }
    v11 = this->pParagraph;
    pText = (const __m128i *)v11->Text.pText;
    v18 = v11->Text.pText;
    if ( v8 && this->LineCursor.ComposStrLength )
    {
      v13 = this->LineCursor.ComposStrPosition - v11->StartIndex;
      memcpy((int)TextBufForCustomFormat, pText, 2 * v13);
      v16 = 2 * this->LineCursor.ComposStrLength;
      v14 = (const __m128i *)this->LineCursor.pComposStr.pObject->GetText(this->LineCursor.pComposStr.pObject);
      memcpy((int)&TextBufForCustomFormat[v13], v14, v16);
      v15 = Scaleform::Render::Text::Paragraph::GetLength(this->pParagraph);
      memcpy(
        (int)&TextBufForCustomFormat[v13 + this->LineCursor.ComposStrLength],
        (const __m128i *)&v18[v13],
        2 * (v15 - v13));
      v7 = v17;
    }
    else
    {
      memcpy((int)TextBufForCustomFormat, pText, 2 * v7);
    }
    TextBufForCustomFormat[v7] = 0;
    this->TextBufLen = v7;
    this->pTextBufForCustomFormat = TextBufForCustomFormat;
  }
}
