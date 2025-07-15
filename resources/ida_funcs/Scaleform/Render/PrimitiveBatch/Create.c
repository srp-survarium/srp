Scaleform::Render::PrimitiveBatch *__cdecl Scaleform::Render::PrimitiveBatch::Create(
        Scaleform::Render::Primitive *p,
        Scaleform::Render::PrimitiveBatch::BatchType type,
        unsigned int meshIndex,
        unsigned int meshCount)
{
  Scaleform::Render::PrimitiveBatch *result; // eax

  result = (Scaleform::Render::PrimitiveBatch *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  p,
                                                  44,
                                                  0);
  result->Type = type;
  result->pPrimitive = p;
  result->MeshNode.pMeshItem = 0;
  result->pFormat = 0;
  result->LargeMesh = 0;
  result->MeshCount = meshCount;
  result->MeshIndex = meshIndex;
  return result;
}
