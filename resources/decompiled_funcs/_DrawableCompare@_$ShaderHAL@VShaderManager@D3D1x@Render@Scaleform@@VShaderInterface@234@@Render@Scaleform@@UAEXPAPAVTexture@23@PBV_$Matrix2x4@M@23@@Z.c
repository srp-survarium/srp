void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCompare(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Texture **texgen)
{
  Scaleform::Render::RenderEvent *v4; // edi
  Scaleform::Render::RenderEvent_vtbl *v5; // ebx
  int v6; // ecx
  void *v7; // ebx
  Scaleform::Render::RenderTarget *pObject; // eax
  Scaleform::Render::Size<int> v9; // [esp-8h] [ebp-18h] BYREF
  unsigned int v10; // [esp+0h] [ebp-10h]
  Scaleform::String src; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(
    &src,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawableCompare");
  v4 = this->GetEvent(this, 16);
  v5 = v4->__vftable;
  v9.Height = v6;
  Scaleform::String::String((Scaleform::String *)&v9.Height, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, int))v5->Begin)(v4, v9.Height);
  v7 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v9.Width = pObject->ViewRect.x2 - pObject->ViewRect.x1;
  v9.Height = pObject->ViewRect.y2 - pObject->ViewRect.y1;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCompare(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)tex,
    texgen,
    0,
    v9,
    this->MappedXY16iAlphaTexture[0],
    &this->ShaderData,
    v10);
  this->drawScreenQuad(this);
  v4->End(v4);
}
