Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *__thiscall Scaleform::GFx::AS3::Classes::fl_gfx::GamePad::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Classes::fl_gfx::GamePad *this,
        char a2)
{
  Scaleform::GFx::AS3::Classes::fl_gfx::GamePad::~GamePad(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
