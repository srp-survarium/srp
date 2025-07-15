char __thiscall Scaleform::Render::HAL::BeginFrame(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // eax
  Scaleform::String::DataDesc *v3; // ecx
  Scaleform::Render::RenderEvent *v4; // ebx
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *); // edi
  unsigned int HALState; // eax
  Scaleform::Render::HAL_vtbl *v8; // edx
  Scaleform::Render::RenderQueueProcessor *v9; // eax
  Scaleform::Render::MeshCache *v10; // eax
  Scaleform::Render::TextureManager *v11; // eax
  Scaleform::String v12; // [esp-4h] [ebp-10h] BYREF

  v2 = this->GetEvent(this, 1);
  v12.pData = v3;
  v4 = v2;
  p_Begin = (void (__thiscall **)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))&v2->Begin;
  Scaleform::String::String(&v12, "Scaleform::Render::HAL::BeginFrame");
  (*p_Begin)(v4, v12.pData);
  HALState = this->HALState;
  if ( (HALState & 1) == 0 || (HALState & 0x2000) != 0 )
    return 0;
  v8 = this->__vftable;
  this->HALState = HALState | 2;
  v9 = v8->GetRQProcessor(this);
  Scaleform::Render::RenderQueueProcessor::BeginFrame(v9);
  v10 = this->GetMeshCache(this);
  v10->BeginFrame(v10);
  v11 = this->GetTextureManager(this);
  v11->BeginFrame(v11);
  return 1;
}
