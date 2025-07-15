Scaleform::Render::MeshKey *__thiscall Scaleform::Render::MeshKeySet::findMatchingKey(
        Scaleform::Render::MeshKeySet *this,
        unsigned int layer,
        unsigned int flags,
        const float *keyData,
        const Scaleform::Render::ToleranceParams *cfg)
{
  Scaleform::Render::MeshKeySet *pNext; // ecx
  const char *pObject; // eax
  const char *pPrev; // esi
  int v10; // ecx
  Scaleform::List<Scaleform::Render::MeshKey,Scaleform::Render::MeshKey> *p_Meshes; // [esp+10h] [ebp-4h]

  pNext = (Scaleform::Render::MeshKeySet *)this->Meshes.Root.pNext;
  p_Meshes = &this->Meshes;
  if ( pNext == (Scaleform::Render::MeshKeySet *)&this->Meshes )
    return 0;
  while ( 1 )
  {
    pObject = (const char *)pNext->pManager.pObject;
    _mm_prefetch(pObject + 96, 2);
    _mm_prefetch(pObject + 64, 2);
    _mm_prefetch(pObject + 32, 2);
    _mm_prefetch(pObject, 2);
    pPrev = (const char *)pNext->pPrev;
    _mm_prefetch(pPrev, 2);
    if ( Scaleform::Render::MeshKey::Match((Scaleform::Render::MeshKey *)pNext, layer, flags, keyData, cfg) )
      break;
    pNext = (Scaleform::Render::MeshKeySet *)pPrev;
    if ( pPrev == (const char *)p_Meshes )
      return 0;
  }
  return (Scaleform::Render::MeshKey *)v10;
}
