void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Shape::graphicsGet(
        Scaleform::GFx::AS3::Instances::fl_display::Shape *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *p_pGraphics; // edi
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *pObject; // ebp
  Scaleform::GFx::DrawingContext *v5; // eax
  Scaleform::GFx::DrawingContext *v6; // ebx
  Scaleform::RefCountNTSImpl *v7; // ecx

  if ( !this->pDispObj.pObject )
    this->CreateStageObject(this);
  p_pGraphics = &this->pGraphics;
  if ( !this->pGraphics.pObject
    && Scaleform::GFx::AS3::ASVM::_constructInstance(
         (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
         (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&this->pGraphics,
         *((Scaleform::GFx::AS3::Object **)&this->pTraits.pObject->pVM[1].__vftable + 1),
         0,
         0) )
  {
    pObject = p_pGraphics->pObject;
    v5 = this->pDispObj.pObject->GetDrawingContext(this->pDispObj.pObject);
    v6 = v5;
    if ( v5 )
      ++v5->RefCount;
    v7 = pObject->pDrawing.pObject;
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
    pObject->pDrawing.pObject = v6;
    p_pGraphics->pObject->pDispObj = this->pDispObj.pObject;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->pGraphics);
}
