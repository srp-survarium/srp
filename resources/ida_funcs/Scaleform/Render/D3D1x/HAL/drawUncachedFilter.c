void __thiscall Scaleform::Render::D3D1x::HAL::drawUncachedFilter(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::HAL::FilterStackEntry *e)
{
  const Scaleform::Render::HAL::FilterStackEntry *v2; // esi
  Scaleform::Render::FilterPrimitive *pObject; // eax
  Scaleform::Render::RenderTarget *v5; // eax
  int v6; // edx
  Scaleform::Render::RenderTarget *v7; // eax
  unsigned int FilterPasses; // esi
  int v9; // eax
  Scaleform::Render::RenderTarget *v10; // eax
  Scaleform::Render::RenderTarget *v11; // esi
  Scaleform::Render::RenderTarget *v12; // ecx
  ID3D11DeviceContext *pDeviceContext; // eax
  ID3D11DeviceContext *v14; // eax
  _DWORD *v15; // eax
  int v16; // edx
  int v17; // esi
  int v18; // esi
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  int v23; // esi
  int v24; // eax
  void (__thiscall *updateViewport)(struct Scaleform::Render::D3D1x::HAL *); // eax
  Scaleform::Render::RenderTarget *v26; // esi
  Scaleform::Render::RenderTarget *v27; // ecx
  int v28; // eax
  Scaleform::Render::RenderTarget *v29; // esi
  Scaleform::Render::FilterPrimitive *v30; // esi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  const Scaleform::Render::Cxform *v32; // eax
  Scaleform::Render::BlendMode v33; // eax
  Scaleform::Render::BlendMode v34; // eax
  unsigned int i; // esi
  int v36; // ecx
  unsigned int *v37; // esi
  int j; // edi
  int v39; // ecx
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *FillFlags; // [esp+252Eh] [ebp-294h]
  Scaleform::Render::D3D1x::ShaderInterface *v41; // [esp+2532h] [ebp-290h]
  char v42; // [esp+2541h] [ebp-281h]
  __int64 __t; // [esp+2542h] [ebp-280h] BYREF
  int v44; // [esp+254Ah] [ebp-278h]
  unsigned int v45; // [esp+254Eh] [ebp-274h] BYREF
  unsigned int *v46; // [esp+2552h] [ebp-270h]
  unsigned int v47; // [esp+2556h] [ebp-26Ch]
  Scaleform::Render::Cxform *v48; // [esp+255Ah] [ebp-268h]
  Scaleform::Render::RenderTarget *results; // [esp+255Eh] [ebp-264h] BYREF
  int v50; // [esp+2562h] [ebp-260h]
  unsigned int Size; // [esp+2566h] [ebp-25Ch]
  Scaleform::Render::FilterSet *v52; // [esp+256Ah] [ebp-258h]
  ID3D11Buffer *v53; // [esp+256Eh] [ebp-254h] BYREF
  _DWORD v54[2]; // [esp+2572h] [ebp-250h] BYREF
  ID3D11ShaderResourceView *views[2]; // [esp+257Ah] [ebp-248h] BYREF
  Scaleform::Render::Matrix2x4<float> v56; // [esp+2582h] [ebp-240h] BYREF
  __int64 v57; // [esp+25A6h] [ebp-21Ch]
  __int64 v58; // [esp+25AEh] [ebp-214h]
  __int64 v59; // [esp+25B6h] [ebp-20Ch]
  __int64 v60; // [esp+25BEh] [ebp-204h]
  __int64 v61; // [esp+25C6h] [ebp-1FCh]
  __int128 v62; // [esp+25D2h] [ebp-1F0h] BYREF
  Scaleform::Ptr<Scaleform::Render::RenderTarget> targets; // [esp+25E2h] [ebp-1E0h] BYREF

  v2 = e;
  pObject = e->pPrimitive.pObject;
  v52 = e->pPrimitive.pObject->pFilters.pObject;
  Size = v52->Filters.Data.Size;
  v48 = 0;
  v46 = 0;
  v45 = 0;
  if ( pObject && e->pRenderTarget.pObject )
  {
    *(_QWORD *)views = 0;
    `vector constructor iterator'(
      (char *)&__t,
      4u,
      3,
      (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
    v5 = e->pRenderTarget.pObject;
    v44 = 0;
    __t = 0;
    v6 = v5->ViewRect.x2 - v5->ViewRect.x1;
    v54[1] = v5->ViewRect.y2 - v5->ViewRect.y1;
    v54[0] = v6;
    if ( v5 )
      v5->AddRef(v5);
    if ( (_DWORD)__t )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)__t + 8))(__t);
    v7 = e->pRenderTarget.pObject;
    v53 = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
    LODWORD(__t) = v7;
    this->pDeviceContext->IASetVertexBuffers(
      this->pDeviceContext,
      0,
      1u,
      &v53,
      &stride,
      (const unsigned int *)&FLOAT_0_0);
    Scaleform::Render::HAL::applyBlendMode(this, Blend_Overlay, 1, 0);
    v47 = 0;
    if ( Size )
    {
      do
      {
        FillFlags = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)this->FillFlags;
        v48 = (Scaleform::Render::Cxform *)v52->Filters.Data.Data[v47].pObject;
        FilterPasses = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
                         (const Scaleform::Render::Filter *)v48,
                         (unsigned int *)&targets,
                         FillFlags,
                         (unsigned int)v41);
        v9 = LODWORD(v48->M[0][2]);
        v45 = FilterPasses;
        v42 = 0;
        if ( v9 >= 1 && v9 <= 5 )
        {
          if ( (_DWORD)__t )
            (*(void (__thiscall **)(_DWORD))(*(_DWORD *)__t + 4))(__t);
          if ( v44 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v44 + 8))(v44);
          v44 = __t;
          v42 = 1;
        }
        v46 = 0;
        if ( FilterPasses )
        {
          v10 = (Scaleform::Render::RenderTarget *)HIDWORD(__t);
          while ( v46 != (unsigned int *)(FilterPasses - 1) || v47 != Size - 1 )
          {
            if ( !v10 )
            {
              v11 = this->CreateTempRenderTarget(this, v54, 0);
              if ( HIDWORD(__t) )
                (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(__t) + 8))(HIDWORD(__t));
              v10 = v11;
              HIDWORD(__t) = v11;
            }
            v12 = (Scaleform::Render::RenderTarget *)v10->pRenderTargetData[1].__vftable;
            pDeviceContext = this->pDeviceContext;
            results = v12;
            pDeviceContext->OMSetRenderTargets(pDeviceContext, 1u, (ID3D11RenderTargetView *const *)&results, 0);
            v14 = this->pDeviceContext;
            ++this->AccumulatedStats.RTChanges;
            v62 = 0;
            v14->ClearRenderTargetView(v14, (ID3D11RenderTargetView *)results, (const float *)&v62);
            v15 = (_DWORD *)HIDWORD(__t);
            v16 = *(_DWORD *)(HIDWORD(__t) + 24);
            v17 = *(_DWORD *)(HIDWORD(__t) + 36);
            LODWORD(v57) = *(_DWORD *)(HIDWORD(__t) + 20);
            v18 = v17 - *(_DWORD *)(HIDWORD(__t) + 28);
            LODWORD(v58) = *(_DWORD *)(HIDWORD(__t) + 28);
            v19 = *(_DWORD *)(HIDWORD(__t) + 40);
            HIDWORD(v57) = v16;
            v20 = *(_DWORD *)(HIDWORD(__t) + 32);
            *(_QWORD *)&this->VP.BufferWidth = v57;
            HIDWORD(v58) = v20;
            *(_QWORD *)&this->VP.Left = v58;
            HIDWORD(v59) = v19 - v20;
            LODWORD(v59) = v18;
            *(_QWORD *)&this->VP.Width = v59;
            v60 = 0;
            *(_QWORD *)&this->VP.ScissorLeft = 0;
            v61 = 0;
            *(_QWORD *)&this->VP.ScissorWidth = 0;
            this->VP.Flags = 0;
            v21 = v15[7];
            v22 = v15[8];
            v23 = v15[9];
            v24 = v15[10];
            this->ViewRect.x1 = v21;
            this->ViewRect.y2 = v24;
            this->ViewRect.y1 = v22;
            this->ViewRect.x2 = v23;
            updateViewport = this->updateViewport;
            this->HALState |= 0x20u;
            updateViewport(this);
            *(_QWORD *)&v56.M[0][0] = LODWORD(retry_to_increase_quality_period_sec);
            *(_QWORD *)&v56.M[0][2] = 0xBF80000000000000uLL;
            v56.M[1][0] = 0.0;
            *(_QWORD *)&v56.M[1][1] = 3221225472LL;
            LODWORD(v56.M[1][3]) = clear_value;
            Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
              this->MappedXY16iAlphaTexture[0],
              (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v56,
              &Scaleform::Render::Cxform::Identity,
              (const Scaleform::Render::Filter *)v48,
              (Scaleform::Ptr<Scaleform::Render::RenderTarget> *)&__t,
              &targets,
              (unsigned int)v46,
              v45,
              &this->ShaderData,
              v41);
            this->drawPrimitive(this, 6u, 1u);
            Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, this->pTextureManager.pObject, 0, views, 0);
            if ( !v42 || v46 )
            {
              v27 = (Scaleform::Render::RenderTarget *)__t;
            }
            else
            {
              v26 = this->CreateTempRenderTarget(this, v54, 0);
              if ( (_DWORD)__t )
                (*(void (__thiscall **)(_DWORD))(*(_DWORD *)__t + 8))(__t);
              v27 = v26;
              LODWORD(__t) = v26;
            }
            if ( v27 )
            {
              v27->AddRef(v27);
              v27 = (Scaleform::Render::RenderTarget *)__t;
            }
            v28 = HIDWORD(__t);
            v29 = v27;
            if ( HIDWORD(__t) )
            {
              (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(__t) + 4))(HIDWORD(__t));
              v28 = HIDWORD(__t);
              v27 = (Scaleform::Render::RenderTarget *)__t;
            }
            if ( v27 )
            {
              v27->Release(v27);
              v28 = HIDWORD(__t);
            }
            LODWORD(__t) = v28;
            if ( v29 )
            {
              v29->AddRef(v29);
              v28 = HIDWORD(__t);
            }
            if ( v28 )
              (*(void (__thiscall **)(int))(*(_DWORD *)v28 + 8))(v28);
            v10 = v29;
            HIDWORD(__t) = v29;
            if ( v29 )
            {
              v29->Release(v29);
              v10 = (Scaleform::Render::RenderTarget *)HIDWORD(__t);
            }
            v46 = (unsigned int *)((char *)v46 + 1);
            if ( (unsigned int)v46 >= v45 )
              break;
            FilterPasses = v45;
          }
        }
        ++v47;
      }
      while ( v47 < Size );
      v2 = e;
    }
    if ( (_DWORD)__t )
    {
      results = (Scaleform::Render::RenderTarget *)__t;
      v50 = v44;
      Scaleform::Render::FilterPrimitive::SetCacheResults(
        v2->pPrimitive.pObject,
        (Scaleform::Render::FilterPrimitive::CacheState)((v45 == 0) + 1),
        &results,
        (v45 != 0) + 1);
      results->pRenderTargetData->CacheID = (unsigned int)v2->pPrimitive.pObject;
      if ( v50 )
        *(_DWORD *)(*(_DWORD *)(v50 + 16) + 12) = v2->pPrimitive.pObject;
    }
    else
    {
      Scaleform::Render::FilterPrimitive::SetCacheResults(v2->pPrimitive.pObject, Cache_Mesh, 0, 0);
    }
    this->PopRenderTarget(this, 0);
    if ( this->MaskStackTop )
    {
      if ( this->StencilAvailable )
      {
        this->pDeviceContext->OMSetDepthStencilState(
          this->pDeviceContext,
          this->DepthStencilStates[5],
          this->MaskStackTop);
      }
      else if ( this->DepthBufferAvailable )
      {
        this->pDeviceContext->OMSetDepthStencilState(
          this->pDeviceContext,
          this->DepthStencilStates[6],
          this->MaskStackTop);
      }
    }
    if ( v45 )
    {
      v30 = v2->pPrimitive.pObject;
      Scaleform::Render::operator*(
        &v56,
        &this->Matrices.pObject->UserView,
        (const Scaleform::Render::Matrix2x4<float> *)(&v30->FilterArea.pHandle->pHeader[1].RefCount
                                                    + 4
                                                    * (unsigned __int8)byte_9B2B74[5
                                                                                 * (v30->FilterArea.pHandle->pHeader->Format
                                                                                  & 0xF)]));
      pHandle = v30->FilterArea.pHandle;
      if ( (pHandle->pHeader->Format & 1) != 0 )
        v32 = (const Scaleform::Render::Cxform *)(&pHandle->pHeader[1].RefCount
                                                + 4
                                                * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHandle->pHeader->Format & 0xF].Offsets[0]);
      else
        v32 = &Scaleform::Render::Cxform::Identity;
      Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
        this->MappedXY16iAlphaTexture[0],
        (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v56,
        v32,
        (const Scaleform::Render::Filter *)v48,
        (Scaleform::Ptr<Scaleform::Render::RenderTarget> *)&__t,
        &targets,
        (unsigned int)v46,
        v45,
        &this->ShaderData,
        v41);
      if ( this->BlendModeStack.Data.Size )
        v33 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
      else
        v33 = Blend_Normal;
      Scaleform::Render::HAL::applyBlendMode(this, v33, 1, 0);
      this->drawPrimitive(this, 6u, 1u);
      if ( this->BlendModeStack.Data.Size )
        v34 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
      else
        v34 = Blend_Normal;
      Scaleform::Render::HAL::applyBlendMode(this, v34, 0, 0);
      Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, this->pTextureManager.pObject, 0, views, 0);
    }
    else
    {
      this->drawCachedFilter(this, v2->pPrimitive.pObject);
    }
    for ( i = 0; i < 3; ++i )
    {
      v36 = *((_DWORD *)&__t + i);
      if ( v36 )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v36 + 20))(v36, 0);
    }
    this->AccumulatedStats.Filters += v52->Filters.Data.Size;
    v37 = &v45;
    for ( j = 2; j >= 0; --j )
    {
      v39 = *--v37;
      if ( v39 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v39 + 8))(v39);
    }
  }
}
