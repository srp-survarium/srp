void __thiscall Scaleform::GFx::AMP::Server::CollectRendererData(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile)
{
  Scaleform::Render::Renderer2D *CurrentRenderer; // ecx
  Scaleform::Render::HAL *HAL; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  Scaleform::Render::Renderer2D *v9; // edx
  _DWORD *v10; // ebx
  unsigned int *v11; // eax
  unsigned int v12; // eax
  Scaleform::Render::GlyphCache *pObject; // ecx
  Scaleform::Render::GlyphQueue *v14; // ebx
  unsigned int v15; // eax
  unsigned int FontTotalArea; // ecx
  Scaleform::Render::HAL *v17; // eax
  Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor> >::TableType *pTable; // eax
  unsigned int EntryCount; // eax
  int v20; // [esp+10h] [ebp-18h] BYREF
  int v21; // [esp+14h] [ebp-14h]
  int v22; // [esp+18h] [ebp-10h]
  int v23; // [esp+1Ch] [ebp-Ch]
  int v24; // [esp+20h] [ebp-8h]
  int v25; // [esp+24h] [ebp-4h]

  Scaleform::GFx::AMP::Server::RenderProfile::CollectStats(this->RenderStats.pObject, frameProfile);
  CurrentRenderer = this->CurrentRenderer;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  HAL = Scaleform::Render::Renderer2D::GetHAL(CurrentRenderer);
  HAL->GetStats(HAL, (Scaleform::Render::HAL::Stats *)&v20, 0);
  v5 = v21;
  frameProfile->TriangleCount += v22;
  v6 = v25;
  frameProfile->MeshCount += v5;
  v7 = v20;
  v8 = v23;
  frameProfile->FilterCount += v6;
  frameProfile->DrawPrimitiveCount += v7;
  frameProfile->MaskCount += v8;
  Scaleform::GFx::AMP::Server::CollectMeshCacheStats(this, frameProfile);
  v9 = this->CurrentRenderer;
  v10 = &v9->pImpl->pGlyphCache.pObject->__vftable;
  v11 = (unsigned int *)v10[708];
  if ( v11 )
    v12 = *v11;
  else
    v12 = 0;
  pObject = v9->pImpl->pGlyphCache.pObject;
  frameProfile->RasterizedGlyphCount = v12;
  frameProfile->FontTextureCount = Scaleform::Render::GlyphCache::GetNumTextures(pObject);
  frameProfile->FontTotalArea = v10[22] * v10[23] * v10[24];
  v14 = (Scaleform::Render::GlyphQueue *)(v10 + 670);
  v15 = Scaleform::Render::GlyphQueue::ComputeUsedArea(v14);
  FontTotalArea = frameProfile->FontTotalArea;
  frameProfile->FontUsedArea = v15;
  if ( FontTotalArea )
    frameProfile->FontFill = 100 * v15 / FontTotalArea;
  frameProfile->FontCacheMemory = Scaleform::Render::GlyphQueue::GetBytes(v14);
  frameProfile->FontFail = this->FontFailures.Value;
  frameProfile->FontThrashing = this->FontThrashing.Value;
  v17 = Scaleform::Render::Renderer2D::GetHAL(this->CurrentRenderer);
  frameProfile->MeshThrashing = v17->GetMeshCache(v17)->Thrashing;
  pTable = this->CurrentRenderer->pImpl->FillManager.Gradients.pTable;
  if ( pTable )
    EntryCount = pTable->EntryCount;
  else
    EntryCount = 0;
  frameProfile->GradientFillCount = EntryCount;
  frameProfile->StrokeCount = this->NumStrokes.Value;
  Scaleform::GFx::AMP::Server::ClearRendererData(this);
}
