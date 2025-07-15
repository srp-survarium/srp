void __thiscall Scaleform::GFx::AS3::VM::exec_constructsuper(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Traits *ot,
        unsigned int arg_count)
{
  const Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *FixedArr; // eax
  Scaleform::GFx::AS3::ReadArgsObject args; // [esp+10h] [ebp-B0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject.Flags = args.OpStack->pCurrent->Flags;
  args.ArgObject.Bonus.pWeakProxy = args.OpStack->pCurrent->Bonus.pWeakProxy;
  args.ArgObject.value.VNumber = args.OpStack->pCurrent->value.VNumber;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    pObject = ot->pParent.pObject;
    if ( pObject )
    {
      FixedArr = args.FixedArr;
      if ( args.ArgNum > 8 )
        FixedArr = args.CallArgs.Data.Data;
      ((void (__thiscall *)(const Scaleform::GFx::AS3::Traits *, const Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))pObject->__vftable[1].IsAS3Object)(
        pObject,
        ot,
        &args.ArgObject,
        arg_count,
        FixedArr);
    }
  }
  Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
}
