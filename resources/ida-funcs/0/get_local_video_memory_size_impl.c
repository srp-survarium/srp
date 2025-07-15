unsigned __int64 __cdecl get_local_video_memory_size_impl()
{
  IDirect3D9 *v0; // eax
  IDirect3D9 *v1; // edi
  unsigned int v3; // ebx
  HMONITOR__ *v4; // esi
  unsigned __int64 v5; // rax
  _D3DADAPTER_IDENTIFIER9 dst; // [esp+10h] [ebp-4B8h] BYREF
  tagMONITORINFO mi; // [esp+460h] [ebp-68h] BYREF
  unsigned __int64 right; // [esp+4A8h] [ebp-20h] BYREF
  unsigned __int64 pdwAdapterRam; // [esp+4B0h] [ebp-18h] BYREF
  unsigned int v10; // [esp+4B8h] [ebp-10h]
  HRESULT v11; // [esp+4BCh] [ebp-Ch]
  unsigned __int64 left; // [esp+4C0h] [ebp-8h]

  v11 = CoInitializeEx(0, 2u);
  v0 = Direct3DCreate9(0x20u);
  v1 = v0;
  if ( !v0 )
  {
    if ( v11 >= 0 )
      CoUninitialize();
    return 0;
  }
  v3 = 0;
  v10 = v0->GetAdapterCount(v0);
  left = 0;
  if ( v10 )
  {
    while ( 1 )
    {
      memset((int)&dst, 0, sizeof(dst));
      v1->GetAdapterIdentifier(v1, v3, 0, &dst);
      v4 = v1->GetAdapterMonitor(v1, v3);
      mi.cbSize = 72;
      GetMonitorInfoA(v4, &mi);
      if ( GetVideoMemoryViaWMI(v4, &pdwAdapterRam) >= 0 )
        break;
      if ( GetVideoMemoryViaDirectDraw(&right, v4) >= 0 )
      {
        v5 = vostok::math::max(left, right);
        goto LABEL_10;
      }
LABEL_11:
      if ( ++v3 >= v10 )
        goto LABEL_12;
    }
    v5 = vostok::math::max(left, pdwAdapterRam);
LABEL_10:
    left = v5;
    goto LABEL_11;
  }
LABEL_12:
  v1->Release(v1);
  if ( v11 >= 0 )
    CoUninitialize();
  return vostok::math::min(left, 0x80000000);
}
