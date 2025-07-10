void __thiscall Scaleform::Render::PrimitiveBatch::ClearCacheItem(Scaleform::Render::PrimitiveBatch *this)
{
  if ( this->MeshNode.pMeshItem )
  {
    this->MeshNode.pPrev->pNext = this->MeshNode.pNext;
    this->MeshNode.pNext->pPrev = this->MeshNode.pPrev;
    this->MeshNode.pMeshItem = 0;
  }
}
