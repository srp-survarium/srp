void __usercall Scaleform::Render::D3D1x::MeshCache::Reset(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  int v4; // eax
  Scaleform::Render::D3D1x::MeshCache *v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax

  v3 = *(_DWORD *)(a2 + 276);
  if ( v3 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
  *(_DWORD *)(a2 + 276) = 0;
  v4 = *(_DWORD *)(a2 + 280);
  if ( v4 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(*(_DWORD *)(a2 + 280));
  *(_DWORD *)(a2 + 280) = 0;
  Scaleform::Render::RenderSync::ReleaseOutstandingFrames((Scaleform::Render::RenderSync *)(a2 + 176));
  if ( *(_DWORD *)(a2 + 88) )
    Scaleform::Render::D3D1x::MeshCache::destroyBuffers(v5, a2, AT_None);
  v6 = *(_DWORD *)(a2 + 388);
  if ( v6 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 8))(*(_DWORD *)(a2 + 388));
  *(_DWORD *)(a2 + 388) = 0;
  v7 = *(_DWORD *)(a2 + 88);
  if ( v7 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(*(_DWORD *)(a2 + 88));
  *(_DWORD *)(a2 + 88) = 0;
  v8 = *(_DWORD *)(a2 + 92);
  if ( v8 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 8))(*(_DWORD *)(a2 + 92));
  *(_DWORD *)(a2 + 92) = 0;
  Scaleform::Render::MeshStagingBuffer::Reset((Scaleform::Render::MeshStagingBuffer *)(a2 + 60));
}
