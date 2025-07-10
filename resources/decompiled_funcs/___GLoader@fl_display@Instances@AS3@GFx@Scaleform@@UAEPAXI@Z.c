Scaleform::GFx::AS3::Instances::fl_display::Loader *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Loader::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::Loader *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_display::Loader::~Loader(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
