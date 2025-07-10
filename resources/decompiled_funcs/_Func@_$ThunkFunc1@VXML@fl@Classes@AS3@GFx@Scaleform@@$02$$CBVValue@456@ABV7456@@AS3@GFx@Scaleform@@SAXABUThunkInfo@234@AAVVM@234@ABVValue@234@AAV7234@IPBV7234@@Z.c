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
      (Scaleform::GFx::AS3::Classes::fl::XML *)(dword_AAD0E4 + v6.VInt),
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
