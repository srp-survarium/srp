void __thiscall Scaleform::GFx::AS3::UserDefinedFunction::Execute(
        Scaleform::GFx::AS3::UserDefinedFunction *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool discard_result)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value result; // [esp+4h] [ebp-10h] BYREF

  result.Flags = 0;
  result.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::UserDefinedFunction::ExecuteImpl(this, _this, &result, argc, argv);
  if ( !discard_result )
    Scaleform::GFx::AS3::Instances::FunctionBase::PushResult(this, &result);
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
