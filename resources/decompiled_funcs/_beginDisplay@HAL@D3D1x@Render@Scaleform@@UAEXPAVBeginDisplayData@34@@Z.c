void __thiscall Scaleform::Render::D3D1x::HAL::beginDisplay(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::BeginDisplayData *data)
{
  Scaleform::Render::RenderEvent *v3; // eax
  Scaleform::String::DataDesc *v4; // ecx
  Scaleform::Render::RenderEvent *v5; // ebx
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *); // edi
  Scaleform::String v7; // [esp-4h] [ebp-10h] BYREF

  v3 = this->GetEvent(this, 4);
  v7.pData = v4;
  v5 = v3;
  p_Begin = (void (__thiscall **)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))&v3->Begin;
  Scaleform::String::String(&v7, "Scaleform::Render::D3D1x::HAL::beginDisplay");
  (*p_Begin)(v5, v7.pData);
  this->pDeviceContext->RSSetState(this->pDeviceContext, this->RasterStates[this->RasterMode]);
  Scaleform::Render::HAL::beginDisplay(
    this,
    (Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2> >::NodeType *)data);
}
