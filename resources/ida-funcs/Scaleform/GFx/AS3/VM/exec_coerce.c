void __thiscall Scaleform::GFx::AS3::VM::exec_coerce(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // eax
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::AS3::Value *pCurrent; // edi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v9; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-8h] BYREF

  Kind = mn->Kind;
  if ( (Kind & 3) == 1 || (Kind & 4) != 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eIllegalOpMultinameError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v5,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    v7 = pNode;
    if ( pNode->RefCount )
      return;
LABEL_10:
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    return;
  }
  pCurrent = this->OpStack.pCurrent;
  v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
  if ( v9 )
  {
    if ( v9->Coerce(v9, pCurrent, pCurrent) )
      return;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eCheckTypeFailedError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v10,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eReadSealedError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v11,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
  }
  v12 = v13.Message.pNode;
  --v13.Message.pNode->RefCount;
  v7 = v12;
  if ( !v12->RefCount )
    goto LABEL_10;
}
