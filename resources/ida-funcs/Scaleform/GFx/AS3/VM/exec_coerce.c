void __thiscall Scaleform::GFx::AS3::VM::exec_coerce(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v3; // edi
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // eax
  Scaleform::GFx::ASString *InternedString; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::AS3::VMFile *v8; // ebp
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v9; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v10; // ebx
  const char *pData; // eax
  unsigned int v12; // eax
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASString *v15; // eax
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *OpStack; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::StringDataPtr v19; // [esp-8h] [ebp-34h]
  Scaleform::StringDataPtr v20; // [esp-8h] [ebp-34h]
  Scaleform::StringDataPtr v21; // [esp-8h] [ebp-34h]
  Scaleform::GFx::AS3::ReadValueRef args; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+1Ch] [ebp-10h] BYREF

  v3 = mn;
  Kind = mn->Kind;
  if ( (Kind & 3) == 1 || (Kind & 4) != 0 )
  {
    InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                       file,
                       (Scaleform::GFx::ASString *)&file,
                       (Scaleform::GFx::ASStringNode *)mn->NameIndex);
    Scaleform::GFx::AS3::Value::Value(&arg1, InternedString);
    v19.pStr = "compile time";
    v19.Size = 12;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&args,
      (Scaleform::GFx::AS3::VM_vtbl *)0x436,
      (Scaleform::GFx::ASStringNode *)this,
      &arg1,
      v19);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v7,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_12:
    OpStack = (Scaleform::GFx::ASStringNode *)args.OpStack;
    --args.OpStack->pCurrentPage;
    if ( !OpStack->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(OpStack);
    Scaleform::GFx::AS3::Value::~Value(&arg1);
    goto LABEL_15;
  }
  v8 = file;
  args.value = this->OpStack.pCurrent;
  v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
  v10 = v9;
  if ( !v9 )
  {
    v15 = Scaleform::GFx::AS3::VMFile::GetInternedString(
            v8,
            (Scaleform::GFx::ASString *)&file,
            (Scaleform::GFx::ASStringNode *)v3->NameIndex);
    Scaleform::GFx::AS3::Value::Value(&arg1, v15);
    v21.pStr = "any object on the scope stack";
    v21.Size = 29;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&args,
      (Scaleform::GFx::AS3::VM_vtbl *)0x42D,
      (Scaleform::GFx::ASStringNode *)this,
      &arg1,
      v21);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v16,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    goto LABEL_12;
  }
  if ( v9->Coerce(v9, args.value, args.value) )
    return;
  pData = v10->GetName(v10, (Scaleform::GFx::ASString *)&file)->pNode->pData;
  v20.pStr = pData;
  if ( pData )
    v12 = strlen(pData);
  else
    v12 = 0;
  v20.Size = v12;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&args,
    (Scaleform::GFx::AS3::VM_vtbl *)0x40A,
    (Scaleform::GFx::ASStringNode *)this,
    args.value,
    v20);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    v13,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  v14 = (Scaleform::GFx::ASStringNode *)args.OpStack;
  --args.OpStack->pCurrentPage;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
LABEL_15:
  v18 = (Scaleform::GFx::ASStringNode *)file;
  --file->pPrev;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
}
