void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  pObject = this->pDispObj.pObject;
  if ( (pObject->Flags & 1) != 0 )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eConstWriteError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    Scaleform::GFx::DisplayObject::SetName(pObject, (int)value);
    this->pDispObj.pObject->Flags &= ~2u;
  }
}
