Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat> *__thiscall Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::operator=(
        Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat> *this,
        const Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat> *p)
{
  Scaleform::Render::Text::ParagraphFormat *pObject; // ebx
  Scaleform::Render::Text::ParagraphFormat *v4; // esi

  pObject = p->pFormat.pObject;
  if ( p->pFormat.pObject )
    ++pObject->RefCount;
  v4 = this->pFormat.pObject;
  if ( this->pFormat.pObject )
  {
    if ( v4->RefCount-- == 1 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4->pTabStops);
      v4->pTabStops = 0;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  this->pFormat.pObject = pObject;
  return this;
}
