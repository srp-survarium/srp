Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::Paragraph::GetTextFormatPtr(
        Scaleform::Render::Text::Paragraph *this,
        unsigned int startPos)
{
  Scaleform::Render::Text::TextFormat *v2; // edi
  Scaleform::Render::Text::TextFormat *pObject; // eax
  Scaleform::Render::Text::TextFormat *v4; // esi
  Scaleform::Render::Text::Paragraph::FormatRunIterator it; // [esp+8h] [ebp-24h] BYREF

  Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(
    &it,
    &this->FormatInfo,
    &this->Text,
    startPos);
  v2 = 0;
  if ( it.CurTextIndex < it.pText->Size )
  {
    pObject = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it)->PlaceHolder.pFormat.pObject;
    if ( pObject )
      v2 = pObject;
  }
  v4 = it.PlaceHolder.pFormat.pObject;
  if ( it.PlaceHolder.pFormat.pObject )
  {
    --it.PlaceHolder.pFormat.pObject->RefCount;
    if ( !v4->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v4);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  return v2;
}
