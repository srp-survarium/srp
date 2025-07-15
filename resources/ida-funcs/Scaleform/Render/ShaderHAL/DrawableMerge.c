void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableMerge(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Texture **texgen,
        const Scaleform::Render::Matrix4x4<float> *cxmul)
{
  Scaleform::Render::RenderEvent *v5; // ebx
  Scaleform::Render::RenderEvent_vtbl *v6; // edi
  unsigned int v7; // ecx
  void *v8; // edi
  Scaleform::Render::RenderTarget *pObject; // eax
  Scaleform::Render::Size<int> v10; // [esp-Ch] [ebp-1Ch]
  Scaleform::String v11[4]; // [esp-4h] [ebp-14h] BYREF
  Scaleform::String src; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(
    &src,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawableMerge");
  v5 = this->GetEvent(this, 18);
  v6 = v5->__vftable;
  v11[0].HeapTypeBits = v7;
  Scaleform::String::String(v11, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, unsigned int))v6->Begin)(v5, v11[0].HeapTypeBits);
  v8 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v10.Height = pObject->ViewRect.x2 - pObject->ViewRect.x1;
  v10.Width = 0;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableMergeFill(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)tex,
    texgen,
    (const Scaleform::Render::Matrix2x4<float> *)cxmul,
    v10,
    (const Scaleform::Render::Matrix4x4<float> *)(pObject->ViewRect.y2 - pObject->ViewRect.y1),
    this->MappedXY16iAlphaTexture[0],
    &this->ShaderData,
    v11[1].HeapTypeBits);
  this->drawScreenQuad(this);
  v5->End(v5);
}
