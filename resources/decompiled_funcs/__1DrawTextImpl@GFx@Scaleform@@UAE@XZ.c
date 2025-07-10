void __thiscall Scaleform::GFx::DrawTextImpl::~DrawTextImpl(Scaleform::GFx::DrawTextImpl *this)
{
  unsigned int Depth; // eax
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::GFx::DrawTextManager *v5; // ecx

  this->__vftable = (Scaleform::GFx::DrawTextImpl_vtbl *)&Scaleform::GFx::DrawTextImpl::`vftable';
  Depth = Scaleform::GFx::DrawTextImpl::GetDepth(this);
  if ( Depth != -1 )
    Scaleform::Render::TreeContainer::Remove(this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject, Depth, 1u);
  pObject = this->pTextNode.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  v5 = this->pDrawTextCtxt.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  this->__vftable = (Scaleform::GFx::DrawTextImpl_vtbl *)&Scaleform::GFx::DrawText::`vftable';
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
