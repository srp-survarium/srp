void __thiscall Scaleform::Render::D3D1x::RenderSync::ReleaseFence(
        Scaleform::Render::D3D1x::RenderSync *this,
        unsigned __int64 handle)
{
  if ( (_DWORD)handle )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)handle + 8))(handle);
}
