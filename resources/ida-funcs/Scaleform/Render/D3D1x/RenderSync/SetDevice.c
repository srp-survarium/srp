bool __userpurge Scaleform::Render::D3D1x::RenderSync::SetDevice@<al>(
        Scaleform::Render::D3D1x::RenderSync *this@<ecx>,
        Scaleform::Render::RenderSync *a2@<esi>,
        ID3D11Device *pdevice,
        Scaleform::Render::FenceFrame *pdeviceCtx)
{
  ID3D11Device *v4; // ebx
  ID3D11Device_vtbl *v5; // eax
  int v6; // edi
  volatile int RefCount; // eax
  Scaleform::Render::FenceFrame *v8; // ebx
  Scaleform::Render::FenceFrame *pPrev; // eax
  volatile int v11; // eax
  Scaleform::Render::FenceFrame *v12; // eax
  D3D11_QUERY_DESC v13; // [esp+8h] [ebp-8h] BYREF

  v4 = pdevice;
  if ( pdevice && pdeviceCtx )
  {
    pdevice = 0;
    v13.Query = D3D11_QUERY_EVENT;
    v13.MiscFlags = 0;
    v5 = v4->lpVtbl;
    v13.Query = D3D11_QUERY_EVENT;
    v6 = v5->CreateQuery(v4, &v13, (ID3D11Query **)&pdevice);
    if ( pdevice )
    {
      pdevice->Release(pdevice);
      v4->AddRef(v4);
      RefCount = a2[1].RefCount;
      if ( RefCount )
        (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 8))(a2[1].RefCount);
      a2[1].RefCount = (volatile int)v4;
      v8 = pdeviceCtx;
      ((void (__stdcall *)(Scaleform::Render::FenceFrame *))pdeviceCtx->pPrev->pNext)(pdeviceCtx);
      pPrev = a2[1].FenceFrames.Root.pPrev;
      if ( pPrev )
        ((void (__stdcall *)(Scaleform::Render::FenceFrame *))pPrev->pPrev->RSContext)(a2[1].FenceFrames.Root.pPrev);
      a2[1].FenceFrames.Root.pPrev = v8;
    }
    return v6 >= 0;
  }
  else
  {
    v11 = a2[1].RefCount;
    if ( v11 )
      (*(void (__stdcall **)(volatile int))(*(_DWORD *)v11 + 8))(a2[1].RefCount);
    a2[1].RefCount = 0;
    v12 = a2[1].FenceFrames.Root.pPrev;
    if ( v12 )
      ((void (__stdcall *)(Scaleform::Render::FenceFrame *))v12->pPrev->RSContext)(a2[1].FenceFrames.Root.pPrev);
    a2[1].FenceFrames.Root.pPrev = 0;
    Scaleform::Render::RenderSync::ReleaseOutstandingFrames(a2);
    return 1;
  }
}
