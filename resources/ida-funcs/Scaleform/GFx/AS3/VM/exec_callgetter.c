void __thiscall Scaleform::GFx::AS3::VM::exec_callgetter(
        Scaleform::GFx::AS3::VM *this,
        unsigned int method_index,
        unsigned int arg_count)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Value *FixedArr; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  const Scaleform::GFx::AS3::Value *v7; // [esp-18h] [ebp-F4h]
  Scaleform::GFx::AS3::Value result; // [esp+Ch] [ebp-D0h] BYREF
  Scaleform::GFx::AS3::Value funct; // [esp+1Ch] [ebp-C0h] BYREF
  Scaleform::GFx::AS3::ReadArgsObject args; // [esp+2Ch] [ebp-B0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject.Flags = args.OpStack->pCurrent->Flags;
  args.ArgObject.Bonus.pWeakProxy = args.OpStack->pCurrent->Bonus.pWeakProxy;
  args.ArgObject.value.VNumber = args.OpStack->pCurrent->value.VNumber;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, &args.ArgObject);
    v7 = &Scaleform::GFx::AS3::Traits::GetVT(ValueTraits)->VTMethods.Data.Data[method_index];
    funct.Flags = 0;
    funct.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, v7, &args.ArgObject, &funct, 0, 0, 0);
    if ( !this->HandleException )
    {
      FixedArr = args.FixedArr;
      if ( args.ArgNum > 8 )
        FixedArr = args.CallArgs.Data.Data;
      if ( (_S15 & 1) == 0 )
      {
        _S15 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      result = v;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          ++v.Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(&v);
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &funct, &args.ArgObject, &result, arg_count, FixedArr, 1);
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags & 0x200) != 0 )
        {
          pWeakProxy = result.Bonus.pWeakProxy;
          --result.Bonus.pWeakProxy->RefCount;
          if ( !pWeakProxy->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
    }
    Scaleform::GFx::AS3::Value::~Value(&funct);
  }
  Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
}
