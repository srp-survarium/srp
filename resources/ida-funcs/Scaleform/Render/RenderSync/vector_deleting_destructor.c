Scaleform::Render::RenderSync *__thiscall Scaleform::Render::RenderSync::`vector deleting destructor'(
        Scaleform::Render::RenderSync *this,
        char a2)
{
  Scaleform::Render::RenderSync::~RenderSync(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
