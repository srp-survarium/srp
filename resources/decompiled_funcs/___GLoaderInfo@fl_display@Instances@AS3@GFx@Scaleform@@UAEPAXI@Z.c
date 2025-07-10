Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *__thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::~LoaderInfo(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
