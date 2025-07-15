void __usercall Scaleform::Render::DrawableImage::updateRenderTargetRT(
        Scaleform::Render::DrawableImage *this@<ecx>,
        int a2@<esi>)
{
  Scaleform::Lock *p_QueueLock; // esi
  Scaleform::Render::DrawableImageContext *pObject; // esi
  void *RenderThreadID; // esi
  int v6; // [esp-4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-10h] BYREF
  Scaleform::Render::TextureManager *pTextureManager; // [esp+Ch] [ebp-Ch]
  Scaleform::Render::HAL *pHAL; // [esp+10h] [ebp-8h]
  Scaleform::Render::Renderer2D *pRenderer2D; // [esp+14h] [ebp-4h]
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
    v7 = 0;
    pTextureManager = 0;
    pHAL = 0;
    pRenderer2D = 0;
    ((void (__thiscall *)(Scaleform::Render::ThreadCommandQueue *, int *, int))pObject->pRTCommandQueue->GetRenderInterfaces)(
      pObject->pRTCommandQueue,
      &v7,
      v6);
    if ( pObject->IDefaults.pTextureManager )
      pTextureManager = pObject->IDefaults.pTextureManager;
    if ( pObject->IDefaults.pHAL )
      pHAL = pObject->IDefaults.pHAL;
    if ( pObject->IDefaults.pRenderer2D )
      pRenderer2D = pObject->IDefaults.pRenderer2D;
    RenderThreadID = pObject->IDefaults.RenderThreadID;
    if ( RenderThreadID )
      retaddr = RenderThreadID;
    ((void (__thiscall *)(Scaleform::Render::Texture *volatile, Scaleform::Render::RenderBuffer::RenderTargetData *))this->pTexture.Value->UpdateRenderTargetData)(
      this->pTexture.Value,
      this->pRT.pObject->pRenderTargetData);
  }
}
