void __thiscall Scaleform::Render::Image::SetMatrixInverse(
        Scaleform::Render::Image *this,
        const Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v4; // eax

  if ( !this->pInverseMatrix )
  {
    v4 = heap;
    if ( !heap )
      v4 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    this->pInverseMatrix = (Scaleform::Render::Matrix2x4<float> *)v4->Alloc(v4, 32u, 16u, 0);
  }
  *this->pInverseMatrix = *mat;
}
