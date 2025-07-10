void __thiscall Scaleform::Render::Renderer2DImpl::AddComplexMeshToUpdateList(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::ComplexMesh::UpdateNode *meshNode)
{
  if ( !meshNode->pPrev )
  {
    meshNode->pPrev = this->mComplexMeshUpdateList.Root.pPrev;
    meshNode->pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)&this->mComplexMeshUpdateList;
    this->mComplexMeshUpdateList.Root.pPrev->pNext = meshNode;
    this->mComplexMeshUpdateList.Root.pPrev = meshNode;
  }
}
