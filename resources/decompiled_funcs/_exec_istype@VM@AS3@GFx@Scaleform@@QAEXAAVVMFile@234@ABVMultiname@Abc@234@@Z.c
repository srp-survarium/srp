void __thiscall Scaleform::GFx::AS3::VM::exec_istype(
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
  Scaleform::GFx::ASStringNode *v11; // eax
  char v12; // al
  Scaleform::GFx::AS3::VM::Error v13; // [esp+4h] [ebp-8h] BYREF

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
    goto LABEL_4;
  }
  pCurrent = this->OpStack.pCurrent;
  v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
  if ( v9 )
  {
    v12 = Scaleform::GFx::AS3::VM::IsOfType(this, pCurrent, (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v9);
    Scaleform::GFx::AS3::Value::SetBool(pCurrent, v12);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eClassNotFoundError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v10,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    v11 = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    v7 = v11;
    if ( !v11->RefCount )
LABEL_4:
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
