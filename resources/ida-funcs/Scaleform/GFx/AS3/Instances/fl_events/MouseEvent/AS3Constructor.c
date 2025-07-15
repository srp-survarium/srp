void __thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v4; // edi
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *p_RelatedObj; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *VInt; // ebp
  long double v; // [esp+Ch] [ebp-8h] BYREF

  v3 = argc;
  v4 = argv;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( v3 >= 4 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 3, (Scaleform::GFx::AS3::CheckResult *)&argv, &v);
    this->LocalX = v * 20.0;
  }
  if ( v3 >= 5 )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(v4 + 4, (Scaleform::GFx::AS3::CheckResult *)&argv, &v);
    this->LocalY = v * 20.0;
  }
  if ( v3 >= 6 )
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
           v4 + 5,
           "flash.display.InteractiveObject",
           this->pTraits.pObject->pVM->CurrentDomain) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->RelatedObj,
        VInt);
    }
    v3 = argc;
  }
  if ( v3 >= 7 )
    this->CtrlKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 6);
  if ( v3 >= 8 )
    this->AltKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 7);
  if ( v3 >= 9 )
    this->ShiftKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 8);
  if ( v3 >= 0xA )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Boolean(v4 + 9) )
      this->ButtonsMask |= 1u;
    else
      this->ButtonsMask &= ~1u;
  }
  if ( v3 >= 0xB )
  {
    Scaleform::GFx::AS3::Value::Convert2Int32(v4 + 10, (Scaleform::GFx::AS3::CheckResult *)&argc, (int *)&argv);
    this->Delta = (int)argv;
  }
}
