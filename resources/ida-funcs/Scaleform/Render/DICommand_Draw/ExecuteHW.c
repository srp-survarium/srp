void __thiscall Scaleform::Render::DICommand_Draw::ExecuteHW(
        Scaleform::Render::DICommand_Draw *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::DrawableImageContext *pObject; // edi
  Scaleform::Render::DrawableImageContext_vtbl *v4; // ebx
  Scaleform::GFx::ASSoundIntf_vtbl *ContextNotify; // eax
  Scaleform::Render::HAL *pHAL; // eax
  char v7; // bl
  Scaleform::Render::Viewport vpin; // [esp+10h] [ebp-2Ch] BYREF

  pObject = this->pImage.pObject->pContext.pObject;
  v4 = pObject->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  ContextNotify = Scaleform::Render::Renderer2D::GetContextNotify((Scaleform::GFx::AS3::SoundObject *)context->pR2D);
  v4->ExecuteNextCapture(pObject, (Scaleform::Render::ContextImpl::RenderNotify *)ContextNotify);
  pHAL = context->pHAL;
  vpin = pHAL->VP;
  v7 = 0;
  if ( (pHAL->HALState & 8) != 0 )
  {
    v7 = 1;
    Scaleform::Render::HAL::EndDisplay(context->pHAL);
  }
  context->pHAL->SetDisplayPass(context->pHAL, Display_All);
  Scaleform::Render::HAL::applyBlendMode(context->pHAL, Blend_Normal, 1, (Scaleform::String::DataDesc *)1);
  Scaleform::Render::Renderer2D::Display(context->pR2D, this->pRoot);
  if ( v7 )
    Scaleform::Render::HAL::BeginDisplay(context->pHAL, 0, &vpin);
  Scaleform::Render::DrawableImageContext::AddTreeRootToKillList(
    pObject,
    (Scaleform::GFx::AS3::ClassTraits::Traits *)this->pRoot);
}
