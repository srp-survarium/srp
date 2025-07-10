void __cdecl Scaleform::GFx::AS3::Instances::FunctionBase::call(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  char v6; // bl
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *GlobalObject; // eax
  const Scaleform::GFx::AS3::Value *v9; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v10; // eax
  const Scaleform::GFx::AS3::Value *v11; // eax
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v13; // [esp+20h] [ebp-10h] BYREF

  v6 = 0;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  r = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
  }
  if ( !argc )
  {
    GlobalObject = Scaleform::GFx::AS3::VM::GetGlobalObject(vm);
    Scaleform::GFx::AS3::Value::Value(&v13, GlobalObject);
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, _this, v9, &r, 0, argv, 0);
    if ( (v13.Flags & 0x1F) <= 9 )
      goto LABEL_18;
    if ( (v13.Flags & 0x200) != 0 )
      goto LABEL_8;
LABEL_17:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
    goto LABEL_18;
  }
  if ( (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) )
  {
    v11 = argv;
  }
  else
  {
    v6 = 1;
    v10 = Scaleform::GFx::AS3::VM::GetGlobalObject(vm);
    Scaleform::GFx::AS3::Value::Value(&v13, v10);
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, _this, v11, &r, argc - 1, argv + 1, 0);
  if ( (v6 & 1) != 0 && (v13.Flags & 0x1F) > 9 )
  {
    if ( (v13.Flags & 0x200) != 0 )
    {
LABEL_8:
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v13);
      goto LABEL_18;
    }
    goto LABEL_17;
  }
LABEL_18:
  Scaleform::GFx::AS3::Value::Swap(result, &r);
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
}
