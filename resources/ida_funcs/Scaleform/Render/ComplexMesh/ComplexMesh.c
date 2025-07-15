void __thiscall Scaleform::Render::ComplexMesh::ComplexMesh(
        Scaleform::Render::ComplexMesh *this,
        Scaleform::Render::Renderer2DImpl *renderer,
        Scaleform::Render::MeshProvider *meshProvider,
        Scaleform::Render::PrimitiveFillManager *fillManager,
        const Scaleform::Render::Matrix2x4<float> *viewMatrix,
        float morphRatio,
        unsigned int layer,
        unsigned int meshGenFlags)
{
  Scaleform::Render::MeshBase::MeshBase(this, renderer, meshProvider, viewMatrix, morphRatio, layer, meshGenFlags);
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,70>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::ComplexMesh_vtbl *)&Scaleform::Render::ComplexMesh::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>'};
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::ComplexMesh::`vftable'{for `Scaleform::Render::MeshStagingNode'};
  this->UpdateListNode.pPrev = 0;
  this->UpdateListNode.pNext = 0;
  this->pCacheMeshItem = 0;
  this->AllocTooBig = 0;
  this->pFillManager = fillManager;
  this->VertexMatrix.M[0][0] = 1.0;
  this->VertexMatrix.M[0][1] = 0.0;
  this->VertexMatrix.M[0][2] = 0.0;
  this->VertexMatrix.M[0][3] = 0.0;
  this->VertexMatrix.M[1][0] = 0.0;
  this->VertexMatrix.M[1][2] = 0.0;
  this->VertexMatrix.M[1][3] = 0.0;
  this->VertexMatrix.M[1][1] = 1.0;
  this->FillRecords.Data.Data = 0;
  this->FillRecords.Data.Size = 0;
  this->FillRecords.Data.Policy.Capacity = 0;
  this->FillMatrixCache.Data.Data = 0;
  this->FillMatrixCache.Data.Size = 0;
  this->FillMatrixCache.Data.Policy.Capacity = 0;
  this->GradientImages.Data.Data = 0;
  this->GradientImages.Data.Size = 0;
  this->GradientImages.Data.Policy.Capacity = 0;
}
