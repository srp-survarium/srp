Scaleform::GFx::AS3::Instances::fl_display::Sprite *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_display::Sprite::~Sprite(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
