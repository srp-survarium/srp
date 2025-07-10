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
  args.ArgValue = *args.VMRef->OpStack.pCurrent--;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, v3, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = *(const Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    ++this->InInitializer;
    Scaleform::GFx::AS3::SetProperty(
      (Scaleform::GFx::AS3::CheckResult *)&file,
      this,
      (Scaleform::GFx::AS3::Value *)&args.ArgObject,
      (Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args.ArgMN,
      &args.ArgValue);
    --this->InInitializer;
  }
  Scaleform::GFx::AS3::ReadValueMnObject::~ReadValueMnObject(&args);
}
