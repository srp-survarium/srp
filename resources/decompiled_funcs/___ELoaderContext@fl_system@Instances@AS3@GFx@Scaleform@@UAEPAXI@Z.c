Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *__thiscall Scaleform::GFx::AS3::Instances::fl_system::LoaderContext::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_system::LoaderContext::~LoaderContext(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
