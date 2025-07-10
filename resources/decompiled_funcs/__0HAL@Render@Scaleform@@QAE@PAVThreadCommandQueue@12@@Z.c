void __thiscall Scaleform::Render::HAL::HAL(
        Scaleform::Render::HAL *this,
        Scaleform::Render::ThreadCommandQueue *commandQueue)
{
  Scaleform::List<Scaleform::Render::HALNotify,Scaleform::Render::HALNotify> *p_NotifyList; // eax
  Scaleform::Render::DisplayPass *p_CurrentPass; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // ecx

  p_NotifyList = &this->NotifyList;
  this->__vftable = (Scaleform::Render::HAL_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::HAL_vtbl *)&Scaleform::Render::HAL::`vftable';
  this->HALState = 0;
  this->CurrentPass = Display_All;
  if ( this == (Scaleform::Render::HAL *)-16 )
    p_CurrentPass = 0;
  else
    p_CurrentPass = &this->CurrentPass;
  p_NotifyList->Root.pPrev = (Scaleform::Render::HALNotify *)p_CurrentPass;
  p_NotifyList->Root.pNext = (Scaleform::Render::HALNotify *)p_CurrentPass;
  this->Matrices.pObject = 0;
  this->AccumulatedStats.Primitives = 0;
  this->AccumulatedStats.Meshes = 0;
  this->AccumulatedStats.Triangles = 0;
  this->AccumulatedStats.Masks = 0;
  this->AccumulatedStats.RTChanges = 0;
  this->AccumulatedStats.Filters = 0;
  this->VMCFlags = 0;
  this->FillFlags = 0;
  this->RenderThreadID = 0;
  this->pHeap = 0;
  this->pRTCommandQueue = commandQueue;
  Scaleform::Render::RenderQueue::RenderQueue(&this->Queue);
  this->pRenderBufferManager.pObject = 0;
  Scaleform::Render::RenderQueueProcessor::RenderQueueProcessor(&this->QueueProcessor, &this->Queue, this);
  this->ViewMatrix3DStack.Data.Data = 0;
  this->ViewMatrix3DStack.Data.Size = 0;
  this->ViewMatrix3DStack.Data.Policy.Capacity = 0;
  this->ProjectionMatrix3DStack.Data.Data = 0;
  this->ProjectionMatrix3DStack.Data.Size = 0;
  this->ProjectionMatrix3DStack.Data.Policy.Capacity = 0;
  this->CurrentBlendState.Mode = Blend_None;
  this->CurrentBlendState.SourceAc = 0;
  this->CurrentBlendState.ForceAc = 0;
  this->BlendModeStack.Data.Data = 0;
  this->BlendModeStack.Data.Size = 0;
  this->BlendModeStack.Data.Policy.Capacity = 0;
  this->MaskStack.Data.Data = 0;
  this->MaskStack.Data.Size = 0;
  this->MaskStack.Data.Policy.Capacity = 0;
  this->MaskStackTop = 0;
  this->RenderTargetStack.Data.Data = 0;
  this->RenderTargetStack.Data.Size = 0;
  this->RenderTargetStack.Data.Policy.Capacity = 0;
  this->FilterStack.Data.Data = 0;
  this->FilterStack.Data.Size = 0;
  this->FilterStack.Data.Policy.Capacity = 0;
  this->CachedFilterIndex = -1;
  this->CachedFilterPrepIndex = -1;
  this->BeginDisplayDataList.FirstPage = 0;
  this->BeginDisplayDataList.LastPage = 0;
  this->BeginDisplayDataList.NumElementsInPage = 127;
  this->BeginDisplayDataList.FirstEmptySlot = 0;
  this->BeginDisplayDataList.pHeapOrPtr = &this->BeginDisplayDataList;
  this->UserDataStack.Data.Data = 0;
  this->UserDataStack.Data.Size = 0;
  this->UserDataStack.Data.Policy.Capacity = 0;
  this->VP.BufferWidth = 0;
  this->VP.BufferHeight = 0;
  this->VP.Top = 0;
  this->VP.Left = 0;
  this->VP.Height = 1;
  this->VP.Width = 1;
  this->VP.ScissorHeight = 0;
  this->VP.ScissorWidth = 0;
  this->VP.ScissorTop = 0;
  this->VP.ScissorLeft = 0;
  this->VP.Flags = 0;
  this->ViewRect.x1 = 0;
  this->ViewRect.y1 = 0;
  this->ViewRect.x2 = 0;
  this->ViewRect.y2 = 0;
  LODWORD(this->NextProfileMode) = 0;
  HIDWORD(this->NextProfileMode) = 0;
  v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)Scaleform::Memory::pGlobalHeap;
  this->pHeap = Scaleform::Memory::pGlobalHeap;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v5);
}
