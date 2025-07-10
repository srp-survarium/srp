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
