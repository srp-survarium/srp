void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::addChildAt(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *child,
        int index)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::AS3::VM *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::DisplayObject *pObject; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v13; // edx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v14; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::DisplayObject *v16; // esi
  int v17; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v18; // ecx
  Scaleform::GFx::AS3::VM *v19; // esi
  const Scaleform::GFx::AS3::VM::Error *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::AS3::VM::Error v22; // [esp+8h] [ebp-8h] BYREF

  if ( !child )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eNullPointerError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
    pNode = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
    v8 = pNode;
    if ( pNode->RefCount )
      return;
LABEL_22:
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    return;
  }
  if ( child == this )
  {
    v9 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eAddObjectItselfError, v9);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v9, v10);
    v11 = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
    v8 = v11;
    if ( v11->RefCount )
      return;
    goto LABEL_22;
  }
  pObject = this->pDispObj.pObject;
  if ( !child->pDispObj.pObject )
    child->CreateStageObject(child);
  v13 = result;
  v14 = result->pObject;
  if ( result->pObject )
  {
    if ( ((unsigned __int8)v14 & 1) != 0 )
    {
      result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v14 - 1);
    }
    else
    {
      RefCount = v14->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v14->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
        v13 = result;
      }
    }
    v13->pObject = 0;
  }
  if ( index < 0 || index > (int)pObject[1].pRenNode.pObject )
  {
    v19 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eParamRangeError, v19);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v19, v20);
    v21 = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
    v8 = v21;
    if ( v21->RefCount )
      return;
    goto LABEL_22;
  }
  v16 = child->pDispObj.pObject;
  v17 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + pObject->AvmObjOffset)
                                   + 20))((int)pObject + 4 * pObject->AvmObjOffset);
  if ( v17 )
    v18 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v17 - 36);
  else
    v18 = 0;
  Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(v18, v16, index);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)child);
}
