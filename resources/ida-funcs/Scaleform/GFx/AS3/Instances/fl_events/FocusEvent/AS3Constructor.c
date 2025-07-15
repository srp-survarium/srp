void __thiscall Scaleform::GFx::AS3::Instances::fl_events::FocusEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // ebp
  unsigned int v4; // edi
  Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject> *p_RelatedObj; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *VInt; // ebx

  v3 = argv;
  v4 = argc;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( v4 >= 4 )
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
    VInt = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v3[3].value.VS._1.VInt;
    if ( VInt
      && Scaleform::GFx::AS3::VM::IsOfType(
           this->pTraits.pObject->pVM,
           v3 + 3,
           "flash.display.InteractiveObject",
           this->pTraits.pObject->pVM->CurrentDomain) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->RelatedObj,
        VInt);
    }
    v4 = argc;
  }
  if ( v4 >= 5 )
    this->ShiftKey = Scaleform::GFx::AS3::Value::Convert2Boolean(v3 + 4);
  if ( v4 >= 6 )
  {
    Scaleform::GFx::AS3::Value::Convert2UInt32(v3 + 5, (Scaleform::GFx::AS3::CheckResult *)&argc, (unsigned int *)&argv);
    this->KeyCode = (unsigned int)argv;
  }
}
