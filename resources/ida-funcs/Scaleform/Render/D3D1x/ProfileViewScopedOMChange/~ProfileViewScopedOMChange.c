void __usercall Scaleform::Render::D3D1x::ProfileViewScopedOMChange::~ProfileViewScopedOMChange(
        Scaleform::Render::D3D1x::ProfileViewScopedOMChange *this@<ecx>,
        int a2@<esi>)
{
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(a2 + 4) + 140))(
    *(_DWORD *)(a2 + 4),
    *(_DWORD *)(a2 + 8),
    0,
    -1);
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a2 + 4) + 144))(
    *(_DWORD *)(a2 + 4),
    *(_DWORD *)(a2 + 12),
    *(_DWORD *)(a2 + 16));
  **(_BYTE **)a2 = 0;
}
