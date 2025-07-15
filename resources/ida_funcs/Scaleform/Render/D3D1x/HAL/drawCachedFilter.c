void __thiscall Scaleform::Render::D3D1x::HAL::drawCachedFilter(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::FilterPrimitive *primitive)
{
  __int32 v3; // eax
  Scaleform::Render::RenderTarget *v4; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx
  int x1; // ecx
  int y1; // edx
  float v8; // xmm1_4
  signed int Height; // esi
  double v10; // st6
  int v11; // ecx
  int v12; // eax
  double v13; // st6
  Scaleform::Render::MatrixPoolImpl::DataHeader *v14; // eax
  bool v15; // zf
  void (__thiscall *SetInUse)(Scaleform::Render::RenderTarget *, bool); // edx
  const Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v18; // ecx
  Scaleform::Render::BlendMode v19; // eax
  Scaleform::Render::BlendMode v20; // eax
  Scaleform::Render::RenderTarget *v21; // esi
  Scaleform::Render::RenderTarget *(__thiscall *CreateTempRenderTarget)(struct Scaleform::Render::D3D1x::HAL *, const Scaleform::Render::Size<unsigned long> *, bool); // edx
  const Scaleform::Render::D3D1x::ShaderPair *v23; // ecx
  int v24; // esi
  int v25; // esi
  Scaleform::Render::BlendMode v26; // eax
  unsigned int i; // esi
  int v28; // ecx
  Scaleform::Render::Matrix2x4<float> *p_m2; // esi
  int j; // edi
  float v31; // ecx
  Scaleform::Render::D3D1x::ShaderInterface *v32; // [esp+2660h] [ebp-2B4h]
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *FillFlags; // [esp+2660h] [ebp-2B4h]
  const Scaleform::Render::VertexFormat *v34; // [esp+2664h] [ebp-2B0h]
  Scaleform::Render::D3D1x::ShaderInterface *v35; // [esp+2664h] [ebp-2B0h]
  float *v; // [esp+267Ch] [ebp-298h]
  float vb; // [esp+267Ch] [ebp-298h]
  Scaleform::Render::Cxform *va; // [esp+267Ch] [ebp-298h]
  Scaleform::Render::RenderTarget *v39[2]; // [esp+2680h] [ebp-294h] BYREF
  Scaleform::Render::RenderTarget *v40; // [esp+2688h] [ebp-28Ch] BYREF
  unsigned int pass; // [esp+268Ch] [ebp-288h]
  const Scaleform::Render::D3D1x::ShaderPair *sd; // [esp+2690h] [ebp-284h] BYREF
  int v43; // [esp+2694h] [ebp-280h]
  __int64 __t; // [esp+2698h] [ebp-27Ch] BYREF
  int v45; // [esp+26A0h] [ebp-274h]
  Scaleform::Render::Matrix2x4<float> m2; // [esp+26A4h] [ebp-270h] BYREF
  ID3D11Buffer *pObject; // [esp+26C8h] [ebp-24Ch] BYREF
  Scaleform::Render::RenderTarget *v48; // [esp+26CCh] [ebp-248h] BYREF
  int v49; // [esp+26D0h] [ebp-244h]
  Scaleform::Render::Matrix2x4<float> result; // [esp+26D4h] [ebp-240h] BYREF
  __int64 v51; // [esp+26F4h] [ebp-220h] BYREF
  float v52; // [esp+26FCh] [ebp-218h]
  float v53; // [esp+2700h] [ebp-214h]
  ID3D11ShaderResourceView *views[2]; // [esp+270Ch] [ebp-208h] BYREF
  Scaleform::Render::Matrix2x4<float> v55; // [esp+2714h] [ebp-200h] BYREF
  Scaleform::Ptr<Scaleform::Render::RenderTarget> targets; // [esp+2734h] [ebp-1E0h] BYREF

  pObject = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  this->pDeviceContext->IASetVertexBuffers(
    this->pDeviceContext,
    0,
    1u,
    &pObject,
    &stride,
    (const unsigned int *)&FLOAT_0_0);
  v3 = primitive->Caching - 1;
  *(_QWORD *)views = 0;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v32 = (Scaleform::Render::D3D1x::ShaderInterface *)this->MappedXY16iAlphaTexture[0];
      v39[0] = (Scaleform::Render::RenderTarget *)(this->FillFlags | 6);
      sd = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFill(
             (unsigned int *)v39,
             0,
             &this->ShaderData,
             (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)5,
             v32,
             v34);
      Scaleform::Render::FilterPrimitive::GetCacheResults(primitive, &v40, 1u);
      v4 = (Scaleform::Render::RenderTarget *)v40->GetTexture(v40);
      pHeader = primitive->FilterArea.pHandle->pHeader;
      v39[0] = v4;
      Scaleform::Render::operator*(
        &result,
        &this->Matrices.pObject->UserView,
        (const Scaleform::Render::Matrix2x4<float> *)(&pHeader[1].RefCount
                                                    + 4 * (unsigned __int8)byte_9B2B74[5 * (pHeader->Format & 0xF)]));
      x1 = v40->ViewRect.x1;
      y1 = v40->ViewRect.y1;
      v8 = (float)x1;
      v = (float *)(v40->ViewRect.x2 - x1);
      Height = v39[0]->BufferSize.Height;
      v10 = (double)Height;
      m2.M[1][3] = (float)y1;
      if ( Height < 0 )
        v10 = v10 + 4294967300.0;
      v11 = v39[0]->ViewRect.x1;
      v12 = v40->ViewRect.y2 - y1;
      *(float *)&pass = (double)(int)v / v10;
      v13 = (double)v12 / (double)(unsigned int)v11;
      v14 = primitive->FilterArea.pHandle->pHeader;
      v15 = (v14->Format & 1) == 0;
      m2.M[0][1] = *(float *)&pass * 0.0;
      m2.M[0][2] = *(float *)&pass * 0.0;
      m2.M[0][3] = v8 * *(float *)&pass;
      vb = v13;
      m2.M[0][0] = *(float *)&pass;
      m2.M[1][0] = vb * 0.0;
      m2.M[1][1] = v13;
      m2.M[1][2] = vb * 0.0;
      m2.M[1][3] = v13 * m2.M[1][3];
      if ( v15 )
        va = &Scaleform::Render::Cxform::Identity;
      else
        va = (Scaleform::Render::Cxform *)(&v14[1].RefCount
                                         + 4
                                         * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v14->Format & 0xF].Offsets[0]);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        sd,
        1u,
        0,
        &this->ShaderData,
        (const float *)va,
        4u,
        0);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        sd,
        0,
        0,
        &this->ShaderData,
        va->M[1],
        4u,
        0);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        sd,
        4u,
        0,
        &this->ShaderData,
        (const float *)&result,
        8u,
        0);
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        sd,
        0xBu,
        0,
        &this->ShaderData,
        (const float *)&m2,
        8u,
        0);
      SetInUse = v39[0]->__vftable[1].SetInUse;
      pFDesc = this->ShaderData.CurShaders.pFDesc;
      HIBYTE(v39[1]) = 3;
      ((void (__stdcall *)(_DWORD, char *))SetInUse)(pFDesc->Uniforms[10].Location, (char *)&v39[1] + 3);
      Scaleform::Render::D3D1x::ShaderInterface::Finish(v18, (int)&this->ShaderData);
      if ( this->BlendModeStack.Data.Size )
        v19 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
      else
        v19 = Blend_Normal;
      Scaleform::Render::HAL::applyBlendMode(this, v19, 1, (Scaleform::String::DataDesc *)1);
      this->drawPrimitive(this, 6u, 1u);
      if ( this->BlendModeStack.Data.Size )
        v20 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
      else
        v20 = Blend_Normal;
      Scaleform::Render::HAL::applyBlendMode(
        this,
        v20,
        0,
        (Scaleform::String::DataDesc *)((this->HALState & 0x10) != 0));
      v40->SetInUse(v40, 0);
    }
  }
  else
  {
    FillFlags = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)this->FillFlags;
    v40 = (Scaleform::Render::RenderTarget *)primitive->pFilters.pObject->Filters.Data.Data[primitive->pFilters.pObject->Filters.Data.Size
                                                                                          - 1].pObject;
    *(float *)&pass = COERCE_FLOAT(
                        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses(
                          (const Scaleform::Render::Filter *)v40,
                          (unsigned int *)&targets,
                          FillFlags,
                          (unsigned int)v34));
    `vector constructor iterator'(
      (char *)&__t,
      4u,
      3,
      (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
    __t = 0;
    v45 = 0;
    Scaleform::Render::FilterPrimitive::GetCacheResults(primitive, &v48, 2u);
    v21 = v48;
    if ( v48 )
      v48->AddRef(v48);
    if ( (_DWORD)__t )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)__t + 8))(__t);
    CreateTempRenderTarget = this->CreateTempRenderTarget;
    LODWORD(__t) = v21;
    v23 = (const Scaleform::Render::D3D1x::ShaderPair *)(v21->ViewRect.x2 - v21->ViewRect.x1);
    v43 = v21->ViewRect.y2 - v21->ViewRect.y1;
    sd = v23;
    v24 = (int)CreateTempRenderTarget(this, (const Scaleform::Render::Size<unsigned long> *)&sd, 0);
    if ( HIDWORD(__t) )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(__t) + 8))(HIDWORD(__t));
    HIDWORD(__t) = v24;
    v25 = v49;
    if ( v49 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v49 + 4))(v49);
    if ( v45 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v45 + 8))(v45);
    v45 = v25;
    v51 = 0;
    v52 = (float)(unsigned int)sd;
    v53 = (float)(unsigned int)v43;
    this->PushRenderTarget(
      this,
      (const Scaleform::Render::Rect<float> *)&v51,
      (Scaleform::Render::RenderTarget *)HIDWORD(__t),
      0);
    *(_QWORD *)&m2.M[0][0] = (unsigned int)clear_value;
    *(_QWORD *)&m2.M[1][1] = (unsigned int)clear_value;
    *(_QWORD *)&result.M[0][0] = LODWORD(retry_to_increase_quality_period_sec);
    *(_QWORD *)&m2.M[0][2] = 0xBF00000000000000uLL;
    m2.M[1][0] = 0.0;
    m2.M[1][3] = -0.5;
    *(_QWORD *)&result.M[0][2] = 0;
    *(_QWORD *)&result.M[1][0] = 0xC000000000000000uLL;
    *(_QWORD *)&result.M[1][2] = 0;
    Scaleform::Render::operator*(&v55, &result, &m2);
    Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFilterFill(
      this->MappedXY16iAlphaTexture[0],
      (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&v55,
      &Scaleform::Render::Cxform::Identity,
      (const Scaleform::Render::Filter *)v40,
      (Scaleform::Ptr<Scaleform::Render::RenderTarget> *)&__t,
      &targets,
      pass - 1,
      pass,
      &this->ShaderData,
      v35);
    if ( this->BlendModeStack.Data.Size )
      v26 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
    else
      v26 = Blend_Normal;
    Scaleform::Render::HAL::applyBlendMode(this, v26, 1, (Scaleform::String::DataDesc *)1);
    this->drawPrimitive(this, 6u, 1u);
    this->PopRenderTarget(this, 0);
    Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, this->pTextureManager.pObject, 0, views, 0);
    v39[0] = (Scaleform::Render::RenderTarget *)HIDWORD(__t);
    Scaleform::Render::FilterPrimitive::SetCacheResults(primitive, Cache_Count, v39, 1u);
    v39[0]->pRenderTargetData->CacheID = (unsigned int)primitive;
    this->drawCachedFilter(this, primitive);
    for ( i = 0; i < 3; ++i )
    {
      v28 = *((_DWORD *)&__t + i);
      if ( v28 )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v28 + 20))(v28, 0);
    }
    p_m2 = &m2;
    for ( j = 2; j >= 0; --j )
    {
      v31 = p_m2[-1].M[1][3];
      p_m2 = (Scaleform::Render::Matrix2x4<float> *)((char *)p_m2 - 4);
      if ( v31 != 0.0 )
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v31) + 8))(COERCE_FLOAT(LODWORD(v31)));
    }
  }
}
