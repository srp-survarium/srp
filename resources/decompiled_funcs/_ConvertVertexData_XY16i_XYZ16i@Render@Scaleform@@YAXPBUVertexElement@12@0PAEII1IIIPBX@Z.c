void __cdecl Scaleform::Render::ConvertVertexData_XY16i_XYZ16i(
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
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // edx
  unsigned __int8 *v11; // ecx

  v9 = psource;
  v10 = &psource[count * sourceSize];
  if ( psource < v10 )
  {
    v11 = &pdest[destOffset + 4];
    do
    {
      *((_WORD *)v11 - 2) = *(_WORD *)&v9[sourceOffset];
      *((_WORD *)v11 - 1) = *(_WORD *)&v9[sourceOffset + 2];
      *(_WORD *)v11 = 0;
      v9 += sourceSize;
      v11 += destSize;
    }
    while ( v9 < v10 );
  }
}
