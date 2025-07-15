void __thiscall Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v4; // edi
  long double result; // [esp+Ch] [ebp-8h] BYREF

  v3 = argc;
  v4 = argv;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( v3 >= 4 )
  {
    Scaleform::GFx::AS3::Value::Convert2UInt32(v4 + 3, (Scaleform::GFx::AS3::CheckResult *)&argv, &argc);
    this->Code = argc;
  }
  if ( v3 >= 5 )
  {
    Scaleform::GFx::AS3::Value::Convert2UInt32(v4 + 4, (Scaleform::GFx::AS3::CheckResult *)&argv, &argc);
    this->ControllerIdx = argc;
  }
  if ( v3 >= 6 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 5, (Scaleform::GFx::AS3::CheckResult *)&argv, &result);
    this->XValue = result;
  }
  if ( v3 >= 7 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 6, (Scaleform::GFx::AS3::CheckResult *)&argv, &result);
    this->YValue = result;
  }
}
