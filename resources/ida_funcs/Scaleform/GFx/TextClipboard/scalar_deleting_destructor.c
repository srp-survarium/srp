Scaleform::GFx::TextClipboard *__thiscall Scaleform::GFx::TextClipboard::`scalar deleting destructor'(
        Scaleform::GFx::TextClipboard *this,
        char a2)
{
  Scaleform::Render::Text::StyledText *pStyledText; // ecx

  pStyledText = this->pStyledText;
  this->__vftable = (Scaleform::GFx::TextClipboard_vtbl *)&Scaleform::GFx::TextClipboard::`vftable';
  if ( pStyledText )
  {
    Scaleform::RefCountNTSImpl::Release(pStyledText);
    this->pStyledText = 0;
  }
  Scaleform::WStringBuffer::~WStringBuffer(&this->PlainText);
  this->__vftable = (Scaleform::GFx::TextClipboard_vtbl *)&Scaleform::GFx::State::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
