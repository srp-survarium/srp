void __thiscall Scaleform::GFx::AS3::VM::exec_deleteproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  int v4; // eax
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char *pData; // eax
  unsigned int v7; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::Value *ArgObject; // ecx
  unsigned int v12; // eax
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  _DWORD *VInt; // eax
  _BYTE *v15; // eax
  Scaleform::StringDataPtr v16; // [esp-8h] [ebp-40h]
  Scaleform::GFx::AS3::VM::Error v17; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::ReadMnObjectRef args; // [esp+10h] [ebp-28h] BYREF

  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( !this->HandleException )
  {
    LOBYTE(mn) = 0;
    if ( this->XMLSupport_.pObject->Enabled
      && (args.ArgMN.Name.Flags & 0x1F) - 12 <= 3
      && args.ArgMN.Name.value.VS._1.VInt
      && (v4 = *(_DWORD *)(args.ArgMN.Name.value.VS._1.VInt + 20), *(_DWORD *)(v4 + 60) == 14)
      && (*(_DWORD *)(v4 + 56) & 0x20) == 0 )
    {
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, &args.ArgMN.Name);
      pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&file)->pNode->pData;
      v16.pStr = pData;
      if ( pData )
        v7 = strlen(pData);
      else
        v7 = 0;
      v16.Size = v7;
      Scaleform::GFx::AS3::VM::Error::Error(&v17, eDeleteTypeError, (Scaleform::String)this, v16);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v8,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v17.Message.pNode;
      --v17.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v10 = (Scaleform::GFx::ASStringNode *)file;
    }
    else
    {
      ArgObject = args.ArgObject;
      v12 = args.ArgObject->Flags & 0x1F;
      if ( v12 >= 5 && v12 != 10 )
      {
        if ( v12 - 12 > 3 )
          goto LABEL_22;
        VInt = (_DWORD *)args.ArgObject->value.VS._1.VInt;
        if ( (*(_DWORD *)(VInt[5] + 56) & 2) != 0 )
        {
          v15 = (_BYTE *)(*(int (__thiscall **)(_DWORD *, Scaleform::GFx::AS3::VMFile **, Scaleform::GFx::AS3::Multiname *))(*VInt + 36))(
                           VInt,
                           &file,
                           &args.ArgMN);
          ArgObject = args.ArgObject;
          LOBYTE(mn) = *v15;
        }
        if ( !this->HandleException )
LABEL_22:
          Scaleform::GFx::AS3::Value::SetBool(ArgObject, (bool)mn);
        goto LABEL_23;
      }
      Scaleform::GFx::AS3::VM::Error::Error(
        &v17,
        (Scaleform::GFx::AS3::VM_vtbl *)0x460,
        (Scaleform::GFx::ASStringNode *)this,
        &args.ArgMN.Name,
        args.ArgObject);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v13,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v10 = v17.Message.pNode;
    }
    if ( !--v10->RefCount )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
      return;
    }
  }
LABEL_23:
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
