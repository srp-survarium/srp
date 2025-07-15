void __thiscall Scaleform::Render::D3D1x::ShaderManager::MapVertexFormat(
        Scaleform::Render::D3D1x::ShaderManager *this,
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *fill,
        const Scaleform::Render::VertexFormat *sourceFormat,
        const Scaleform::Render::VertexFormat **single,
        Scaleform::FixedSizeHash<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash> **batch,
        const Scaleform::Render::VertexFormat **instanced,
        Scaleform::Render::PrimitiveFillType *flags)
{
  const Scaleform::Render::VertexFormat *v7; // edx
  Scaleform::Render::ProfileViews **p_pElements; // ecx
  const Scaleform::Render::VertexFormat *v9; // esi
  int v10; // eax
  Scaleform::Render::ProfileViews *v11; // ecx
  unsigned int *v12; // edi
  int v13; // eax
  int v14; // [esp+Ch] [ebp-54h]
  int v15; // [esp+10h] [ebp-50h]
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> singlea[3]; // [esp+14h] [ebp-4Ch] BYREF

  singlea[0].VFormats.KeyBuffer.pLast = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *)&singlea[0].VFormats.ValueBuffer.pLast;
  v7 = single[1];
  singlea[0].VFormats.ValueBuffer.pPages = 0;
  v14 = 0;
  v15 = 0;
  if ( v7->pElements )
  {
    p_pElements = (Scaleform::Render::ProfileViews **)&v7->pElements;
    v9 = v7;
    v10 = 0;
    do
    {
      v11 = *p_pElements;
      v12 = (unsigned int *)((char *)&singlea[0].Profiler + v10);
      *(Scaleform::Render::ProfileViews **)((char *)&singlea[0].Profiler + v10) = v11;
      if ( ((unsigned __int16)v11 & 0xF00) == 0x100 )
      {
        *v12 = (unsigned int)v11 & 0xFFFFFF0F | 0x60;
        *(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page **)((char *)&singlea[0].VFormats.ValueBuffer.pLast + v10) = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *)(v14 + v9->Size);
        if ( (*(_BYTE *)v12 & 0xF0) == 0x30 )
          v14 += 4;
      }
      else
      {
        *(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page **)((char *)&singlea[0].VFormats.ValueBuffer.pLast + v10) = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *)(v14 + v9->Size);
      }
      ++v15;
      v10 = 8 * v15;
      v9 = (const Scaleform::Render::VertexFormat *)((char *)v7 + 8 * v15);
      p_pElements = (Scaleform::Render::ProfileViews **)&v9->pElements;
    }
    while ( v9->pElements );
  }
  v13 = 8 * v15;
  *(Scaleform::Render::ProfileViews **)((char *)&singlea[0].Profiler + v13) = 0;
  *(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page **)((char *)&singlea[0].VFormats.ValueBuffer.pLast + v13) = 0;
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::MapVertexFormat(
    singlea,
    fill,
    sourceFormat,
    (const Scaleform::Render::VertexFormat **)singlea,
    batch,
    instanced,
    flags,
    (fill[2452].VFormats.ValueBuffer.pLast == (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *)2
   ? 8
   : 0)
  | 3);
  if ( singlea[0].VFormats.ValueBuffer.pPages )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)singlea[0].VFormats.ValueBuffer.pPages);
}
