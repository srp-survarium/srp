void __thiscall Scaleform::Render::ComplexPrimitiveBundle::EmitToHAL(
        Scaleform::Render::ComplexPrimitiveBundle *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  unsigned int Data; // eax
  int v4; // esi
  Scaleform::Render::ComplexMesh *v5; // edi
  unsigned int v6; // eax
  Scaleform::Render::HAL *pHAL; // ecx
  _DWORD v8[3]; // [esp+4h] [ebp-Ch] BYREF

  if ( qp->QueueEmitFilter == QPF_All )
  {
    Data = (unsigned int)item->Data;
    v4 = this->RefCount + 8 * Data;
    v5 = *(Scaleform::Render::ComplexMesh **)(v4 + 4);
    if ( item != qp->PrepareItemBuffer.pItem )
    {
      if ( v5 )
      {
        v6 = Scaleform::Render::ComplexPrimitiveBundle::countConsecutiveMeshesAtIndex(
               (Scaleform::Render::ComplexPrimitiveBundle *)((char *)this - 32),
               Data);
        pHAL = qp->pHAL;
        v8[1] = v6;
        v8[0] = v4;
        v8[2] = 8;
        pHAL->DrawProcessedComplexMeshes(
          pHAL,
          v5,
          (const Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *)v8);
      }
    }
  }
}
