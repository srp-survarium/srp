void __thiscall Scaleform::GFx::AS3::Instances::fl_events::TouchEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebp
  Scaleform::GFx::AS3::Value *v4; // edi
  long double v6; // st7
  long double v7; // st7
  long double v8; // st7
  long double v9; // st7
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *p_RelatedObj; // ebp
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *VInt; // ebx
  long double v; // [esp+Ch] [ebp-8h] BYREF

  v3 = argc;
  v4 = argv;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( argc >= 4 )
    Scaleform::GFx::AS3::Value::Convert2Int32(v4 + 3, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->TouchPointID);
  if ( argc >= 5 )
    this->PrimaryPoint = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 4);
  if ( argc >= 6 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 5, (Scaleform::GFx::AS3::CheckResult *)&argv, &v);
    v6 = v * 20.0;
    this->LocalInitialized = 1;
    this->LocalX = v6;
  }
  if ( argc >= 7 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 6, (Scaleform::GFx::AS3::CheckResult *)&argv, &v);
    v7 = v * 20.0;
    this->LocalInitialized = 1;
    this->LocalY = v7;
  }
  if ( argc >= 8 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 7, (Scaleform::GFx::AS3::CheckResult *)&argv, &v);
    v8 = v * 20.0;
    this->LocalInitialized = 1;
    this->SizeX = v8;
  }
  if ( argc >= 9 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 8, (Scaleform::GFx::AS3::CheckResult *)&argv, &v);
    v9 = v * 20.0;
    this->LocalInitialized = 1;
    this->SizeY = v9;
  }
  if ( argc >= 0xA )
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 9, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->Pressure);
  if ( argc >= 0xB )
  {
    pObject = this->RelatedObj.pObject;
    p_RelatedObj = &this->RelatedObj;
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        p_RelatedObj->pObject = (Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      p_RelatedObj->pObject = 0;
    }
    VInt = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v4[5].value.VS._1.VInt;
    if ( VInt
      && Scaleform::GFx::AS3::VM::IsOfType(
           this->pTraits.pObject->pVM,
           v4 + 10,
           "flash.display.InteractiveObject",
           this->pTraits.pObject->pVM->CurrentDomain) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->RelatedObj,
        VInt);
    }
    v3 = argc;
  }
  if ( v3 >= 0xC )
    this->CtrlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 11);
  if ( v3 >= 0xD )
    this->AltKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 12);
  if ( v3 >= 0xE )
    this->ShiftKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 13);
  if ( v3 >= 0xF )
    this->CommandKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 14);
  if ( v3 >= 0x10 )
    this->ControlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 15);
}
