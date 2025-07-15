void __thiscall Scaleform::GFx::AS3::VM::exec_callmethod(
        Scaleform::GFx::AS3::VM *this,
        unsigned int method_index,
        unsigned int arg_count)
{
  const Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // ecx
  Scaleform::GFx::AS3::ReadArgsObject args; // [esp+8h] [ebp-B0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject.Flags = args.OpStack->pCurrent->Flags;
  args.ArgObject.Bonus.pWeakProxy = args.OpStack->pCurrent->Bonus.pWeakProxy;
  args.ArgObject.value.VNumber = args.OpStack->pCurrent->value.VNumber;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, &args.ArgObject);
    FixedArr = args.FixedArr;
    if ( args.ArgNum > 8 )
      FixedArr = args.CallArgs.Data.Data;
    Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(
      this,
      method_index,
      ValueTraits,
      &args.ArgObject,
      arg_count,
      FixedArr);
  }
  Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
}
