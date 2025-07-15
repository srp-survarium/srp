void __thiscall Scaleform::GFx::AS3::VM::exec_istype(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v3; // edi
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // eax
  Scaleform::GFx::ASString *InternedString; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS3::VMFile *v10; // ebx
  Scaleform::GFx::AS3::Value *pCurrent; // ebp
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v12; // eax
  Scaleform::GFx::ASString *v13; // eax
  char v14; // al
  Scaleform::StringDataPtr v15; // [esp-8h] [ebp-30h]
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+18h] [ebp-10h] BYREF

  v3 = mn;
  Kind = mn->Kind;
  if ( (Kind & 3) == 1 || (Kind & 4) != 0 )
  {
    InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                       file,
                       (Scaleform::GFx::ASString *)&file,
                       (Scaleform::GFx::ASStringNode *)mn->NameIndex);
    Scaleform::GFx::AS3::Value::Value(&arg1, InternedString);
    v15.pStr = "compile time";
    v15.Size = 12;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v16,
      (Scaleform::GFx::AS3::VM_vtbl *)0x436,
      (Scaleform::GFx::ASStringNode *)this,
      &arg1,
      v15);
  }
  else
  {
    v10 = file;
    pCurrent = this->OpStack.pCurrent;
    v12 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v12 )
    {
      v14 = Scaleform::GFx::AS3::VM::IsOfType(this, pCurrent, (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v12);
      Scaleform::GFx::AS3::Value::SetBool(pCurrent, v14);
      return;
    }
    v13 = Scaleform::GFx::AS3::VMFile::GetInternedString(
            v10,
            (Scaleform::GFx::ASString *)&file,
            (Scaleform::GFx::ASStringNode *)v3->NameIndex);
    Scaleform::GFx::AS3::Value::Value(&arg1, v13);
    Scaleform::GFx::AS3::VM::Error::Error(
      &v16,
      (Scaleform::GFx::AS3::VM_vtbl *)0x3F6,
      (Scaleform::GFx::ASStringNode *)this,
      &arg1);
  }
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    v7,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v16.Message.pNode;
  --v16.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Value::~Value(&arg1);
  v9 = (Scaleform::GFx::ASStringNode *)file;
  --file->pPrev;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}
