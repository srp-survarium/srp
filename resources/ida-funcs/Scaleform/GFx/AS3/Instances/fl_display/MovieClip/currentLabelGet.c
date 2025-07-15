void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::currentLabelGet(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // edi
  _DWORD *v4; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v7; // zf
  Scaleform::GFx::ASStringManager *pManager; // esi
  Scaleform::GFx::ASStringNode *v9; // ecx
  Scaleform::GFx::ASStringNode *p_NullStringNode; // esi
  unsigned int fr; // [esp+8h] [ebp-4h] BYREF

  pObject = this->pDispObj.pObject;
  pVM = this->pTraits.pObject->pVM;
  fr = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *))pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].GetY)(pObject);
  v4 = (_DWORD *)(*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *, unsigned int, unsigned int *))(pObject[1].pNameHandle.pObject->RefCount + 56))(
                   pObject[1].pNameHandle.pObject,
                   fr,
                   &fr);
  if ( v4 )
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   pVM->StringManagerRef->pStringManager,
                   (char *)((*v4 & 0xFFFFFFFC) + 8));
    StringNode->RefCount += 2;
    pNode = result->pNode;
    v7 = result->pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = StringNode;
    v7 = StringNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  }
  else
  {
    pManager = result->pNode->pManager;
    ++pManager->NullStringNode.RefCount;
    v9 = result->pNode;
    p_NullStringNode = &pManager->NullStringNode;
    v7 = result->pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    result->pNode = p_NullStringNode;
  }
}
