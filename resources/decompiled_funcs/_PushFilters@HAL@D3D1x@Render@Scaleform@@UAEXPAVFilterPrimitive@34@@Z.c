void __thiscall Scaleform::Render::D3D1x::HAL::PushFilters(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::GFx::Resource *prim)
{
  Scaleform::Render::RenderEvent *v3; // eax
  int v4; // ecx
  Scaleform::Render::RenderEvent *v5; // ebx
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String); // edi
  bool (__thiscall *shouldRenderFilters)(struct Scaleform::Render::D3D1x::HAL *, const Scaleform::Render::FilterPrimitive *); // eax
  ID3D11DepthStencilState *v8; // ecx
  float *v9; // edi
  double v10; // st7
  Scaleform::Render::RenderTarget *(__thiscall *CreateTempRenderTarget)(struct Scaleform::Render::D3D1x::HAL *, const Scaleform::Render::Size<unsigned long> *, bool); // edx
  Scaleform::Render::RenderTarget *v12; // eax
  float v13; // xmm2_4
  float v14; // xmm3_4
  Scaleform::Render::RenderTarget *v15; // ebx
  void (__thiscall *PushRenderTarget)(struct Scaleform::Render::D3D1x::HAL *, const Scaleform::Render::Rect<float> *, Scaleform::Render::RenderTarget *, unsigned int); // edx
  float v17; // xmm0_4
  float v18; // xmm1_4
  Scaleform::Render::BlendMode v19; // eax
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ebx
  unsigned int Size; // ecx
  Scaleform::Render::D3D1x::HAL_vtbl *v22; // edx
  Scaleform::Render::RenderQueueProcessor *(__thiscall *GetRQProcessor)(struct Scaleform::Render::D3D1x::HAL *); // eax
  __int64 v24; // [esp+38h] [ebp-48h] BYREF
  unsigned __int16 v25; // [esp+4Eh] [ebp-32h]
  __int64 v26; // [esp+50h] [ebp-30h] BYREF
  float v27; // [esp+58h] [ebp-28h]
  float v28; // [esp+5Ch] [ebp-24h]
  int v29; // [esp+6Ch] [ebp-14h]
  Scaleform::Render::HAL::FilterStackEntry val; // [esp+70h] [ebp-10h] BYREF
  __int64 v31; // [esp+78h] [ebp-8h] BYREF

  v3 = this->GetEvent(this, 12);
  HIDWORD(v24) = v4;
  v5 = v3;
  p_Begin = &v3->Begin;
  Scaleform::String::String((Scaleform::String *)&v24 + 1, (char *)&argv);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, _DWORD))*p_Begin)(v5, HIDWORD(v24));
  if ( (this->HALState & 8) == 0 )
  {
    Scaleform::GFx::AS2::Object::SetValue((Scaleform::GFx::AS3::Instances::fl_geom::Transform *)this, 8u, &argv);
    return;
  }
  if ( prim )
    Scaleform::RefCountImpl::AddRef(prim);
  shouldRenderFilters = this->shouldRenderFilters;
  val.pPrimitive.pObject = (Scaleform::Render::FilterPrimitive *)prim;
  val.pRenderTarget.pObject = 0;
  if ( shouldRenderFilters(this, (const Scaleform::Render::FilterPrimitive *)prim) )
  {
    if ( (this->HALState & 0x100) != 0 )
    {
LABEL_28:
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::PushBack(
        &this->FilterStack,
        &val);
      Scaleform::Render::HAL::FilterStackEntry::~FilterStackEntry(&val);
      return;
    }
    if ( this->MaskStackTop && !LOBYTE(prim[3].__vftable) )
    {
      if ( this->StencilAvailable )
      {
        HIDWORD(v24) = this->MaskStackTop;
        v8 = this->DepthStencilStates[5];
      }
      else
      {
        if ( !this->DepthBufferAvailable )
          goto LABEL_18;
        HIDWORD(v24) = this->MaskStackTop;
        v8 = this->DepthStencilStates[6];
      }
      this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, v8, HIDWORD(v24));
    }
LABEL_18:
    this->HALState |= 0x80u;
    if ( prim[2].__vftable )
    {
      Size = this->FilterStack.Data.Size;
      v22 = this->__vftable;
      this->HALState |= 0x100u;
      GetRQProcessor = v22->GetRQProcessor;
      this->CachedFilterIndex = Size;
      GetRQProcessor(this)->QueueEmitFilter = QPF_Filters;
    }
    else
    {
      v9 = (float *)&prim[1].pLib->__vftable[(unsigned __int8)byte_9B2B74[5 * (HIBYTE(prim[1].pLib->PinResource) & 0xF)]
                                           + 1];
      LOBYTE(v29) = prim[3].__vftable;
      v10 = *v9;
      LODWORD(v26) = v25 | 0xC00;
      v31 = (__int64)v10;
      LODWORD(v31) = (__int64)v10;
      CreateTempRenderTarget = this->CreateTempRenderTarget;
      v26 = (__int64)v9[5];
      HIDWORD(v31) = v26;
      v12 = CreateTempRenderTarget(this, (const Scaleform::Render::Size<unsigned long> *)&v31, v29);
      v13 = v9[7];
      v14 = v9[3];
      v15 = v12;
      PushRenderTarget = this->PushRenderTarget;
      v24 = (unsigned int)v12;
      v17 = v13 + v9[5];
      v18 = v14 + *v9;
      val.pRenderTarget.pObject = v12;
      v26 = __PAIR64__(LODWORD(v13), LODWORD(v14));
      v27 = v18;
      v28 = v17;
      PushRenderTarget(this, (const Scaleform::Render::Rect<float> *)&v26, v12, 0);
      if ( this->BlendModeStack.Data.Size )
        v19 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
      else
        v19 = Blend_Normal;
      Scaleform::Render::HAL::applyBlendMode(this, v19, 0, 0);
      if ( LOBYTE(prim[3].__vftable) )
      {
        pRenderTargetData = v15->pRenderTargetData;
        if ( this->StencilAvailable )
        {
          ((void (__stdcall *)(ID3D11DeviceContext *, Scaleform::Render::RenderBuffer *, int, _DWORD, _DWORD))this->pDeviceContext->ClearDepthStencilView)(
            this->pDeviceContext,
            pRenderTargetData[1].pBuffer,
            2,
            0.0,
            LOBYTE(this->MaskStackTop));
        }
        else if ( this->DepthBufferAvailable )
        {
          ((void (__stdcall *)(ID3D11DeviceContext *, Scaleform::Render::RenderBuffer *, int, _DWORD, _DWORD))this->pDeviceContext->ClearDepthStencilView)(
            this->pDeviceContext,
            pRenderTargetData[1].pBuffer,
            1,
            1.0,
            LOBYTE(this->MaskStackTop));
        }
      }
    }
    goto LABEL_28;
  }
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::PushBack(
    &this->FilterStack,
    &val);
  if ( val.pRenderTarget.pObject )
    val.pRenderTarget.pObject->Release(val.pRenderTarget.pObject);
  if ( val.pPrimitive.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)val.pPrimitive.pObject);
}
