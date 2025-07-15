void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::contains(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *child)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v6; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-8h] BYREF

  if ( child )
  {
    *result = Scaleform::GFx::DisplayObjContainer::Contains(
                (Scaleform::GFx::DisplayObjContainer *)this->pDispObj.pObject,
                (Scaleform::GFx::DisplayObjContainer *)child->pDispObj.pObject);
  }
  else
  {
    v6.pStr = "child";
    v6.Size = 5;
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eNullPointerError, this->pTraits.pObject->pVM, v6);
    Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v4);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
