Scaleform::Render::MeshKeySet *__thiscall Scaleform::Render::MeshKeySet::`vector deleting destructor'(
        Scaleform::Render::MeshKeySet *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::Render::MeshKeySet_vtbl *)&Scaleform::Render::MeshKeySet::`vftable';
  Scaleform::Render::MeshKeySet::DestroyAllKeys(this);
  pObject = (Scaleform::RefCountVImpl *)this->pManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::Render::MeshKeySet_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
