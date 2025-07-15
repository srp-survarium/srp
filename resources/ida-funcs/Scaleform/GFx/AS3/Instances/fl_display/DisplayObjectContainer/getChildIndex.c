void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::getChildIndex(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        int *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *child)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v6; // ecx
  int DisplayIndex; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::StringDataPtr v10; // [esp-8h] [ebp-14h]
  Scaleform::StringDataPtr v11; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v12; // [esp+4h] [ebp-8h] BYREF

  if ( !child )
  {
    v10.pStr = "child";
    v10.Size = 5;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eNullPointerError, this->pTraits.pObject->pVM, v10);
    Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v4);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    v6 = pNode;
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
    v11.pStr = "DisplayObject";
    v11.Size = 13;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eMustBeChildError, this->pTraits.pObject->pVM, v11);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v8);
    v9 = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    v6 = v9;
    if ( !v9->RefCount )
LABEL_3:
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}
