void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_geom::Point,0,double,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::Value *v7; // eax
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Instances::fl_geom::Point *v9; // edx
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_geom::Point *> def_ags; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<double,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_geom::Point *> args; // [esp+10h] [ebp-20h] BYREF

  v6 = obj->value.VS._1;
  def_ags._0 = 0;
  def_ags._1 = 0;
  Scaleform::GFx::AS3::UnboxArgV2<double,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::UnboxArgV2<double,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_geom::Point *>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_geom::Point *, long double *, Scaleform::GFx::AS3::Instances::fl_geom::Point *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_geom::Point,0,double,Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_geom::Point *)(dword_AAC734 + v6.VInt),
      &args.r,
      args.a0,
      args.a1);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    Flags = args.Result->Flags;
    def_ags = *(Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Point *,Scaleform::GFx::AS3::Instances::fl_geom::Point *> *)&args.r;
    v9 = def_ags._0;
    args.Result->Flags = Flags & 0xFFFFFFE0 | 4;
    v7->value.VS._2.VObj = def_ags._1;
    v7->value.VS._1.VInt = (int)v9;
  }
}
