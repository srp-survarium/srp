void __thiscall Scaleform::GFx::AS3::VM::exec_deleteproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  bool v4; // zf
  int v5; // eax
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *ArgObject; // ecx
  unsigned int v9; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  _DWORD *VInt; // eax
  _BYTE *v12; // eax
  Scaleform::GFx::AS3::VM::Error v13; // [esp+4h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::ReadMnObjectRef args; // [esp+Ch] [ebp-28h] BYREF

  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( !this->HandleException )
  {
    v4 = !this->XMLSupport_.pObject->Enabled;
    LOBYTE(mn) = 0;
    if ( v4
      || (args.ArgMN.Name.Flags & 0x1F) - 12 > 3
      || !args.ArgMN.Name.value.VS._1.VInt
      || (v5 = *(_DWORD *)(args.ArgMN.Name.value.VS._1.VInt + 20), *(_DWORD *)(v5 + 60) != 14)
      || (*(_DWORD *)(v5 + 56) & 0x20) != 0 )
    {
      ArgObject = args.ArgObject;
      v9 = args.ArgObject->Flags & 0x1F;
      if ( v9 >= 5 && v9 != 10 )
      {
        if ( v9 - 12 > 3 )
          goto LABEL_17;
        VInt = (_DWORD *)args.ArgObject->value.VS._1.VInt;
        if ( (*(_DWORD *)(VInt[5] + 56) & 2) != 0 )
        {
          v12 = (_BYTE *)(*(int (__thiscall **)(_DWORD *, Scaleform::GFx::AS3::VMFile **, Scaleform::GFx::AS3::Multiname *))(*VInt + 24))(
                           VInt,
                           &file,
                           &args.ArgMN);
          ArgObject = args.ArgObject;
          LOBYTE(mn) = *v12;
        }
        if ( !this->HandleException )
LABEL_17:
          Scaleform::GFx::AS3::Value::SetBool(ArgObject, (bool)mn);
        goto LABEL_18;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v13, eDeleteSealedError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v10,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v13, eDeleteTypeError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v6,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    }
    pNode = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    if ( !pNode->RefCount )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
      return;
    }
  }
LABEL_18:
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
