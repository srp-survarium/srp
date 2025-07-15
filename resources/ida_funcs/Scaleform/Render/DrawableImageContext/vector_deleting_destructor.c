Scaleform::Render::DrawableImageContext *__thiscall Scaleform::Render::DrawableImageContext::`vector deleting destructor'(
        Scaleform::Render::DrawableImageContext *this,
        char a2)
{
  Scaleform::Render::DrawableImageContext::~DrawableImageContext(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::Render::DrawableImageContext::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::Render::DrawableImageContext::`vector deleting destructor'(
           (Scaleform::Render::DrawableImageContext *)(this - 8),
           a2);
}
