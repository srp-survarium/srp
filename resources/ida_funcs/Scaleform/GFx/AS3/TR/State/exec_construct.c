void __thiscall Scaleform::GFx::AS3::TR::State::exec_construct(Scaleform::GFx::AS3::TR::State *this, int arg_count)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v4; // esi
  int *Data; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Value::V1U v7; // edx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // ecx
  bool v9; // zf
  Scaleform::GFx::AS3::Value val; // [esp+Ch] [ebp-C0h] BYREF
  Scaleform::GFx::AS3::TR::ReadArgsObject args; // [esp+1Ch] [ebp-B0h] BYREF

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
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    &args.ArgObject);
  ++args.Num;
  ValueTraits = Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &args.ArgObject);
  switch ( args.ArgObject.Flags & 0x1F )
  {
    case 8:
      v7 = args.ArgObject.value.VS._1;
      goto LABEL_8;
    case 9:
      v7 = *(Scaleform::GFx::AS3::Value::V1U *)(args.ArgObject.value.VS._1.VInt + 100);
LABEL_8:
      val.value.VS._1 = v7;
      goto LABEL_9;
    case 0xC:
      v9 = (ValueTraits->Flags & 0x20) != 0;
      val.Bonus.pWeakProxy = 0;
      val.value.VS._1.VInt = (int)ValueTraits;
      p_OpStack = &this->OpStack;
      if ( !v9 )
        goto LABEL_10;
      val.Flags = 9;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &p_OpStack->Data,
        &val);
      goto LABEL_11;
    case 0xD:
      val.value.VS._1.VInt = *(_DWORD *)(*(_DWORD *)(args.ArgObject.value.VS._1.VInt + 20) + 100);
LABEL_9:
      val.Bonus.pWeakProxy = 0;
      p_OpStack = &this->OpStack;
LABEL_10:
      val.Flags = 8;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &p_OpStack->Data,
        &val);
LABEL_11:
      Scaleform::GFx::AS3::Value::~Value(&val);
      Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject(&args);
      break;
    default:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        &args.ArgObject);
      Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject(&args);
      break;
  }
}
