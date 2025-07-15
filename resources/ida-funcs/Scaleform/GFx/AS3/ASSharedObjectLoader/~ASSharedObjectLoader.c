void __thiscall Scaleform::GFx::AS3::ASSharedObjectLoader::~ASSharedObjectLoader(
        Scaleform::GFx::AS3::ASSharedObjectLoader *this)
{
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // eax

  Data = this->ObjectStack.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
