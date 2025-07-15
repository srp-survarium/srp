void __usercall Scaleform::Render::D3D1x::ShaderInterface::BeginScene(
        Scaleform::Render::D3D1x::ShaderInterface *this@<ecx>,
        _DWORD *a2@<edi>)
{
  int v2; // esi

  v2 = *(_DWORD *)(a2[1096] + 63796);
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 276))(v2, 0, 0, 0);
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 256))(v2, 0, 0, 0);
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 92))(v2, 0, 0, 0);
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 240))(v2, 0, 0, 0);
  a2[1102] = 0;
  a2[1104] = 0;
  a2[1103] = 0;
}
