void __thiscall Scaleform::Render::D3D1x::HAL::PushFilters(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::GFx::Resource *prim)
{
  Scaleform::Render::RenderEvent *v3; // eax
  Scaleform::Render::RenderEvent_vtbl *v4; // esi
  Scaleform::String::DataDesc *v5; // ecx
  Scaleform::Render::D3D1x::HAL_vtbl *v6; // eax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > > *v7; // ecx
  ID3D11Buffer *pObject; // eax
  ID3D11DeviceContext *pDeviceContext; // eax
  Scaleform::Render::ProfileViews *v10; // ecx
  Scaleform::Render::Color *v11; // eax
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v12; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v13; // ecx
  Scaleform::Render::D3D1x::ShaderInterface *v14; // ecx
  float *v15; // esi
  double v16; // st7
  unsigned __int64 v17; // rax
  Scaleform::Render::RenderTarget *v18; // eax
  float v19; // xmm3_4
  float v20; // xmm2_4
  Scaleform::Render::D3D1x::HAL_vtbl *v21; // edx
  float v22; // xmm0_4
  float v23; // xmm1_4
  Scaleform::Render::BlendMode v24; // eax
  int v25; // eax
  Scaleform::String v26; // [esp+30h] [ebp-64h] BYREF
  void *v27; // [esp+4Ch] [ebp-48h] BYREF
  unsigned int fillflags; // [esp+50h] [ebp-44h] BYREF
  Scaleform::Render::Color v29[2]; // [esp+54h] [ebp-40h] BYREF
  Scaleform::Render::HAL::FilterStackEntry val; // [esp+5Ch] [ebp-38h] BYREF
  Scaleform::Render::Color color; // [esp+64h] [ebp-30h] BYREF
  float v32; // [esp+68h] [ebp-2Ch]
  float v33; // [esp+6Ch] [ebp-28h]
  float v34; // [esp+70h] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> v35; // [esp+74h] [ebp-20h] BYREF

  v3 = this->GetEvent(this, 12);
  v4 = v3->__vftable;
  v26.pData = v5;
  v27 = v3;
  Scaleform::String::String(&v26, "Scaleform::Render::D3D1x::HAL::PushFilters");
  ((void (__thiscall *)(void *, Scaleform::String::DataDesc *))v4->Begin)(v27, v26.pData);
  if ( Scaleform::Render::HAL::checkState(
         this,
         8u,
         (Scaleform::GFx::AS3::Value *)"Scaleform::Render::D3D1x::HAL::PushFilters") )
  {
    if ( prim )
      Scaleform::RefCountImpl::AddRef(prim);
    v6 = this->__vftable;
    val.pPrimitive.pObject = (Scaleform::Render::FilterPrimitive *)prim;
    val.pRenderTarget.pObject = 0;
    if ( v6->shouldRenderFilters(this, (const Scaleform::Render::FilterPrimitive *)prim) )
    {
      if ( this->Profiler.OverrideMasks )
      {
        pObject = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
        v26.pData = (Scaleform::String::DataDesc *)&FLOAT_0_0;
        v27 = pObject;
        pDeviceContext = this->pDeviceContext;
        this->Profiler.DrawMode = 2;
        pDeviceContext->IASetVertexBuffers(
          pDeviceContext,
          0,
          1u,
          (ID3D11Buffer *const *)&v27,
          &stride,
          &v26.pData->Size);
        fillflags = 0;
        v11 = Scaleform::Render::ProfileViews::GetColor(
                v10,
                (int)&this->Profiler,
                v29,
                (Scaleform::Render::Color *)0xFFFFFFFF,
                (Scaleform::Render::Color)&color);
        Scaleform::Render::Color::GetRGBAFloat(v11, (float *)&v26.pData->Size);
        v12 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
                PrimFill_SolidColor,
                &fillflags,
                0,
                (unsigned int)this->MappedXY16iAlphaSolid[0]);
        Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
          v13,
          this->ShaderData.UniformData,
          v12,
          (const Scaleform::Render::VertexFormat *)v26.pData);
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
        Scaleform::Render::Matrix2x4<float>::SetToAppend(
          &v35,
          (const Scaleform::Render::Matrix2x4<float> *)&prim[1].pLib->__vftable[(unsigned __int8)byte_874214[5 * (HIBYTE(prim[1].pLib->PinResource) & 0xF)]
                                                                              + 1],
          &this->Matrices.pObject->UserView);
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
          &this->ShaderData.CurShaders,
          &this->ShaderData,
          4u,
          (float *)&v35,
          8u,
          0,
          0);
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
          &this->ShaderData.CurShaders,
          &this->ShaderData,
          1u,
          (float *)&color.Raw,
          4u,
          0,
          0);
        Scaleform::Render::D3D1x::ShaderInterface::Finish(v14, (unsigned int)&this->ShaderData);
        this->drawPrimitive(this, 6u, 1u);
      }
      else if ( (this->HALState & 0x100) == 0 )
      {
        if ( this->MaskStackTop && !LOBYTE(prim[3].__vftable) )
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
        this->HALState |= 0x80u;
        if ( prim[2].__vftable )
        {
          this->HALState |= 0x100u;
          this->CachedFilterIndex = this->FilterStack.Data.Size;
          this->GetRQProcessor(this)->QueueEmitFilter = QPF_Filters;
        }
        else
        {
          v15 = (float *)&prim[1].pLib->__vftable[(unsigned __int8)byte_874214[5
                                                                             * (HIBYTE(prim[1].pLib->PinResource) & 0xF)]
                                                + 1];
          v16 = *v15;
          LOBYTE(fillflags) = prim[3].__vftable;
          v29[0].Raw = (unsigned __int64)v16;
          v17 = (unsigned __int64)v15[5];
          v29[1].Raw = v17;
          v18 = (Scaleform::Render::RenderTarget *)((int (__fastcall *)(Scaleform::Render::D3D1x::HAL *, _DWORD, Scaleform::Render::Color *, unsigned int))this->CreateTempRenderTarget)(
                                                     this,
                                                     HIDWORD(v17),
                                                     v29,
                                                     fillflags);
          v19 = v15[7];
          v20 = v15[3];
          v21 = this->__vftable;
          v26.pData = 0;
          fillflags = (unsigned int)v18;
          val.pRenderTarget.pObject = v18;
          v22 = v19 + v15[5];
          v23 = v20 + *v15;
          color.Raw = LODWORD(v20);
          v32 = v19;
          v33 = v23;
          v34 = v22;
          v21->PushRenderTarget(this, (const Scaleform::Render::Rect<float> *)&color, v18, 0);
          if ( this->BlendModeStack.Data.Size )
            v24 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
          else
            v24 = Blend_Normal;
          Scaleform::Render::HAL::applyBlendMode(this, v24, 0, 0);
          if ( LOBYTE(prim[3].__vftable) )
          {
            v25 = *(_DWORD *)(fillflags + 16);
            if ( this->StencilAvailable )
            {
              ((void (__stdcall *)(ID3D11DeviceContext *, _DWORD, int, _DWORD, _DWORD))this->pDeviceContext->ClearDepthStencilView)(
                this->pDeviceContext,
                *(_DWORD *)(v25 + 20),
                2,
                0.0,
                LOBYTE(this->MaskStackTop));
            }
            else if ( this->DepthBufferAvailable )
            {
              ((void (__stdcall *)(ID3D11DeviceContext *, _DWORD, int, _DWORD, _DWORD))this->pDeviceContext->ClearDepthStencilView)(
                this->pDeviceContext,
                *(_DWORD *)(v25 + 20),
                1,
                1.0,
                LOBYTE(this->MaskStackTop));
            }
          }
        }
      }
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::PushBack(
      v7,
      &this->FilterStack.Data,
      &val);
    Scaleform::Render::HAL::FilterStackEntry::~FilterStackEntry(&val);
  }
}
