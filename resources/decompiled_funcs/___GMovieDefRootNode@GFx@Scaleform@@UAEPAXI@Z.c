Scaleform::GFx::MovieDefRootNode *__thiscall Scaleform::GFx::MovieDefRootNode::`scalar deleting destructor'(
        Scaleform::GFx::MovieDefRootNode *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::MovieDefRootNode_vtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pFontManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
