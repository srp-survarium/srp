void __thiscall Scaleform::GFx::AS3::VM::exec_astype(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v3; // edi
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // eax
  Scaleform::GFx::ASString *InternedString; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::AS3::VMFile *v8; // ebp
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v9; // ebx
  Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::ASStringNode *OpStack; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::StringDataPtr v13; // [esp-8h] [ebp-34h]
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
    v13.pStr = "compile time";
    v13.Size = 12;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&args,
      (Scaleform::GFx::AS3::VM_vtbl *)0x436,
      (Scaleform::GFx::ASStringNode *)this,
      &arg1,
      v13);
  }
  else
  {
    v8 = file;
    args.value = this->OpStack.pCurrent;
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v9 && v9 != Scaleform::GFx::AS3::VM::GetClassTraits(this, args.value) )
    {
      Scaleform::GFx::AS3::Value::SetNull(args.value);
      return;
    }
    v10 = Scaleform::GFx::AS3::VMFile::GetInternedString(
            v8,
            (Scaleform::GFx::ASString *)&file,
            (Scaleform::GFx::ASStringNode *)v3->NameIndex);
    Scaleform::GFx::AS3::Value::Value(&arg1, v10);
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&args,
      (Scaleform::GFx::AS3::VM_vtbl *)0x3F6,
      (Scaleform::GFx::ASStringNode *)this,
      &arg1);
  }
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    v7,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  OpStack = (Scaleform::GFx::ASStringNode *)args.OpStack;
  --args.OpStack->pCurrentPage;
  if ( !OpStack->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(OpStack);
  Scaleform::GFx::AS3::Value::~Value(&arg1);
  v12 = (Scaleform::GFx::ASStringNode *)file;
  --file->pPrev;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
