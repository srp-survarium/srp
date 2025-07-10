Scaleform::Render::Text::Paragraph::CharactersIterator *__thiscall Scaleform::Render::Text::Paragraph::CharactersIterator::operator=(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this,
        const Scaleform::Render::Text::Paragraph::CharactersIterator *__that)
{
  Scaleform::Render::Text::TextFormat *pObject; // ebx

  if ( __that->PlaceHolder.pFormat.pObject )
    ++__that->PlaceHolder.pFormat.pObject->RefCount;
  pObject = this->PlaceHolder.pFormat.pObject;
  if ( this->PlaceHolder.pFormat.pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->PlaceHolder.pFormat.pObject = __that->PlaceHolder.pFormat.pObject;
  this->PlaceHolder.Index = __that->PlaceHolder.Index;
  this->PlaceHolder.Character = __that->PlaceHolder.Character;
  this->pFormatInfo = __that->pFormatInfo;
  this->FormatIterator = __that->FormatIterator;
  this->pText = __that->pText;
  this->CurTextIndex = __that->CurTextIndex;
  return this;
}
