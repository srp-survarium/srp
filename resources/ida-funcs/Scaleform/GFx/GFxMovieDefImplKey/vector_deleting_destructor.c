Scaleform::GFx::GFxMovieDefImplKey *__thiscall Scaleform::GFx::GFxMovieDefImplKey::`vector deleting destructor'(
        Scaleform::GFx::GFxMovieDefImplKey *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::MovieDataDef *v4; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pBindStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pDataDef.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
