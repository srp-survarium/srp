void __thiscall Scaleform::Render::HAL::PrepareFilters(
        Scaleform::Render::HAL *this,
        Scaleform::Render::FilterPrimitive *prim)
{
  int v3; // esi
  int CachedFilterPrepIndex; // eax
  bool v5; // bl
  Scaleform::Render::RenderTarget *v6; // ecx
  unsigned int i; // esi
  Scaleform::Render::RenderTarget *v8; // ecx
  int v9; // eax
  Scaleform::Render::RenderTarget *results[2]; // [esp+4h] [ebp-8h] BYREF

  if ( (this->HALState & 8) == 0 )
    return;
  v3 = 0;
  if ( !prim )
    return;
  if ( prim->Caching == Cache_Mesh )
  {
    if ( prim->pFilters.pObject )
    {
      if ( this->CurrentPass == Display_Prepass )
        this->GetRQProcessor(this)->QueuePrepareFilter = QPF_All;
      CachedFilterPrepIndex = this->CachedFilterPrepIndex;
      if ( CachedFilterPrepIndex >= 0 )
        this->CachedFilterPrepIndex = CachedFilterPrepIndex + 1;
      return;
    }
    goto LABEL_27;
  }
  if ( !prim->pFilters.pObject )
  {
LABEL_27:
    v9 = this->CachedFilterPrepIndex;
    if ( v9 >= 0 )
    {
      if ( v9 || this->CurrentPass == Display_Prepass )
      {
        if ( !v9 && this->CurrentPass == Display_Prepass )
          this->GetRQProcessor(this)->QueuePrepareFilter = QPF_Filters;
        --this->CachedFilterPrepIndex;
      }
      else
      {
        this->GetRQProcessor(this)->QueuePrepareFilter = QPF_All;
        --this->CachedFilterPrepIndex;
      }
    }
    return;
  }
  Scaleform::Render::FilterPrimitive::GetCacheResults(prim, results, 2u);
  v5 = 1;
  while ( 1 )
  {
    v6 = results[v3];
    if ( !v6 )
    {
      v5 = v3 != 0;
      goto LABEL_19;
    }
    if ( v6->GetStatus(v6) == RTS_Lost
      || results[v3]->GetStatus(results[v3]) == RTS_Unresolved
      || (Scaleform::Render::FilterPrimitive *)results[v3]->pRenderTargetData->CacheID != prim )
    {
      break;
    }
    if ( (unsigned int)++v3 >= 2 )
      goto LABEL_19;
  }
  v5 = 0;
LABEL_19:
  ++this->CachedFilterPrepIndex;
  if ( v5 )
  {
    if ( !this->CachedFilterPrepIndex )
    {
      for ( i = 0; i < 2; ++i )
      {
        v8 = results[i];
        if ( v8 )
          v8->SetInUse(v8, 1);
      }
      this->GetRQProcessor(this)->QueuePrepareFilter = QPF_Filters;
    }
  }
  else
  {
    Scaleform::Render::FilterPrimitive::SetCacheResults(prim, Cache_Mesh, 0, 0);
  }
}
