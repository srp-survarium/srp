void __thiscall Scaleform::GFx::AS3::VM::exec_call(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  Scaleform::GFx::AS3::Value *FixedArr; // ebp
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value result; // [esp+8h] [ebp-D0h] BYREF
  Scaleform::GFx::AS3::ReadArgsObjectValue args; // [esp+18h] [ebp-C0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject = *(Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  args.value = *(const Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  if ( !this->HandleException )
  {
    FixedArr = args.FixedArr;
    if ( args.ArgNum > 8 )
      FixedArr = args.CallArgs.Data.Data;
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
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
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &args.value, &args.ArgObject, &result, arg_count, FixedArr, 1);
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags & 0x200) != 0 )
      {
        pWeakProxy = result.Bonus.pWeakProxy;
        --result.Bonus.pWeakProxy->RefCount;
        if ( !pWeakProxy->RefCount )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          Scaleform::GFx::AS3::ReadArgsObjectValue::~ReadArgsObjectValue(&args);
          return;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      }
    }
  }
  Scaleform::GFx::AS3::ReadArgsObjectValue::~ReadArgsObjectValue(&args);
}
