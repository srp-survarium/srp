void __userpurge Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::removeChildren(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::VM::ErrorID beginIndex,
        Scaleform::GFx::AS3::VM::ErrorID endIndex)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  int v6; // edx
  int v7; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v8; // ebx
  Scaleform::GFx::AS3::VM::ErrorID i; // esi
  int v10; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v14; // [esp+10h] [ebp-8h] BYREF

  pObject = this->pDispObj.pObject;
  v6 = (int)pObject[1].pRenNode.pObject;
  v14.ID = (Scaleform::GFx::AS3::VM::ErrorID)this;
  if ( beginIndex < 0 || beginIndex >= v6 || endIndex < 0 )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eParamRangeError, pVM);
    Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v12);
    pNode = v14.Message.pNode;
    --v14.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    v7 = (*(int (__thiscall **)(int, int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + pObject->AvmObjOffset)
                                         + 20))(
           (int)pObject + 4 * pObject->AvmObjOffset,
           a2);
    if ( v7 )
      v8 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v7 - 36);
    else
      v8 = 0;
    for ( i = beginIndex; i < endIndex; ++i )
    {
      if ( i >= v14.ID )
        break;
      Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChildAt(v8, beginIndex);
    }
    v10 = *(_DWORD *)(*(_DWORD *)(v14.Message.pNode->Size + 64) + 20);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 4))(v10, 2);
  }
}
