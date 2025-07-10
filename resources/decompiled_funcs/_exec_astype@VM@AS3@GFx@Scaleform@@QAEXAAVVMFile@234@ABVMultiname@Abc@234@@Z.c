void __thiscall Scaleform::GFx::AS3::VM::exec_astype(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // eax
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::AS3::Value *pCurrent; // ebx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v9; // edi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::VM::Error v12; // [esp+4h] [ebp-8h] BYREF

  Kind = mn->Kind;
  if ( (Kind & 3) == 1 || (Kind & 4) != 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eIllegalOpMultinameError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v5,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    v7 = pNode;
    if ( pNode->RefCount )
      return;
LABEL_9:
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    return;
  }
  pCurrent = this->OpStack.pCurrent;
  v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
  if ( v9 && v9 != Scaleform::GFx::AS3::VM::GetClassTraits(this, pCurrent) )
  {
    Scaleform::GFx::AS3::Value::SetNull(pCurrent);
    return;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v12, eClassNotFoundError, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    v10,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  v11 = v12.Message.pNode;
  --v12.Message.pNode->RefCount;
  v7 = v11;
  if ( !v11->RefCount )
    goto LABEL_9;
}
