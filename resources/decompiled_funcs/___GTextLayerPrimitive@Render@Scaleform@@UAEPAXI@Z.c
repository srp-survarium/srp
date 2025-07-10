Scaleform::Render::TextLayerPrimitive *__thiscall Scaleform::Render::TextLayerPrimitive::`scalar deleting destructor'(
        Scaleform::Render::TextLayerPrimitive *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::Render::Primitive::~Primitive(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
