void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_ApplyFilter>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_ApplyFilter *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_SourceRect *v5; // eax
  _DWORD *v6; // esi
  Scaleform::GFx::Resource *v7; // ecx
  Scaleform::Render::DICommandQueue *v8; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                      this->pQueue.pObject,
                                                      0x28u,
                                                      &this->pQueue.pObject->QueueLock);
    v6 = &v5->__vftable;
    if ( v5 )
    {
      Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v5, cmd);
      *v6 = &Scaleform::Render::DICommand_ApplyFilter::`vftable';
      v7 = (Scaleform::GFx::Resource *)cmd->pFilter.pObject;
      if ( v7 )
        Scaleform::RefCountImpl::AddRef(v7);
      v6[9] = cmd->pFilter.pObject;
    }
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v8 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8->ExecuteCmd.pObject);
      v8->pRTCommandQueue->PushThreadCommand(v8->pRTCommandQueue, v8->ExecuteCmd.pObject);
      p_ExecuteDone = &v8->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Clear>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_Clear *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  Scaleform::Render::DrawableImage *v7; // ecx
  Scaleform::Render::DICommandQueue *v8; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = Scaleform::Render::DICommandQueue::allocCommandFromPage(
           this->pQueue.pObject,
           0xCu,
           &this->pQueue.pObject->QueueLock);
    v6 = v5;
    if ( v5 )
    {
      *v5 = &Scaleform::Render::DICommand::`vftable';
      v7 = cmd->pImage.pObject;
      if ( v7 )
        v7->AddRef(v7);
      v6[1] = cmd->pImage.pObject;
      *v6 = &Scaleform::Render::DICommand_Clear::`vftable';
      v6[2] = cmd->FillColor.Raw;
    }
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v8 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8->ExecuteCmd.pObject);
      v8->pRTCommandQueue->PushThreadCommand(v8->pRTCommandQueue, v8->ExecuteCmd.pObject);
      p_ExecuteDone = &v8->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_ColorTransform>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_ColorTransform *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_SourceRect *v5; // eax
  _DWORD *v6; // edi
  Scaleform::Render::DICommandQueue *v7; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                      this->pQueue.pObject,
                                                      0x50u,
                                                      &this->pQueue.pObject->QueueLock);
    v6 = &v5->__vftable;
    if ( v5 )
    {
      Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v5, cmd);
      *v6 = &Scaleform::Render::DICommand_ColorTransform::`vftable';
      qmemcpy(v6 + 12, &cmd->Cx, 0x20u);
    }
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v7 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v7);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v7->ExecuteCmd.pObject);
      v7->pRTCommandQueue->PushThreadCommand(v7->pRTCommandQueue, v7->ExecuteCmd.pObject);
      p_ExecuteDone = &v7->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Compare>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_Compare *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_SourceRect *v5; // eax
  _DWORD *v6; // esi
  Scaleform::Render::DrawableImage *v7; // ecx
  Scaleform::Render::DICommandQueue *v8; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                      this->pQueue.pObject,
                                                      0x28u,
                                                      &this->pQueue.pObject->QueueLock);
    v6 = &v5->__vftable;
    if ( v5 )
    {
      Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v5, cmd);
      *v6 = &Scaleform::Render::DICommand_Compare::`vftable';
      v7 = cmd->pImageCompare1.pObject;
      if ( v7 )
        v7->AddRef(v7);
      v6[9] = cmd->pImageCompare1.pObject;
    }
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v8 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8->ExecuteCmd.pObject);
      v8->pRTCommandQueue->PushThreadCommand(v8->pRTCommandQueue, v8->ExecuteCmd.pObject);
      p_ExecuteDone = &v8->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CopyChannel>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_CopyChannel *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_SourceRect *v5; // eax
  _DWORD *v6; // esi
  Scaleform::Render::DICommandQueue *v7; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                      this->pQueue.pObject,
                                                      0x2Cu,
                                                      &this->pQueue.pObject->QueueLock);
    v6 = &v5->__vftable;
    if ( v5 )
    {
      Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v5, cmd);
      *v6 = &Scaleform::Render::DICommand_CopyChannel::`vftable';
      v6[9] = cmd->SourceChannel;
      v6[10] = cmd->DestChannel;
    }
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v7 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v7);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v7->ExecuteCmd.pObject);
      v7->pRTCommandQueue->PushThreadCommand(v7->pRTCommandQueue, v7->ExecuteCmd.pObject);
      p_ExecuteDone = &v7->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CopyPixels>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_CopyPixels *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommandQueue *v5; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_CopyPixels>(
      this->pQueue.pObject,
      cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v5 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5->ExecuteCmd.pObject);
      v5->pRTCommandQueue->PushThreadCommand(v5->pRTCommandQueue, v5->ExecuteCmd.pObject);
      p_ExecuteDone = &v5->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CreateTexture>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_CreateTexture *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  Scaleform::Render::DrawableImage *v7; // ecx
  Scaleform::Render::DICommandQueue *v8; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = Scaleform::Render::DICommandQueue::allocCommandFromPage(
           this->pQueue.pObject,
           8u,
           &this->pQueue.pObject->QueueLock);
    v6 = v5;
    if ( v5 )
    {
      *v5 = &Scaleform::Render::DICommand::`vftable';
      v7 = cmd->pImage.pObject;
      if ( v7 )
        v7->AddRef(v7);
      v6[1] = cmd->pImage.pObject;
      *v6 = &Scaleform::Render::DICommand_CreateTexture::`vftable';
    }
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v8 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8->ExecuteCmd.pObject);
      v8->pRTCommandQueue->PushThreadCommand(v8->pRTCommandQueue, v8->ExecuteCmd.pObject);
      p_ExecuteDone = &v8->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Draw>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_Draw *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_Draw *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_Draw *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                this->pQueue.pObject,
                                                0x20u,
                                                &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_Draw::DICommand_Draw(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_FillRect>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_FillRect *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_FillRect *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_FillRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                    this->pQueue.pObject,
                                                    0x1Cu,
                                                    &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_FillRect::DICommand_FillRect(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_FloodFill>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_FloodFill *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommandQueue *v5; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_FloodFill>(this->pQueue.pObject, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v5 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5->ExecuteCmd.pObject);
      v5->pRTCommandQueue->PushThreadCommand(v5->pRTCommandQueue, v5->ExecuteCmd.pObject);
      p_ExecuteDone = &v5->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetColorBoundsRect>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_GetColorBoundsRect *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_GetColorBoundsRect *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_GetColorBoundsRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                              this->pQueue.pObject,
                                                              0x18u,
                                                              &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_GetColorBoundsRect::DICommand_GetColorBoundsRect(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetPixel32>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_GetPixel32 *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommandQueue *v5; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_GetPixel32>(
      this->pQueue.pObject,
      cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v5 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5->ExecuteCmd.pObject);
      v5->pRTCommandQueue->PushThreadCommand(v5->pRTCommandQueue, v5->ExecuteCmd.pObject);
      p_ExecuteDone = &v5->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetPixels>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_GetPixels *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_GetPixels *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_GetPixels *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                     this->pQueue.pObject,
                                                     0x20u,
                                                     &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_GetPixels::DICommand_GetPixels(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Histogram>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_Histogram *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_Histogram *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_Histogram *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                     this->pQueue.pObject,
                                                     0x1Cu,
                                                     &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_Histogram::DICommand_Histogram(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_HitTest>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_HitTest *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_HitTest *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_HitTest *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                   this->pQueue.pObject,
                                                   0x38u,
                                                   &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_HitTest::DICommand_HitTest(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Merge>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_Merge *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_SourceRect *v5; // eax
  _DWORD *v6; // esi
  Scaleform::Render::DICommandQueue *v7; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                      this->pQueue.pObject,
                                                      0x34u,
                                                      &this->pQueue.pObject->QueueLock);
    v6 = &v5->__vftable;
    if ( v5 )
    {
      Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v5, cmd);
      *v6 = &Scaleform::Render::DICommand_Merge::`vftable';
      v6[9] = cmd->RedMultiplier;
      v6[10] = cmd->GreenMultiplier;
      v6[11] = cmd->BlueMultiplier;
      v6[12] = cmd->AlphaMultiplier;
    }
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v7 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v7);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v7->ExecuteCmd.pObject);
      v7->pRTCommandQueue->PushThreadCommand(v7->pRTCommandQueue, v7->ExecuteCmd.pObject);
      p_ExecuteDone = &v7->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Noise>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_Noise *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_Noise *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_Noise *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                 this->pQueue.pObject,
                                                 0x1Cu,
                                                 &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_Noise::DICommand_Noise(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PaletteMap>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_PaletteMap *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_PaletteMap *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_PaletteMap *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                      this->pQueue.pObject,
                                                      0x2Cu,
                                                      &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PerlinNoise>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_PerlinNoise *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_PerlinNoise *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_PerlinNoise *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                       this->pQueue.pObject,
                                                       0xA8u,
                                                       &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PixelDissolve>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_PixelDissolve *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_PixelDissolve *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_PixelDissolve *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                         this->pQueue.pObject,
                                                         0x34u,
                                                         &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_PixelDissolve::DICommand_PixelDissolve(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Scroll>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_Scroll *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_SourceRect *v5; // eax
  _DWORD *v6; // esi
  Scaleform::Render::DICommandQueue *v7; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_SourceRect *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                      this->pQueue.pObject,
                                                      0x2Cu,
                                                      &this->pQueue.pObject->QueueLock);
    v6 = &v5->__vftable;
    if ( v5 )
    {
      Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(v5, cmd);
      *v6 = &Scaleform::Render::DICommand_Scroll::`vftable';
      v6[9] = cmd->X;
      v6[10] = cmd->Y;
    }
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v7 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v7);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v7->ExecuteCmd.pObject);
      v7->pRTCommandQueue->PushThreadCommand(v7->pRTCommandQueue, v7->ExecuteCmd.pObject);
      p_ExecuteDone = &v7->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixel32>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_SetPixel32 *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_SetPixel32 *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_SetPixel32 *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                      this->pQueue.pObject,
                                                      0x18u,
                                                      &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_SetPixel32::DICommand_SetPixel32(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixels>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_SetPixels *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommand_SetPixels *v5; // eax
  Scaleform::Render::DICommandQueue *v6; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    v5 = (Scaleform::Render::DICommand_SetPixels *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                     this->pQueue.pObject,
                                                     0x20u,
                                                     &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_SetPixels::DICommand_SetPixels(v5, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v6->ExecuteCmd.pObject);
      v6->pRTCommandQueue->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      p_ExecuteDone = &v6->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}


void __thiscall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Threshold>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_Threshold *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pControlContext; // eax
  Scaleform::Render::DICommandQueue *v5; // esi
  Scaleform::Event *p_ExecuteDone; // esi
  Scaleform::Render::DISourceImages sources; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pContext.pObject;
  if ( pObject )
  {
    pControlContext = pObject->pControlContext;
    if ( pControlContext )
      pControlContext->DIChangesRequired = 1;
  }
  sources.pImages[0] = 0;
  sources.pImages[1] = 0;
  if ( !cmd->GetSourceImages(cmd, &sources)
    || (!sources.pImages[0]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[0]))
    && (!sources.pImages[1]
     || Scaleform::Render::DrawableImage::mergeQueueWith(this, (Scaleform::Render::DrawableImage *)sources.pImages[1])) )
  {
    Scaleform::Render::DICommandQueue::AddCommand_NTS<Scaleform::Render::DICommand_Threshold>(this->pQueue.pObject, cmd);
    if ( (cmd->GetRenderCaps(cmd) & 0x10) != 0 )
    {
      v5 = this->pQueue.pObject;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5);
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5->ExecuteCmd.pObject);
      v5->pRTCommandQueue->PushThreadCommand(v5->pRTCommandQueue, v5->ExecuteCmd.pObject);
      p_ExecuteDone = &v5->ExecuteCmd.pObject->ExecuteDone;
      Scaleform::Event::Wait(p_ExecuteDone, 0xFFFFFFFF);
      Scaleform::Event::ResetEvent(p_ExecuteDone);
    }
  }
}
