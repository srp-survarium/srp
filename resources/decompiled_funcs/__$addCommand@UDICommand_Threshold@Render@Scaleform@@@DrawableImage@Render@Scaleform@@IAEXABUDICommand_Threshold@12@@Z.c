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
