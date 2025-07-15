Scaleform::Render::Filter *__thiscall Scaleform::Render::ColorMatrixFilter::Clone(
        Scaleform::Render::ColorMatrixFilter *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // eax
  Scaleform::Render::Filter *result; // eax

  v2 = heap;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  result = (Scaleform::Render::Filter *)v2->Alloc(v2, 96u, 0);
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::Render::Filter_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  result->RefCount = 1;
  result->Type = Filter_ColorMatrix;
  result->Frozen = 0;
  result->__vftable = (Scaleform::Render::Filter_vtbl *)&Scaleform::Render::ColorMatrixFilter::`vftable';
  qmemcpy(&result[1], ColorMatrix_Identity, 0x50u);
  qmemcpy(&result[1], this->MatrixData, 0x50u);
  return result;
}
