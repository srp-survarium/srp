unsigned __int64 __thiscall Scaleform::Render::D3D1x::RenderSync::SetFence(Scaleform::Render::D3D1x::RenderSync *this)
{
  if ( this->pNextEndFrameFence )
    this->pNextEndFrameFence->AddRef(this->pNextEndFrameFence);
  return (int)this->pNextEndFrameFence;
}
