void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::contains(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *child)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+0h] [ebp-8h] BYREF

  if ( child )
  {
    *result = Scaleform::GFx::DisplayObjContainer::Contains(
                (Scaleform::GFx::DisplayObjContainer *)this->pDispObj.pObject,
                (Scaleform::GFx::DisplayObjContainer *)child->pDispObj.pObject);
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eNullPointerError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v6.Message.pNode;
    --v6.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
