void __thiscall Scaleform::GFx::AS3::TR::State::exec_call(Scaleform::GFx::AS3::TR::State *this, int arg_count)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // ebx
  unsigned int v4; // edi
  int *Data; // ecx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // edi
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // edx
  Scaleform::GFx::AS3::VM *VMRef; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // eax
  Scaleform::GFx::AS3::Tracer *pTracer; // ecx
  unsigned int v12; // esi
  Scaleform::GFx::AS3::Value val; // [esp+Ch] [ebp-D0h] BYREF
  Scaleform::GFx::AS3::TR::ReadArgsObjectValue args; // [esp+1Ch] [ebp-C0h] BYREF

  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v4 = WCode->Size + 1;
  if ( v4 >= WCode->Size )
  {
    if ( v4 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v4 + (v4 >> 2));
  }
  else if ( v4 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v4;
  Data[v4 - 1] = arg_count;
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&args, this->pTracer->CF->pFile->VMRef, this, arg_count);
  p_OpStack = &this->OpStack;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    &args.ArgObject);
  ++args.Num;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    (Scaleform::GFx::AS3::Value *)&args.value);
  pFile = this->pTracer->CF->pFile;
  AppDomain = pFile->AppDomain;
  VMRef = pFile->VMRef;
  ++args.Num;
  FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(VMRef, &args.value, AppDomain);
  pTracer = this->pTracer;
  val.Bonus.pWeakProxy = 0;
  val.value.VS._1.VInt = (int)FunctReturnType;
  v12 = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(pTracer, FunctReturnType) & 0xFFFFFFF7)) | 8;
  val.Flags = v12;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &p_OpStack->Data,
    &val);
  if ( (v12 & 0x1F) > 9 )
  {
    if ( (v12 & 0x200) != 0 )
    {
      if ( !--MEMORY[0] )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
        Scaleform::GFx::AS3::TR::ReadArgsObjectValue::~ReadArgsObjectValue(&args);
        return;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    }
  }
  Scaleform::GFx::AS3::TR::ReadArgsObjectValue::~ReadArgsObjectValue(&args);
}
