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
