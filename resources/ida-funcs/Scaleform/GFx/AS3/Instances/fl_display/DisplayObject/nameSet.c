void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v7; // [esp-10h] [ebp-1Ch]
  Scaleform::StringDataPtr v8; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v9; // [esp+4h] [ebp-8h] BYREF

  pObject = this->pDispObj.pObject;
  if ( (pObject->Flags & 1) != 0 )
  {
    v8.pStr = "Timeline";
    v8.Size = 8;
    v7.pStr = "name";
    v7.Size = 4;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eConstWriteError, this->pTraits.pObject->pVM, v7, v8);
    Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v5);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    Scaleform::GFx::DisplayObject::SetName(pObject, (int)value);
    this->pDispObj.pObject->Flags &= ~2u;
  }
}
