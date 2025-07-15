void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCxform(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Texture **texgen,
        Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::RenderEvent *v5; // eax
  Scaleform::Render::RenderTarget *pObject; // eax
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v7; // edx
  Scaleform::String v8; // [esp-8h] [ebp-18h] BYREF
  BOOL v9; // [esp-4h] [ebp-14h]
  unsigned int v10; // [esp+0h] [ebp-10h]
  Scaleform::Render::ScopedRenderEvent v11; // [esp+Ch] [ebp-4h] BYREF

  v9 = 1;
  v8.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(
    &v8,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawableCxform");
  v5 = this->GetEvent(this, 15);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v11, v5, v8, v9);
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v7 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)(pObject->ViewRect.y2 - pObject->ViewRect.y1);
  v8.pData = (Scaleform::String::DataDesc *)(pObject->ViewRect.x2 - pObject->ViewRect.x1);
  v9 = (BOOL)v7;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCxform(
    &this->ShaderData,
    (Scaleform::Render::D3D1x::ShaderInterface *)v8.pData,
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)tex,
    texgen,
    cx,
    (const Scaleform::Render::Size<int>)(unsigned int)this->MappedXY16iAlphaTexture[0],
    (Scaleform::Render::D3D1x::ShaderInterface *)v8.pData,
    v7,
    v10);
  this->drawScreenQuad(this);
  v11.EventObj->End(v11.EventObj);
}
