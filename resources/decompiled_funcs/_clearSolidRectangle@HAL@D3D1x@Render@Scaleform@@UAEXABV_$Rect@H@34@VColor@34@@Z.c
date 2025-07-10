void __thiscall Scaleform::Render::D3D1x::HAL::clearSolidRectangle(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::Rect<int> *r,
        Scaleform::Render::Color color)
{
  Scaleform::Render::RenderEvent *v4; // esi
  Scaleform::Render::RenderEvent_vtbl *v5; // edi
  unsigned int v6; // ecx
  void *v7; // esi
  float x1; // xmm1_4
  int y1; // ecx
  int y2; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v11; // ecx
  Scaleform::String v12[6]; // [esp+1B0h] [ebp-74h] BYREF
  Scaleform::String src; // [esp+1C8h] [ebp-5Ch] BYREF
  unsigned int fillFlags; // [esp+1CCh] [ebp-58h] BYREF
  Scaleform::Render::RenderEvent *v15; // [esp+1D0h] [ebp-54h]
  float pr; // [esp+1D4h] [ebp-50h] BYREF
  float pg; // [esp+1D8h] [ebp-4Ch] BYREF
  float pb; // [esp+1DCh] [ebp-48h] BYREF
  float pa; // [esp+1E0h] [ebp-44h] BYREF
  Scaleform::Render::Matrix2x4<float> m0; // [esp+1E4h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v21; // [esp+204h] [ebp-20h] BYREF

  Scaleform::String::String(&src, "Scaleform::Render::D3D1x::HAL::clearSolidRectangle");
  v4 = this->GetEvent(this, 5);
  v5 = v4->__vftable;
  v12[0].HeapTypeBits = v6;
  v15 = v4;
  Scaleform::String::String(v12, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, unsigned int))v5->Begin)(v4, v12[0].HeapTypeBits);
  v7 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  Scaleform::Render::Color::GetRGBAFloat(&color, &pr, &pg, &pb, &pa);
  x1 = (float)r->x1;
  y1 = r->y1;
  y2 = r->y2;
  m0.M[0][0] = (float)(r->x2 - r->x1);
  *(_QWORD *)&m0.M[0][1] = 0;
  m0.M[1][0] = 0.0;
  m0.M[1][2] = 0.0;
  v12[0].HeapTypeBits = (unsigned int)&this->Matrices.pObject->UserView;
  m0.M[0][3] = x1;
  m0.M[1][1] = (float)(y2 - y1);
  m0.M[1][3] = (float)y1;
  Scaleform::Render::Matrix2x4<float>::SetToAppend(&v21, &m0, (const Scaleform::Render::Matrix2x4<float> *)v12[0].pData);
  v12[0] = (Scaleform::String)this->MappedXY16iAlphaSolid[0];
  fillFlags = 0;
  fillFlags = (unsigned int)Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFill(
                              &fillFlags,
                              0,
                              &this->ShaderData,
                              (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)2,
                              (Scaleform::Render::D3D1x::ShaderInterface *)v12[0].pData,
                              (const Scaleform::Render::VertexFormat *)v12[1].pData);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    (const Scaleform::Render::D3D1x::ShaderPair *)fillFlags,
    4u,
    0,
    &this->ShaderData,
    (const float *)&v21,
    8u,
    0);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    (const Scaleform::Render::D3D1x::ShaderPair *)fillFlags,
    1u,
    0,
    &this->ShaderData,
    &pr,
    4u,
    0);
  Scaleform::Render::D3D1x::ShaderInterface::Finish(v11, (int)&this->ShaderData);
  this->drawScreenQuad(this);
  v15->End(v15);
}
