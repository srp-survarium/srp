void __usercall Scaleform::Render::D3D1x::VertexShader::Shutdown(
        Scaleform::Render::D3D1x::VertexShader *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 4));
  *(_DWORD *)(a2 + 4) = 0;
}
