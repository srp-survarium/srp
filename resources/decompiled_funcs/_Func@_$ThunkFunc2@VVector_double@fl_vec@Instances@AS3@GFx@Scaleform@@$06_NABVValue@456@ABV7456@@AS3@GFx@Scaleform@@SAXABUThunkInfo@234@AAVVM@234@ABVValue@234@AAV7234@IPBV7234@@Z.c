void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,7,bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Value *Null; // ecx
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> *p_def_ags; // edx
  Scaleform::GFx::AS3::Value *v10; // eax
  bool v11; // zf
  Scaleform::GFx::AS3::Value *v12; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::Extra v14; // edx
  Scaleform::GFx::AS3::Value v15; // [esp+8h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::Value v16; // [esp+18h] [ebp-44h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> def_ags; // [esp+3Ch] [ebp-20h] BYREF

  v6 = obj->value.VS._1;
  Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
  v16 = *Null;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
  }
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  v15 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
  }
  def_ags._0 = v15;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v15);
  }
  def_ags._1 = v16;
  if ( (v16.Flags & 0x1F) > 9 )
  {
    if ( (v16.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v16);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v16);
  }
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
  }
  if ( (v16.Flags & 0x1F) > 9 )
  {
    if ( (v16.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v16);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
  }
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  p_def_ags = argv;
  if ( !argc )
    p_def_ags = &def_ags;
  args.a0 = &p_def_ags->_0;
  v10 = &argv->_1;
  if ( argc <= 1 )
    v10 = &def_ags._1;
  v11 = !vm->HandleException;
  args.a1 = v10;
  if ( v11 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, bool *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,7,bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)(dword_AAEEEC + v6.VInt),
      &args.r,
      &p_def_ags->_0,
      v10);
    if ( !args.Vm->HandleException )
    {
      v12 = args.Result;
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v15.Bonus;
      LOBYTE(v15.Flags) = r;
      v12->value.VS._1.VInt = v15.Flags;
      v12->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14.pWeakProxy;
    }
  }
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::~DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>(&def_ags);
}
