void __usercall Scaleform::Render::D3D1x::RenderSync::~RenderSync(
        Scaleform::Render::D3D1x::RenderSync *this@<ecx>,
        Scaleform::Render::RenderSync *a2@<esi>)
{
  Scaleform::Render::FenceFrame *pPrev; // eax
  volatile int RefCount; // eax

  pPrev = a2[1].FenceFrames.Root.pPrev;
  if ( pPrev )
    ((void (__stdcall *)(Scaleform::Render::FenceFrame *))pPrev->pPrev->RSContext)(a2[1].FenceFrames.Root.pPrev);
  RefCount = a2[1].RefCount;
  if ( RefCount )
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 8))(a2[1].RefCount);
  Scaleform::Render::RenderSync::~RenderSync(a2);
}
