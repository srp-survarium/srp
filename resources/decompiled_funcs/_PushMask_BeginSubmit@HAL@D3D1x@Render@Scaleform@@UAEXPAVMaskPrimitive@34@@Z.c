void __thiscall Scaleform::Render::D3D1x::HAL::PushMask_BeginSubmit(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::GFx::Resource *prim)
{
  Scaleform::Render::RenderEvent *v3; // eax
  Scaleform::String::DataDesc *v4; // ecx
  Scaleform::Render::RenderEvent *v5; // ebx
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *); // edi
  Scaleform::Render::D3D1x::HAL *v7; // ecx
  unsigned int MaskStackTop; // ecx
  bool v9; // al
  Scaleform::Render::MaskPrimitive *pObject; // eax
  Scaleform::ArrayLH<Scaleform::Render::HAL::MaskStackEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_MaskStack; // ebx
  unsigned int v12; // edi
  unsigned int v13; // ebx
  int y1; // eax
  int y2; // ecx
  int x1; // edx
  _DWORD *v17; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v18; // ecx
  unsigned __int8 Format; // al
  int Top; // edi
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  float *v24; // eax
  int v25; // ecx
  float v26; // xmm0_4
  float v27; // ecx
  float v28; // edx
  float v29; // xmm0_4
  float v30; // ecx
  int Left; // edi
  float v32; // eax
  char v33; // bl
  Scaleform::Render::MatrixPoolImpl::DataHeader *v34; // edx
  Scaleform::Render::Matrix2x4<float> *v35; // ecx
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // ecx
  ID3D11DeviceContext *pDeviceContext; // eax
  Scaleform::String v40; // [esp+222h] [ebp-64h] BYREF
  int v41; // [esp+232h] [ebp-54h]
  unsigned int Size; // [esp+236h] [ebp-50h]
  int v43; // [esp+23Ah] [ebp-4Ch]
  int x2; // [esp+23Eh] [ebp-48h]
  unsigned int v45; // [esp+242h] [ebp-44h]
  Scaleform::Render::Rect<float> r; // [esp+246h] [ebp-40h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+256h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v48; // [esp+266h] [ebp-20h] BYREF

  v3 = this->GetEvent(this, 6);
  v40.pData = v4;
  v5 = v3;
  p_Begin = (void (__thiscall **)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))&v3->Begin;
  Scaleform::String::String(&v40, (char *)&stru_973EF0);
  (*p_Begin)(v5, v40.pData);
  if ( (this->HALState & 8) == 0 )
  {
    Scaleform::GFx::AS2::Object::SetValue((Scaleform::GFx::AS3::Instances::fl_geom::Transform *)this, 8u, &stru_973EF0);
    return;
  }
  if ( this->StencilAvailable
    || this->DepthBufferAvailable
    || Scaleform::Render::D3D1x::HAL::checkMaskBufferCaps(v7, (int)this) )
  {
    this->pDeviceContext->OMSetBlendState(this->pDeviceContext, this->BlendStates[36], 0, -1u);
    MaskStackTop = this->MaskStackTop;
    v9 = (this->HALState & 0x20) != 0;
    HIBYTE(v41) = v9;
    v45 = MaskStackTop;
    if ( MaskStackTop && this->MaskStack.Data.Size > MaskStackTop && v9 && this->StencilAvailable )
    {
      this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, this->DepthStencilStates[2], MaskStackTop);
      pObject = this->MaskStack.Data.Data[this->MaskStackTop].pPrimitive.pObject;
      this->drawMaskClearRectangles(this, pObject->MaskAreas.Data.Data, pObject->MaskAreas.Data.Size);
    }
    p_MaskStack = &this->MaskStack;
    v12 = this->MaskStackTop + 1;
    Size = this->MaskStack.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &this->MaskStack.Data,
      &this->MaskStack,
      v12);
    if ( v12 > Size )
      Scaleform::ConstructorMov<Scaleform::Render::HAL::MaskStackEntry>::ConstructArray(
        (char *)&p_MaskStack->Data.Data[Size],
        v12 - Size);
    v13 = (unsigned int)&p_MaskStack->Data.Data[this->MaskStackTop];
    Size = v13;
    if ( prim )
      Scaleform::RefCountImpl::AddRef(prim);
    if ( *(_DWORD *)v13 )
      Scaleform::RefCountImpl::Release(*(Scaleform::RefCountVImpl **)v13);
    *(_BYTE *)(v13 + 4) = HIBYTE(v41);
    *(_DWORD *)v13 = prim;
    y1 = this->ViewRect.y1;
    y2 = this->ViewRect.y2;
    x2 = this->ViewRect.x2;
    x1 = this->ViewRect.x1;
    v43 = y1;
    v17 = (_DWORD *)Size;
    *(_DWORD *)(Size + 8) = x1;
    v17[3] = v43;
    v17[4] = x2;
    v17[5] = y2;
    this->HALState |= 0x40u;
    ++this->MaskStackTop;
    if ( prim[1].RefCount.Value == 1 && HIBYTE(v41) )
    {
      v18 = (Scaleform::Render::MatrixPoolImpl::DataHeader *)prim[1].pLib->~Scaleform::GFx::ResourceLibBase;
      Format = v18->Format;
      if ( this->Matrices.pObject->OrientationSet )
      {
        Scaleform::Render::Matrix2x4<float>::operator=(
          &v48,
          (const Scaleform::Render::Matrix2x4<float> *)(&v18[1].RefCount
                                                      + 4 * (unsigned __int8)byte_9B2B74[5 * (Format & 0xF)]));
        Scaleform::Render::Matrix2x4<float>::Append(&v48, &this->Matrices.pObject->Orient2D);
        r.x1 = 0.0;
        r.y1 = 0.0;
        LODWORD(r.x2) = clear_value;
        LODWORD(r.y2) = clear_value;
        Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v48, &pr, (__m128 *)&r);
        Left = this->VP.Left;
        LODWORD(v30) = this->VP.Top + (int)pr.y1;
        LODWORD(r.x1) = Left + (int)pr.x1;
        LODWORD(v32) = this->VP.Top + (int)pr.y2;
        LODWORD(r.x2) = Left + (int)pr.x2;
        r.y2 = v32;
      }
      else
      {
        Top = this->VP.Top;
        v21 = 16 * ((unsigned __int8)byte_9B2B74[5 * (Format & 0xF)] + 1);
        v22 = *(float *)&(&v18[1].pHandle)[v21 / 4u];
        v23 = *(float *)((char *)&v18[2].RefCount + v21);
        v24 = (float *)((char *)v18 + v21);
        v25 = (int)v22;
        v26 = v22 + *v24;
        LODWORD(v27) = this->VP.Left + v25;
        LODWORD(v48.M[0][1]) = Top + (int)v23;
        LODWORD(v28) = this->VP.Left + (int)v26;
        v29 = v24[5];
        r.x2 = v28;
        r.x1 = v27;
        v30 = v48.M[0][1];
        LODWORD(r.y2) = Top + (int)(float)(v29 + v23);
      }
      r.y1 = v30;
      if ( Scaleform::Render::Rect<int>::IntersectRect(
             &this->ViewRect,
             &this->ViewRect,
             (const Scaleform::Render::Rect<int> *)&r) )
      {
        v33 = HIBYTE(v41);
      }
      else
      {
        this->ViewRect.x1 = 0;
        this->ViewRect.y1 = 0;
        this->ViewRect.x2 = 0;
        this->ViewRect.y2 = 0;
        this->HALState &= ~0x20u;
        v33 = 0;
      }
      this->updateViewport(this);
      if ( this->MaskStackTop == 1 && v33 )
      {
        if ( this->StencilAvailable )
        {
          ((void (__stdcall *)(ID3D11DeviceContext *, ID3D11DepthStencilView *, int, _DWORD, _DWORD))this->pDeviceContext->ClearDepthStencilView)(
            this->pDeviceContext,
            this->pDepthStencilView.pObject,
            2,
            1.0,
            0);
        }
        else if ( this->DepthBufferAvailable )
        {
          ((void (__stdcall *)(ID3D11DeviceContext *, ID3D11DepthStencilView *, int, _DWORD, _DWORD))this->pDeviceContext->ClearDepthStencilView)(
            this->pDeviceContext,
            this->pDepthStencilView.pObject,
            1,
            1.0,
            0);
        }
      }
    }
    else if ( this->MaskStackTop == 1 && HIBYTE(v41) )
    {
      if ( this->StencilAvailable )
      {
        this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, this->DepthStencilStates[1], v45);
        this->drawMaskClearRectangles(
          this,
          (const Scaleform::Render::MatrixPoolImpl::HMatrix *)prim[1].pLib,
          (unsigned int)prim[2].__vftable);
      }
      else
      {
        v45 = (unsigned int)prim[2].__vftable;
        for ( Size = 0; Size < v45; ++Size )
        {
          v34 = (Scaleform::Render::MatrixPoolImpl::DataHeader *)**((_DWORD **)&prim[1].pLib->__vftable + Size);
          v40.pData = (Scaleform::String::DataDesc *)&pr;
          v35 = (Scaleform::Render::Matrix2x4<float> *)(&v34[1].RefCount
                                                      + 4 * (unsigned __int8)byte_9B2B74[5 * (v34->Format & 0xF)]);
          pr.x1 = 0.0;
          pr.y1 = 0.0;
          LODWORD(pr.x2) = clear_value;
          LODWORD(pr.y2) = clear_value;
          Scaleform::Render::Matrix2x4<float>::EncloseTransform(
            v35,
            (Scaleform::Render::Rect<float> *)&v48,
            (__m128 *)&pr);
          LODWORD(r.x2) = (int)v48.M[0][2];
          v36 = this->VP.Left;
          LODWORD(r.x2) = v36 + (int)v48.M[0][2];
          LODWORD(r.y1) = (int)v48.M[0][1];
          LODWORD(r.y2) = (int)v48.M[0][3];
          v37 = this->VP.Top;
          LODWORD(r.y1) = v37 + (int)v48.M[0][1];
          LODWORD(r.y2) = v37 + (int)v48.M[0][3];
          LODWORD(r.x1) = v36 + (int)v48.M[0][0];
          if ( Scaleform::Render::Rect<int>::IntersectRect(
                 (Scaleform::Render::Rect<int> *)&r,
                 (Scaleform::Render::Rect<int> *)&r,
                 &this->ViewRect) )
          {
            ((void (__stdcall *)(ID3D11DeviceContext *, ID3D11DepthStencilView *, int, _DWORD, _DWORD))this->pDeviceContext->ClearDepthStencilView)(
              this->pDeviceContext,
              this->pDepthStencilView.pObject,
              1,
              1.0,
              0);
          }
        }
      }
    }
    if ( this->StencilAvailable )
    {
      this->pDeviceContext->OMSetDepthStencilState(
        this->pDeviceContext,
        this->DepthStencilStates[3],
        this->MaskStackTop - 1);
      ++this->AccumulatedStats.Masks;
      return;
    }
    if ( this->DepthBufferAvailable )
    {
      v38 = this->MaskStackTop;
      pDeviceContext = this->pDeviceContext;
      if ( v38 == 1 )
      {
        pDeviceContext->OMSetDepthStencilState(pDeviceContext, this->DepthStencilStates[4], 0);
        ++this->AccumulatedStats.Masks;
        return;
      }
      pDeviceContext->OMSetDepthStencilState(pDeviceContext, this->DepthStencilStates[7], v38 - 1);
    }
    ++this->AccumulatedStats.Masks;
  }
}
