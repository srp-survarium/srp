void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawablePaletteMap(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen,
        const Scaleform::Render::D3D1x::FragShader *mvp,
        unsigned int channelMask,
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *values)
{
  Scaleform::Render::RenderEvent *v7; // eax
  Scaleform::Render::TextureManager *v8; // eax
  Scaleform::Render::TextureManager *v9; // edi
  Scaleform::Render::TextureManager_vtbl *v10; // esi
  int v11; // eax
  Scaleform::Render::Texture *v12; // eax
  Scaleform::Render::Texture *v13; // esi
  Scaleform::Render::Texture_vtbl *v14; // eax
  int v15; // edx
  unsigned __int8 *v16; // edi
  Scaleform::Render::RenderTarget *pObject; // eax
  Scaleform::Render::D3D1x::ShaderPair v18; // [esp+0h] [ebp-6Ch] BYREF
  Scaleform::String v19; // [esp+14h] [ebp-58h] BYREF
  int v20; // [esp+18h] [ebp-54h]
  unsigned int i; // [esp+28h] [ebp-44h]
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v22; // [esp+30h] [ebp-3Ch]
  Scaleform::Render::Texture *ptexture; // [esp+34h] [ebp-38h]
  Scaleform::Render::ScopedRenderEvent v24; // [esp+38h] [ebp-34h] BYREF
  _DWORD v25[2]; // [esp+3Ch] [ebp-30h] BYREF
  Scaleform::Render::ImageData v26; // [esp+44h] [ebp-28h] BYREF

  v20 = 1;
  v19.pData = (Scaleform::String::DataDesc *)this;
  Scaleform::String::String(
    &v19,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawablePaletteMap");
  v7 = this->GetEvent(this, 19);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v24, v7, v19, v20);
  Scaleform::Render::ImageData::ImageData(&v26);
  v8 = this->GetTextureManager(this);
  v20 = 0;
  v19.pData = 0;
  v9 = v8;
  v10 = v8->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  v25[0] = 256;
  v25[1] = 4;
  v11 = ((int (__thiscall *)(Scaleform::Render::TextureManager *, int, _DWORD *, int, _DWORD, _DWORD))v10->GetDrawableImageFormat)(
          v8,
          1,
          v25,
          192,
          0,
          0);
  v12 = (Scaleform::Render::Texture *)((int (__thiscall *)(Scaleform::Render::TextureManager *, int))v10->CreateTexture)(
                                        v9,
                                        v11);
  v20 = 1;
  v13 = v12;
  v14 = v12->__vftable;
  ptexture = v13;
  if ( v14->Map(v13, &v26, 0, 1u) )
  {
    v15 = 0;
    v22 = values;
    do
    {
      v16 = &v26.pPlanes->pData[v15 * v26.pPlanes->Pitch];
      if ( ((1 << v15) & channelMask) != 0 )
      {
        qmemcpy(v16, v22, 0x400u);
        v13 = ptexture;
      }
      else
      {
        for ( i = 0; i < 0x100; ++i )
        {
          *(_DWORD *)v16 = i << (8 * v15);
          v16 += 4;
        }
      }
      v22 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)((char *)v22 + 1024);
      ++v15;
    }
    while ( v15 < 4 );
    if ( v13->Unmap(v13) )
    {
      Scaleform::Render::HAL::applyBlendMode(this, 0x10u, 1, (Scaleform::String::DataDesc *)1);
      v20 = (int)this->MappedXY16iAlphaTexture[0];
      pObject = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
      v22 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)(pObject->ViewRect.y2 - pObject->ViewRect.y1);
      i = pObject->ViewRect.x2 - pObject->ViewRect.x1;
      if ( Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
             (Scaleform::Render::D3D1x::ShaderInterface *)i,
             this->ShaderData.UniformData,
             ST_start_DrawablePaletteMap,
             (const Scaleform::Render::VertexFormat *)v20) )
      {
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
        qmemcpy((void *)&v18, &this->ShaderData.CurShaders, sizeof(v18));
        Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
          8u,
          ptexture,
          &this->ShaderData,
          v18,
          (Scaleform::Render::ImageFillMode)1,
          0);
        v18.pFDesc = (const Scaleform::Render::D3D1x::FragShaderDesc *)&this->ShaderData;
        v18.pFS = mvp;
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::DrawableFinish(
          v22,
          1u,
          tex,
          texgen,
          *(const Scaleform::Render::Size<int> *)&v18.pFS,
          0,
          (Scaleform::Render::D3D1x::ShaderInterface *)i,
          (int)v22);
        v13 = ptexture;
      }
      this->drawScreenQuad(this);
    }
  }
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v13);
  Scaleform::Render::ImageData::~ImageData(&v26);
  v24.EventObj->End(v24.EventObj);
}
