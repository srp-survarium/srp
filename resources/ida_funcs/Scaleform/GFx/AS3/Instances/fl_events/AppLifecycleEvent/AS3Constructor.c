void __thiscall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // esi
  Scaleform::GFx::AS3::VM *pVM; // ebp
  const Scaleform::GFx::AS3::Value *v6; // esi
  Scaleform::GFx::AS3::Value *p_Status; // edi

  v3 = argv;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  pVM = this->pTraits.pObject->pVM;
  if ( argc >= 4 )
  {
    v6 = v3 + 3;
    p_Status = &this->Status;
    Scaleform::GFx::AS3::Value::Assign(p_Status, v6);
    if ( (v6->Flags & 0x1F) - 12 > 3 || v6->value.VS._1.VInt )
      Scaleform::GFx::AS3::Value::ToStringValue(
        p_Status,
        (Scaleform::GFx::AS3::CheckResult *)&argv,
        pVM->StringManagerRef);
  }
}
