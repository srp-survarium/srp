void __thiscall Scaleform::Render::Renderer2DImpl::OnHALEvent(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::HALNotifyType type)
{
  switch ( type )
  {
    case HAL_Initialize:
    case HAL_RestoreAfterReset:
      Scaleform::Render::GlyphCache::Initialize(
        (Scaleform::Render::GlyphCache *)this->MPool.HandleTable.PartiallyFreePages.Root.pNext,
        (Scaleform::Render::HAL *)this->pRTCommandQueue,
        (Scaleform::Render::PrimitiveFillManager *)&this->Tolerances.StrokeUpperScale);
      break;
    case HAL_Shutdown:
      Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData((Scaleform::Render::Renderer2DImpl *)((char *)this - 28));
      Scaleform::Render::MeshKeyManager::DestroyAllKeys((Scaleform::Render::MeshKeyManager *)this->MPool.HandleTable.PartiallyFreePages.Root.pPrev);
      goto $LN2_44;
    case HAL_PrepareForReset:
$LN2_44:
      Scaleform::Render::GlyphCache::Destroy((Scaleform::Render::GlyphCache *)this->MPool.HandleTable.PartiallyFreePages.Root.pNext);
      break;
    default:
      return;
  }
}
