void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyback(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture *source,
        const Scaleform::Render::Matrix2x4<float> *mvpOriginal,
        Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::RenderEvent *v5; // eax
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v6; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v7; // ecx
  Scaleform::Render::D3D1x::ShaderInterface *v8; // ecx
  Scaleform::Render::D3D1x::ShaderPair v9; // [esp-1Ch] [ebp-5Ch] BYREF
  Scaleform::String v10; // [esp-8h] [ebp-48h] BYREF
  BOOL v11; // [esp-4h] [ebp-44h]
  unsigned int v12; // [esp+0h] [ebp-40h]
  Scaleform::Render::D3D1x::ShaderPair *p_CurShaders; // [esp+18h] [ebp-28h] BYREF
  Scaleform::Render::ScopedRenderEvent v14; // [esp+1Ch] [ebp-24h] BYREF
  Scaleform::Render::Matrix2x4<float> v15; // [esp+20h] [ebp-20h] BYREF

  v11 = 1;
  v10.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(
    &v10,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawableCopyback");
  v5 = this->GetEvent(this, 21);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v14, v5, v10, v11);
  v10.pData = (Scaleform::String::DataDesc *)5;
  p_CurShaders = 0;
  v6 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
         PrimFill_Texture,
         (unsigned int *)&p_CurShaders,
         0,
         v12);
  Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
    v7,
    this->ShaderData.UniformData,
    v6,
    this->MappedXY16iAlphaTexture[0]);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
  p_CurShaders = &this->ShaderData.CurShaders;
  Scaleform::Render::Matrix2x4<float>::SetMatrix(&v15, mvpOriginal);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    p_CurShaders,
    &this->ShaderData,
    4u,
    (float *)&v15,
    8u,
    0,
    0);
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
    p_CurShaders,
    &this->ShaderData,
    0xBu,
    (float *)texgen,
    8u,
    0,
    0);
  qmemcpy((void *)&v9, p_CurShaders, sizeof(v9));
  Scaleform::Render::D3D1x::ShaderInterface::SetTexture(0xAu, source, &this->ShaderData, v9, 0, 0);
  Scaleform::Render::D3D1x::ShaderInterface::Finish(v8, (unsigned int)&this->ShaderData);
  this->drawScreenQuad(this);
  v14.EventObj->End(v14.EventObj);
}
