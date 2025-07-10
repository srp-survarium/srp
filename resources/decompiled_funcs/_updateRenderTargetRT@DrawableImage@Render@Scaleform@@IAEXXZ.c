void __usercall Scaleform::Render::DrawableImage::updateRenderTargetRT(
        Scaleform::Render::DrawableImage *this@<ecx>,
        int a2@<esi>)
{
  Scaleform::Lock *p_QueueLock; // esi
  Scaleform::Render::DrawableImageContext *pObject; // esi
  void *RenderThreadID; // esi
  int v6; // [esp-4h] [ebp-1Ch]
  Scaleform::Render::Interfaces rifs; // [esp+8h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+18h] [ebp+0h]

  if ( this->pTexture.Value )
  {
    v6 = a2;
    p_QueueLock = &this->pQueue.pObject->QueueLock;
    EnterCriticalSection(&p_QueueLock->cs);
    if ( (this->DrawableImageState & 3) != 0 && this->pTexture.Value )
    {
      ((void (__thiscall *)(Scaleform::Render::Texture *volatile, int))this->pTexture.Value->Unmap)(
        this->pTexture.Value,
        v6);
      this->DrawableImageState &= 0xFFFFFFFC;
    }
    LeaveCriticalSection(&p_QueueLock->cs);
    pObject = this->pContext.pObject;
    memset(&rifs, 0, sizeof(rifs));
    ((void (__thiscall *)(Scaleform::Render::ThreadCommandQueue *, Scaleform::Render::Interfaces *, int))pObject->pRTCommandQueue->GetRenderInterfaces)(
      pObject->pRTCommandQueue,
      &rifs,
      v6);
    if ( pObject->IDefaults.pTextureManager )
      rifs.pHAL = (Scaleform::Render::HAL *)pObject->IDefaults.pTextureManager;
    if ( pObject->IDefaults.pHAL )
      rifs.pRenderer2D = (Scaleform::Render::Renderer2D *)pObject->IDefaults.pHAL;
    if ( pObject->IDefaults.pRenderer2D )
      rifs.RenderThreadID = pObject->IDefaults.pRenderer2D;
    RenderThreadID = pObject->IDefaults.RenderThreadID;
    if ( RenderThreadID )
      retaddr = RenderThreadID;
    ((void (__thiscall *)(Scaleform::Render::Texture *volatile, Scaleform::Render::RenderBuffer::RenderTargetData *))this->pTexture.Value->UpdateRenderTargetData)(
      this->pTexture.Value,
      this->pRT.pObject->pRenderTargetData);
  }
}
