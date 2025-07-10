void __thiscall Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *type,
        Scaleform::GFx::AS3::Abc::Code::OpCode op,
        int reg_num)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Tracer *pTracer; // ecx
  Scaleform::GFx::AS3::Value::TraceNullType CanBeNull; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v9; // esi
  int *Data; // edx

  ValueTraits = Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->Registers.Data.Data[reg_num]);
  pTracer = this->pTracer;
  if ( ValueTraits == type )
  {
    pTracer->WCode->Data.Data[pTracer->WCode->Data.Size - 1] = op;
  }
  else
  {
    CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(pTracer, type);
    Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(
      this,
      (Scaleform::GFx::AS3::AbsoluteIndex)reg_num,
      type,
      CanBeNull);
  }
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v9 = WCode->Size + 1;
  if ( v9 >= WCode->Size )
  {
    if ( v9 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v9 + (v9 >> 2));
  }
  else if ( v9 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v9;
  Data[v9 - 1] = reg_num;
}
