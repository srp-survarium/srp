void __usercall Scaleform::Render::D3D1x::RenderEvent::InitializeEvents(ID3D11DeviceContext *pctx@<eax>)
{
  ID3D11DeviceContext_vtbl *v1; // ecx
  HMODULE LibraryA; // eax
  HMODULE v3; // edi

  v1 = pctx->lpVtbl;
  Scaleform::Render::D3D1x::RenderEvent::pContext = pctx;
  v1->AddRef(pctx);
  LibraryA = LoadLibraryA("D3D9.dll");
  v3 = LibraryA;
  if ( LibraryA )
  {
    Scaleform::Render::D3D1x::RenderEvent::BeginEventFn = (int (__stdcall *)(unsigned int, const wchar_t *))GetProcAddress(LibraryA, "D3DPERF_BeginEvent");
    Scaleform::Render::D3D1x::RenderEvent::EndEventFn = GetProcAddress(v3, "D3DPERF_EndEvent");
  }
}
