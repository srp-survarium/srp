void __thiscall Scaleform::GFx::AS3::VM::exec_initproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VMFile *v3; // edx
  Scaleform::GFx::AS3::ReadValueMnObject args; // [esp+8h] [ebp-40h] BYREF

  v3 = file;
  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  args.ArgValue.Flags = args.VMRef->OpStack.pCurrent->Flags;
  args.ArgValue.Bonus.pWeakProxy = args.VMRef->OpStack.pCurrent->Bonus.pWeakProxy;
  args.ArgValue.value.VNumber = args.VMRef->OpStack.pCurrent->value.VNumber;
  --args.VMRef->OpStack.pCurrent;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, v3, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject.Flags = args.OpStack->pCurrent->Flags;
  args.ArgObject.Bonus.pWeakProxy = args.OpStack->pCurrent->Bonus.pWeakProxy;
  args.ArgObject.value.VNumber = args.OpStack->pCurrent->value.VNumber;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    ++this->InInitializer;
    Scaleform::GFx::AS3::SetProperty(
      (Scaleform::GFx::AS3::CheckResult *)&file,
      this,
      (Scaleform::GFx::AS3::Value *)&args.ArgObject,
      (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
      &args.ArgValue);
    --this->InInitializer;
  }
  Scaleform::GFx::AS3::ReadValueMnObject::~ReadValueMnObject(&args);
}
