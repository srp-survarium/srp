void __thiscall Scaleform::Render::PrimitiveBatch::RemoveAndFree(Scaleform::Render::PrimitiveBatch *this)
{
  this->pPrev->pNext = this->pNext;
  this->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$B6E31D4B7F8069B2127C6EE45BDFC5DE::pPrev = this->pPrev;
  if ( this->MeshNode.pMeshItem )
  {
    this->MeshNode.pPrev->pNext = this->MeshNode.pNext;
    this->MeshNode.pNext->pPrev = this->MeshNode.pPrev;
    this->MeshNode.pMeshItem = 0;
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
}
