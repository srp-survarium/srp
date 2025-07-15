Scaleform::GFx::XML::ParserHandler *__thiscall Scaleform::GFx::XML::ParserHandler::`vector deleting destructor'(
        Scaleform::GFx::XML::ParserHandler *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::XML::ParserHandler_vtbl *)&Scaleform::GFx::XML::ParserHandler::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
