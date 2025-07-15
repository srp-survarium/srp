Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuClipboardItems *__thiscall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuClipboardItems::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuClipboardItems *this,
        char a2)
{
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
