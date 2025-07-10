void __thiscall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::objectIDGet(
        Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this,
        Scaleform::RefCountVImpl *result)
{
  Scaleform::RefCountVImpl *v2; // ebx
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v5; // ecx
  Scaleform::GFx::LogState *pObject; // esi

  v2 = result;
  pNode = this->pTraits.pObject->pVM->StringManagerRef->Builtins[2].pNode;
  ++pNode->RefCount;
  v5 = (Scaleform::GFx::ASStringNode *)v2->__vftable;
  if ( v2->__vftable[1].~Scaleform::RefCountVImpl-- == (void (__thiscall *)(struct Scaleform::RefCountVImpl *))1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v2->__vftable = (Scaleform::RefCountVImpl_vtbl *)pNode;
  pObject = Scaleform::GFx::StateBag::GetLogState(
              (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 2,
              (Scaleform::Ptr<Scaleform::GFx::LogState> *)&result)->pObject;
  if ( result )
    Scaleform::RefCountImpl::Release(result);
  if ( pObject )
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
      &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
      "ExternalInterface::objectID is not supported.");
}
