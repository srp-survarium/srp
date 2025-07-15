void __thiscall Scaleform::Render::DICommandSet::ExecuteCommandsRT(
        Scaleform::Render::DICommandSet *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::HAL *pHAL; // esi
  Scaleform::Render::DICommandSet *v3; // edi
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *p_QueueList; // eax
  bool v5; // zf
  Scaleform::Render::DICommand *pNext; // edi
  _DWORD *v7; // eax
  Scaleform::Render::DICommand_vtbl *v8; // ecx
  Scaleform::Render::DICommand *v9; // eax
  Scaleform::Render::DICommand_vtbl *v10; // ebx
  unsigned int v11; // ecx
  Scaleform::Render::DrawableImage *v12; // ebx
  Scaleform::Render::DICommand *v13; // ecx
  Scaleform::Render::DrawableImage *pObject; // edi
  char v15; // al
  bool (__thiscall *EndScene)(Scaleform::Render::HAL *); // edx
  Scaleform::Render::DICommand *v17; // edi
  unsigned int v18; // eax
  Scaleform::Render::DICommand *v19; // ecx
  void (__thiscall *v20)(Scaleform::Render::DICommand *); // eax
  Scaleform::Render::DICommand *v21; // ecx
  bool (__thiscall *v22)(Scaleform::Render::HAL *); // eax
  unsigned int *v23; // eax
  int v24; // edx
  double v25; // st7
  Scaleform::Render::HAL_vtbl *v26; // eax
  double v27; // st7
  int v28; // eax
  bool (__thiscall *v29)(Scaleform::Render::HAL *); // eax
  Scaleform::Render::Size<unsigned long> *(__thiscall *GetSize)(struct Scaleform::Render::DrawableImage *, Scaleform::Render::Size<unsigned long> *); // edx
  int *v31; // eax
  int v32; // ecx
  int v33; // edx
  Scaleform::Render::RenderSync *v34; // eax
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *inserted; // eax
  Scaleform::Render::Fence *v36; // ecx
  int v37; // eax
  Scaleform::Render::RenderEvent *v38; // eax
  Scaleform::Render::RenderEvent_vtbl *v39; // edi
  unsigned int v40; // ecx
  bool (__thiscall *v41)(Scaleform::Render::HAL *); // edx
  unsigned int *v42; // eax
  int v43; // edx
  double v44; // st7
  Scaleform::Render::DrawableImage_vtbl *v45; // eax
  Scaleform::Render::HAL_vtbl *v46; // edi
  Scaleform::Render::RenderTarget *(__thiscall *GetRenderTarget)(Scaleform::Render::DrawableImage *); // edx
  int v48; // eax
  bool (__thiscall *BeginScene)(Scaleform::Render::HAL *); // edx
  int v50; // edi
  int *v51; // eax
  int v52; // ecx
  Scaleform::Render::DICommand *v53; // edi
  int v54; // eax
  int v55; // ecx
  void (__thiscall *v56)(Scaleform::Render::DICommand *); // eax
  Scaleform::Render::RenderSync *v57; // eax
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *v58; // eax
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *v59; // edi
  Scaleform::Render::Fence *v60; // ecx
  int v61; // eax
  Scaleform::Render::DICommandSet *v62; // ebx
  Scaleform::Render::DICommandQueue *pQueue; // ecx
  Scaleform::String v64[4]; // [esp+22h] [ebp-C4h] BYREF
  char v65; // [esp+33h] [ebp-B3h]
  bool v66; // [esp+34h] [ebp-B2h]
  char v67; // [esp+35h] [ebp-B1h]
  int v68; // [esp+36h] [ebp-B0h]
  Scaleform::Render::DICommand *v69; // [esp+3Ah] [ebp-ACh]
  int p_PushRenderTarget; // [esp+3Eh] [ebp-A8h]
  void (__thiscall **v71)(Scaleform::Render::HAL *, float *, int); // [esp+42h] [ebp-A4h]
  __int16 v72; // [esp+46h] [ebp-A0h]
  char v73; // [esp+48h] [ebp-9Eh]
  Scaleform::Render::DICommandSet *v74; // [esp+4Ah] [ebp-9Ch]
  Scaleform::Render::DICommand *v75; // [esp+4Eh] [ebp-98h]
  int v76; // [esp+52h] [ebp-94h]
  float v77; // [esp+56h] [ebp-90h]
  float v78; // [esp+5Ah] [ebp-8Ch] BYREF
  float v79; // [esp+5Eh] [ebp-88h]
  float v80; // [esp+62h] [ebp-84h]
  float v81; // [esp+66h] [ebp-80h]
  float v82; // [esp+6Ah] [ebp-7Ch] BYREF
  float v83; // [esp+6Eh] [ebp-78h]
  float v84; // [esp+72h] [ebp-74h]
  Scaleform::Render::Viewport vpin; // [esp+7Ah] [ebp-6Ch] BYREF
  Scaleform::Render::Size<unsigned long> v86; // [esp+A6h] [ebp-40h] BYREF
  int v87; // [esp+AEh] [ebp-38h]
  Scaleform::Render::Size<unsigned long> v88; // [esp+BEh] [ebp-28h] BYREF
  int v89; // [esp+C6h] [ebp-20h]
  Scaleform::Render::Size<unsigned long> v90; // [esp+D6h] [ebp-10h] BYREF
  Scaleform::Render::Size<unsigned long> v91; // [esp+DEh] [ebp-8h] BYREF

  pHAL = context->pHAL;
  v3 = this;
  p_QueueList = &this->QueueList;
  v74 = this;
  v67 = 0;
  v72 = 256;
  v73 = 0;
  if ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)this->QueueList.Root.pNext != &this->QueueList )
  {
    while ( 1 )
    {
      v5 = v67 == 0;
      pNext = (Scaleform::Render::DICommand *)v3->QueueList.Root.pNext;
      pNext->GetType = (Scaleform::Render::DICommandType (__thiscall *)(Scaleform::Render::DICommand *))pNext->pImage.pObject;
      v7 = &pNext->pImage.pObject->__vftable;
      v8 = pNext->__vftable;
      v75 = pNext;
      *v7 = v8;
      if ( v5 )
      {
        v9 = (Scaleform::Render::DICommand *)pHAL->GetEvent(pHAL, Event_DrawableImage);
        v10 = v9->__vftable;
        v64[0].HeapTypeBits = v11;
        v69 = v9;
        Scaleform::String::String(v64, (const __m128i *)"Scaleform::Render::DrawableImage");
        ((void (__thiscall *)(Scaleform::Render::DICommand *, unsigned int))v10->GetCPUCaps)(v69, v64[0].HeapTypeBits);
        v67 = 1;
      }
      v12 = 0;
      if ( pNext[63].__vftable )
      {
        v13 = pNext + 1;
        v69 = pNext + 1;
      }
      else
      {
        v69 = 0;
        v13 = 0;
      }
      v65 = 0;
      if ( v13 )
        break;
LABEL_71:
      if ( v67 )
      {
        v61 = (int)pHAL->GetEvent(pHAL, Event_DrawableImage);
        (*(void (__thiscall **)(int))(*(_DWORD *)v61 + 12))(v61);
      }
      v62 = v74;
      pQueue = v74->pQueue;
      if ( v74->pQueue->FreePageCount >= 3 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)pNext);
      }
      else
      {
        pNext[63].__vftable = 0;
        pNext->__vftable = (Scaleform::Render::DICommand_vtbl *)pQueue->Queues[3].Root.pPrev;
        pNext->pImage.pObject = (Scaleform::Render::DrawableImage *)&pQueue->Queues[3];
        pQueue->Queues[3].Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)pNext;
        pQueue->Queues[3].Root.pPrev = (Scaleform::Render::DIQueuePage *)pNext;
        ++pQueue->FreePageCount;
      }
      p_QueueList = &v62->QueueList;
      v3 = v62;
      if ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)v62->QueueList.Root.pNext == &v62->QueueList )
        goto LABEL_77;
    }
    while ( 1 )
    {
      pObject = v13->pImage.pObject;
      v15 = ((int (*)(void))v13->GetRenderCaps)();
      if ( v12 == pObject && v12 && v65 )
      {
        v66 = (v15 & 2) != 0;
        if ( (v15 & 2) == 0 )
          goto LABEL_28;
      }
      else
      {
        if ( (v15 & 4) == 0 && (v15 & 1) != 0 || (v15 & 8) != 0 )
        {
          v66 = 0;
          goto LABEL_28;
        }
        v66 = 1;
      }
      if ( !pObject->pRT.pObject )
      {
        if ( !(_BYTE)v72 )
        {
          if ( (pHAL->HALState & 4) != 0 )
          {
            EndScene = pHAL->EndScene;
            v73 = 1;
            EndScene(pHAL);
          }
          if ( (pHAL->HALState & 2) == 0 )
          {
            pHAL->BeginFrame(pHAL);
            HIBYTE(v72) = 0;
          }
          LOBYTE(v72) = 1;
        }
        if ( !Scaleform::Render::DrawableImage::ensureRenderableRT(pObject) )
        {
          v17 = v69;
          v18 = v69->GetSize(v69);
          v19 = (char *)v17 + v18 < (char *)&v75[63].GetCPUCaps + (unsigned int)v75
              ? (Scaleform::Render::DICommand *)((char *)v17 + v18)
              : 0;
          v20 = v17->~Scaleform::Render::DICommand;
          v69 = v19;
          ((void (__thiscall *)(Scaleform::Render::DICommand *, _DWORD))v20)(v17, 0);
          v21 = v69;
          goto LABEL_61;
        }
      }
LABEL_28:
      if ( v12 && v65 || !v66 )
      {
        if ( v12 == pObject )
          goto LABEL_60;
        if ( v65 )
        {
          v12 = pObject;
          Scaleform::Render::HAL::EndDisplay(pHAL);
          pHAL->EndScene(pHAL);
          Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(v74->pQueue);
          pHAL->PopRenderTarget(pHAL, 2u);
          if ( context->pHAL->GetRenderSync(context->pHAL) )
          {
            v34 = context->pHAL->GetRenderSync(context->pHAL);
            inserted = Scaleform::Render::RenderSync::InsertFence(v34);
            v68 = (int)inserted;
            if ( inserted )
              ++inserted->Data[0].RefCount;
            v36 = pObject->pFence.pObject;
            if ( v36 )
            {
              Scaleform::Render::Fence::Release(v36);
              inserted = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *)v68;
            }
            pObject->pFence.pObject = (Scaleform::Render::Fence *)inserted;
          }
          v65 = 0;
        }
        v37 = (int)pHAL->GetEvent(pHAL, Event_DrawableImage);
        (*(void (__thiscall **)(int))(*(_DWORD *)v37 + 12))(v37);
        v38 = pHAL->GetEvent(pHAL, Event_DrawableImage);
        v39 = v38->__vftable;
        v64[0].HeapTypeBits = v40;
        v68 = (int)v38;
        Scaleform::String::String(v64, (const __m128i *)"Scaleform::Render::DrawableImage");
        ((void (__thiscall *)(int, unsigned int))v39->Begin)(v68, v64[0].HeapTypeBits);
        if ( !v66 )
          goto LABEL_60;
        if ( !(_BYTE)v72 )
        {
          if ( (pHAL->HALState & 4) != 0 )
          {
            v41 = pHAL->EndScene;
            v73 = 1;
            v41(pHAL);
          }
          if ( (pHAL->HALState & 2) == 0 )
          {
            pHAL->BeginFrame(pHAL);
            HIBYTE(v72) = 0;
          }
          LOBYTE(v72) = 1;
        }
        v42 = (unsigned int *)v12->GetSize(v12, &v86);
        v43 = v42[1];
        *(float *)&v68 = (float)*v42;
        v44 = (double)(int)v42[1];
        if ( v43 < 0 )
          v44 = v44 + 4294967300.0;
        v45 = v12->__vftable;
        *(float *)&p_PushRenderTarget = v44;
        v46 = pHAL->__vftable;
        GetRenderTarget = v45->GetRenderTarget;
        v81 = 0.0;
        v82 = 0.0;
        v83 = *(float *)&v68;
        v84 = *(float *)&p_PushRenderTarget;
        v48 = ((int (__thiscall *)(Scaleform::Render::DrawableImage *, int))GetRenderTarget)(v12, 3);
        ((void (__thiscall *)(Scaleform::Render::HAL *, float *, int))v46->PushRenderTarget)(pHAL, &v82, v48);
        BeginScene = pHAL->BeginScene;
        v65 = 1;
        BeginScene(pHAL);
        v50 = (int)v84;
        p_PushRenderTarget = (int)v83;
        v68 = (int)v82;
        v89 = (int)v81;
        v51 = (int *)v12->GetSize(v12, &v91);
        v52 = v51[1];
        v33 = v89;
        vpin.BufferWidth = *v51;
        vpin.BufferHeight = v52;
        vpin.Top = v68;
        vpin.Width = p_PushRenderTarget - v89;
        vpin.Height = v50 - v68;
        vpin.Flags = 0;
      }
      else
      {
        if ( !(_BYTE)v72 )
        {
          if ( (pHAL->HALState & 4) != 0 )
          {
            v22 = pHAL->EndScene;
            v73 = 1;
            v22(pHAL);
          }
          if ( (pHAL->HALState & 2) == 0 )
          {
            pHAL->BeginFrame(pHAL);
            HIBYTE(v72) = 0;
          }
          LOBYTE(v72) = 1;
        }
        v12 = pObject;
        v23 = (unsigned int *)pObject->GetSize(pObject, &v90);
        v24 = v23[1];
        *(float *)&v76 = (float)*v23;
        v25 = (double)(int)v23[1];
        if ( v24 < 0 )
          v25 = v25 + 4294967300.0;
        v26 = pHAL->__vftable;
        *(float *)&p_PushRenderTarget = v25;
        v77 = 0.0;
        v64[0].HeapTypeBits = 3;
        v78 = 0.0;
        v79 = *(float *)&v76;
        v27 = *(float *)&p_PushRenderTarget;
        p_PushRenderTarget = (int)&v26->PushRenderTarget;
        v80 = v27;
        v28 = ((int (__thiscall *)(Scaleform::Render::DrawableImage *, int))pObject->GetRenderTarget)(pObject, 3);
        (*v71)(pHAL, &v78, v28);
        v29 = pHAL->BeginScene;
        v65 = 1;
        v29(pHAL);
        v68 = (int)v80;
        v76 = (int)v79;
        p_PushRenderTarget = (int)v78;
        GetSize = pObject->GetSize;
        v87 = (int)v77;
        v31 = (int *)GetSize(pObject, &v88);
        v32 = v31[1];
        v33 = v87;
        vpin.BufferWidth = *v31;
        vpin.BufferHeight = v32;
        vpin.Width = v76 - v87;
        vpin.Top = p_PushRenderTarget;
        vpin.Height = v68 - p_PushRenderTarget;
        vpin.Flags = 1;
      }
      vpin.Left = v33;
      memset(&vpin.ScissorLeft, 0, 16);
      Scaleform::Render::HAL::BeginDisplay(pHAL, 0, &vpin);
LABEL_60:
      v53 = v69;
      Scaleform::Render::DICommand::ExecuteRT(v69, context);
      v54 = v53->GetSize(v53);
      v55 = (char *)v53 + v54 < (char *)&v75[63].GetCPUCaps + (unsigned int)v75 ? (unsigned int)v53 + v54 : 0;
      v56 = v53->~Scaleform::Render::DICommand;
      v68 = v55;
      ((void (__thiscall *)(Scaleform::Render::DICommand *, _DWORD))v56)(v53, 0);
      v21 = (Scaleform::Render::DICommand *)v68;
LABEL_61:
      v69 = v21;
      if ( !v21 )
      {
        if ( v12 )
        {
          if ( v65 )
          {
            Scaleform::Render::HAL::EndDisplay(pHAL);
            pHAL->EndScene(pHAL);
            Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(v74->pQueue);
            pHAL->PopRenderTarget(pHAL, 2u);
            if ( context->pHAL->GetRenderSync(context->pHAL) )
            {
              v57 = context->pHAL->GetRenderSync(context->pHAL);
              v58 = Scaleform::Render::RenderSync::InsertFence(v57);
              v59 = v58;
              if ( v58 )
                ++v58->Data[0].RefCount;
              v60 = v12->pFence.pObject;
              if ( v60 )
                Scaleform::Render::Fence::Release(v60);
              v12->pFence.pObject = (Scaleform::Render::Fence *)v59;
            }
          }
        }
        pNext = v75;
        goto LABEL_71;
      }
      v13 = v69;
    }
  }
LABEL_77:
  v5 = (_BYTE)v72 == 0;
  p_QueueList->Root.pPrev = (Scaleform::Render::DIQueuePage *)p_QueueList;
  p_QueueList->Root.pNext = (Scaleform::Render::DIQueuePage *)p_QueueList;
  if ( !v5 )
  {
    if ( !HIBYTE(v72) )
      pHAL->EndFrame(pHAL);
    if ( v73 )
      pHAL->BeginScene(pHAL);
  }
  Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(v3->pQueue);
  Scaleform::Render::DICommandQueue::updateGPUModifiedImagesRT(v3->pQueue);
}
