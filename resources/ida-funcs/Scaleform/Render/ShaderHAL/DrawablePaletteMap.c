void __thiscall Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::DrawablePaletteMap(
        Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *this,
        Scaleform::Render::Texture **tex,
        Scaleform::Render::Texture **texgen,
        const Scaleform::Render::Matrix2x4<float> *mvp,
        unsigned int channelMask,
        char *values)
{
  Scaleform::Render::RenderEvent *v7; // esi
  Scaleform::Render::RenderEvent v8; // edi
  unsigned int v9; // ecx
  void *v10; // edi
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>_vtbl *v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // esi
  int (__thiscall *v15)(int, int, _DWORD *, int, _DWORD, _DWORD); // edx
  int v16; // eax
  Scaleform::Render::Texture *v17; // edi
  bool (__thiscall *Map)(Scaleform::Render::Texture *, Scaleform::Render::ImageData *, unsigned int, unsigned int); // edx
  Scaleform::Render::Palette *v19; // esi
  int v20; // edx
  unsigned __int8 *v21; // edi
  unsigned int i; // eax
  unsigned int v23; // esi
  Scaleform::Render::Texture *pObject; // edi
  Scaleform::Render::RenderTarget *v25; // eax
  Scaleform::Render::Palette *v26; // esi
  Scaleform::Render::Size<int> v27; // [esp+14h] [ebp-5Ch]
  Scaleform::String v28[5]; // [esp+1Ch] [ebp-54h] BYREF
  char *v29; // [esp+30h] [ebp-40h]
  Scaleform::Render::ScopedRenderEvent GPUEvent; // [esp+34h] [ebp-3Ch]
  Scaleform::String src; // [esp+38h] [ebp-38h] BYREF
  Scaleform::Ptr<Scaleform::Render::Texture> ptex; // [esp+3Ch] [ebp-34h]
  _DWORD v33[2]; // [esp+40h] [ebp-30h] BYREF
  Scaleform::Render::ImageData data; // [esp+48h] [ebp-28h] BYREF

  Scaleform::String::String(
    &src,
    "Scaleform::Render::ShaderHAL<class Scaleform::Render::D3D1x::ShaderManager,class Scaleform::Render::D3D1x::ShaderInt"
    "erface>::DrawablePaletteMap");
  v7 = this->GetEvent(this, 19);
  v8.__vftable = v7->__vftable;
  v28[0].HeapTypeBits = v9;
  GPUEvent.EventObj = v7;
  Scaleform::String::String(v28, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, unsigned int))v8.Begin)(v7, v28[0].HeapTypeBits);
  v10 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  memset(&data, 0, 10);
  memset(&data.pPalette, 0, 24);
  v11 = this->__vftable;
  data.RawPlaneCount = 1;
  data.pPlanes = &data.Plane0;
  v12 = (int)v11->GetTextureManager(this);
  v28[0].HeapTypeBits = 0;
  v13 = v12;
  v14 = *(_DWORD *)v12;
  v15 = *(int (__thiscall **)(int, int, _DWORD *, int, _DWORD, _DWORD))(*(_DWORD *)v12 + 52);
  v33[0] = 256;
  v33[1] = 4;
  v16 = v15(v12, 1, v33, 192, 0, 0);
  v17 = (Scaleform::Render::Texture *)(*(int (__thiscall **)(int, int))(v14 + 4))(v13, v16);
  Map = v17->Map;
  ptex.pObject = v17;
  if ( Map(v17, &data, 0, 1u) )
  {
    v20 = 0;
    v29 = values;
    do
    {
      v21 = &data.pPlanes->pData[v20 * data.pPlanes->Pitch];
      if ( ((1 << v20) & channelMask) != 0 )
      {
        qmemcpy(v21, v29, 0x400u);
      }
      else
      {
        for ( i = 0; i < 0x100; ++i )
        {
          v23 = i << (8 * v20);
          v21 += 4;
          *((_DWORD *)v21 - 1) = v23;
        }
      }
      v29 += 1024;
      pObject = ptex.pObject;
      ++v20;
    }
    while ( v20 < 4 );
    if ( ptex.pObject->Unmap(ptex.pObject) )
    {
      Scaleform::Render::HAL::applyBlendMode(this, Blend_OverwriteAll, 1, 1);
      v25 = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject;
      v27.Height = v25->ViewRect.x2 - v25->ViewRect.x1;
      v27.Width = 0;
      Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetDrawablePaletteMap(
        (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)tex,
        texgen,
        mvp,
        v27,
        (const Scaleform::Render::Matrix2x4<float> *)(v25->ViewRect.y2 - v25->ViewRect.y1),
        pObject,
        this->MappedXY16iAlphaTexture[0],
        &this->ShaderData,
        v28[1].HeapTypeBits);
      this->drawScreenQuad(this);
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
    Scaleform::Render::ImageData::freePlanes(&data);
    if ( data.pPalette.pObject )
    {
      v26 = data.pPalette.pObject;
      if ( InterlockedExchangeAdd(&data.pPalette.pObject->RefCount.Value, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v26);
    }
  }
  else
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v17);
    Scaleform::Render::ImageData::freePlanes(&data);
    if ( data.pPalette.pObject )
    {
      v19 = data.pPalette.pObject;
      if ( InterlockedExchangeAdd(&data.pPalette.pObject->RefCount.Value, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
    }
  }
  GPUEvent.EventObj->End(GPUEvent.EventObj);
}
