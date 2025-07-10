Scaleform::Render::Text::Paragraph *__thiscall Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(
        Scaleform::Render::Text::StyledText *this,
        const Scaleform::Render::Text::Paragraph *srcPara)
{
  unsigned int Size; // eax
  unsigned int v4; // ebp
  Scaleform::Render::Text::Paragraph *pPara; // ecx
  unsigned int v6; // eax
  unsigned int StartIndex; // esi
  wchar_t *pText; // ecx
  unsigned int v9; // edx
  wchar_t *v10; // ecx
  Scaleform::Render::Text::Allocator *Allocator; // esi
  Scaleform::Render::Text::Paragraph *v12; // eax
  Scaleform::Render::Text::Paragraph *v13; // eax
  Scaleform::Render::Text::Paragraph *v14; // ebx
  Scaleform::Render::Text::Paragraph *result; // eax
  unsigned int v16; // [esp-4h] [ebp-14h]

  Size = this->Paragraphs.Data.Size;
  v4 = 0;
  if ( Size )
  {
    pPara = this->Paragraphs.Data.Data[Size - 1].pPara;
    v6 = pPara->Text.Size;
    StartIndex = pPara->StartIndex;
    if ( v6 )
    {
      pText = pPara->Text.pText;
      v9 = v6 - 1;
      if ( pText && v9 < v6 )
        v10 = &pText[v9];
      else
        v10 = 0;
      if ( !*v10 )
        --v6;
    }
    v4 = v6 + StartIndex;
  }
  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v12 = (Scaleform::Render::Text::Paragraph *)Allocator->pHeap->Alloc(Allocator->pHeap, 40u, 0);
  if ( v12 )
  {
    Scaleform::Render::Text::Paragraph::Paragraph(v12, srcPara, Allocator);
    v14 = v13;
  }
  else
  {
    v14 = 0;
  }
  v16 = this->Paragraphs.Data.Size + 1;
  srcPara = v14;
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Paragraphs.Data,
    &this->Paragraphs,
    v16);
  if ( &this->Paragraphs.Data.Data[this->Paragraphs.Data.Size] != (Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *)4 )
  {
    this->Paragraphs.Data.Data[this->Paragraphs.Data.Size - 1].pPara = v14;
    srcPara = 0;
  }
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper::~ParagraphPtrWrapper((Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *)&srcPara);
  result = this->Paragraphs.Data.Data[this->Paragraphs.Data.Size - 1].pPara;
  result->StartIndex = v4;
  return result;
}
