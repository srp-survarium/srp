char __thiscall Scaleform::Render::HAL::BeginScene(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // eax
  int v3; // ecx
  Scaleform::Render::RenderEvent *v4; // ebx
  void (__thiscall **p_Begin)(Scaleform::Render::RenderEvent *, Scaleform::String); // edi
  Scaleform::Render::TextureManager *v7; // eax
  unsigned __int64 NextProfileMode; // [esp-8h] [ebp-14h] BYREF

  v2 = this->GetEvent(this, 2);
  HIDWORD(NextProfileMode) = v3;
  v4 = v2;
  p_Begin = &v2->Begin;
  Scaleform::String::String(
    (Scaleform::String *)&NextProfileMode + 1,
    (const __m128i *)"Scaleform::Render::HAL::BeginScene");
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, _DWORD))*p_Begin)(v4, HIDWORD(NextProfileMode));
  if ( (this->HALState & 2) == 0 )
    return 0;
  if ( this->GetTextureManager(this) )
  {
    v7 = this->GetTextureManager(this);
    v7->BeginScene(v7);
  }
  NextProfileMode = this->NextProfileMode;
  this->CurrentBlendState.Mode = Blend_None;
  this->CurrentBlendState.SourceAc = 0;
  this->CurrentBlendState.ForceAc = 0;
  Scaleform::Render::ProfileViews::SetProfileViews(&this->Profiler, NextProfileMode);
  this->HALState |= 4u;
  return 1;
}
