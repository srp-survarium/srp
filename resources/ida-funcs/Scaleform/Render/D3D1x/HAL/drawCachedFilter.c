void __thiscall Scaleform::Render::D3D1x::HAL::drawCachedFilter(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::FilterPrimitive *primitive)
{
  unsigned int v3; // eax
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v4; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v5; // ecx
  int y2; // edx
  float v7; // xmm1_4
  int y1; // ecx
  int v9; // eax
  Scaleform::Render::Cxform *v10; // edx
  double v11; // st7
  Scaleform::Render::Cxform *Cxform; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v13; // ecx
  Scaleform::Render::BlendMode v14; // esi
  Scaleform::Render::BlendMode v15; // eax
  Scaleform::Render::Cxform *v16; // eax
  Scaleform::Render::Filter_vtbl *v17; // esi
  int v18; // eax
  Scaleform::Render::D3D1x::HAL_vtbl *v19; // eax
  int v20; // edi
  Scaleform::Render::FilterType v21; // esi
  Scaleform::Render::D3D1x::HAL_vtbl *v22; // eax
  Scaleform::Render::BlendMode v23; // eax
  int v24; // edi
  unsigned int i; // esi
  int v26; // ecx
  bool *p_Frozen; // esi
  Scaleform::Render::D3D1x::ShaderPair v28; // [esp+Ch] [ebp-2CCh] BYREF
  int v29; // [esp+20h] [ebp-2B8h]
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v30; // [esp+24h] [ebp-2B4h]
  Scaleform::Render::D3D1x::ShaderInterface *v31; // [esp+28h] [ebp-2B0h]
  unsigned int fillflags; // [esp+38h] [ebp-2A0h] BYREF
  int x1; // [esp+3Ch] [ebp-29Ch] BYREF
  unsigned int v34; // [esp+40h] [ebp-298h]
  Scaleform::Render::RenderTarget *results; // [esp+44h] [ebp-294h] BYREF
  const Scaleform::Render::D3D1x::ShaderPair *sd; // [esp+48h] [ebp-290h]
  Scaleform::Render::Cxform *v37; // [esp+4Ch] [ebp-28Ch]
  Scaleform::Render::MatrixPoolImpl::HMatrix *FilterPasses; // [esp+50h] [ebp-288h]
  Scaleform::Render::RenderTarget *v39; // [esp+54h] [ebp-284h] BYREF
  Scaleform::Render::FilterType v40; // [esp+58h] [ebp-280h]
  Scaleform::Render::Filter filter; // [esp+5Ch] [ebp-27Ch] BYREF
  float v42; // [esp+6Ch] [ebp-26Ch]
  float v43; // [esp+70h] [ebp-268h]
  float v44; // [esp+74h] [ebp-264h]
  float v45; // [esp+78h] [ebp-260h]
  float v46; // [esp+7Ch] [ebp-25Ch]
  float v47; // [esp+80h] [ebp-258h]
  float v48; // [esp+84h] [ebp-254h]
  ID3D11Buffer *pObject; // [esp+94h] [ebp-244h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+98h] [ebp-240h] BYREF
  _DWORD v51[6]; // [esp+B8h] [ebp-220h] BYREF
  ID3D11ShaderResourceView *views[2]; // [esp+D0h] [ebp-208h] BYREF
  Scaleform::Render::Matrix2x4<float> v53; // [esp+D8h] [ebp-200h] BYREF
  unsigned int passes[120]; // [esp+F8h] [ebp-1E0h] BYREF

  v30 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&FLOAT_0_0;
  v29 = (int)&stride;
  pObject = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  this->pDeviceContext->IASetVertexBuffers(
    this->pDeviceContext,
    0,
    1u,
    &pObject,
    &stride,
    (const unsigned int *)&FLOAT_0_0);
  views[0] = 0;
  views[1] = 0;
  if ( primitive->Caching == Cache_Glyph )
  {
    v16 = (Scaleform::Render::Cxform *)primitive->pFilters.pObject->Filters.Data.Data[primitive->pFilters.pObject->Filters.Data.Size
                                                                                    - 1].pObject;
    v30 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)this->FillFlags;
    v37 = v16;
    FilterPasses = (Scaleform::Render::MatrixPoolImpl::HMatrix *)Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
                                                                   (const Scaleform::Render::Filter *)v16,
                                                                   passes,
                                                                   v30,
                                                                   (unsigned int)v31);
    memset(&filter, 0, 12);
    Scaleform::Render::FilterPrimitive::GetCacheResults(primitive, &v39, 2u);
    v17 = (Scaleform::Render::Filter_vtbl *)v39;
    if ( *(float *)&v39 != 0.0 )
      v39->AddRef(v39);
    if ( filter.__vftable )
      (*((void (__thiscall **)(Scaleform::Render::Filter_vtbl *))filter.~Scaleform::Render::Filter + 2))(filter.__vftable);
    v18 = (char *)v17[2].IsContributing - (char *)v17[2].~Scaleform::Render::Filter;
    x1 = (char *)v17[2].Clone - (char *)v17[1].CanCacheAcrossTransform;
    v30 = 0;
    v34 = v18;
    v19 = this->__vftable;
    filter.__vftable = v17;
    v20 = (int)v19->CreateTempRenderTarget(this, (const Scaleform::Render::Size<unsigned long> *)&x1, 0);
    if ( filter.RefCount )
      (*(void (__thiscall **)(volatile int))(*(_DWORD *)filter.RefCount + 8))(filter.RefCount);
    filter.RefCount = v20;
    v21 = v40;
    if ( v40 )
      (*(void (__thiscall **)(Scaleform::Render::FilterType))(*(_DWORD *)v40 + 4))(v40);
    if ( filter.Type )
      (*(void (__thiscall **)(Scaleform::Render::FilterType))(*(_DWORD *)filter.Type + 8))(filter.Type);
    filter.Type = v21;
    v51[0] = 0;
    v51[1] = 0;
    *(float *)&v51[2] = (float)(unsigned int)x1;
    v22 = this->__vftable;
    *(float *)&v51[3] = (float)v34;
    v22->PushRenderTarget(this, (const Scaleform::Render::Rect<float> *)v51, (Scaleform::Render::RenderTarget *)v20, 0);
    *(float *)&filter.Frozen = s_bm_current_air_resistance;
    v46 = s_bm_current_air_resistance;
    *(_QWORD *)&result.M[0][0] = LODWORD(retry_to_increase_quality_period_sec);
    v42 = 0.0;
    v43 = 0.0;
    v44 = FLOAT_N0_5;
    v45 = 0.0;
    v47 = 0.0;
    v48 = FLOAT_N0_5;
    memset(&result.M[0][2], 0, 12);
    *(_QWORD *)&result.M[1][1] = LODWORD(FLOAT_N2_0);
    result.M[1][3] = 0.0;
    Scaleform::Render::operator*(&v53, &result, (const Scaleform::Render::Matrix2x4<float> *)&filter.Frozen);
    Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
      passes,
      (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v53,
      &Scaleform::Render::Cxform::Identity,
      v37,
      &filter,
      (Scaleform::Render::D3D1x::ShaderInterface *)((char *)&FilterPasses[-1].pHandle + 3),
      (unsigned int)FilterPasses,
      this->MappedXY16iAlphaTexture[0],
      &this->ShaderData,
      v31);
    if ( this->BlendModeStack.Data.Size )
      v23 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
    else
      v23 = Blend_Normal;
    Scaleform::Render::HAL::applyBlendMode(this, v23, 1, (Scaleform::String::DataDesc *)1);
    this->drawPrimitive(this, 6u, 1u);
    this->PopRenderTarget(this, 0);
    Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, this->pTextureManager.pObject, 0, views, 0);
    fillflags = v20;
    v24 = 2;
    Scaleform::Render::FilterPrimitive::SetCacheResults(
      primitive,
      Cache_Count,
      (Scaleform::Render::RenderTarget **)&fillflags,
      1u);
    *(_DWORD *)(*(_DWORD *)(fillflags + 16) + 12) = primitive;
    this->drawCachedFilter(this, primitive);
    for ( i = 0; i < 3; ++i )
    {
      v26 = *((_DWORD *)&filter.__vftable + i);
      if ( v26 )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v26 + 20))(v26, 0);
    }
    p_Frozen = &filter.Frozen;
    do
    {
      p_Frozen -= 4;
      if ( *(_DWORD *)p_Frozen )
        (*(void (__thiscall **)(_DWORD))(**(_DWORD **)p_Frozen + 8))(*(_DWORD *)p_Frozen);
      --v24;
    }
    while ( v24 >= 0 );
  }
  else if ( primitive->Caching == Cache_Count )
  {
    v3 = this->FillFlags;
    v29 = 5;
    fillflags = v3 | 6;
    v4 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
           PrimFill_Texture,
           &fillflags,
           0,
           (unsigned int)v31);
    Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
      v5,
      this->ShaderData.UniformData,
      v4,
      this->MappedXY16iAlphaTexture[0]);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
    sd = &this->ShaderData.CurShaders;
    Scaleform::Render::FilterPrimitive::GetCacheResults(primitive, &results, 1u);
    fillflags = (unsigned int)results->GetTexture(results);
    FilterPasses = &primitive->FilterArea;
    Scaleform::Render::operator*(
      &result,
      &this->Matrices.pObject->UserView,
      (const Scaleform::Render::Matrix2x4<float> *)(&primitive->FilterArea.pHandle->pHeader[1].RefCount
                                                  + 4
                                                  * (unsigned __int8)byte_874214[5
                                                                               * (primitive->FilterArea.pHandle->pHeader->Format
                                                                                & 0xF)]));
    y2 = results->ViewRect.y2;
    x1 = results->ViewRect.x1;
    v7 = (float)x1;
    y1 = results->ViewRect.y1;
    v9 = results->ViewRect.x2 - x1;
    v37 = (Scaleform::Render::Cxform *)(y2 - y1);
    v10 = *(Scaleform::Render::Cxform **)(fillflags + 28);
    x1 = *(int *)(fillflags + 24);
    *(float *)&v39 = (double)v9 / (double)(unsigned int)x1;
    v11 = (double)(int)v37;
    v37 = v10;
    v42 = *(float *)&v39 * 0.0;
    v43 = *(float *)&v39 * 0.0;
    v44 = v7 * *(float *)&v39;
    *(float *)&x1 = v11 / (double)(unsigned int)v10;
    *(float *)&filter.Frozen = *(float *)&v39;
    v46 = *(float *)&x1;
    v45 = *(float *)&x1 * 0.0;
    v47 = *(float *)&x1 * 0.0;
    v48 = (float)y1 * *(float *)&x1;
    Cxform = (Scaleform::Render::Cxform *)Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(FilterPasses);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
      Cxform,
      &this->ShaderData,
      sd,
      0,
      (unsigned int)v31);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      sd,
      &this->ShaderData,
      4u,
      (float *)&result,
      8u,
      0,
      0);
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
      sd,
      &this->ShaderData,
      0xBu,
      (float *)&filter.Frozen,
      8u,
      0,
      0);
    qmemcpy((void *)&v28, sd, sizeof(v28));
    Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
      0xAu,
      (Scaleform::Render::Texture *)fillflags,
      &this->ShaderData,
      v28,
      (Scaleform::Render::ImageFillMode)3,
      0);
    Scaleform::Render::D3D1x::ShaderInterface::Finish(v13, (unsigned int)&this->ShaderData);
    v14 = Blend_Normal;
    if ( this->BlendModeStack.Data.Size )
      v15 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
    else
      v15 = Blend_Normal;
    Scaleform::Render::HAL::applyBlendMode(this, v15, 1, (Scaleform::String::DataDesc *)1);
    this->drawPrimitive(this, 6u, 1u);
    if ( this->BlendModeStack.Data.Size )
      v14 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
    Scaleform::Render::HAL::applyBlendMode(this, v14, 0, (Scaleform::String::DataDesc *)((this->HALState & 0x10) != 0));
    results->SetInUse(results, 0);
    if ( this->Profiler.NoFilterCaching )
      Scaleform::Render::FilterPrimitive::SetCacheResults(primitive, Cache_Mesh, 0, 0);
  }
}
