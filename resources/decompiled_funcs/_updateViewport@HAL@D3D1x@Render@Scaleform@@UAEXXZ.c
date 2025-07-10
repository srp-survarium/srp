void __thiscall Scaleform::Render::D3D1x::HAL::updateViewport(Scaleform::Render::D3D1x::HAL *this)
{
  int Left; // ecx
  int Top; // edx
  int v4; // eax
  int v5; // edi
  int y2; // ecx
  int x2; // edx
  int y1; // ebx
  Scaleform::Render::Rect<int> *p_ViewRect; // eax
  ID3D11DeviceContext *pDeviceContext; // esi
  D3D11_VIEWPORT vp; // [esp+18h] [ebp-18h] BYREF

  Left = 0;
  Top = 0;
  v4 = 0;
  v5 = 0;
  if ( (this->HALState & 0x20) != 0 )
  {
    this->CalcHWViewMatrix(
      this,
      0,
      &this->Matrices.pObject->View2D,
      &this->ViewRect,
      this->ViewRect.x1 - this->VP.Left,
      this->ViewRect.y1 - this->VP.Top);
    ((void (__stdcall *)(Scaleform::Render::Matrix2x4<float> *))this->Matrices.pObject->SetUserMatrix)(&this->Matrices.pObject->User);
    y2 = this->ViewRect.y2;
    x2 = this->ViewRect.x2;
    y1 = this->ViewRect.y1;
    p_ViewRect = &this->Matrices.pObject->ViewRect;
    p_ViewRect->x1 = this->ViewRect.x1;
    p_ViewRect->y1 = y1;
    p_ViewRect->x2 = x2;
    p_ViewRect->y2 = y2;
    this->Matrices.pObject->UVPOChanged = 1;
    if ( (this->HALState & 0x10) != 0 )
    {
      Left = this->VP.Left;
      Top = this->VP.Top;
      v4 = Left + this->VP.Width;
      v5 = Top + this->VP.Height;
    }
    else
    {
      Left = this->ViewRect.x1;
      Top = this->ViewRect.y1;
      v4 = this->ViewRect.x2;
      v5 = this->ViewRect.y2;
    }
  }
  vp.TopLeftX = (float)Left;
  vp.TopLeftY = (float)Top;
  vp.Width = (float)(v4 - Left);
  vp.Height = (float)(v5 - Top);
  if ( vp.Width <= *(float *)&clear_value )
    LODWORD(vp.Width) = clear_value;
  if ( (float)(v5 - Top) <= *(float *)&clear_value )
    LODWORD(vp.Height) = clear_value;
  pDeviceContext = this->pDeviceContext;
  vp.MinDepth = 0.0;
  vp.MaxDepth = 0.0;
  pDeviceContext->RSSetViewports(pDeviceContext, 1u, &vp);
}
