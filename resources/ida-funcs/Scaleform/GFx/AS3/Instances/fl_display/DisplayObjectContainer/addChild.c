void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::addChild(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *child)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // ecx
  Scaleform::GFx::AS3::VM *v7; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::DisplayObject *pObject; // esi
  Scaleform::GFx::DisplayObject *v11; // ebx
  int v12; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v13; // ecx
  Scaleform::GFx::AS3::VM::Error v14; // [esp+8h] [ebp-8h] BYREF

  if ( !child )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eNullPointerError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v14.Message.pNode;
    --v14.Message.pNode->RefCount;
    v6 = pNode;
    if ( pNode->RefCount )
      return;
    goto LABEL_3;
  }
  if ( child == this )
  {
    v7 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eAddObjectItselfError, v7);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v7, v8);
    v9 = v14.Message.pNode;
    --v14.Message.pNode->RefCount;
    v6 = v9;
    if ( !v9->RefCount )
LABEL_3:
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  else
  {
    pObject = this->pDispObj.pObject;
    if ( !child->pDispObj.pObject )
      child->CreateStageObject(child);
    v11 = child->pDispObj.pObject;
    if ( pObject
      && (v12 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + pObject->AvmObjOffset)
                                           + 20))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
    {
      v13 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v12 - 36);
    }
    else
    {
      v13 = 0;
    }
    Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v13, v11);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)child);
  }
}
