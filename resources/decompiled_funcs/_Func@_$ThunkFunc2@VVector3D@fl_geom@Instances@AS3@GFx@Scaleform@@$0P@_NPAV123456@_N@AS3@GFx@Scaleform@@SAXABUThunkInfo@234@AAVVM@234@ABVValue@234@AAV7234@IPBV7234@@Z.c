void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,15,bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *v9; // ecx
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,bool> def_ags; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,bool> args; // [esp+10h] [ebp-14h] BYREF

  v6 = obj->value.VS._1;
  def_ags._0 = 0;
  def_ags._1 = 0;
  Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,bool>::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,bool>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, bool))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,15,bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC914 + v6.VInt),
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
    v7->value.VS._2.VObj = *(Scaleform::GFx::AS3::Object **)&def_ags._1;
    v7->value.VS._1.VInt = (int)v9;
  }
}
