void __thiscall Scaleform::Render::ImageDelegate::SetMatrixInverse(
        Scaleform::Render::ImageDelegate *this,
        const Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::MemoryHeap *heap)
{
  this->pImage.pObject->SetMatrixInverse(this->pImage.pObject, mat, heap);
}
