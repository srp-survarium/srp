void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCopyPixels(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen,
        const Scaleform::Render::Matrix2x4<float> *mvp,
        bool mergeAlpha,
        bool destAlpha)
{
  Scaleform::Render::RenderEvent *v7; // eax
  Scaleform::Render::RenderTarget *pObject; // eax
  Scaleform::String::DataDesc *v9; // edi
  int v10; // ebx
  bool v11; // zf
  Scaleform::Render::D3D1x::ShaderInterface *v12; // ecx
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v13; // edx
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v14; // [esp-20h] [ebp-38h]
  Scaleform::Render::Size<int> v15; // [esp-14h] [ebp-2Ch]
  Scaleform::String v16; // [esp-8h] [ebp-20h] BYREF
  BOOL v17; // [esp-4h] [ebp-1Ch]
  int v18; // [esp+10h] [ebp-8h]
  Scaleform::Render::ScopedRenderEvent v19; // [esp+14h] [ebp-4h] BYREF

  v17 = 1;
  v16.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(
    &v16,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawableCopyPixels");
  v7 = this->GetEvent(this, 17);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v19, v7, v16, v17);
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v9 = (Scaleform::String::DataDesc *)(pObject->ViewRect.x2 - pObject->ViewRect.x1);
  v10 = pObject->ViewRect.y2 - pObject->ViewRect.y1;
  v11 = tex[2] == 0;
  v12 = (Scaleform::Render::D3D1x::ShaderInterface *)this->MappedXY16iAlphaTexture[0];
  v18 = 24576;
  v13 = ST_DrawableCopyPixelsAlpha;
  if ( v11 )
    v13 = v18;
  if ( destAlpha )
  {
    if ( mergeAlpha )
      v13 += 2;
  }
  else
  {
    ++v13;
  }
  if ( Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
         v12,
         this->ShaderData.UniformData,
         v13,
         (const Scaleform::Render::VertexFormat *)v12) )
  {
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
    v16.pData = v9;
    v17 = v10;
    v15.Height = (int)&this->ShaderData;
    v15.Width = (int)mvp;
    v14 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)((tex[2] != 0) + 2);
    Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
      v14,
      (unsigned int)v14,
      tex,
      texgen,
      v15,
      0,
      (Scaleform::Render::D3D1x::ShaderInterface *)v9,
      v10);
  }
  this->drawScreenQuad(this);
  v19.EventObj->End(v19.EventObj);
}
