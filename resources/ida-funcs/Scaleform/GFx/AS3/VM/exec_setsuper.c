void __thiscall Scaleform::GFx::AS3::VM::exec_setsuper(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        const Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VMFile *v4; // edx
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+8h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::ReadValueMnObject args; // [esp+10h] [ebp-40h] BYREF

  v4 = file;
  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  args.ArgValue.Flags = args.VMRef->OpStack.pCurrent->Flags;
  args.ArgValue.Bonus.pWeakProxy = args.VMRef->OpStack.pCurrent->Bonus.pWeakProxy;
  args.ArgValue.value.VNumber = args.VMRef->OpStack.pCurrent->value.VNumber;
  --args.VMRef->OpStack.pCurrent;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, v4, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject.Flags = args.OpStack->pCurrent->Flags;
  args.ArgObject.Bonus.pWeakProxy = args.OpStack->pCurrent->Bonus.pWeakProxy;
  args.ArgObject.value.VNumber = args.OpStack->pCurrent->value.VNumber;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException
    && !Scaleform::GFx::AS3::SetSuperProperty(
          (Scaleform::GFx::AS3::CheckResult *)&file,
          this,
          ot,
          (Scaleform::GFx::ASStringNode *)&args.ArgObject,
          (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
          &args.ArgValue)->Result )
  {
    Scaleform::GFx::AS3::VM::Error::Error(
      &v8,
      (Scaleform::GFx::AS3::VM_vtbl *)0x40B,
      (Scaleform::GFx::ASStringNode *)this,
      &args.ArgMN.Name);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v6,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  Scaleform::GFx::AS3::ReadValueMnObject::~ReadValueMnObject(&args);
}
