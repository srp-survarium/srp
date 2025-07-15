bool __thiscall Scaleform::Render::D3D1x::RenderSync::IsPending(
        Scaleform::Render::D3D1x::RenderSync *this,
        Scaleform::Render::FenceType waitType,
        unsigned __int64 handle,
        const Scaleform::Render::FenceFrame *parent)
{
  if ( !(_DWORD)handle
    || (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
  {
    return 0;
  }
  if ( (ID3D11Query *)handle == this->pNextEndFrameFence )
    return 1;
  return this->pDeviceContext.pObject->GetData(this->pDeviceContext.pObject, (ID3D11Asynchronous *)handle, 0, 0, 1u) != 0;
}
