void __thiscall Scaleform::Render::MeshBase::MeshBase(
        Scaleform::Render::MeshBase *this,
        Scaleform::Render::Renderer2DImpl *prenderer,
        Scaleform::Render::MeshProvider *provider,
        const Scaleform::Render::Matrix2x4<float> *viewMatrix,
        float morphRatio,
        unsigned int layer,
        unsigned int meshGenFlags)
{
  double v8; // st7

  this->Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,70>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::MeshBase_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::MeshStagingNode::`vftable';
  this->StagingBufferSize = 0;
  this->StagingBufferOffset = 0;
  this->StagingBufferIndexOffset = 0;
  this->PinCount = 0;
  this->VertexCount = 0;
  this->IndexCount = 0;
  this->Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,70>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::MeshBase_vtbl *)&Scaleform::Render::MeshBase::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>'};
  this->Scaleform::Render::MeshStagingNode::__vftable = (Scaleform::Render::MeshStagingNode_vtbl *)&Scaleform::Render::MeshBase::`vftable'{for `Scaleform::Render::MeshStagingNode'};
  this->pRenderer2D = prenderer;
  if ( provider )
    provider->AddRef(provider);
  this->ViewMatrix.M[0][0] = viewMatrix->M[0][0];
  v8 = viewMatrix->M[0][1];
  this->pProvider.pObject = provider;
  this->ViewMatrix.M[0][1] = v8;
  this->pScale9Grid.pObject = 0;
  this->ViewMatrix.M[0][2] = viewMatrix->M[0][2];
  this->ViewMatrix.M[0][3] = viewMatrix->M[0][3];
  this->ViewMatrix.M[1][0] = viewMatrix->M[1][0];
  this->ViewMatrix.M[1][1] = viewMatrix->M[1][1];
  this->ViewMatrix.M[1][2] = viewMatrix->M[1][2];
  this->ViewMatrix.M[1][3] = viewMatrix->M[1][3];
  this->Layer = layer;
  this->MGFlags = meshGenFlags;
  this->MorphRatio = morphRatio;
}
