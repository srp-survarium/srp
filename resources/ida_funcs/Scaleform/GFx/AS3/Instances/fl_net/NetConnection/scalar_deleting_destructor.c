Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *__thiscall Scaleform::GFx::AS3::Instances::fl_net::NetConnection::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
