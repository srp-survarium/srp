unsigned int __userpurge Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::GetFilterPasses@<eax>(
        const Scaleform::Render::Filter *filter@<ecx>,
        unsigned int *passes@<esi>,
        Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *this,
        unsigned int fillFlags)
{
  char v4; // al
  Scaleform::Render::FilterType Type; // ecx
  volatile int RefCount; // ebp
  char v8; // dl
  unsigned int i; // ecx
  Scaleform::Render::Filter_vtbl *v10; // ebx
  unsigned int v11; // edx
  unsigned int result; // eax
  int v13; // ebx

  v4 = (char)this;
  Type = filter->Type;
  if ( Type > Filter_GradientBevel )
  {
    if ( Type == Filter_ColorMatrix )
    {
      RefCount = 1;
      *passes = 12288;
      if ( ((unsigned __int8)this & 1) != 0 )
      {
        result = 1;
        *passes = 12289;
        return result;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    RefCount = filter[1].RefCount;
    v8 = 0;
    if ( (float)(*(float *)&filter[1].Frozen * *(float *)&filter[1].Type) >= 12800.0 )
    {
      RefCount *= 2;
      v8 = 1;
    }
    for ( i = 0; i < RefCount - 1; ++i )
    {
      passes[i] = v8 != 0 ? 0x4000 : 18432;
      v4 = (char)this;
    }
    v10 = filter[1].__vftable;
    if ( ((unsigned __int8)v10 & 7) == 0 )
      goto LABEL_32;
    if ( ((unsigned __int8)v10 & 7u) <= 2 )
    {
      if ( ((unsigned __int8)v10 & 0x20) != 0 )
      {
        if ( ((unsigned __int8)v10 & 0x50) != 0 )
          passes[i] = 21000;
        else
          passes[i] = 20992;
      }
      else if ( ((unsigned __int8)v10 & 0x50) == 0x40 )
      {
        passes[i] = 20736;
      }
      else
      {
        passes[i] = 20480;
        if ( ((unsigned __int8)v10 & 0x10) != 0 )
          passes[i] = 20488;
      }
      if ( (v4 & 1) != 0 )
      {
        ++passes[i];
        return RefCount;
      }
      return RefCount;
    }
    if ( ((unsigned __int8)v10 & 7) != 3 )
    {
LABEL_32:
      v13 = v8 != 0 ? 0 : 0x800;
      passes[i] = v13 + 0x4000;
      if ( (v4 & 1) != 0 )
      {
        result = RefCount;
        passes[i] = v13 + 16385;
        return result;
      }
      return RefCount;
    }
    if ( ((unsigned __int8)v10 & 0x20) != 0 )
    {
      passes[i] = 21568;
    }
    else if ( (char)v10 >= 0 )
    {
      passes[i] = 21632;
    }
    else if ( ((unsigned __int8)v10 & 0x10) != 0 )
    {
      passes[i] = 21520;
    }
    else
    {
      passes[i] = 21536;
    }
    v11 = passes[i];
    if ( v11 != 21520 && ((unsigned __int8)v10 & 0x10) != 0 )
      passes[i] = v11 + 8;
    if ( (v4 & 1) != 0 )
    {
      ++passes[i];
      return RefCount;
    }
  }
  return RefCount;
}
