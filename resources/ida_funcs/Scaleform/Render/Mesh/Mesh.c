void __thiscall Scaleform::Render::Mesh::Mesh(
        Scaleform::Render::Mesh *this,
        Scaleform::Render::Renderer2DImpl *prenderer,
        Scaleform::Render::MeshProvider *provider,
        const Scaleform::Render::Matrix2x4<float> *viewMatrix,
        float morphRatio,
        unsigned int layer,
        unsigned int meshGenFlags)
{
  Scaleform::Render::MeshBase::MeshBase(this, prenderer, provider, viewMatrix, morphRatio, layer, meshGenFlags);
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,70>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::Mesh_vtbl *)&Scaleform::Render::Mesh::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>'};
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::Mesh::`vftable'{for `Scaleform::Render::MeshStagingNode'};
  this->CacheItems.Size = 0;
  this->VertexMatrix.M[0][0] = 1.0;
  this->VertexMatrix.M[0][1] = 0.0;
  this->VertexMatrix.M[0][2] = 0.0;
  this->VertexMatrix.M[0][3] = 0.0;
  this->VertexMatrix.M[1][0] = 0.0;
  this->VertexMatrix.M[1][2] = 0.0;
  this->VertexMatrix.M[1][3] = 0.0;
  this->VertexMatrix.M[1][1] = 1.0;
  this->LargeMesh = 0;
}
