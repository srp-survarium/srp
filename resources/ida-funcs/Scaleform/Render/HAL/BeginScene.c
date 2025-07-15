bool __thiscall Scaleform::Render::HAL::BeginScene(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // eax
  Scaleform::String::DataDesc *v3; // ecx
  Scaleform::Render::RenderEvent *v4; // ebx
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *); // edi
  bool result; // al
  Scaleform::Render::TextureManager *v7; // eax
  Scaleform::String v8; // [esp-4h] [ebp-10h] BYREF

  v2 = this->GetEvent(this, 2);
  v8.pData = v3;
  v4 = v2;
  p_Begin = (void (__thiscall **)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))&v2->Begin;
  Scaleform::String::String(&v8, "Scaleform::Render::HAL::BeginScene");
  (*p_Begin)(v4, v8.pData);
  if ( (this->HALState & 2) == 0 )
    return 0;
  if ( this->GetTextureManager(this) )
  {
    v7 = this->GetTextureManager(this);
    v7->BeginScene(v7);
  }
  this->HALState |= 4u;
  result = 1;
  this->CurrentBlendState.Mode = Blend_None;
  this->CurrentBlendState.SourceAc = 0;
  this->CurrentBlendState.ForceAc = 0;
  return result;
}
