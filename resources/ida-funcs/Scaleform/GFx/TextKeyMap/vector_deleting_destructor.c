Scaleform::GFx::TextKeyMap *__thiscall Scaleform::GFx::TextKeyMap::`vector deleting destructor'(
        Scaleform::GFx::TextKeyMap *this,
        char a2)
{
  Scaleform::GFx::TextKeyMap::KeyMapEntry *Data; // eax

  Data = this->Map.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  this->__vftable = (Scaleform::GFx::TextKeyMap_vtbl *)&Scaleform::GFx::State::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
