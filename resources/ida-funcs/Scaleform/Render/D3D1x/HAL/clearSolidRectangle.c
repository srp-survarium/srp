void __thiscall Scaleform::Render::D3D1x::HAL::clearSolidRectangle(
        Scaleform::Render::D3D1x::HAL *this,
        const Scaleform::Render::Rect<int> *r,
        Scaleform::Render::Color color)
{
  Scaleform::Render::RenderEvent *v4; // eax
  unsigned int *p_fillflags; // eax
  int v6; // edx
  int y1; // ecx
  int v8; // eax
  unsigned int v9; // xmm1_4
  Scaleform::Render::MatrixState *pObject; // eax
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v11; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v12; // ecx
  Scaleform::Render::D3D1x::ShaderInterface *v13; // ecx
  Scaleform::Render::BlendMode v14; // eax
  Scaleform::String v15; // [esp-8h] [ebp-78h] BYREF
  unsigned int v16; // [esp-4h] [ebp-74h]
  char v17; // [esp+14h] [ebp-5Ch] BYREF
  __int16 v18; // [esp+15h] [ebp-5Bh]
  char v19; // [esp+17h] [ebp-59h]
  unsigned int fillflags; // [esp+18h] [ebp-58h] BYREF
  Scaleform::Render::ScopedRenderEvent v21; // [esp+1Ch] [ebp-54h] BYREF
  float pr; // [esp+20h] [ebp-50h] BYREF
  float pg; // [esp+24h] [ebp-4Ch] BYREF
  float pb; // [esp+28h] [ebp-48h] BYREF
  float pa; // [esp+2Ch] [ebp-44h] BYREF
  Scaleform::Render::Matrix2x4<float> m0; // [esp+30h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v27; // [esp+50h] [ebp-20h] BYREF

  v16 = 1;
  v15.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(&v15, "Scaleform::Render::D3D1x::HAL::clearSolidRectangle");
  v4 = this->GetEvent(this, 5);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v21, v4, v15, v16);
  fillflags = color.Raw;
  if ( this->Profiler.FillMode || this->Profiler.BatchMode )
  {
    v18 = 0;
    v17 = 0;
    v19 = -1;
    p_fillflags = (unsigned int *)&v17;
  }
  else
  {
    p_fillflags = &fillflags;
  }
  color = (Scaleform::Render::Color)*p_fillflags;
  if ( this->Profiler.OverrideMasks )
    this->pDeviceContext->OMSetBlendState(this->pDeviceContext, this->BlendStates[0], 0, -1u);
  Scaleform::Render::Color::GetRGBAFloat(&color, &pr, &pg, &pb, &pa);
  v6 = r->x2 - r->x1;
  y1 = r->y1;
  v8 = r->y2 - y1;
  m0.M[0][3] = (float)r->x1;
  *(float *)&v9 = (float)v8;
  pObject = this->Matrices.pObject;
  m0.M[0][0] = (float)v6;
  *(_QWORD *)&m0.M[0][1] = 0;
  m0.M[1][0] = 0.0;
  *(_QWORD *)&m0.M[1][1] = v9;
  m0.M[1][3] = (float)y1;
  Scaleform::Render::Matrix2x4<float>::SetToAppend(&v27, &m0, &pObject->UserView);
  v16 = (unsigned int)this->MappedXY16iAlphaSolid[0];
  fillflags = 0;
  v11 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
          PrimFill_SolidColor,
          &fillflags,
          0,
          v16);
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    v12,
    this->ShaderData.UniformData,
    v11,
    (const Scaleform::Render::VertexFormat *)v16);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    &this->ShaderData.CurShaders,
    &this->ShaderData,
    4u,
    (float *)&v27,
    8u,
    0,
    0);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    &this->ShaderData.CurShaders,
    &this->ShaderData,
    1u,
    &pr,
    4u,
    0,
    0);
  Scaleform::Render::D3D1x::ShaderInterface::Finish(v13, (unsigned int)&this->ShaderData);
  this->drawScreenQuad(this);
  if ( this->Profiler.OverrideMasks )
  {
    if ( this->BlendModeStack.Data.Size )
      v14 = this->BlendModeStack.Data.Data[this->BlendModeStack.Data.Size - 1];
    else
      v14 = Blend_None;
    Scaleform::Render::HAL::applyBlendMode(this, v14, 0, 0);
  }
  v21.EventObj->End(v21.EventObj);
}
