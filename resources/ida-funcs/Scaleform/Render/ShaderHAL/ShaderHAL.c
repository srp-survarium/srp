void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::HAL *commandQueue,
        Scaleform::Render::ThreadCommandQueue *commandQueuea)
{
  Scaleform::Render::HAL::HAL(commandQueue, commandQueuea);
  commandQueue->__vftable = (Scaleform::Render::HAL_vtbl *)&Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::`vftable';
  commandQueue[1].__vftable = 0;
  commandQueue[1].RefCount = 0;
  commandQueue[1].HALState = 0;
  commandQueue[1].CurrentPass = 0;
  commandQueue[1].NotifyList.Root.pPrev = 0;
  Scaleform::Render::D3D1x::ShaderManager::ShaderManager(
    (Scaleform::Render::D3D1x::ShaderManager *)&commandQueue[1].NotifyList.Root.4,
    &commandQueue->Profiler);
  commandQueue[102].pHeap = 0;
  commandQueue[102].pRTCommandQueue = 0;
  commandQueue[102].Queue.QueueSize = 0;
  commandQueue[102].Queue.pQueue = 0;
  commandQueue[102].AccumulatedStats.Filters = 0;
  commandQueue[102].VMCFlags = 0;
  commandQueue[102].FillFlags = 0;
  LOWORD(commandQueue[102].RenderThreadID) = 0;
  BYTE2(commandQueue[102].RenderThreadID) = 0;
  commandQueue[102].Queue.QueueHead = (unsigned int)commandQueue;
  commandQueue[102].Queue.QueueTail = 0;
  *(_DWORD *)&commandQueue[102].Queue.HeadReserved = 0;
  commandQueue[102].pRenderBufferManager.pObject = 0;
  commandQueue[102].QueueProcessor.pHAL = 0;
  commandQueue[102].QueueProcessor.Caches.pCaches[0] = 0;
  commandQueue[102].QueueProcessor.Caches.pCaches[1] = 0;
  commandQueue[102].QueueProcessor.Caches.LockFlags = 0;
  commandQueue[102].QueueProcessor.Queue = 0;
  commandQueue[102].QueueProcessor.QueueMode = QM_WaitForFences;
  commandQueue[102].QueueProcessor.QueuePrepareFilter = QPF_All;
  commandQueue[102].QueueProcessor.QueueEmitFilter = QPF_All;
  commandQueue[102].QueueProcessor.CurrentItem.pQueue = 0;
  commandQueue[102].QueueProcessor.CurrentItem.QueuePos = 0;
  commandQueue[102].QueueProcessor.PrepareItemBuffer.pItem = 0;
}
