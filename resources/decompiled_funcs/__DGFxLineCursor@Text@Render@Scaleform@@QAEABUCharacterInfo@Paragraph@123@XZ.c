const Scaleform::Render::Text::Paragraph::CharacterInfo *__thiscall Scaleform::Render::Text::GFxLineCursor::operator*(
        Scaleform::Render::Text::GFxLineCursor *this)
{
  Scaleform::Render::Text::Paragraph::CharactersIterator *p_CharIter; // ebx
  Scaleform::Render::Text::Paragraph::CharacterInfo *v3; // eax
  Scaleform::Render::Text::CompositionStringBase *pObject; // ecx
  unsigned int v5; // edi
  const wchar_t *v6; // eax
  Scaleform::Render::Text::CompositionStringBase *v7; // edi
  Scaleform::Render::Text::TextFormat *v8; // ebx
  const Scaleform::Render::Text::TextFormat *v9; // eax
  Scaleform::Render::Text::TextFormat *v10; // eax
  Scaleform::Render::Text::Allocator *v11; // eax
  Scaleform::Render::Text::TextFormat *TextFormat; // eax
  Scaleform::Render::Text::Paragraph::CharacterInfo *p_CharInfoHolder; // edi
  Scaleform::Render::Text::TextFormat *v14; // esi
  Scaleform::Render::Text::TextFormat *v15; // ebx
  bool v16; // zf
  const Scaleform::Render::Text::Paragraph::CharacterInfo *v17; // eax
  Scaleform::Render::Text::CompositionStringBase *v18; // edi
  Scaleform::Render::Text::Paragraph::CharacterInfo *v19; // ebp
  Scaleform::Render::Text::Paragraph::CharacterInfo *v20; // ebp
  Scaleform::Render::Text::TextFormat *v21; // eax
  Scaleform::Render::Text::Paragraph::CharacterInfo *RefCount; // ecx
  Scaleform::Render::Text::TextFormat *v23; // edi
  wchar_t Character; // dx
  const Scaleform::Render::Text::TextFormat *ComposStrCurPos; // [esp-4h] [ebp-40h]
  Scaleform::Render::Text::TextFormat result; // [esp+10h] [ebp-2Ch] BYREF

  p_CharIter = &this->CharIter;
  v3 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&this->CharIter);
  pObject = this->pComposStr.pObject;
  this->CharInfoHolder.Index = v3->Index;
  if ( pObject )
  {
    if ( pObject->GetLength(pObject) )
    {
      v5 = this->CharInfoHolder.Index + this->pParagraph->StartIndex;
      if ( v5 >= this->pComposStr.pObject->GetPosition(this->pComposStr.pObject) )
      {
        if ( v5 == this->pComposStr.pObject->GetPosition(this->pComposStr.pObject)
          && this->ComposStrCurPos < this->pComposStr.pObject->GetLength(this->pComposStr.pObject) )
        {
          this->CharInfoHolder.Index = this->ComposStrCurPos
                                     + Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter)->Index;
          v6 = this->pComposStr.pObject->GetText(this->pComposStr.pObject);
          v7 = this->pComposStr.pObject;
          this->CharInfoHolder.Character = v6[this->ComposStrCurPos];
          v8 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter)->pFormat.pObject;
          ComposStrCurPos = (const Scaleform::Render::Text::TextFormat *)this->ComposStrCurPos;
          v9 = (const Scaleform::Render::Text::TextFormat *)((int (__thiscall *)(Scaleform::Render::Text::CompositionStringBase *))v7->GetTextFormat)(v7);
          v10 = Scaleform::Render::Text::TextFormat::Merge(v8, &result, v9);
          v11 = (Scaleform::Render::Text::Allocator *)((int (__thiscall *)(Scaleform::Render::Text::CompositionStringBase *, Scaleform::Render::Text::TextFormat *))v7->GetAllocator)(
                                                        v7,
                                                        v10);
          TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(v11, ComposStrCurPos);
          p_CharInfoHolder = &this->CharInfoHolder;
          v14 = this->CharInfoHolder.pFormat.pObject;
          v15 = TextFormat;
          if ( v14 )
          {
            v16 = v14->RefCount-- == 1;
            if ( v16 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v14);
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
            }
          }
          p_CharInfoHolder->pFormat.pObject = v15;
          Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)&result.FontList);
          return p_CharInfoHolder;
        }
        v18 = this->pComposStr.pObject;
        v19 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter);
        this->CharInfoHolder.Index = v19->Index + v18->GetLength(v18);
      }
    }
  }
  v20 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter);
  v21 = v20->pFormat.pObject;
  RefCount = &this->CharInfoHolder;
  result.RefCount = (unsigned int)&this->CharInfoHolder;
  if ( v21 )
    ++v21->RefCount;
  v23 = RefCount->pFormat.pObject;
  if ( RefCount->pFormat.pObject )
  {
    v16 = v23->RefCount-- == 1;
    if ( v16 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v23);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
      RefCount = (Scaleform::Render::Text::Paragraph::CharacterInfo *)result.RefCount;
    }
  }
  RefCount->pFormat.pObject = v20->pFormat.pObject;
  if ( (this->pDocView->Flags & 0x10) != 0
    && Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter)->Character )
  {
    v17 = (const Scaleform::Render::Text::Paragraph::CharacterInfo *)result.RefCount;
    this->CharInfoHolder.Character = 42;
  }
  else
  {
    Character = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter)->Character;
    v17 = (const Scaleform::Render::Text::Paragraph::CharacterInfo *)result.RefCount;
    this->CharInfoHolder.Character = Character;
  }
  return v17;
}
