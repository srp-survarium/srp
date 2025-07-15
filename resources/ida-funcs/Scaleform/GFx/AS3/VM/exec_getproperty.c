void __thiscall Scaleform::GFx::AS3::VM::exec_getproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+4h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::ReadMnObjectRef args; // [esp+1Ch] [ebp-28h] BYREF

  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( !this->HandleException )
  {
    _this = *args.ArgObject;
    args.ArgObject->Flags = 0;
    if ( !Scaleform::GFx::AS3::GetPropertyUnsafe(
            (Scaleform::GFx::AS3::CheckResult *)&file,
            this,
            &_this,
            (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
            args.ArgObject)->Result
      && !this->HandleException
      && ((_this.Flags & 0x1F) < 5 || (_this.Flags & 0x1F) == 0xA) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        &v6,
        (Scaleform::GFx::AS3::VM_vtbl *)0x42D,
        (Scaleform::GFx::ASStringNode *)this,
        &args.ArgMN.Name,
        &_this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v4,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v6.Message.pNode;
      --v6.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Scaleform::GFx::AS3::Value::~Value(&_this);
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
