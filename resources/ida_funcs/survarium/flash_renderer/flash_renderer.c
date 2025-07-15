void __userpurge survarium::flash_renderer::flash_renderer(
        survarium::flash_renderer *this@<ecx>,
        int a2@<esi>,
        survarium::scaleform_render_command_queue *render_command_queue,
        ID3D11Device *pd3d_device,
        ID3D11DeviceContext *pd3d_device_context)
{
  Scaleform::Render::D3D1x::HAL *v5; // ecx
  int v6; // eax
  Scaleform::MemoryHeap *v7; // ecx
  Scaleform::Render::Renderer2D *v8; // eax
  int v9; // eax
  int v10; // ecx
  void *CurrentThreadId; // eax
  int v12; // ecx
  Scaleform::Render::D3D1x::HALInitParams params; // [esp+10h] [ebp-20h] BYREF

  v5 = (Scaleform::Render::D3D1x::HAL *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64440, 0);
  if ( v5 )
    Scaleform::Render::D3D1x::HAL::HAL(v5, render_command_queue->impl);
  else
    v6 = 0;
  v7 = Scaleform::Memory::pGlobalHeap;
  *(_DWORD *)(a2 + 8) = v6;
  v8 = (Scaleform::Render::Renderer2D *)v7->Alloc(v7, 12u, 0);
  if ( v8 )
    Scaleform::Render::Renderer2D::Renderer2D(v8, *(Scaleform::Render::HAL **)(a2 + 8));
  else
    v9 = 0;
  v10 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(a2 + 12) = v9;
  if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 12))(v10) )
  {
    CurrentThreadId = (void *)GetCurrentThreadId();
    params.pD3DDevice = pd3d_device;
    v12 = *(_DWORD *)(a2 + 8);
    params.RenderThreadId = CurrentThreadId;
    params.pD3DContext = pd3d_device_context;
    params.pMemoryManager = 0;
    params.ConfigFlags = 0;
    params.pTextureManager.pObject = 0;
    params.pRenderBufferManager.pObject = 0;
    params.RenderQueueSize = 256;
    (*(void (__thiscall **)(int, Scaleform::Render::D3D1x::HALInitParams *))(*(_DWORD *)v12 + 296))(v12, &params);
    if ( params.pRenderBufferManager.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)params.pRenderBufferManager.pObject);
    if ( params.pTextureManager.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)params.pTextureManager.pObject);
  }
  render_command_queue->impl->pHAL = *(Scaleform::Render::HAL **)(a2 + 8);
  render_command_queue->impl->pHALTextureMgr = (Scaleform::Render::TextureManager *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 8) + 220))(*(_DWORD *)(a2 + 8));
  render_command_queue->impl->pR2D = *(Scaleform::Render::Renderer2D **)(a2 + 12);
  render_command_queue->impl->pRenderThreadId = (void *)Scaleform::GetCurrentThreadId();
}
