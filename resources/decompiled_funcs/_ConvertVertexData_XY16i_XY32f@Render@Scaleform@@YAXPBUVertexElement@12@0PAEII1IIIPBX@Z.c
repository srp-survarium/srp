void __cdecl Scaleform::Render::ConvertVertexData_XY16i_XY32f(
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
  unsigned __int8 *v11; // edx
  float *v12; // ecx
  signed int sourceSizea; // [esp+14h] [ebp+10h]

  v9 = psource;
  v11 = &psource[count * sourceSize];
  if ( psource < v11 )
  {
    v12 = (float *)&pdest[destOffset];
    do
    {
      *v12 = (float)*(__int16 *)&v9[sourceOffset];
      sourceSizea = *(__int16 *)&v9[sourceOffset + 2];
      v9 += sourceSize;
      v12[1] = (float)sourceSizea;
      v12 = (float *)((char *)v12 + destSize);
    }
    while ( v9 < v11 );
  }
}
