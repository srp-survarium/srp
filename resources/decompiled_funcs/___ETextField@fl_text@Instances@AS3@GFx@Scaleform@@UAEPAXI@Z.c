Scaleform::GFx::AS3::Instances::fl_text::TextField *__thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::~InteractiveObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
