void __thiscall Scaleform::Render::Primitive::SetMesh(
        Scaleform::Render::Primitive *this,
        unsigned int index,
        Scaleform::GFx::Resource *pmesh)
{
  Scaleform::RefCountVImpl **p_pMesh; // esi
  Scaleform::Render::PrimitiveBatch *pNext; // eax
  int v6; // ecx

  p_pMesh = (Scaleform::RefCountVImpl **)&this->Meshes.Data.Data[index].pMesh;
  if ( *p_pMesh != (Scaleform::RefCountVImpl *)pmesh )
  {
    if ( pmesh )
      Scaleform::RefCountImpl::AddRef(pmesh);
    if ( *p_pMesh )
      Scaleform::RefCountImpl::Release(*p_pMesh);
    *p_pMesh = (Scaleform::RefCountVImpl *)pmesh;
    pNext = this->Batches.Root.pNext;
    v6 = 0;
    if ( index >= pNext->MeshCount )
    {
      do
      {
        v6 += pNext->MeshCount;
        pNext = pNext->pNext;
      }
      while ( index >= v6 + pNext->MeshCount );
    }
    pNext->Type = DP_Virtual;
    if ( pNext->MeshNode.pMeshItem )
    {
      pNext->MeshNode.pPrev->pNext = pNext->MeshNode.pNext;
      pNext->MeshNode.pNext->pPrev = pNext->MeshNode.pPrev;
      pNext->MeshNode.pMeshItem = 0;
    }
  }
}
