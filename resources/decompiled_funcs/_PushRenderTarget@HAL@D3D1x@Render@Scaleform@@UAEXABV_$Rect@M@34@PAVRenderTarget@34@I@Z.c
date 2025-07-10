void __thiscall Scaleform::Render::D3D1x::HAL::PushRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::Rect<float> *frameRect,
        Scaleform::Render::RenderTarget *prt,
        char flags)
{
  Scaleform::Render::RenderEvent *v5; // eax
  int v6; // ecx
  Scaleform::Render::RenderEvent *v7; // ebx
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String); // esi
  unsigned int v9; // ecx
  int y1; // eax
  int x1; // edx
  __int64 v12; // xmm0_8
  int x2; // ecx
  __int64 v14; // xmm0_8
  Scaleform::Render::MatrixState *pObject; // eax
  int y2; // edx
  __int64 v17; // xmm0_8
  const vostok::math::float4x4 *v18; // xmm1_4
  Scaleform::Render::Matrix2x4<float> *p_Orient2D; // eax
  Scaleform::Render::Matrix4x4<float> *p_Orient3D; // esi
  unsigned int v21; // ecx
  Scaleform::ArrayLH<Scaleform::Render::HAL::RenderTargetEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *v22; // edi
  int v23; // edx
  Scaleform::Render::D3D1x::TextureManager *v24; // edx
  ID3D11RenderTargetView **v25; // esi
  ID3D11DeviceContext *pDeviceContext; // eax
  ID3D11RenderTargetView *v27; // edx
  unsigned int Width; // esi
  int v29; // edx
  int v30; // eax
  int v31; // ecx
  unsigned int Height; // esi
  float v33; // esi
  int Top; // ecx
  int Left; // edx
  Scaleform::Render::Rect<int> *p_ViewRectOriginal; // eax
  int v37; // ecx
  int v38; // edx
  void (__thiscall *updateViewport)(struct Scaleform::Render::D3D1x::HAL *); // eax
  unsigned int Size; // ecx
  Scaleform::ArrayLH<Scaleform::Render::HAL::RenderTargetEntry,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_RenderTargetStack; // edi
  Scaleform::Render::HAL::RenderTargetEntry entry; // [esp+C58h] [ebp-640h] BYREF
  __int64 v43; // [esp+F54h] [ebp-344h]
  __int64 v44; // [esp+F5Ch] [ebp-33Ch]
  __int64 v45; // [esp+F64h] [ebp-334h]
  __int64 v46; // [esp+F6Ch] [ebp-32Ch]
  __int64 v47; // [esp+F74h] [ebp-324h]
  __int64 v48; // [esp+F7Ch] [ebp-31Ch]
  float v49[6]; // [esp+F88h] [ebp-310h] BYREF
  __int64 views; // [esp+FA0h] [ebp-2F8h] BYREF
  Scaleform::Render::HAL::RenderTargetEntry __that; // [esp+FA8h] [ebp-2F0h] BYREF

  v5 = this->GetEvent(this, 11);
  *((_DWORD *)&entry.OldViewport + 11) = v6;
  v7 = v5;
  p_Begin = &v5->Begin;
  Scaleform::String::String(
    (Scaleform::String *)&entry.OldViewport + 11,
    "Scaleform::Render::D3D1x::HAL::PushRenderTarget");
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, _DWORD))*p_Begin)(v7, *((_DWORD *)&entry.OldViewport + 11));
  this->HALState |= 0x10u;
  Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(&__that);
  if ( prt )
    prt->AddRef(prt);
  if ( __that.pRenderTarget.pObject )
    __that.pRenderTarget.pObject->Release(__that.pRenderTarget.pObject);
  v9 = this->VP.Flags;
  y1 = this->ViewRect.y1;
  x1 = this->ViewRect.x1;
  *(_QWORD *)&__that.OldViewport.BufferWidth = *(_QWORD *)&this->VP.BufferWidth;
  *(_QWORD *)&__that.OldViewport.Left = *(_QWORD *)&this->VP.Left;
  v12 = *(_QWORD *)&this->VP.Width;
  __that.OldViewport.Flags = v9;
  x2 = this->ViewRect.x2;
  *(_QWORD *)&__that.OldViewport.Width = v12;
  v14 = *(_QWORD *)&this->VP.ScissorLeft;
  __that.OldViewRect.y1 = y1;
  pObject = this->Matrices.pObject;
  __that.OldViewRect.x1 = x1;
  y2 = this->ViewRect.y2;
  *(_QWORD *)&__that.OldViewport.ScissorLeft = v14;
  v17 = *(_QWORD *)&this->VP.ScissorWidth;
  __that.OldViewRect.x2 = x2;
  __that.pRenderTarget.pObject = prt;
  *(_QWORD *)&__that.OldViewport.ScissorWidth = v17;
  __that.OldViewRect.y2 = y2;
  Scaleform::Render::MatrixState::CopyFrom(&__that.OldMatrixState, pObject);
  v18 = clear_value;
  p_Orient2D = &this->Matrices.pObject->Orient2D;
  LODWORD(p_Orient2D->M[0][0]) = clear_value;
  p_Orient2D->M[0][1] = 0.0;
  p_Orient2D->M[0][2] = 0.0;
  p_Orient2D->M[0][3] = 0.0;
  p_Orient2D->M[1][0] = 0.0;
  LODWORD(p_Orient2D->M[1][1]) = v18;
  p_Orient2D->M[1][2] = 0.0;
  p_Orient2D->M[1][3] = 0.0;
  p_Orient3D = &this->Matrices.pObject->Orient3D;
  memset((int)p_Orient3D, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  LODWORD(v17) = clear_value;
  LODWORD(p_Orient3D->M[0][0]) = clear_value;
  LODWORD(p_Orient3D->M[1][1]) = v17;
  LODWORD(p_Orient3D->M[2][2]) = v17;
  LODWORD(p_Orient3D->M[3][3]) = v17;
  this->Matrices.pObject->SetUserMatrix(this->Matrices.pObject, &Scaleform::Render::Matrix2x4<float>::Identity);
  if ( prt )
  {
    v24 = this->pTextureManager.pObject;
    HIDWORD(v43) = prt->pRenderTargetData;
    views = 0;
    Scaleform::Render::D3D1x::TextureManager::SetSamplerState(2u, v24, 0, (ID3D11ShaderResourceView **)&views, 0);
    v25 = (ID3D11RenderTargetView **)(HIDWORD(v43) + 16);
    this->pDeviceContext->OMSetRenderTargets(
      this->pDeviceContext,
      1u,
      (ID3D11RenderTargetView *const *)(HIDWORD(v43) + 16),
      *(ID3D11DepthStencilView **)(HIDWORD(v43) + 20));
    ++this->AccumulatedStats.RTChanges;
    this->StencilChecked = 0;
    if ( (flags & 1) == 0 )
    {
      pDeviceContext = this->pDeviceContext;
      *((_DWORD *)&entry.OldViewport + 11) = v49;
      v27 = *v25;
      *(_OWORD *)v49 = 0;
      pDeviceContext->ClearRenderTargetView(pDeviceContext, v27, v49);
    }
    Width = prt->BufferSize.Width;
    v29 = prt->ViewRect.x1;
    v30 = prt->ViewRect.x2 - v29;
    v49[1] = *(float *)&prt->ViewRect.y1;
    v31 = prt->ViewRect.y2;
    LODWORD(v44) = Width;
    Height = prt->BufferSize.Height;
    LODWORD(v45) = v29;
    HIDWORD(v44) = Height;
    v33 = v49[1];
    *(_QWORD *)&this->VP.BufferWidth = v44;
    LODWORD(v46) = v30;
    HIDWORD(v46) = v31 - LODWORD(v33);
    *((float *)&v45 + 1) = v33;
    *(_QWORD *)&this->VP.Left = v45;
    *(_QWORD *)&this->VP.Width = v46;
    v47 = 0;
    *(_QWORD *)&this->VP.ScissorLeft = 0;
    v48 = 0;
    *(_QWORD *)&this->VP.ScissorWidth = 0;
    this->VP.Flags = 0;
    this->ViewRect.x1 = (int)frameRect->x1;
    this->ViewRect.y1 = (int)frameRect->y1;
    Top = __that.OldViewport.Top;
    this->ViewRect.x2 = (int)frameRect->x2;
    Left = __that.OldViewport.Left;
    this->ViewRect.y2 = (int)frameRect->y2;
    p_ViewRectOriginal = &this->Matrices.pObject->ViewRectOriginal;
    v37 = -Top;
    p_ViewRectOriginal->y1 += v37;
    p_ViewRectOriginal->y2 += v37;
    v38 = -Left;
    p_ViewRectOriginal->x1 += v38;
    p_ViewRectOriginal->x2 += v38;
    this->Matrices.pObject->UVPOChanged = 1;
    updateViewport = this->updateViewport;
    this->HALState |= 0x20u;
    updateViewport(this);
    Size = this->RenderTargetStack.Data.Size;
    p_RenderTargetStack = &this->RenderTargetStack;
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &p_RenderTargetStack->Data,
      p_RenderTargetStack,
      Size + 1);
    if ( &p_RenderTargetStack->Data.Data[p_RenderTargetStack->Data.Size] != (Scaleform::Render::HAL::RenderTargetEntry *)752 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(
        &p_RenderTargetStack->Data.Data[p_RenderTargetStack->Data.Size - 1],
        &__that);
  }
  else
  {
    v21 = this->RenderTargetStack.Data.Size;
    v22 = &this->RenderTargetStack;
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &v22->Data,
      v22,
      v21 + 1);
    v23 = v22->Data.Size;
    if ( &v22->Data.Data[v23] != (Scaleform::Render::HAL::RenderTargetEntry *)752 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(&v22->Data.Data[v23 - 1], &__that);
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(&__that.OldMatrixState);
  if ( __that.pRenderTarget.pObject )
    __that.pRenderTarget.pObject->Release(__that.pRenderTarget.pObject);
}
