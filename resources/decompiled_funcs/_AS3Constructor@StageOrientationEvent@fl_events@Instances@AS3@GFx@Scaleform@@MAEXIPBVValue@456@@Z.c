void __thiscall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v4; // edi
  Scaleform::GFx::AS3::Value *p_AfterOrientation; // esi
  Scaleform::GFx::AS3::ASVM *vm; // [esp+Ch] [ebp-4h]

  v3 = argc;
  v4 = argv;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  vm = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  if ( v3 >= 4 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->BeforeOrientation, v4 + 3);
    if ( (v4[3].Flags & 0x1F) - 12 > 3 || v4[3].value.VS._1.VInt )
      Scaleform::GFx::AS3::Value::ToStringValue(
        &this->BeforeOrientation,
        (Scaleform::GFx::AS3::CheckResult *)&argv,
        vm->StringManagerRef);
  }
  if ( argc >= 5 )
  {
    p_AfterOrientation = &this->AfterOrientation;
    Scaleform::GFx::AS3::Value::Assign(p_AfterOrientation, v4 + 4);
    if ( (v4[3].Flags & 0x1F) - 12 > 3 || v4[3].value.VS._1.VInt )
      Scaleform::GFx::AS3::Value::ToStringValue(
        p_AfterOrientation,
        (Scaleform::GFx::AS3::CheckResult *)&argc,
        vm->StringManagerRef);
  }
}
