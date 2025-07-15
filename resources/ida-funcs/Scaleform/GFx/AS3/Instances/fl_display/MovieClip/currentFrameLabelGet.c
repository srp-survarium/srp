void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::currentFrameLabelGet(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // edi
  int v4; // ebx
  _DWORD *v5; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // esi
  Scaleform::GFx::ASStringNode *v10; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // esi
  unsigned int exactFr; // [esp+Ch] [ebp-4h] BYREF

  pObject = this->pDispObj.pObject;
  pVM = this->pTraits.pObject->pVM;
  v4 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(pObject);
  v5 = (_DWORD *)(*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *, int, unsigned int *))(pObject[1].pNameHandle.pObject->RefCount
                                                                                               + 56))(
                   pObject[1].pNameHandle.pObject,
                   v4,
                   &exactFr);
  if ( v5 && v4 == exactFr )
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   pVM->StringManagerRef->pStringManager,
                   (__m128i *)((*v5 & 0xFFFFFFFC) + 8));
    StringNode->RefCount += 2;
    pNode = result->pNode;
    v8 = result->pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = StringNode;
    v8 = StringNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  }
  else
  {
    pManager = result->pNode->pManager;
    ++pManager->NullStringNode.RefCount;
    v10 = result->pNode;
    p_NullStringNode = &pManager->NullStringNode;
    v8 = result->pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    result->pNode = p_NullStringNode;
  }
}
