void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::graphicsGet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *p_pGraphics; // esi
  Scaleform::GFx::AS3::Object *pObject; // ebp
  Scaleform::GFx::DrawingContext *v5; // eax
  Scaleform::GFx::DrawingContext *v6; // ebx
  Scaleform::RefCountNTSImpl *v7; // ecx

  p_pGraphics = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&this->pGraphics;
  if ( !this->pGraphics.pObject
    && Scaleform::GFx::AS3::ASVM::_constructInstance(
         (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
         p_pGraphics,
         *((Scaleform::GFx::AS3::Object **)&this->pTraits.pObject->pVM[1].__vftable + 1),
         0,
         0) )
  {
    pObject = p_pGraphics->pObject;
    v5 = this->pDispObj.pObject->GetDrawingContext(this->pDispObj.pObject);
    v6 = v5;
    if ( v5 )
      ++v5->RefCount;
    v7 = (Scaleform::RefCountNTSImpl *)pObject[1].__vftable;
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
    pObject[1].__vftable = (Scaleform::GFx::AS3::Object_vtbl *)v6;
    p_pGraphics->pObject[1].pRCCRaw = (unsigned int)this->pDispObj.pObject;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_pGraphics);
}
