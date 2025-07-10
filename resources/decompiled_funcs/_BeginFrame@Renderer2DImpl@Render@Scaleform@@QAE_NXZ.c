int __thiscall Scaleform::Render::Renderer2DImpl::BeginFrame(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::Render::GlyphCache *pObject; // ecx

  Scaleform::Render::MeshKeyManager::ProcessKillList(this->pMeshKeyManager.pObject);
  pObject = this->pGlyphCache.pObject;
  if ( pObject )
    Scaleform::Render::GlyphCache::OnBeginFrame(pObject);
  return ((int (__thiscall *)(Scaleform::Render::HAL *))this->pHal.pObject->BeginFrame)(this->pHal.pObject);
}
