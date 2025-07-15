unsigned int __thiscall Scaleform::Render::DICommand::GetRenderCaps(Scaleform::Render::DICommand *this)
{
  unsigned int v2; // edi
  Scaleform::Render::DrawableImage *pObject; // eax
  Scaleform::Render::DrawableImageContext *v4; // eax
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // eax
  Scaleform::Render::DICommandContext v7; // [esp+8h] [ebp-8h] BYREF

  v2 = this->GetCPUCaps(this);
  pObject = this->pImage.pObject;
  if ( pObject
    && (v4 = pObject->pContext.pObject) != 0
    && (pRTCommandQueue = v4->pRTCommandQueue) != 0
    && (Scaleform::Render::DICommandContext::DICommandContext(&v7, pRTCommandQueue), v7.pHAL) )
  {
    return v2 | v7.pHAL->DrawableCommandGetFlags(v7.pHAL, this);
  }
  else
  {
    return v2;
  }
}
