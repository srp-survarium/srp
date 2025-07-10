void __cdecl Scaleform::Render::ConvertVertexData_ARGB_RGBA(
        const Scaleform::Render::VertexElement *psourceElement,
        const Scaleform::Render::VertexElement *pdestElement,
        unsigned __int8 *psource,
        unsigned int sourceSize,
        unsigned int sourceOffset,
        unsigned __int8 *pdest,
        unsigned int destSize,
        unsigned int destOffset,
        unsigned int count)
{
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // edx
  int v12; // eax
  int v13; // ebx

  v9 = psource;
  v10 = &psource[count * sourceSize];
  if ( psource < v10 )
  {
    v11 = &pdest[destOffset];
    do
    {
      v12 = *(_DWORD *)&v9[sourceOffset];
      v13 = v9[sourceOffset + 2];
      v9 += sourceSize;
      *(_DWORD *)v11 = v12 & 0xFF00FF00 | ((unsigned __int8)v12 << 16) | v13;
      v11 += destSize;
    }
    while ( v9 < v10 );
  }
}
