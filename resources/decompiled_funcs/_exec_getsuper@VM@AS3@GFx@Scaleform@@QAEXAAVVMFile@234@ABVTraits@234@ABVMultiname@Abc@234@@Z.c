void __thiscall Scaleform::GFx::AS3::VM::exec_getsuper(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::ReadMnObjectRef args; // [esp+1Ch] [ebp-28h] BYREF

  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( !this->HandleException )
  {
    value = *args.ArgObject;
    args.ArgObject->Flags = 0;
    if ( !Scaleform::GFx::AS3::GetSuperProperty(
            (Scaleform::GFx::AS3::CheckResult *)&file,
            this,
            ot,
            args.ArgObject,
            &value,
            (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
            valGet)->Result )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v7, eIllegalSuperCallError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v5,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v7.Message.pNode;
      --v7.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Scaleform::GFx::AS3::Value::~Value(&value);
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
