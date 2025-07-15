Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *__thiscall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::`vector deleting destructor'(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        char a2)
{
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::~EventDispatcher(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
