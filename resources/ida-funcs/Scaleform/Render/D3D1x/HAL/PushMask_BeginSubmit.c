void __thiscall Scaleform::Render::D3D1x::HAL::PushMask_BeginSubmit(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::GFx::Resource *prim)
{
  Scaleform::Render::RenderEvent *v3; // eax
  Scaleform::Render::RenderEvent_vtbl *v4; // edi
  Scaleform::String::DataDesc *v5; // ecx
  Scaleform::Render::D3D1x::HAL *v6; // ecx
  bool v7; // zf
  unsigned int MaskStackTop; // ecx
  bool v9; // al
  Scaleform::Render::MaskPrimitive *pObject; // eax
  Scaleform::Render::HAL::MaskStackEntry *v11; // ebx
  Scaleform::Render::MatrixState *v12; // ebx
  Scaleform::GFx::ResourceLibBase_vtbl *v13; // eax
  int v14; // ebx
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // edx
  int v19; // edi
  float v20; // eax
  int Left; // edi
  int Top; // ebx
  Scaleform::GFx::Resource_vtbl *v23; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  unsigned int v28; // ecx
  ID3D11DeviceContext *pDeviceContext; // eax
  Scaleform::String v30; // [esp+30h] [ebp-64h] BYREF
  int v31; // [esp+48h] [ebp-4Ch]
  unsigned int v32; // [esp+4Ch] [ebp-48h]
  Scaleform::GFx::Resource_vtbl *v33; // [esp+50h] [ebp-44h]
  Scaleform::Render::Rect<float> r; // [esp+54h] [ebp-40h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+64h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v36; // [esp+74h] [ebp-20h] BYREF

  v3 = this->GetEvent(this, 6);
  v4 = v3->__vftable;
  v30.pData = v5;
  v32 = (unsigned int)v3;
  Scaleform::String::String(&v30, "Scaleform::Render::D3D1x::HAL::PushMask_BeginSubmit");
  ((void (__thiscall *)(unsigned int, Scaleform::String::DataDesc *))v4->Begin)(v32, v30.pData);
  if ( Scaleform::Render::HAL::checkState(
         this,
         8u,
         (Scaleform::GFx::AS3::Value *)"Scaleform::Render::D3D1x::HAL::PushMask_BeginSubmit") )
  {
    v7 = !this->StencilAvailable;
    this->Profiler.DrawMode = 1;
    if ( !v7 || this->DepthBufferAvailable || Scaleform::Render::D3D1x::HAL::checkMaskBufferCaps(v6, (int)this) )
    {
      this->pDeviceContext->OMSetBlendState(this->pDeviceContext, this->BlendStates[36], 0, -1u);
      MaskStackTop = this->MaskStackTop;
      v9 = (this->HALState & 0x20) != 0;
      HIBYTE(v31) = v9;
      v32 = MaskStackTop;
      if ( MaskStackTop && this->MaskStack.Data.Size > MaskStackTop && v9 && this->StencilAvailable )
      {
        this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, this->DepthStencilStates[2], MaskStackTop);
        pObject = this->MaskStack.Data.Data[this->MaskStackTop].pPrimitive.pObject;
        this->drawMaskClearRectangles(this, pObject->MaskAreas.Data.Data, pObject->MaskAreas.Data.Size);
      }
      Scaleform::ArrayData<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
        &this->MaskStack.Data,
        this->MaskStackTop + 1);
      v11 = &this->MaskStack.Data.Data[this->MaskStackTop];
      if ( prim )
        Scaleform::RefCountImpl::AddRef(prim);
      if ( v11->pPrimitive.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v11->pPrimitive.pObject);
      v11->OldViewportValid = HIBYTE(v31);
      v30.pData = (Scaleform::String::DataDesc *)&this->ViewRect;
      v11->pPrimitive.pObject = (Scaleform::Render::MaskPrimitive *)prim;
      Scaleform::Render::Rect<int>::SetRect(&v11->OldViewRect, (const Scaleform::Render::Rect<int> *)v30.pData);
      ++this->MaskStackTop;
      this->HALState |= 0x40u;
      if ( prim[1].RefCount.Value == 1 && HIBYTE(v31) )
      {
        v12 = this->Matrices.pObject;
        v13 = prim[1].pLib->__vftable;
        if ( v12->OrientationSet )
        {
          Scaleform::Render::Matrix2x4<float>::SetMatrix(
            &v36,
            (const Scaleform::Render::Matrix2x4<float> *)((char *)v13->~Scaleform::GFx::ResourceLibBase
                                                        + 16
                                                        * (unsigned __int8)byte_874214[5
                                                                                     * (*((_BYTE *)v13->~Scaleform::GFx::ResourceLibBase
                                                                                        + 11)
                                                                                      & 0xF)]
                                                        + 16));
          Scaleform::Render::Matrix2x4<float>::Append(&v36, &v12->Orient2D);
          r.x1 = 0.0;
          r.y1 = 0.0;
          r.x2 = s_bm_current_air_resistance;
          r.y2 = s_bm_current_air_resistance;
          Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v36, (__m128 *)&pr, (__m128 *)&r);
          Left = this->VP.Left;
          Top = this->VP.Top;
          LODWORD(r.x1) = Left + (int)pr.x1;
          LODWORD(r.y1) = Top + (int)pr.y1;
          LODWORD(r.x2) = Left + (int)pr.x2;
          LODWORD(v20) = Top + (int)pr.y2;
        }
        else
        {
          v14 = this->VP.Left;
          v15 = (float *)((char *)v13->~Scaleform::GFx::ResourceLibBase
                        + 16
                        * (unsigned __int8)byte_874214[5
                                                     * (*((_BYTE *)v13->~Scaleform::GFx::ResourceLibBase + 11) & 0xF)]
                        + 16);
          v16 = v15[3];
          v17 = v15[7];
          LODWORD(v18) = this->VP.Top + (int)v17;
          v19 = (int)(float)(v16 + *v15);
          LODWORD(v20) = this->VP.Top + (int)(float)(v15[5] + v17);
          LODWORD(r.x1) = v14 + (int)v16;
          r.y1 = v18;
          LODWORD(r.x2) = v14 + v19;
        }
        r.y2 = v20;
        if ( !Scaleform::Render::Rect<int>::IntersectRect(
                &this->ViewRect,
                &this->ViewRect,
                (const Scaleform::Render::Rect<int> *)&r) )
        {
          Scaleform::Render::Rect<int>::Clear(&this->ViewRect);
          this->HALState &= ~0x20u;
          HIBYTE(v31) = 0;
        }
        this->updateViewport(this);
        if ( this->MaskStackTop == 1 && HIBYTE(v31) )
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
      else if ( this->MaskStackTop == 1 && HIBYTE(v31) )
      {
        if ( this->StencilAvailable )
        {
          this->pDeviceContext->OMSetDepthStencilState(this->pDeviceContext, this->DepthStencilStates[1], v32);
          this->drawMaskClearRectangles(
            this,
            (const Scaleform::Render::MatrixPoolImpl::HMatrix *)prim[1].pLib,
            (unsigned int)prim[2].__vftable);
        }
        else
        {
          v23 = prim[2].__vftable;
          v32 = 0;
          v33 = v23;
          if ( v23 )
          {
            do
            {
              v24 = **((_DWORD **)&prim[1].pLib->__vftable + v32);
              v30.pData = (Scaleform::String::DataDesc *)&pr;
              v25 = 16 * ((unsigned __int8)byte_874214[5 * (*(_BYTE *)(v24 + 11) & 0xF)] + 1);
              pr.x1 = 0.0;
              pr.y1 = 0.0;
              pr.x2 = s_bm_current_air_resistance;
              pr.y2 = s_bm_current_air_resistance;
              Scaleform::Render::Matrix2x4<float>::EncloseTransform(
                (Scaleform::Render::Matrix2x4<float> *)(v24 + v25),
                (__m128 *)&v36,
                (__m128 *)&pr);
              v26 = this->VP.Left;
              LODWORD(r.x2) = v26 + (int)v36.M[0][2];
              LODWORD(r.y2) = (int)v36.M[0][3];
              v27 = this->VP.Top;
              LODWORD(r.y2) = v27 + (int)v36.M[0][3];
              LODWORD(r.x1) = v26 + (int)v36.M[0][0];
              LODWORD(r.y1) = v27 + (int)v36.M[0][1];
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
              ++v32;
            }
            while ( v32 < (unsigned int)v33 );
          }
        }
      }
      if ( this->StencilAvailable )
      {
        this->pDeviceContext->OMSetDepthStencilState(
          this->pDeviceContext,
          this->DepthStencilStates[3],
          this->MaskStackTop - 1);
      }
      else if ( this->DepthBufferAvailable )
      {
        v28 = this->MaskStackTop;
        pDeviceContext = this->pDeviceContext;
        if ( v28 == 1 )
          pDeviceContext->OMSetDepthStencilState(pDeviceContext, this->DepthStencilStates[4], 0);
        else
          pDeviceContext->OMSetDepthStencilState(pDeviceContext, this->DepthStencilStates[7], v28 - 1);
      }
      ++this->AccumulatedStats.Masks;
    }
  }
}
