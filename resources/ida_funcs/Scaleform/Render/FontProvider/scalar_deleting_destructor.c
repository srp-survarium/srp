Scaleform::GFx::AS2::XMLFileLoader *__thiscall Scaleform::Render::FontProvider::`scalar deleting destructor'(
        Scaleform::GFx::AS2::XMLFileLoader *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS2::XMLFileLoader_vtbl *)&Scaleform::GFx::AS2::ASCSSFileLoader::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
