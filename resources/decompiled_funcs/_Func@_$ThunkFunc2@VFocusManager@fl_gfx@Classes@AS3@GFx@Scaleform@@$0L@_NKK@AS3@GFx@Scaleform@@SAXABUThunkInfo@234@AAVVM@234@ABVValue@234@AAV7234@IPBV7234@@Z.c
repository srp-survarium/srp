void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,11,bool,unsigned long,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::DefArgs2<unsigned long,unsigned long> def_ags; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<bool,unsigned long,unsigned long> args; // [esp+10h] [ebp-14h] BYREF

  v6 = obj->value.VS._1;
  def_ags._0 = 0;
  def_ags._1 = 0;
  Scaleform::GFx::AS3::UnboxArgV2<bool,unsigned long,unsigned long>::UnboxArgV2<bool,unsigned long,unsigned long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, bool *, unsigned int, unsigned int))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,11,bool,unsigned long,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(dword_AAECB4 + v6.VInt),
      &args.r,
      args.a0,
      args.a1);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(def_ags._0) = r;
    v9 = def_ags._0;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)def_ags._1;
    v7->value.VS._1.VInt = v9;
  }
}
