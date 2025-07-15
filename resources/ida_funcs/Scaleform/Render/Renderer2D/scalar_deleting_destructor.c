Scaleform::Render::Renderer2D *__thiscall Scaleform::Render::Renderer2D::`scalar deleting destructor'(
        Scaleform::Render::Renderer2D *this,
        char a2)
{
  Scaleform::Render::Renderer2DImpl *pImpl; // ecx

  pImpl = this->pImpl;
  this->__vftable = (Scaleform::Render::Renderer2D_vtbl *)&Scaleform::Render::Renderer2D::`vftable';
  if ( pImpl )
    ((void (__thiscall *)(Scaleform::Render::Renderer2DImpl *, int))pImpl->~Scaleform::Render::Renderer2DImpl)(pImpl, 1);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
