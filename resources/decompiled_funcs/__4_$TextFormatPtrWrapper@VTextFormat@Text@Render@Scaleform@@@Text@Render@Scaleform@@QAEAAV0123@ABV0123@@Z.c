Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat> *__thiscall Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::operator=(
        Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat> *this,
        const Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat> *p)
{
  Scaleform::Render::Text::TextFormat *pObject; // ebx
  Scaleform::Render::Text::TextFormat *v4; // edi

  pObject = p->pFormat.pObject;
  if ( p->pFormat.pObject )
    ++pObject->RefCount;
  v4 = this->pFormat.pObject;
  if ( this->pFormat.pObject )
  {
    if ( v4->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v4);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  this->pFormat.pObject = pObject;
  return this;
}
