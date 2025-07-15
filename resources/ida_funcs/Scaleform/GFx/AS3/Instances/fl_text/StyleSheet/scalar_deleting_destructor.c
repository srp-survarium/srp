Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *__thiscall Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this,
        char a2)
{
  Scaleform::GFx::Text::StyleManager::~StyleManager(&this->CSS);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::~EventDispatcher(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
