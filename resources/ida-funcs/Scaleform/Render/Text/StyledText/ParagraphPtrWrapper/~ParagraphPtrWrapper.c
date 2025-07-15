void __thiscall Scaleform::Render::Text::StyledText::ParagraphPtrWrapper::~ParagraphPtrWrapper(
        Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *this)
{
  Scaleform::Render::Text::Paragraph *pPara; // esi

  pPara = this->pPara;
  if ( this->pPara )
  {
    Scaleform::Render::Text::Paragraph::~Paragraph(this->pPara);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)pPara);
  }
}
