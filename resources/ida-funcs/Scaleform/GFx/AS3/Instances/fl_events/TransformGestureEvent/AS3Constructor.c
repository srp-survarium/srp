void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::ASStringNode *VStr; // ebx
  long double v7; // st7
  long double v8; // st7
  Scaleform::GFx::AS3::CheckResult result; // [esp+Fh] [ebp-19h] BYREF
  long double v; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+18h] [ebp-10h] BYREF

  v3 = argc;
  Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::AS3Constructor(this, argc, argv);
  if ( argc >= 4 )
  {
    VStr = argv[3].value.VS._1.VStr;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    ++VStr->RefCount;
    LODWORD(v) = VStr;
    Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::phaseSet(this, &r, (Scaleform::GFx::ASString *)&v);
    if ( VStr->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
    if ( (r.Flags & 0x1F) > 9 )
    {
      if ( (r.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
    v3 = argc;
  }
  if ( v3 >= 5 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &result, &v);
    v7 = v * 20.0;
    this->LocalInitialized = 1;
    this->LocalX = v7;
  }
  if ( v3 >= 6 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 5, &result, &v);
    v8 = v * 20.0;
    this->LocalInitialized = 1;
    this->LocalY = v8;
  }
  if ( v3 >= 7 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 6, &result, &v);
    this->ScaleX = v;
  }
  if ( v3 >= 8 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 7, &result, &v);
    this->ScaleY = v;
  }
  if ( v3 >= 9 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 8, &result, &v);
    this->Rotation = v;
  }
  if ( v3 >= 0xA )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 9, &result, &v);
    this->OffsetX = v * 20.0;
  }
  if ( v3 >= 0xB )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 10, &result, &v);
    this->OffsetY = v * 20.0;
  }
  if ( v3 >= 0xC )
    this->CtrlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 11);
  if ( v3 >= 0xD )
    this->AltKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 12);
  if ( v3 >= 0xE )
    this->ShiftKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 13);
  if ( v3 >= 0xF )
    this->CommandKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 14);
  if ( v3 >= 0x10 )
    this->ControlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 15);
}
