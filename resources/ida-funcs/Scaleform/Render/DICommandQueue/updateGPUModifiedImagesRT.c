void __thiscall Scaleform::Render::DICommandQueue::updateGPUModifiedImagesRT(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DICommandQueue *p_pGPUModifiedNext; // edi
  Scaleform::Render::DrawableImage *pObject; // ecx
  _DWORD *v3; // ebx
  Scaleform::Render::DrawableImage *v4; // esi
  Scaleform::Render::DrawableImage *v5; // ecx
  Scaleform::Lock *lpCriticalSection; // [esp+Ch] [ebp-4h]

  p_pGPUModifiedNext = this;
  lpCriticalSection = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  pObject = p_pGPUModifiedNext->pGPUModifiedImageList.pObject;
  v3 = 0;
  if ( pObject )
    pObject->AddRef(pObject);
  v4 = p_pGPUModifiedNext->pGPUModifiedImageList.pObject;
  if ( v4 )
    v4->Release(v4);
  p_pGPUModifiedNext->pGPUModifiedImageList.pObject = 0;
  if ( v4 )
  {
    do
    {
      v4->AddRef(v4);
      if ( v3 )
        (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(v3);
      v3 = &v4->__vftable;
      Scaleform::Render::DrawableImage::updateStagingTargetRT(v4, (int)p_pGPUModifiedNext);
      v5 = v4->pGPUModifiedNext.pObject;
      p_pGPUModifiedNext = (Scaleform::Render::DICommandQueue *)&v4->pGPUModifiedNext;
      if ( v5 )
        v5->AddRef(v5);
      v4->Release(v4);
      v4 = (Scaleform::Render::DrawableImage *)p_pGPUModifiedNext->__vftable;
      if ( p_pGPUModifiedNext->__vftable )
        (*((void (__thiscall **)(Scaleform::Render::DICommandQueue_vtbl *))p_pGPUModifiedNext->~Scaleform::Render::DICommandQueue
         + 2))(p_pGPUModifiedNext->__vftable);
      p_pGPUModifiedNext->__vftable = 0;
      v3[10] &= ~0x10u;
    }
    while ( v4 );
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(v3);
  }
  LeaveCriticalSection(&lpCriticalSection->cs);
}
