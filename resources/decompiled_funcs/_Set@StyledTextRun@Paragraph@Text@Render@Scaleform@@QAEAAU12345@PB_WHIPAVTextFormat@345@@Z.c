Scaleform::Render::Text::Paragraph::StyledTextRun *__thiscall Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
        Scaleform::Render::Text::Paragraph::StyledTextRun *this,
        const wchar_t *ptext,
        int index,
        unsigned int len,
        Scaleform::Render::Text::TextFormat *pfmt)
{
  Scaleform::Render::Text::TextFormat *pObject; // edi

  this->pText = ptext;
  this->Index = index;
  this->Length = len;
  if ( pfmt )
    ++pfmt->RefCount;
  pObject = this->pFormat.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pFormat.pObject = pfmt;
  return this;
}
