Scaleform::Render::Renderer2DImpl *__thiscall Scaleform::Render::Renderer2DImpl::`scalar deleting destructor'(
        Scaleform::Render::Renderer2DImpl *this,
        char a2)
{
  Scaleform::Render::Renderer2DImpl::~Renderer2DImpl(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
