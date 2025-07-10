Scaleform::GFx::XML::RootNode *__thiscall Scaleform::GFx::XML::RootNode::`vector deleting destructor'(
        Scaleform::GFx::XML::RootNode *this,
        char a2)
{
  Scaleform::GFx::XML::Node *pObject; // ecx

  pObject = this->pDOMTree.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
