void __thiscall Scaleform::Render::ImageDelegate::SetMatrix(
        Scaleform::Render::ImageDelegate *this,
        const Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::MemoryHeap *heap)
{
  this->pImage.pObject->SetMatrix(this->pImage.pObject, mat, heap);
}
