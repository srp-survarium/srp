Scaleform::GFx::Text::StyleManager *__thiscall Scaleform::GFx::Text::StyleManager::`vector deleting destructor'(
        Scaleform::GFx::Text::StyleManager *this,
        char a2)
{
  Scaleform::GFx::Text::StyleManager::~StyleManager(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
