Scaleform::GFx::AS2::StyleSheetObject *__thiscall Scaleform::GFx::AS2::StyleSheetObject::`scalar deleting destructor'(
        Scaleform::GFx::AS2::StyleSheetObject *this,
        char a2)
{
  Scaleform::GFx::Text::StyleManager::~StyleManager(&this->CSS);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
