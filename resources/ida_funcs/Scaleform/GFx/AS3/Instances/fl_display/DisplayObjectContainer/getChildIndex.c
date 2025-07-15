void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::getChildIndex(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        int *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *child)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  int DisplayIndex; // eax
  Scaleform::GFx::AS3::VM *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::VM::Error v12; // [esp+4h] [ebp-8h] BYREF

  if ( !child )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eNullPointerError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    v7 = pNode;
    if ( pNode->RefCount )
      return;
    goto LABEL_3;
  }
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(
                   (Scaleform::GFx::DisplayList *)&this->pDispObj.pObject[1].LastHitTestY,
                   child->pDispObj.pObject);
  if ( DisplayIndex >= 0 )
  {
    *result = DisplayIndex;
  }
  else
  {
    v9 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eMustBeChildError, v9);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v9, v10);
    v11 = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    v7 = v11;
    if ( !v11->RefCount )
LABEL_3:
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
