void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::Value *Null; // ecx
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> *p_def_ags; // ecx
  Scaleform::GFx::AS3::Value *v10; // eax
  Scaleform::GFx::AS3::Value v11; // [esp+4h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v12; // [esp+14h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &> def_ags; // [esp+24h] [ebp-20h] BYREF

  v6 = obj->value.VS._1;
  Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
  v12 = *Null;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
  }
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  v11 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
  }
  def_ags._0 = v11;
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v11);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v11);
  }
  def_ags._1 = v12;
  if ( (v12.Flags & 0x1F) > 9 )
  {
    if ( (v12.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v12);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v12);
  }
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
  }
  if ( (v12.Flags & 0x1F) > 9 )
  {
    if ( (v12.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v12);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
  }
  p_def_ags = argv;
  if ( !argc )
    p_def_ags = &def_ags;
  v10 = &argv->_1;
  if ( argc <= 1 )
    v10 = &def_ags._1;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(v6.VInt + dword_AAF004),
      result,
      &p_def_ags->_0,
      v10);
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::~DefArgs2<Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>(&def_ags);
}
