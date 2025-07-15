Scaleform::GFx::AS3::Classes::fl_vec::Vector *__thiscall Scaleform::GFx::AS3::Classes::fl_vec::Vector::ApplyTypeArgs(
        Scaleform::GFx::AS3::Classes::fl_vec::Vector *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VM *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::Class *VClass; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *v14; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *v15; // eax
  Scaleform::GFx::AS3::VM::Error v16; // [esp+8h] [ebp-8h] BYREF

  if ( argc != 1 )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eWrongTypeArgCountError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v16.Message.pNode;
    --v16.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return this;
  }
  v8 = argv->Flags & 0x1F;
  if ( v8 == 13 )
    goto LABEL_26;
  if ( !v8 )
    goto LABEL_13;
  if ( v8 - 12 <= 3 && !argv->value.VS._1.VInt )
  {
LABEL_26:
    if ( v8 - 12 > 3 || argv->value.VS._1.VInt )
    {
      VClass = argv->value.VS._1.VClass;
LABEL_15:
      pObject = (const Scaleform::GFx::AS3::ClassTraits::Traits *)VClass->pTraits.pObject;
      v14 = this->pTraits.pObject->pVM;
      if ( pObject == v14->TraitsInt.pObject )
        return (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::VM::GetClassVectorSInt(v14);
      if ( pObject == v14->TraitsUint.pObject )
        return (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::VM::GetClassVectorUInt(v14);
      if ( pObject == v14->TraitsNumber.pObject )
        return (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::VM::GetClassVectorNumber(v14);
      if ( pObject == v14->TraitsString.pObject )
        return (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::VM::GetClassVectorString(v14);
      v15 = Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(this, pObject);
      return (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::Traits::GetConstructor(v15->ITraits.pObject);
    }
LABEL_13:
    VClass = Scaleform::GFx::AS3::Traits::GetConstructor(this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
    goto LABEL_15;
  }
  v9 = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v16, eCorruptABCError, v9);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v9, v10);
  v11 = v16.Message.pNode;
  --v16.Message.pNode->RefCount;
  if ( v11->RefCount )
    return this;
  Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return this;
}
