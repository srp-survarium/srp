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
