void __thiscall Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long>::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long>(
        Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long> *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long> *da)
{
  bool v6; // zf
  const Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long> *v7; // ebp
  __int16 Flags; // ax
  char v10; // dl
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = argc == 0;
  v7 = da;
  this->Vm = vm;
  this->Result = result;
  this->r = 0;
  this->a0 = v7->_0;
  if ( !v6 )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    Flags = to.Flags;
    v10 = to.Flags & 0x1F;
    this->a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( v10 > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  this->a1 = v7->_1;
  if ( !vm->HandleException && argc > 1 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(
      (Scaleform::GFx::AS3::Value *)&argv[1],
      (Scaleform::GFx::AS3::CheckResult *)&argc,
      &this->a1);
}
