void __thiscall Scaleform::GFx::AS3::VM::exec_getproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *ArgObject; // eax
  Scaleform::GFx::AS3::Value::Extra v5; // ecx
  unsigned int Flags; // edi
  int v7; // edi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v10; // [esp+4h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::ReadMnObjectRef args; // [esp+1Ch] [ebp-28h] BYREF

  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( this->HandleException )
  {
    Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
  }
  else
  {
    ArgObject = args.ArgObject;
    v5.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)args.ArgObject->Bonus;
    Flags = args.ArgObject->Flags;
    _this.value.VS._1.VInt = args.ArgObject->value.VS._1.VInt;
    args.ArgObject->Flags = 0;
    _this.Bonus = v5;
    _this.value.VS._2.VObj = ArgObject->value.VS._2.VObj;
    _this.Flags = Flags;
    if ( !Scaleform::GFx::AS3::GetPropertyUnsafe(
            (Scaleform::GFx::AS3::CheckResult *)&file,
            this,
            &_this,
            (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
            args.ArgObject)->Result
      && !this->HandleException )
    {
      v7 = Flags & 0x1F;
      if ( v7 < 5 || v7 == 10 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v10, eReadSealedError, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v8,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        pNode = v10.Message.pNode;
        --v10.Message.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
    }
    Scaleform::GFx::AS3::Value::~Value(&_this);
    Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
  }
}
