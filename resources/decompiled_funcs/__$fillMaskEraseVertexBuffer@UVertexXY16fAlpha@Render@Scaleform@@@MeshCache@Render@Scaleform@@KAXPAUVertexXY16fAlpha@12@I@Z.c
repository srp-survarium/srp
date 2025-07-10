void __usercall Scaleform::Render::MeshCache::fillMaskEraseVertexBuffer<Scaleform::Render::VertexXY16fAlpha>(
        Scaleform::Render::VertexXY16fAlpha *pbuffer@<eax>)
{
  const vostok::math::float4x4 *v1; // xmm1_4
  unsigned int v2; // ecx
  unsigned __int8 *Alpha; // eax

  v1 = clear_value;
  v2 = 0;
  Alpha = pbuffer->Alpha;
  do
  {
    *Alpha = v2;
    Alpha[12] = v2;
    Alpha[24] = v2;
    Alpha[36] = v2;
    Alpha[48] = v2;
    Alpha[60] = v2;
    *((_DWORD *)Alpha - 2) = 0;
    *((_DWORD *)Alpha - 1) = v1;
    *((_DWORD *)Alpha + 1) = 0;
    *((_DWORD *)Alpha + 2) = 0;
    *((_DWORD *)Alpha + 4) = v1;
    *((_DWORD *)Alpha + 5) = 0;
    *((_DWORD *)Alpha + 7) = 0;
    *((_DWORD *)Alpha + 8) = v1;
    *((_DWORD *)Alpha + 10) = v1;
    *((_DWORD *)Alpha + 11) = 0;
    *((_DWORD *)Alpha + 13) = v1;
    *((_DWORD *)Alpha + 14) = v1;
    ++v2;
    Alpha += 72;
  }
  while ( v2 < 0x18 );
}
