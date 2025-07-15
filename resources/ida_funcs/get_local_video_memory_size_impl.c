int __cdecl get_local_video_memory_size_impl()
{
  unsigned int v0; // ebx
  HRESULT v1; // edi
  IDirect3D9 *v2; // esi
  unsigned __int64 v4; // kr08_8
  HMONITOR__ *v5; // edi
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rax
  HRESULT hrCoInitialize; // [esp+28h] [ebp-4B4h]
  unsigned int dwAdapterCount; // [esp+2Ch] [ebp-4B0h]
  unsigned __int64 dwAdapterRAM; // [esp+30h] [ebp-4ACh] BYREF
  unsigned __int64 dwAvailableVidMem; // [esp+38h] [ebp-4A4h] BYREF
  tagMONITORINFOEXA mi; // [esp+40h] [ebp-49Ch] BYREF
  _D3DADAPTER_IDENTIFIER9 id; // [esp+88h] [ebp-454h] BYREF

  v0 = 0;
  v1 = CoInitializeEx(0, 2u);
  hrCoInitialize = v1;
  v2 = Direct3DCreate9(0x20u);
  if ( v2 )
  {
    dwAdapterCount = v2->GetAdapterCount(v2);
    v4 = 0;
    if ( dwAdapterCount )
    {
      do
      {
        memset((int)&id, 0, sizeof(id));
        v2->GetAdapterIdentifier(v2, v0, 0, &id);
        v5 = v2->GetAdapterMonitor(v2, v0);
        mi.cbSize = 72;
        GetMonitorInfoA(v5, &mi);
        if ( (GetVideoMemoryViaWMI(&dwAdapterRAM) & 0x80000000) != 0 )
        {
          if ( GetVideoMemoryViaDirectDraw(&dwAvailableVidMem, v5) >= 0 )
          {
            LODWORD(v7) = guess_exact_memory_size(dwAvailableVidMem);
            v4 = vostok::math::max(v4, v7);
          }
        }
        else
        {
          LODWORD(v6) = guess_exact_memory_size(dwAdapterRAM);
          v4 -= v4 < v6 ? v4 - v6 : 0;
        }
        ++v0;
      }
      while ( v0 < dwAdapterCount );
      v1 = hrCoInitialize;
    }
    v2->Release(v2);
    if ( v1 >= 0 )
      CoUninitialize();
    return v4;
  }
  else
  {
    if ( v1 >= 0 )
      CoUninitialize();
    return 0;
  }
}
