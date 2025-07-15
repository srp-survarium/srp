void __thiscall Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *VStr; // ebx
  __int16 Flags; // ax
  char v7; // cl
  __int16 v8; // ax
  char v9; // dl
  __int16 v10; // ax
  char v11; // cl
  __int16 v12; // ax
  char v13; // dl
  Scaleform::GFx::ASString value[2]; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+18h] [ebp-10h] BYREF

  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( argc >= 4 )
  {
    VStr = argv[3].value.VS._1.VStr;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    ++VStr->RefCount;
    value[0].pNode = VStr;
    Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::phaseSet(this, &r, value);
    if ( VStr->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
    if ( (r.Flags & 0x1F) > 9 )
    {
      if ( (r.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  if ( argc >= 5 )
  {
    *(double *)&value[0].pNode = argv[4].value.VNumber;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::InitLocalCoords(this);
    Flags = r.Flags;
    v7 = r.Flags & 0x1F;
    this->LocalX = *(double *)&value[0].pNode * 20.0;
    if ( v7 > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  if ( argc >= 6 )
  {
    *(double *)&value[0].pNode = argv[5].value.VNumber;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Instances::fl_events::GestureEvent::InitLocalCoords(this);
    v8 = r.Flags;
    v9 = r.Flags & 0x1F;
    this->LocalY = *(double *)&value[0].pNode * 20.0;
    if ( v9 > 9 )
    {
      if ( (v8 & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  if ( argc >= 7 )
  {
    *(double *)&value[0].pNode = argv[6].value.VNumber;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::InitLocalCoords(this);
    v10 = r.Flags;
    v11 = r.Flags & 0x1F;
    this->TapLocalX = *(double *)&value[0].pNode * 20.0;
    if ( v11 > 9 )
    {
      if ( (v10 & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  if ( argc >= 8 )
  {
    *(double *)&value[0].pNode = argv[7].value.VNumber;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Instances::fl_events::PressAndTapGestureEvent::InitLocalCoords(this);
    v12 = r.Flags;
    v13 = r.Flags & 0x1F;
    this->TapLocalY = *(double *)&value[0].pNode * 20.0;
    if ( v13 > 9 )
    {
      if ( (v12 & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  if ( argc >= 9 )
    this->CtrlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 8);
  if ( argc >= 0xA )
    this->AltKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 9);
  if ( argc >= 0xB )
    this->ShiftKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 10);
  if ( argc >= 0xC )
    this->CommandKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 11);
  if ( argc >= 0xD )
    this->ControlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 12);
}
