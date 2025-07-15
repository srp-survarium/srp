void __userpurge survarium::flash_renderer::flash_renderer(
        survarium::flash_renderer *this@<ecx>,
        int a2@<edi>,
        Scaleform::Render::D3D1x::HAL *render_command_queue,
        ID3D11Device *pd3d_device,
        ID3D11DeviceContext *pd3d_device_context)
{
  void *v5; // eax
  int v6; // eax
  Scaleform::MemoryHeap *v7; // ecx
  Scaleform::Render::Renderer2D *v8; // eax
  int v9; // eax
  int v10; // ecx
  DWORD CurrentThreadId; // eax
  int v12; // ecx
  _DWORD v13[3]; // [esp+8h] [ebp-24h] BYREF
  Scaleform::RefCountVImpl *v14; // [esp+14h] [ebp-18h]
  Scaleform::RefCountVImpl *v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h]
  ID3D11Device *v17; // [esp+20h] [ebp-Ch]
  ID3D11DeviceContext *v18; // [esp+24h] [ebp-8h]

  v5 = Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64608, 0);
  if ( v5 )
    Scaleform::Render::D3D1x::HAL::HAL(
      render_command_queue,
      (int)v5,
      (Scaleform::Render::ThreadCommandQueue *)render_command_queue->__vftable);
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
    CurrentThreadId = GetCurrentThreadId();
    v12 = *(_DWORD *)(a2 + 8);
    v13[2] = CurrentThreadId;
    v17 = pd3d_device;
    v13[0] = 0;
    v13[1] = 0;
    v14 = 0;
    v15 = 0;
    v16 = 256;
    v18 = pd3d_device_context;
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v12 + 296))(v12, v13);
    if ( v15 )
      Scaleform::RefCountImpl::Release(v15);
    if ( v14 )
      Scaleform::RefCountImpl::Release(v14);
  }
  render_command_queue->initHAL = *(bool (__thiscall **)(struct Scaleform::Render::D3D1x::HAL *, const Scaleform::Render::HALInitParams *))(a2 + 8);
  render_command_queue->IsInitialized = (bool (__thiscall *)(struct Scaleform::Render::D3D1x::HAL *))(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 8) + 220))(*(_DWORD *)(a2 + 8));
  render_command_queue->shutdownHAL = *(bool (__thiscall **)(struct Scaleform::Render::D3D1x::HAL *))(a2 + 12);
  render_command_queue->BeginFrame = (bool (__thiscall *)(struct Scaleform::Render::D3D1x::HAL *))Scaleform::GetCurrentThreadId();
}
