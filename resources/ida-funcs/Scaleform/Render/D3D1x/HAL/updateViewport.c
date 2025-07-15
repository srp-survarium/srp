void __thiscall Scaleform::Render::D3D1x::HAL::updateViewport(Scaleform::Render::D3D1x::HAL *this)
{
  int Top; // edx
  int Left; // ecx
  int x2; // eax
  int y2; // edi
  ID3D11DeviceContext *pDeviceContext; // esi
  float v7[2]; // [esp+8h] [ebp-18h] BYREF
  float v8; // [esp+10h] [ebp-10h]
  float v9; // [esp+14h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-8h]
  int v11; // [esp+1Ch] [ebp-4h]

  Top = 0;
  Left = 0;
  x2 = 0;
  y2 = 0;
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
    Scaleform::Render::Rect<int>::SetRect(
      &this->Matrices.pObject->Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::Scaleform::Render::HAL::ViewRect,
      &this->ViewRect);
    this->Matrices.pObject->UVPOChanged = 1;
    if ( (this->HALState & 0x10) != 0 )
    {
      Left = this->VP.Left;
      Top = this->VP.Top;
      x2 = Left + this->VP.Width;
      y2 = Top + this->VP.Height;
    }
    else
    {
      Left = this->ViewRect.x1;
      Top = this->ViewRect.y1;
      x2 = this->ViewRect.x2;
      y2 = this->ViewRect.y2;
    }
  }
  v7[0] = (float)Left;
  v7[1] = (float)Top;
  v8 = (float)(x2 - Left);
  v9 = (float)(y2 - Top);
  if ( v8 <= s_bm_current_air_resistance )
    v8 = s_bm_current_air_resistance;
  if ( (float)(y2 - Top) <= s_bm_current_air_resistance )
    v9 = s_bm_current_air_resistance;
  pDeviceContext = this->pDeviceContext;
  v10 = 0;
  v11 = 0;
  pDeviceContext->RSSetViewports(pDeviceContext, 1u, (const D3D11_VIEWPORT *)v7);
}
