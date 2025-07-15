void __userpurge Scaleform::Render::D3D1x::ShaderConstantRange::Finish(
        Scaleform::Render::D3D1x::ShaderConstantRange *this@<ecx>,
        int a2@<esi>,
        bool bfragment,
        char a4)
{
  int v4; // ecx
  int v5; // ecx
  int v6; // [esp-8h] [ebp-10h]
  int v7; // [esp+4h] [ebp-4h]

  v4 = *(_DWORD *)(a2 + 16);
  if ( v4 )
  {
    (*(void (__stdcall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)(*(_DWORD *)(a2 + 20) + 63956) + 60))(
      *(_DWORD *)(*(_DWORD *)(a2 + 20) + 63956),
      v4,
      0,
      v7);
    v5 = **(_DWORD **)(*(_DWORD *)(a2 + 20) + 63956);
    v6 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 63956);
    if ( a4 )
      (*(void (__stdcall **)(int, _DWORD, int))(v5 + 64))(v6, 0, 1);
    else
      (*(void (__stdcall **)(int, _DWORD, int))(v5 + 28))(v6, 0, 1);
  }
}
