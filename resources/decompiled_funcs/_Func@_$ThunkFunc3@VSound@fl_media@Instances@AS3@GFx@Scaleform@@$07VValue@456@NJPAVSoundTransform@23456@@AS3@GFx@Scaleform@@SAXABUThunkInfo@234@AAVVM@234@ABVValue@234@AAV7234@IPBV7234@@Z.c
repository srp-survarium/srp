void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_media::Sound,8,Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::DefArgs3<double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *> def_ags; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *> args; // [esp+30h] [ebp-20h] BYREF

  def_ags._0 = 0.0;
  v6 = obj->value.VS._1;
  def_ags._1 = 0;
  def_ags._2 = 0;
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>::UnboxArgV3<Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, Scaleform::GFx::AS3::Value *, long double, int, Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_media::Sound,8,Scaleform::GFx::AS3::Value,double,long,Scaleform::GFx::AS3::Instances::fl_media::SoundTransform *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_media::Sound *)(dword_AACB7C + v6.VInt),
      args.r,
      args.a0,
      args.a1,
      args.a2);
}
