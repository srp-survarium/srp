Scaleform::Render::Text::Paragraph *__thiscall Scaleform::Render::Text::StyledText::AppendNewParagraph(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  unsigned int Size; // eax
  Scaleform::Render::Text::Paragraph *pPara; // ecx
  unsigned int v5; // eax
  unsigned int StartIndex; // esi
  wchar_t *pText; // ecx
  unsigned int v8; // edx
  wchar_t *v9; // ecx
  Scaleform::Render::Text::Allocator *Allocator; // esi
  int v11; // eax
  unsigned int NewParagraphId; // ecx
  Scaleform::Render::Text::Paragraph *v13; // ebx
  Scaleform::Render::Text::Paragraph *v14; // esi
  Scaleform::Render::Text::ParagraphFormat *pObject; // eax
  unsigned int v17; // [esp-4h] [ebp-1Ch]
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper v18; // [esp+10h] [ebp-8h] BYREF
  unsigned int v19; // [esp+14h] [ebp-4h]

  Size = this->Paragraphs.Data.Size;
  v19 = 0;
  if ( Size )
  {
    pPara = this->Paragraphs.Data.Data[Size - 1].pPara;
    v5 = pPara->Text.Size;
    StartIndex = pPara->StartIndex;
    if ( v5 )
    {
      pText = pPara->Text.pText;
      v8 = v5 - 1;
      if ( pText && v8 < v5 )
        v9 = &pText[v8];
      else
        v9 = 0;
      if ( !*v9 )
        --v5;
    }
    v19 = StartIndex + v5;
  }
  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v11 = (int)Allocator->pHeap->Alloc(Allocator->pHeap, 40u, 0);
  if ( v11 )
  {
    *(_DWORD *)v11 = 0;
    *(_DWORD *)(v11 + 4) = 0;
    *(_DWORD *)(v11 + 8) = 0;
    *(_DWORD *)(v11 + 12) = 0;
    *(_DWORD *)(v11 + 16) = 0;
    *(_DWORD *)(v11 + 20) = 0;
    *(_DWORD *)(v11 + 24) = 0;
    *(_DWORD *)(v11 + 28) = 0;
    *(_WORD *)(v11 + 36) = 0;
    NewParagraphId = Allocator->NewParagraphId;
    Allocator->NewParagraphId = NewParagraphId + 1;
    *(_DWORD *)(v11 + 32) = NewParagraphId;
    v13 = (Scaleform::Render::Text::Paragraph *)v11;
  }
  else
  {
    v13 = 0;
  }
  v17 = this->Paragraphs.Data.Size + 1;
  v18.pPara = v13;
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Paragraphs.Data,
    &this->Paragraphs,
    v17);
  if ( &this->Paragraphs.Data.Data[this->Paragraphs.Data.Size] != (Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *)4 )
  {
    this->Paragraphs.Data.Data[this->Paragraphs.Data.Size - 1].pPara = v13;
    v18.pPara = 0;
  }
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper::~ParagraphPtrWrapper(&v18);
  v14 = this->Paragraphs.Data.Data[this->Paragraphs.Data.Size - 1].pPara;
  pObject = pdefParaFmt;
  if ( !pdefParaFmt )
    pObject = this->pDefaultParagraphFormat.pObject;
  Scaleform::Render::Text::Paragraph::SetFormat(v14, this->pTextAllocator.pObject, pObject);
  v14->StartIndex = v19;
  return v14;
}
