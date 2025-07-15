void __thiscall Scaleform::Render::D3D1x::HAL::drawUncachedFilter(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::HAL::FilterStackEntry *e)
{
  const Scaleform::Render::HAL::FilterStackEntry *v2; // esi
  Scaleform::Render::FilterPrimitive *pObject; // eax
  Scaleform::Render::RenderTarget *v5; // ecx
  int v6; // edi
  Scaleform::Render::Filter_vtbl *v7; // edi
  ID3D11DeviceContext_vtbl *v8; // ecx
  Scaleform::Render::Cxform *v9; // edi
  int FilterPasses; // eax
  int v11; // edi
  Scaleform::Render::Filter_vtbl *v12; // esi
  _DWORD *RefCount; // esi
  const void *v14; // eax
  Scaleform::Render::Filter_vtbl *v15; // edi
  int v16; // ecx
  int v17; // edx
  int v18; // esi
  Scaleform::Render::D3D1x::HAL_vtbl *v19; // eax
  Scaleform::Render::Filter_vtbl *v20; // esi
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_FilterArea; // esi
  Scaleform::Render::Cxform *Cxform; // eax
  Scaleform::Render::BlendMode v23; // esi
  Scaleform::Render::BlendMode v24; // eax
  unsigned int i; // esi
  int v26; // ecx
  bool *p_Frozen; // esi
  int j; // ebx
  ID3D11DeviceContext *pDeviceContext; // [esp+2Ch] [ebp-2D8h]
  Scaleform::Render::Cxform *v30; // [esp+2Ch] [ebp-2D8h]
  const Scaleform::Render::VertexFormat *v31; // [esp+3Ch] [ebp-2C8h]
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *FillFlags; // [esp+40h] [ebp-2C4h]
  Scaleform::Render::D3D1x::ShaderInterface *v33; // [esp+44h] [ebp-2C0h]
  char v34; // [esp+53h] [ebp-2B1h]
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *targets; // [esp+54h] [ebp-2B0h]
  unsigned int pass; // [esp+58h] [ebp-2ACh]
  Scaleform::Render::Filter filter; // [esp+5Ch] [ebp-2A8h] BYREF
  unsigned int Size; // [esp+6Ch] [ebp-298h]
  Scaleform::Render::Cxform *v39; // [esp+70h] [ebp-294h]
  Scaleform::Render::RenderTarget *results; // [esp+74h] [ebp-290h] BYREF
  Scaleform::Render::FilterType Type; // [esp+78h] [ebp-28Ch]
  Scaleform::Render::FilterSet *v42; // [esp+7Ch] [ebp-288h]
  ID3D11Buffer *v43; // [esp+80h] [ebp-284h] BYREF
  _DWORD v44[2]; // [esp+84h] [ebp-280h] BYREF
  ID3D11ShaderResourceView *views[2]; // [esp+8Ch] [ebp-278h] BYREF
  Scaleform::Render::Matrix2x4<float> m2; // [esp+94h] [ebp-270h] BYREF
  Scaleform::Render::Viewport v47; // [esp+B4h] [ebp-250h] BYREF
  int v48; // [esp+F0h] [ebp-214h]
  Scaleform::Render::Matrix2x4<float> result; // [esp+F4h] [ebp-210h] BYREF
  _BYTE v50[16]; // [esp+114h] [ebp-1F0h] BYREF
  unsigned int passes[120]; // [esp+124h] [ebp-1E0h] BYREF

  v2 = e;
  pObject = e->pPrimitive.pObject;
  v42 = e->pPrimitive.pObject->pFilters.pObject;
  Size = v42->Filters.Data.Size;
  v39 = 0;
  targets = 0;
  pass = 0;
  if ( pObject )
  {
    v5 = e->pRenderTarget.pObject;
    if ( v5 )
    {
      views[0] = 0;
      views[1] = 0;
      memset(&filter, 0, sizeof(filter));
      v6 = v5->ViewRect.x2 - v5->ViewRect.x1;
      v44[1] = v5->ViewRect.y2 - v5->ViewRect.y1;
      v44[0] = v6;
      v5->AddRef(v5);
      v7 = (Scaleform::Render::Filter_vtbl *)e->pRenderTarget.pObject;
      v43 = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
      v8 = this->pDeviceContext->lpVtbl;
      pDeviceContext = this->pDeviceContext;
      filter.__vftable = v7;
      v8->IASetVertexBuffers(pDeviceContext, 0, 1u, &v43, &stride, (const unsigned int *)&FLOAT_0_0);
      Scaleform::Render::HAL::applyBlendMode(this, 0xDu, 1, 0);
      if ( Size )
      {
        do
        {
          FillFlags = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)this->FillFlags;
          v39 = (Scaleform::Render::Cxform *)v42->Filters.Data.Data[*(_DWORD *)&filter.Frozen].pObject;
          v9 = v39;
          FilterPasses = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
                           (const Scaleform::Render::Filter *)v39,
                           passes,
                           FillFlags,
                           (unsigned int)v33);
          v11 = LODWORD(v9->M[0][2]);
          pass = FilterPasses;
          v34 = 0;
          if ( v11 >= 1 && v11 <= 5 )
          {
            v12 = filter.__vftable;
            if ( filter.__vftable )
              (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))filter.~Scaleform::Render::Filter + 1))(filter.__vftable);
            if ( filter.Type )
              (*(void (__thiscall **)(Scaleform::Render::FilterType))(*(_DWORD *)filter.Type + 8))(filter.Type);
            filter.Type = (Scaleform::Render::FilterType)v12;
            v34 = 1;
          }
          for ( targets = 0;
                (unsigned int)targets < pass;
                targets = (Scaleform::Ptr<Scaleform::Render::RenderTarget> *)((char *)targets + 1) )
          {
            if ( targets == (Scaleform::Ptr<Scaleform::Render::RenderTarget> *)(pass - 1)
              && *(_DWORD *)&filter.Frozen == Size - 1 )
            {
              break;
            }
            RefCount = (_DWORD *)filter.RefCount;
            if ( !filter.RefCount )
            {
              filter.RefCount = (volatile int)this->CreateTempRenderTarget(this, v44, 0);
              RefCount = (_DWORD *)filter.RefCount;
            }
            results = *(Scaleform::Render::RenderTarget **)(RefCount[4] + 16);
            this->pDeviceContext->OMSetRenderTargets(
              this->pDeviceContext,
              1u,
              (ID3D11RenderTargetView *const *)&results,
              0);
            ++this->AccumulatedStats.RTChanges;
            memset(v50, 0, sizeof(v50));
            this->pDeviceContext->ClearRenderTargetView(
              this->pDeviceContext,
              (ID3D11RenderTargetView *)results,
              (const float *)v50);
            Scaleform::Render::Viewport::Viewport(
              &v47,
              RefCount[5],
              RefCount[6],
              RefCount[7],
              RefCount[8],
              RefCount[9] - RefCount[7],
              RefCount[10] - RefCount[8],
              0);
            qmemcpy(&this->VP, v14, sizeof(this->VP));
            v15 = (Scaleform::Render::Filter_vtbl *)filter.RefCount;
            v16 = *(_DWORD *)(filter.RefCount + 28);
            v17 = *(_DWORD *)(filter.RefCount + 32);
            v18 = *(_DWORD *)(filter.RefCount + 36);
            v48 = *(_DWORD *)(filter.RefCount + 40);
            this->ViewRect.x1 = v16;
            this->ViewRect.y2 = v48;
            this->ViewRect.y1 = v17;
            this->ViewRect.x2 = v18;
            v19 = this->__vftable;
            this->HALState |= 0x20u;
            v19->updateViewport(this);
            *(_QWORD *)&m2.M[0][0] = LODWORD(s_bm_current_air_resistance);
            *(_QWORD *)&m2.M[1][1] = LODWORD(s_bm_current_air_resistance);
            *(float *)&v47.BufferWidth = retry_to_increase_quality_period_sec;
            m2.M[0][2] = 0.0;
            m2.M[0][3] = FLOAT_N0_5;
            m2.M[1][0] = 0.0;
            m2.M[1][3] = FLOAT_N0_5;
            memset(&v47.BufferHeight, 0, 16);
            *(float *)&v47.Height = FLOAT_N2_0;
            v47.ScissorLeft = 0;
            v47.ScissorTop = 0;
            Scaleform::Render::operator*(&result, (const Scaleform::Render::Matrix2x4<float> *)&v47, &m2);
            Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
              passes,
              (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&result,
              &Scaleform::Render::Cxform::Identity,
              v39,
              &filter,
              (Scaleform::Render::D3D1x::ShaderInterface *)targets,
              pass,
              this->MappedXY16iAlphaTexture[0],
              &this->ShaderData,
              v33);
            this->drawPrimitive(this, 6u, 1u);
            Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, this->pTextureManager.pObject, 0, views, 0);
            if ( !v34 || targets )
            {
              v20 = filter.__vftable;
            }
            else
            {
              v20 = (Scaleform::Render::Filter_vtbl *)this->CreateTempRenderTarget(this, v44, 0);
              if ( filter.__vftable )
                (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))filter.~Scaleform::Render::Filter + 2))(filter.__vftable);
              filter.__vftable = v20;
            }
            if ( v20 )
              (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))v20->~Scaleform::Render::Filter + 1))(v20);
            (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))v15->~Scaleform::Render::Filter + 1))(v15);
            if ( filter.__vftable )
              (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))filter.~Scaleform::Render::Filter + 2))(filter.__vftable);
            filter.__vftable = v15;
            if ( v20 )
              (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))v20->~Scaleform::Render::Filter + 1))(v20);
            (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))v15->~Scaleform::Render::Filter + 2))(v15);
            filter.RefCount = (volatile int)v20;
            if ( v20 )
              (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))v20->~Scaleform::Render::Filter + 2))(v20);
          }
          ++*(_DWORD *)&filter.Frozen;
        }
        while ( *(_DWORD *)&filter.Frozen < Size );
        v2 = e;
        v7 = filter.__vftable;
      }
      if ( !v7 || this->Profiler.NoFilterCaching && pass )
      {
        Scaleform::Render::FilterPrimitive::SetCacheResults(v2->pPrimitive.pObject, Cache_Mesh, 0, 0);
      }
      else
      {
        Type = filter.Type;
        results = (Scaleform::Render::RenderTarget *)v7;
        Scaleform::Render::FilterPrimitive::SetCacheResults(
          v2->pPrimitive.pObject,
          (Scaleform::Render::FilterPrimitive::CacheState)((pass == 0) + 1),
          &results,
          (pass != 0) + 1);
        results->pRenderTargetData->CacheID = (unsigned int)v2->pPrimitive.pObject;
        if ( Type )
          *(_DWORD *)(*(_DWORD *)(Type + 16) + 12) = v2->pPrimitive.pObject;
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
      if ( pass )
      {
        p_FilterArea = &v2->pPrimitive.pObject->FilterArea;
        Scaleform::Render::operator*(
          &result,
          &this->Matrices.pObject->UserView,
          (const Scaleform::Render::Matrix2x4<float> *)(&p_FilterArea->pHandle->pHeader[1].RefCount
                                                      + 4
                                                      * (unsigned __int8)byte_874214[5
                                                                                   * (p_FilterArea->pHandle->pHeader->Format
                                                                                    & 0xF)]));
        v31 = this->MappedXY16iAlphaTexture[0];
        v30 = v39;
        Cxform = (Scaleform::Render::Cxform *)Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(p_FilterArea);
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
          passes,
          (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&result,
          Cxform,
          v30,
          &filter,
          (Scaleform::Render::D3D1x::ShaderInterface *)targets,
          pass,
          v31,
          &this->ShaderData,
          v33);
        v23 = Blend_Normal;
        if ( this->BlendModeStack.Data.Size )
          v24 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
        else
          v24 = Blend_Normal;
        Scaleform::Render::HAL::applyBlendMode(this, v24, 1, 0);
        this->drawPrimitive(this, 6u, 1u);
        if ( this->BlendModeStack.Data.Size )
          v23 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
        Scaleform::Render::HAL::applyBlendMode(this, v23, 0, 0);
        Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, this->pTextureManager.pObject, 0, views, 0);
      }
      else
      {
        this->drawCachedFilter(this, v2->pPrimitive.pObject);
      }
      for ( i = 0; i < 3; ++i )
      {
        v26 = *((_DWORD *)&filter.__vftable + i);
        if ( v26 )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v26 + 20))(v26, 0);
      }
      this->AccumulatedStats.Filters += v42->Filters.Data.Size;
      p_Frozen = &filter.Frozen;
      for ( j = 2; j >= 0; --j )
      {
        p_Frozen -= 4;
        if ( *(_DWORD *)p_Frozen )
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)p_Frozen + 8))(*(_DWORD *)p_Frozen);
      }
    }
  }
}
