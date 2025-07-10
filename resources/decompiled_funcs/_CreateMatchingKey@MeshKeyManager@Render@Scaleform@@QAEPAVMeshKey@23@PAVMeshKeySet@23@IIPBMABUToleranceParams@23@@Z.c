Scaleform::Render::MeshKey *__thiscall Scaleform::Render::MeshKeyManager::CreateMatchingKey(
        Scaleform::Render::MeshKeyManager *this,
        Scaleform::Render::MeshKeySet *keySet,
        unsigned int layer,
        unsigned int flags,
        float *keyData,
        const Scaleform::Render::ToleranceParams *cfg)
{
  Scaleform::Render::MeshKey *result; // eax

  result = Scaleform::Render::MeshKeySet::findMatchingKey(keySet, layer, flags, keyData, cfg);
  if ( !result )
    return Scaleform::Render::MeshKeySet::CreateKey(keySet, keyData, flags);
  ++result->UseCount;
  return result;
}
