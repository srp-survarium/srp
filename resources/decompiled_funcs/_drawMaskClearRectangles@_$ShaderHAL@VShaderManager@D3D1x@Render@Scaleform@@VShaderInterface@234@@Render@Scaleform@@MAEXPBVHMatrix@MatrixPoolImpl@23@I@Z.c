void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawMaskClearRectangles(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *matrices,
        unsigned int count)
{
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v3; // esi
  Scaleform::Render::RenderEvent *EventObj; // ebx
  Scaleform::Render::RenderEvent v5; // edi
  Scaleform::String::DataDesc *v6; // ecx
  void *v7; // edi
  const Scaleform::Render::D3D1x::ShaderPair *v8; // eax
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>_vtbl *v9; // edx
  Scaleform::Render::D3D1x::ShaderInterface *v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // edi
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *p_ShaderData; // esi
  Scaleform::String v15; // [esp-4h] [ebp-3Ch] BYREF
  const Scaleform::Render::VertexFormat *v16; // [esp+0h] [ebp-38h]
  unsigned int v17; // [esp+4h] [ebp-34h]
  Scaleform::Render::MatrixPoolImpl::HMatrix *m2; // [esp+10h] [ebp-28h]
  unsigned int i; // [esp+14h] [ebp-24h]
  Scaleform::String src; // [esp+18h] [ebp-20h] BYREF
  unsigned int fillflags; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *v22; // [esp+20h] [ebp-18h]
  Scaleform::Render::ScopedRenderEvent GPUEvent; // [esp+24h] [ebp-14h]
  float colorf[4]; // [esp+28h] [ebp-10h] BYREF

  v3 = this;
  v22 = this;
  Scaleform::String::String(&src, "HAL::drawMaskClearRectangles");
  EventObj = v3->GetEvent(v3, Event_MaskClear);
  v5.__vftable = EventObj->__vftable;
  v15.pData = v6;
  GPUEvent.EventObj = EventObj;
  Scaleform::String::String(&v15, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))v5.Begin)(EventObj, v15.pData);
  v7 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  v15.pData = (Scaleform::String::DataDesc *)v3->MappedXY16iAlphaSolid[1];
  fillflags = 0;
  v8 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFill(
         &fillflags,
         (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)1,
         &v3->ShaderData,
         (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)2,
         (Scaleform::Render::D3D1x::ShaderInterface *)v15.pData,
         v16);
  v9 = v3->__vftable;
  fillflags = (unsigned int)v8;
  v9->setBatchUnitSquareVertexStream(v3);
  v11 = count;
  i = 0;
  if ( count )
  {
    while ( 1 )
    {
      v12 = v11;
      if ( v11 >= 0x18 )
        v12 = 24;
      v13 = 0;
      if ( v12 )
      {
        m2 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)&matrices[i];
        do
        {
          v15.pData = (Scaleform::String::DataDesc *)v3->Matrices.pObject;
          p_ShaderData = &v3->ShaderData;
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
            &Scaleform::Render::Matrix2x4<float>::Identity,
            m2,
            v13,
            p_ShaderData,
            (const Scaleform::Render::D3D1x::ShaderPair *)fillflags,
            (const Scaleform::Render::MatrixState *)v15.pData,
            (const Scaleform::Render::MatrixState *)v16,
            v17);
          LODWORD(colorf[0]) = clear_value;
          colorf[1] = 0.0;
          colorf[2] = 0.0;
          colorf[3] = FLOAT_0_5;
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (const Scaleform::Render::D3D1x::ShaderPair *)fillflags,
            1u,
            0,
            p_ShaderData,
            colorf,
            4u,
            0);
          ++m2;
          v3 = v22;
          ++v13;
        }
        while ( v13 < v12 );
      }
      Scaleform::Render::D3D1x::ShaderInterface::Finish(v10, (unsigned int)v16);
      v3->drawPrimitive(v3, 6 * v12, v12);
      i += v12;
      if ( i >= count )
        break;
      v11 = count;
    }
    EventObj = GPUEvent.EventObj;
  }
  EventObj->End(EventObj);
}
