void __thiscall Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::GestureEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // ebp
  Scaleform::GFx::AS3::Value *VInt; // edi
  long double v7; // st7
  long double v8; // st7
  Scaleform::GFx::AS3::Value v; // [esp+Ch] [ebp-10h] BYREF

  v3 = argv;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( argc >= 4 )
  {
    VInt = (Scaleform::GFx::AS3::Value *)v3[3].value.VS._1.VInt;
    *(_QWORD *)&v.Flags = 0;
    ++VInt->value.VS._2.VObj;
    argv = VInt;
    Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::phaseSet(this, &v, (Scaleform::GFx::ASString *)&argv);
    if ( VInt->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)VInt);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  if ( argc >= 5 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(
      v3 + 4,
      (Scaleform::GFx::AS3::CheckResult *)&argv,
      (long double *)&v.Flags);
    v7 = *(double *)&v.Flags * 20.0;
    this->LocalInitialized = 1;
    this->LocalX = v7;
  }
  if ( argc >= 6 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(
      v3 + 5,
      (Scaleform::GFx::AS3::CheckResult *)&argv,
      (long double *)&v.Flags);
    v8 = *(double *)&v.Flags * 20.0;
    this->LocalInitialized = 1;
    this->LocalY = v8;
  }
  if ( argc >= 7 )
    this->CtrlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 6);
  if ( argc >= 8 )
    this->AltKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 7);
  if ( argc >= 9 )
    this->ShiftKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 8);
  if ( argc >= 0xA )
    this->CommandKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 9);
  if ( argc >= 0xB )
    this->ControlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 10);
}
