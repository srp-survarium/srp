bool __thiscall Scaleform::Render::D3D1x::RenderSync::EndFrame(Scaleform::Render::D3D1x::RenderSync *this)
{
  bool result; // al

  if ( this->pDevice.pObject && this->pDeviceContext.pObject )
  {
    result = Scaleform::Render::RenderSync::EndFrame(this);
    if ( !result )
      return result;
    if ( this->pNextEndFrameFence )
    {
      this->pDeviceContext.pObject->End(this->pDeviceContext.pObject, this->pNextEndFrameFence);
      this->pNextEndFrameFence->Release(this->pNextEndFrameFence);
    }
    this->pNextEndFrameFence = 0;
  }
  return 1;
}
