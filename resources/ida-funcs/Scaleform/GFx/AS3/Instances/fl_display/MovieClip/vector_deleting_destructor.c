Scaleform::GFx::AS3::Instances::fl_display::MovieClip *__thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Clear(&this->mFrameScript);
  Scaleform::GFx::AS3::Instances::fl_display::Sprite::~Sprite(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
