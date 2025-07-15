Scaleform::GFx::AS3::ASSharedObjectLoader *__thiscall Scaleform::GFx::AS2::GASSharedObjectLoader::`vector deleting destructor'(
        Scaleform::GFx::AS3::ASSharedObjectLoader *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // eax

  Data = this->ObjectStack.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
