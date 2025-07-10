void __thiscall Scaleform::Render::ComplexMeshVertexOutput::EndOutput(Scaleform::Render::ComplexMeshVertexOutput *this)
{
  this->pCache->PostUpdateMesh(this->pCache, this->pMesh->pCacheMeshItem);
}
