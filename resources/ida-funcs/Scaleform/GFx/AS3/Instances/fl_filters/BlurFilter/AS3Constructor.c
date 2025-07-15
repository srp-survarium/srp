void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *this,
        float argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebp
  Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::Render::Filter *pObject; // eax
  Scaleform::Render::Filter *v7; // ecx
  volatile int v8; // eax
  int qual; // [esp+4h] [ebp-24h] BYREF
  double v10; // [esp+8h] [ebp-20h] BYREF
  double by; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+18h] [ebp-10h] BYREF

  v10 = 4.0;
  v3 = LODWORD(argc);
  by = 4.0;
  v4 = argv;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0;
  qual = 1;
  if ( argc != 0.0
    && !Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &v10)->Result
    || v3 >= 2
    && !Scaleform::GFx::AS3::Value::Convert2Number(v4 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &by)->Result
    || v3 >= 3
    && !Scaleform::GFx::AS3::Value::Convert2Int32(v4 + 2, (Scaleform::GFx::AS3::CheckResult *)&argc, &qual)->Result )
  {
    if ( (result.Flags & 0x1F) <= 9 )
      return;
    if ( (result.Flags & 0x200) == 0 )
      goto LABEL_14;
    goto LABEL_5;
  }
  pObject = this->FilterData.pObject;
  argc = v10;
  argc = argc * 20.0;
  *(float *)&pObject[1].Type = argc;
  v7 = this->FilterData.pObject;
  argc = by;
  argc = 20.0 * argc;
  *(float *)&v7[1].Frozen = argc;
  v8 = (__int16)qual;
  if ( (unsigned int)(__int16)qual >= 0xF )
    v8 = 15;
  this->FilterData.pObject[1].RefCount = v8;
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) == 0 )
    {
LABEL_14:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      return;
    }
LABEL_5:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
  }
}
