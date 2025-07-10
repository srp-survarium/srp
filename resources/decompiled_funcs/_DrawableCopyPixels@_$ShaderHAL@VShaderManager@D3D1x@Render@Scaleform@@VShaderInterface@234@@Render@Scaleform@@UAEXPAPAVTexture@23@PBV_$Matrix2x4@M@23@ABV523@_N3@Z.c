void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyPixels(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *texgen,
        const Scaleform::Render::Matrix2x4<float> *mvp,
        unsigned int mergeAlpha,
        unsigned int destAlpha)
{
  Scaleform::Render::RenderEvent *v7; // ebx
  Scaleform::Render::RenderEvent_vtbl *v8; // edi
  unsigned int v9; // ecx
  void *v10; // edi
  Scaleform::Render::RenderTarget *pObject; // eax
  Scaleform::String v12[4]; // [esp-4h] [ebp-14h] BYREF
  Scaleform::String src; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(
    &src,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawableCopyPixels");
  v7 = this->GetEvent(this, 17);
  v8 = v7->__vftable;
  v12[0].HeapTypeBits = v9;
  Scaleform::String::String(v12, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, unsigned int))v8->Begin)(v7, v12[0].HeapTypeBits);
  v10 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCopyPixelsFill(
    texgen,
    tex,
    mvp,
    (const Scaleform::Render::Size<int>)__PAIR64__(destAlpha, mergeAlpha),
    0,
    LOBYTE(pObject->ViewRect.x2) - LOBYTE(pObject->ViewRect.x1),
    LOBYTE(pObject->ViewRect.y2) - LOBYTE(pObject->ViewRect.y1),
    this->MappedXY16iAlphaTexture[0],
    &this->ShaderData,
    v12[1].HeapTypeBits);
  this->drawScreenQuad(this);
  v7->End(v7);
}
