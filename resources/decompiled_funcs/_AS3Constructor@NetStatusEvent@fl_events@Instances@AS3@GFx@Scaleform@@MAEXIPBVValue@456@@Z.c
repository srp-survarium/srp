void __thiscall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // edi

  v3 = argv;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( argc >= 4 )
    Scaleform::GFx::AS3::Value::Convert2String(v3 + 3, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->Code);
  if ( argc >= 5 )
    Scaleform::GFx::AS3::Value::Convert2String(v3 + 4, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->Level);
}
