void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebp
  const Scaleform::GFx::AS3::Value *v5; // ebx
  Scaleform::GFx::AS3::AvmBitmap *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v7; // edi
  const Scaleform::GFx::AS3::Value *pStringManager; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::AvmBitmap *v11; // esi

  v3 = argc;
  if ( argc )
  {
    v5 = argv;
    if ( Scaleform::GFx::AS3::VM::IsOfType(
           this->pTraits.pObject->pVM,
           argv,
           "flash.display.BitmapData",
           this->pTraits.pObject->pVM->CurrentDomain) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pBitmapData,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v5->value.VS._1.VInt);
      pObject = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
      if ( pObject )
      {
        v7 = this->pBitmapData.pObject;
        if ( v7 )
          Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(pObject, v7->pDefImpl.pObject);
        else
          Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(pObject, 0);
      }
    }
    if ( v3 >= 2 )
    {
      pStringManager = (const Scaleform::GFx::AS3::Value *)this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
      argv = (Scaleform::GFx::AS3::Value *)&pStringManager[2];
      ++pStringManager[2].value.VS._2.VObj;
      if ( !Scaleform::GFx::AS3::Value::Convert2String(
              (Scaleform::GFx::AS3::Value *)&v5[1],
              (Scaleform::GFx::AS3::CheckResult *)&argc,
              (Scaleform::GFx::ASString *)&argv)->Result )
      {
        v9 = (Scaleform::GFx::ASStringNode *)argv;
        --argv->value.VS._2.VObj;
        if ( !v9->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        return;
      }
      this->PixelSnapping = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(
                              this,
                              (const char *)argv->Flags);
      if ( v3 >= 3 )
        this->Smoothing = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)&v5[2]);
      v10 = (Scaleform::GFx::ASStringNode *)argv;
      --argv->value.VS._2.VObj;
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
    v11 = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
    if ( v11 )
      Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v11);
  }
}
