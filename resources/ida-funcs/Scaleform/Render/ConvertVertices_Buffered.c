void __cdecl Scaleform::Render::ConvertVertices_Buffered(
        const Scaleform::Render::VertexFormat *sourceFormat,
        unsigned __int8 *psource,
        const Scaleform::Render::VertexFormat *destFormat,
        unsigned __int8 *pdest,
        unsigned int count,
        const void **pargumentData)
{
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int Size; // [esp+Ch] [ebp-2004h]
  __m128i src[512]; // [esp+10h] [ebp-2000h] BYREF

  Size = destFormat->Size;
  v8 = 0x2000 / destFormat->Size;
  v9 = count;
  if ( count )
  {
    while ( 1 )
    {
      if ( v8 > v9 )
        v8 = v9;
      Scaleform::Render::ConvertVertices(sourceFormat, psource, destFormat, (unsigned __int8 *)src, v8, pargumentData);
      memcpy((int)pdest, src, Size * v8);
      psource += v8 * sourceFormat->Size;
      pdest += Size * v8;
      count -= v8;
      if ( !count )
        break;
      v9 = count;
    }
  }
}
