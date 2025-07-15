void __thiscall Scaleform::Render::D3D1x::HAL::PushRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::Rect<float> *frameRect,
        Scaleform::Render::RenderTarget *prt,
        char flags)
{
  Scaleform::Render::RenderEvent *v5; // eax
  Scaleform::String::DataDesc *v6; // ecx
  Scaleform::Render::RenderEvent *v7; // edi
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *); // esi
  int x1; // eax
  float v10; // xmm1_4
  Scaleform::Render::Matrix2x4<float> *p_Orient2D; // eax
  Scaleform::Render::Matrix4x4<float> *p_Orient3D; // edi
  float v13; // xmm0_4
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > > *v14; // ecx
  ID3D11RenderTargetView **v15; // esi
  int Left; // edx
  const void *v17; // eax
  int Top; // ecx
  Scaleform::Render::Rect<int> *p_ViewRectOriginal; // eax
  int v20; // ecx
  int v21; // edx
  Scaleform::Render::D3D1x::HAL_vtbl *v22; // eax
  Scaleform::String v23; // [esp-4h] [ebp-354h] BYREF
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // [esp+18h] [ebp-338h]
  ID3D11ShaderResourceView *views[2]; // [esp+1Ch] [ebp-334h] BYREF
  _BYTE v26[16]; // [esp+24h] [ebp-32Ch] BYREF
  Scaleform::Render::Viewport v27; // [esp+34h] [ebp-31Ch] BYREF
  Scaleform::Render::HAL::RenderTargetEntry val; // [esp+60h] [ebp-2F0h] BYREF

  v5 = this->GetEvent(this, 11);
  v23.pData = v6;
  v7 = v5;
  p_Begin = (void (__thiscall **)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))&v5->Begin;
  Scaleform::String::String(&v23, "Scaleform::Render::D3D1x::HAL::PushRenderTarget");
  (*p_Begin)(v7, v23.pData);
  this->HALState |= 0x10u;
  Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(&val);
  if ( prt )
    prt->AddRef(prt);
  if ( val.pRenderTarget.pObject )
    val.pRenderTarget.pObject->Release(val.pRenderTarget.pObject);
  x1 = this->ViewRect.x1;
  val.pRenderTarget.pObject = prt;
  v23.pData = (Scaleform::String::DataDesc *)this->Matrices.pObject;
  qmemcpy(&val.OldViewport, &this->VP, sizeof(val.OldViewport));
  val.OldViewRect.x1 = x1;
  val.OldViewRect.y1 = this->ViewRect.y1;
  val.OldViewRect.x2 = this->ViewRect.x2;
  val.OldViewRect.y2 = this->ViewRect.y2;
  Scaleform::Render::MatrixState::CopyFrom(&val.OldMatrixState, (Scaleform::Render::MatrixState *)v23.pData);
  v10 = s_bm_current_air_resistance;
  p_Orient2D = &this->Matrices.pObject->Orient2D;
  p_Orient2D->M[0][0] = s_bm_current_air_resistance;
  p_Orient2D->M[0][1] = 0.0;
  p_Orient2D->M[0][2] = 0.0;
  p_Orient2D->M[0][3] = 0.0;
  p_Orient2D->M[1][0] = 0.0;
  p_Orient2D->M[1][1] = v10;
  p_Orient2D->M[1][2] = 0.0;
  p_Orient2D->M[1][3] = 0.0;
  p_Orient3D = &this->Matrices.pObject->Orient3D;
  memset((int)p_Orient3D, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  v13 = s_bm_current_air_resistance;
  p_Orient3D->M[0][0] = s_bm_current_air_resistance;
  p_Orient3D->M[1][1] = v13;
  p_Orient3D->M[2][2] = v13;
  p_Orient3D->M[3][3] = v13;
  this->Matrices.pObject->SetUserMatrix(this->Matrices.pObject, &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( prt )
  {
    pRenderTargetData = prt->pRenderTargetData;
    views[0] = 0;
    views[1] = 0;
    Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, this->pTextureManager.pObject, 0, views, 0);
    v23.pData = (Scaleform::String::DataDesc *)pRenderTargetData[1].pBuffer;
    v15 = (ID3D11RenderTargetView **)&pRenderTargetData[1];
    this->pDeviceContext->OMSetRenderTargets(
      this->pDeviceContext,
      1u,
      (ID3D11RenderTargetView *const *)&pRenderTargetData[1],
      (ID3D11DepthStencilView *)v23.pData);
    ++this->AccumulatedStats.RTChanges;
    this->StencilChecked = 0;
    if ( (flags & 1) == 0 )
    {
      memset(v26, 0, sizeof(v26));
      v23.pData = (Scaleform::String::DataDesc *)v26;
      this->pDeviceContext->ClearRenderTargetView(this->pDeviceContext, *v15, (const float *)v26);
    }
    Scaleform::Render::Viewport::Viewport(
      &v27,
      prt->BufferSize.Width,
      prt->BufferSize.Height,
      prt->ViewRect.x1,
      prt->ViewRect.y1,
      prt->ViewRect.x2 - prt->ViewRect.x1,
      prt->ViewRect.y2 - prt->ViewRect.y1,
      0);
    Left = val.OldViewport.Left;
    qmemcpy(&this->VP, v17, sizeof(this->VP));
    this->ViewRect.x1 = (int)frameRect->x1;
    this->ViewRect.y1 = (int)frameRect->y1;
    this->ViewRect.x2 = (int)frameRect->x2;
    Top = val.OldViewport.Top;
    this->ViewRect.y2 = (int)frameRect->y2;
    p_ViewRectOriginal = &this->Matrices.pObject->ViewRectOriginal;
    v20 = -Top;
    p_ViewRectOriginal->y1 += v20;
    p_ViewRectOriginal->y2 += v20;
    v21 = -Left;
    p_ViewRectOriginal->x1 += v21;
    p_ViewRectOriginal->x2 += v21;
    this->Matrices.pObject->UVPOChanged = 1;
    v22 = this->__vftable;
    this->HALState |= 0x20u;
    v22->updateViewport(this);
  }
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>>::PushBack(
    v14,
    &this->RenderTargetStack.Data,
    &val);
  Scaleform::Render::HAL::RenderTargetEntry::~RenderTargetEntry(&val);
}
