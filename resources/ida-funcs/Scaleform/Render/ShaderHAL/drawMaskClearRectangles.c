void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::drawMaskClearRectangles(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *matrices,
        unsigned int count)
{
  Scaleform::Render::RenderEvent *v4; // eax
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v5; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v6; // ecx
  unsigned int v7; // ebx
  Scaleform::Render::D3D1x::ShaderInterface *v8; // ecx
  Scaleform::String v9; // [esp-8h] [ebp-38h] BYREF
  unsigned int v10; // [esp-4h] [ebp-34h]
  unsigned int v11; // [esp+0h] [ebp-30h]
  unsigned int v12; // [esp+4h] [ebp-2Ch]
  const Scaleform::Render::Matrix2x4<float> *v13; // [esp+10h] [ebp-20h]
  unsigned int i; // [esp+14h] [ebp-1Ch]
  Scaleform::Render::MatrixPoolImpl::HMatrix *v15; // [esp+18h] [ebp-18h] BYREF
  Scaleform::Render::ScopedRenderEvent v16; // [esp+1Ch] [ebp-14h] BYREF
  float v17[4]; // [esp+20h] [ebp-10h] BYREF

  v10 = 1;
  v9.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(&v9, "HAL::drawMaskClearRectangles");
  v4 = this->GetEvent(this, 8);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v16, v4, v9, v10);
  v10 = (unsigned int)this->MappedXY16iAlphaSolid[1];
  v15 = 0;
  v5 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
         PrimFill_SolidColor,
         (unsigned int *)&v15,
         (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)1,
         v10);
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    v6,
    this->ShaderData.UniformData,
    v5,
    (const Scaleform::Render::VertexFormat *)v10);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
  this->setBatchUnitSquareVertexStream(this);
  for ( i = 0; i < count; i += v7 )
  {
    v7 = 24;
    if ( count < 0x18 )
      v7 = count;
    v13 = 0;
    v15 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)&matrices[i];
    do
    {
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
        v15,
        this->Matrices.pObject,
        &this->ShaderData,
        &this->ShaderData.CurShaders,
        &Scaleform::Render::Matrix2x4<float>::Identity,
        v13,
        v11,
        v12);
      v17[0] = s_bm_current_air_resistance;
      v17[1] = 0.0;
      v17[2] = 0.0;
      v17[3] = c_anim_center;
      Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
        &this->ShaderData.CurShaders,
        &this->ShaderData,
        1u,
        v17,
        4u,
        0,
        0);
      v13 = (const Scaleform::Render::Matrix2x4<float> *)((char *)v13 + 1);
      ++v15;
    }
    while ( (unsigned int)v13 < v7 );
    Scaleform::Render::D3D1x::ShaderInterface::Finish(v8, (unsigned int)&this->ShaderData);
    this->drawPrimitive(this, 6 * v7, v7);
  }
  v16.EventObj->End(v16.EventObj);
}
