Scaleform::GFx::AS3::Instances::fl_text::StaticText *__thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_text::StaticText *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::~DisplayObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
