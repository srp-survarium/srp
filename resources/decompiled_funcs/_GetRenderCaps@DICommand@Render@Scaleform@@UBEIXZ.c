unsigned int __thiscall Scaleform::Render::DICommand::GetRenderCaps(Scaleform::Render::DICommand *this)
{
  unsigned int v2; // edi
  Scaleform::Render::DrawableImage *pObject; // eax
  Scaleform::Render::DrawableImageContext *v4; // eax
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // eax
  Scaleform::Render::DICommandContext cmdCtx; // [esp+8h] [ebp-8h] BYREF

  v2 = this->GetCPUCaps(this);
  pObject = this->pImage.pObject;
  if ( pObject
    && (v4 = pObject->pContext.pObject) != 0
    && (pRTCommandQueue = v4->pRTCommandQueue) != 0
    && (Scaleform::Render::DICommandContext::DICommandContext(&cmdCtx, pRTCommandQueue), cmdCtx.pHAL) )
  {
    return v2 | cmdCtx.pHAL->DrawableCommandGetFlags(cmdCtx.pHAL, this);
  }
  else
  {
    return v2;
  }
}
