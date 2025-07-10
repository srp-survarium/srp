void __thiscall Scaleform::Render::PrimitiveBatch::RemoveAndFree(Scaleform::Render::PrimitiveBatch *this)
{
  this->pPrev->pNext = this->pNext;
  this->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$C512BB809886916B7F681A9EBDF58E11::pPrev = this->pPrev;
  if ( this->MeshNode.pMeshItem )
  {
    this->MeshNode.pPrev->pNext = this->MeshNode.pNext;
    this->MeshNode.pNext->pPrev = this->MeshNode.pPrev;
    this->MeshNode.pMeshItem = 0;
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
}
