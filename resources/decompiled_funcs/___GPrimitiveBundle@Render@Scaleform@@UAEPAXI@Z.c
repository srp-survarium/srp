Scaleform::Render::PrimitiveBundle *__thiscall Scaleform::Render::PrimitiveBundle::`scalar deleting destructor'(
        Scaleform::Render::PrimitiveBundle *this,
        char a2)
{
  Scaleform::Render::Primitive::~Primitive(&this->Prim);
  this->__vftable = (Scaleform::Render::PrimitiveBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
