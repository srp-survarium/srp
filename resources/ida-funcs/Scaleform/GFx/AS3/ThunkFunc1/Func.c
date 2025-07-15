void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Array,1,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Array *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Array,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_8F1F14 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Date,0,double,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  double v9; // st7
  bool v11; // zf
  Scaleform::GFx::AS3::Value *v12; // eax
  unsigned int v13; // edx
  Scaleform::GFx::AS3::Value::Extra v14; // ecx
  Scaleform::GFx::AS3::Value *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // edx
  Scaleform::GFx::AS3::Value::Extra v18; // ecx
  Scaleform::GFx::AS3::Value v19; // [esp+8h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<double,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v19 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v19.Flags;
  }
  def_ags._0.value.VNumber = v19.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v19.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v19);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v19);
    LOWORD(Flags) = v19.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v19);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
  }
  args.Vm = vm;
  args.Result = result;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  args.r = v9;
  if ( !argc )
    argv = &def_ags;
  v11 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v11 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Date *, long double *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Date,0,double,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Date *)(v6.VInt + dword_8F1E04),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v15 = args.Result;
      v16 = args.Result->Flags;
      *(double *)&v19.Flags = args.r;
      v17 = v19.Flags;
      args.Result->Flags = v16 & 0xFFFFFFE0 | 4;
      v18.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v19.Bonus;
      v15->value.VS._1.VInt = v17;
      v15->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v18.pWeakProxy;
    }
    if ( (def_ags._0.Flags & 0x1F) > 9 )
    {
      if ( (def_ags._0.Flags & 0x200) != 0 )
        goto LABEL_22;
LABEL_27:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
    }
  }
  else
  {
    if ( !args.Vm->HandleException )
    {
      v12 = args.Result;
      *(double *)&v19.Flags = v9;
      v13 = v19.Flags;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v19.Bonus;
      v12->value.VS._1.VInt = v13;
      v12->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14.pWeakProxy;
    }
    if ( (def_ags._0.Flags & 0x1F) > 9 )
    {
      if ( (def_ags._0.Flags & 0x200) != 0 )
      {
LABEL_22:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
        return;
      }
      goto LABEL_27;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,1,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,1,double,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(v6.VInt + dword_8F1C5C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,42,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,42,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F186C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,44,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,44,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1A84 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,46,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,46,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1C4C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,48,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,48,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1874 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,50,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,50,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1E5C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,52,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,52,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1BC4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,54,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,54,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1D44 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,56,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,56,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1F64 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,58,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,58,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1EEC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,60,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,60,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F17CC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,62,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,62,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1B94 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,64,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,64,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1E8C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,66,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,66,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F199C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,68,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,68,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F1BD4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,70,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Date *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Date,70,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Date *)(dword_8F18D4 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Error,0,Scaleform::GFx::ASString,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Error *, Scaleform::GFx::ASString *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Error,0,Scaleform::GFx::ASString,long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Error *)(dword_8F1E3C + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,7,Scaleform::GFx::ASString,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, Scaleform::GFx::ASString *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,7,Scaleform::GFx::ASString,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_8F3334 + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,12,unsigned long,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<unsigned long,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, unsigned int *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,12,unsigned long,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(v6.VInt + dword_8F3304),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 3;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,13,unsigned long,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<unsigned long,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, unsigned int *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,13,unsigned long,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(v6.VInt + dword_8F337C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 3;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::Font,3,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::Font *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::Font,3,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::Font *)(dword_8F179C + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,50,bool,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v8; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, bool *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,50,bool,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(v6.VInt + dword_8F1D6C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v8.VS._1.VBool = r;
      args.Result->value = v8;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,51,bool,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v8; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, bool *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,51,bool,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(v6.VInt + dword_8F1BCC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v8.VS._1.VBool = r;
      args.Result->value = v8;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::IME,3,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_system::IME *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_system::IME,3,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_system::IME *)(v6.VInt + dword_8F31DC),
      result,
      args_8);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,1,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,1,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1E0C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,2,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,2,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1B34),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,3,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,3,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F19E4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,5,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,5,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1884),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,6,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,6,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F19A4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,7,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,7,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1E34),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,8,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,8,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1CA4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,9,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,9,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1ADC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,10,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,10,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1BEC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,0,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,0,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1F84),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,11,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,11,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F180C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,12,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,12,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1924),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,13,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,13,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_8F1C24),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,3,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Point *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,3,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(dword_8F0ECC + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,4,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Point *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,4,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(dword_8F10FC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,5,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,5,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1CBC + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,9,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,9,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_8F1824 + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,8,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,8,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0B9C + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,29,Scaleform::GFx::ASString,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::Socket,29,Scaleform::GFx::ASString,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_8F0D34 + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,2,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,2,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(dword_8F3324 + v6.VInt),
      args.r,
      args.a0);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,70,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,70,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_8F13E4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,73,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,73,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_8F16BC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,74,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,74,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_8F15FC),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,76,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,76,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_8F15E4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,78,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<long,long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, int *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,78,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(v6.VInt + dword_8F13D4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 2;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,14,double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  unsigned int Flags; // ecx
  unsigned int v9; // edx
  Scaleform::GFx::AS3::Value to; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Vector3DTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,14,double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v6.VInt + dword_8F11A4),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    Flags = args.Result->Flags;
    *(double *)&to.Flags = args.r;
    v9 = to.Flags;
    args.Result->Flags = Flags & 0xFFFFFFE0 | 4;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = v9;
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Null; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
  Flags = Null->Flags;
  v10 = *Null;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::XML *)(dword_8F1A9C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Null; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
  Flags = Null->Flags;
  v10 = *Null;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::XML,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::XML *)(dword_8F189C + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1804 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,3,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,3,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F1954 + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,13,bool,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::Extra v13; // edx
  Scaleform::GFx::AS3::Value v14; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v14 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v14.Flags;
  }
  def_ags._0.value.VNumber = v14.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v14.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v14);
    LOWORD(Flags) = v14.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
  }
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, bool *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,13,bool,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_8F196C + v6.VInt),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v11 = args.Result;
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v14.Bonus;
      LOBYTE(v14.Flags) = r;
      v11->value.VS._1.VInt = v14.Flags;
      v11->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13.pWeakProxy;
    }
  }
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,12,bool,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::Extra v13; // edx
  Scaleform::GFx::AS3::Value v14; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v14 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v14.Flags;
  }
  def_ags._0.value.VNumber = v14.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v14.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v14);
    LOWORD(Flags) = v14.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
  }
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, bool *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,12,bool,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_8F1984 + v6.VInt),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v11 = args.Result;
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v14.Bonus;
      LOBYTE(v14.Flags) = r;
      v11->value.VS._1.VInt = v14.Flags;
      v11->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13.pWeakProxy;
    }
  }
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}
