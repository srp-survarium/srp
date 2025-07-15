void __thiscall Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  _DWORD *v3; // ebx
  Scaleform::Render::DrawableImage *v4; // esi
  Scaleform::Render::DrawableImage *v5; // ecx
  Scaleform::Ptr<Scaleform::Render::DrawableImage> *p_pCPUModifiedNext; // edi
  Scaleform::Lock *lpCriticalSection; // [esp+Ch] [ebp-4h]

  lpCriticalSection = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  pObject = this->pCPUModifiedImageList.pObject;
  v3 = 0;
  if ( pObject )
    pObject->AddRef(pObject);
  v4 = this->pCPUModifiedImageList.pObject;
  if ( v4 )
    v4->Release(v4);
  this->pCPUModifiedImageList.pObject = 0;
  if ( v4 )
  {
    do
    {
      v4->AddRef(v4);
      if ( v3 )
        (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(v3);
      v3 = &v4->__vftable;
      Scaleform::Render::DrawableImage::updateRenderTargetRT(v4, (int)v4);
      v5 = v4->pCPUModifiedNext.pObject;
      p_pCPUModifiedNext = &v4->pCPUModifiedNext;
      if ( v5 )
        v5->AddRef(v5);
      v4->Release(v4);
      v4 = p_pCPUModifiedNext->pObject;
      if ( p_pCPUModifiedNext->pObject )
        p_pCPUModifiedNext->pObject->Release(p_pCPUModifiedNext->pObject);
      p_pCPUModifiedNext->pObject = 0;
      v3[10] &= ~8u;
    }
    while ( v4 );
    (*(void (__thiscall **)(_DWORD *))(*v3 + 8))(v3);
  }
  LeaveCriticalSection(&lpCriticalSection->cs);
}
