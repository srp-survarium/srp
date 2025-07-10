void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyback(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture *source,
        const Scaleform::Render::Matrix2x4<float> *mvpOriginal,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::RenderEvent *v5; // esi
  Scaleform::Render::RenderEvent_vtbl *v6; // edi
  Scaleform::String::DataDesc *v7; // ecx
  void *v8; // esi
  const Scaleform::Render::D3D1x::ShaderPair *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm0_4
  void (__thiscall *ApplyTexture)(Scaleform::Render::Texture *, unsigned int, const Scaleform::Render::ImageFillMode *); // edx
  const Scaleform::Render::D3D1x::FragShaderDesc *pFDesc; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v14; // ecx
  Scaleform::String v15; // [esp+90h] [ebp-44h] BYREF
  const Scaleform::Render::VertexFormat *v16; // [esp+94h] [ebp-40h]
  char v17; // [esp+A7h] [ebp-2Dh] BYREF
  Scaleform::String src; // [esp+A8h] [ebp-2Ch] BYREF
  const Scaleform::Render::D3D1x::ShaderPair *sd; // [esp+ACh] [ebp-28h] BYREF
  Scaleform::Render::RenderEvent *v20; // [esp+B0h] [ebp-24h]
  _QWORD v[3]; // [esp+B4h] [ebp-20h] BYREF
  float v22; // [esp+CCh] [ebp-8h]
  float v23; // [esp+D0h] [ebp-4h]

  Scaleform::String::String(
    &src,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawableCopyback");
  v5 = this->GetEvent(this, 21);
  v6 = v5->__vftable;
  v15.pData = v7;
  v20 = v5;
  Scaleform::String::String(&v15, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))v6->Begin)(v5, v15.pData);
  v8 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  v15.pData = (Scaleform::String::DataDesc *)this->MappedXY16iAlphaTexture[0];
  sd = 0;
  v9 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFill(
         (unsigned int *)&sd,
         0,
         &this->ShaderData,
         (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)5,
         (Scaleform::Render::D3D1x::ShaderInterface *)v15.pData,
         v16);
  v[0] = *(_QWORD *)&mvpOriginal->M[0][0];
  v[1] = *(_QWORD *)&mvpOriginal->M[0][2];
  v[2] = *(_QWORD *)&mvpOriginal->M[1][0];
  v10 = mvpOriginal->M[1][2];
  v15.pData = 0;
  v22 = v10;
  v11 = mvpOriginal->M[1][3];
  sd = v9;
  v23 = v11;
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    v9,
    4u,
    0,
    &this->ShaderData,
    (const float *)v,
    8u,
    0);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    sd,
    0xBu,
    0,
    &this->ShaderData,
    (const float *)texgen,
    8u,
    0);
  ApplyTexture = source->ApplyTexture;
  v15.pData = (Scaleform::String::DataDesc *)&v17;
  pFDesc = this->ShaderData.CurShaders.pFDesc;
  v17 = 0;
  ApplyTexture(source, pFDesc->Uniforms[10].Location, (const Scaleform::Render::ImageFillMode *)&v17);
  Scaleform::Render::D3D1x::ShaderInterface::Finish(v14, (unsigned int)v16);
  this->drawScreenQuad(this);
  v20->End(v20);
}
