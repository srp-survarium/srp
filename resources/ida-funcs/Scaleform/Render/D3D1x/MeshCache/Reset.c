void __usercall Scaleform::Render::D3D1x::MeshCache::Reset(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<eax>)
{
  Scaleform::Render::RenderSync *v3; // edi
  int v4; // eax
  Scaleform::Render::FenceFrame *pPrev; // eax
  Scaleform::Render::D3D1x::MeshCache *v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax

  v3 = (Scaleform::Render::RenderSync *)(a2 + 184);
  v4 = *(_DWORD *)(a2 + 284);
  if ( v4 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4);
  v3[1].RefCount = 0;
  pPrev = v3[1].FenceFrames.Root.pPrev;
  if ( pPrev )
    ((void (__stdcall *)(Scaleform::Render::FenceFrame *))pPrev->pPrev->RSContext)(v3[1].FenceFrames.Root.pPrev);
  v3[1].FenceFrames.Root.pPrev = 0;
  Scaleform::Render::RenderSync::ReleaseOutstandingFrames(v3);
  if ( *(_DWORD *)(a2 + 92) )
    Scaleform::Render::D3D1x::MeshCache::destroyBuffers(v6, a2, AT_None);
  v7 = *(_DWORD *)(a2 + 396);
  if ( v7 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(*(_DWORD *)(a2 + 396));
  *(_DWORD *)(a2 + 396) = 0;
  v8 = *(_DWORD *)(a2 + 92);
  if ( v8 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 8))(*(_DWORD *)(a2 + 92));
  *(_DWORD *)(a2 + 92) = 0;
  v9 = *(_DWORD *)(a2 + 96);
  if ( v9 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 8))(*(_DWORD *)(a2 + 96));
  *(_DWORD *)(a2 + 96) = 0;
  Scaleform::Render::MeshStagingBuffer::Reset((Scaleform::Render::MeshStagingBuffer *)(a2 + 60));
}
