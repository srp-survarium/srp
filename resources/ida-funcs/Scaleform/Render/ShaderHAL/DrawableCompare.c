void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawableCompare(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::RenderEvent *v4; // eax
  Scaleform::Render::RenderTarget *pObject; // eax
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v6; // edx
  Scaleform::Render::Size<int> v7; // [esp-14h] [ebp-1Ch]
  Scaleform::String v8; // [esp-8h] [ebp-10h] BYREF
  BOOL v9; // [esp-4h] [ebp-Ch]
  Scaleform::Render::ScopedRenderEvent v10; // [esp+4h] [ebp-4h] BYREF

  v9 = 1;
  v8.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(
    &v8,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawableCompare");
  v4 = this->GetEvent(this, 16);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v10, v4, v8, v9);
  pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
  v6 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)(pObject->ViewRect.y2 - pObject->ViewRect.y1);
  v8.pData = (Scaleform::String::DataDesc *)(pObject->ViewRect.x2 - pObject->ViewRect.x1);
  v9 = (BOOL)v6;
  v7.Height = (int)&this->ShaderData;
  v7.Width = (int)this->MappedXY16iAlphaTexture[0];
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawableCompare(
    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)v8.pData,
    tex,
    texgen,
    v7,
    0,
    (Scaleform::Render::D3D1x::ShaderInterface *)v8.pData,
    v6);
  this->drawScreenQuad(this);
  v10.EventObj->End(v10.EventObj);
}
