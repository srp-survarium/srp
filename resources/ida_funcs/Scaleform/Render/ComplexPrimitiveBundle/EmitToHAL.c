void __thiscall Scaleform::Render::ComplexPrimitiveBundle::EmitToHAL(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  unsigned int Data; // eax
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // esi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // edi
  unsigned int v6; // eax
  Scaleform::Render::HAL *pHAL; // ecx
  Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> matrices; // [esp+4h] [ebp-Ch] BYREF

  if ( qp->QueueEmitFilter == QPF_All )
  {
    Data = (unsigned int)item->Data;
    v4 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)(this->RefCount + 8 * Data);
    pHandle = v4[1].pHandle;
    if ( item != qp->PrepareItemBuffer.pItem )
    {
      if ( pHandle )
      {
        v6 = Scaleform::Render::ComplexPrimitiveBundle::countConsecutiveMeshesAtIndex(
               (Scaleform::Render::ComplexPrimitiveBundle *)((char *)this - 32),
               Data);
        pHAL = qp->pHAL;
        matrices.Size = v6;
        matrices.pData = v4;
        matrices.StrideSize = 8;
        pHAL->DrawProcessedComplexMeshes(pHAL, (Scaleform::Render::ComplexMesh *)pHandle, &matrices);
      }
    }
  }
}
