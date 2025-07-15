void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3toString(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  char v4; // bl
  unsigned int v5; // eax
  const char *pData; // eax
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  unsigned int v8; // eax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::StringDataPtr v12; // [esp-10h] [ebp-24h]
  Scaleform::StringDataPtr v13; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v14; // [esp+Ch] [ebp-8h] BYREF

  v4 = 0;
  v14.ID = 0;
  v5 = _this->Flags & 0x1F;
  if ( v5 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, _this);
  }
  else
  {
    if ( v5 && (v5 - 12 > 3 || _this->value.VS._1.VInt) )
    {
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
      v4 = 1;
      pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&_this)->pNode->pData;
    }
    else
    {
      pData = "null";
    }
    v13.pStr = "String";
    v13.Size = 6;
    v12.pStr = pData;
    if ( pData )
      v8 = strlen(pData);
    else
      v8 = 0;
    v12.Size = v8;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eIllegalOperandTypeError, vm, v12, v13);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v9);
    pNode = v14.Message.pNode;
    --v14.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( (v4 & 1) != 0 )
    {
      v11 = (Scaleform::GFx::ASStringNode *)_this;
      --_this->value.VS._2.VObj;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
  }
}
