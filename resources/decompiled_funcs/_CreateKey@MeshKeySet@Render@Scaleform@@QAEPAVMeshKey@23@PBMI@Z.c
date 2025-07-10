Scaleform::Render::MeshKey *__thiscall Scaleform::Render::MeshKeySet::CreateKey(
        Scaleform::Render::MeshKeySet *this,
        float *keyData,
        unsigned __int16 flags)
{
  int v4; // eax
  int v5; // edi
  Scaleform::Render::MeshKey *result; // eax
  Scaleform::Render::MeshKey *v7; // esi
  Scaleform::Render::MeshKey *pPrev; // ecx

  v4 = 3;
  if ( (flags & 0x10) != 0 )
    v4 = 13;
  v5 = v4 + 1;
  result = (Scaleform::Render::MeshKey *)this->pManager.pObject->pRenderHeap->Alloc(
                                           this->pManager.pObject->pRenderHeap,
                                           4 * (v4 + 1) + 24,
                                           0);
  v7 = result;
  if ( result )
  {
    result->pKeySet = 0;
    result->pMesh.pObject = 0;
    result->UseCount = 1;
    result->Flags = flags;
    result->pKeySet = this;
    result->Size = v5;
    memcpy((unsigned __int8 *)result->Data, (unsigned __int8 *)keyData, 4 * v5);
    pPrev = this->Meshes.Root.pPrev;
    v7->pNext = (Scaleform::Render::MeshKey *)&this->Meshes;
    v7->pPrev = pPrev;
    this->Meshes.Root.pPrev->pNext = v7;
    this->Meshes.Root.pPrev = v7;
    return v7;
  }
  return result;
}
