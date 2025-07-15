void __cdecl Scaleform::Render::CopyVertexElements(
        const __m128i *source,
        unsigned int sourceFormatSize,
        unsigned __int8 *dest,
        unsigned int destFormatSize,
        unsigned int elementSize,
        unsigned int count)
{
  const __m128i *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // ebp
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax

  v6 = source;
  v7 = &source->m128i_u8[count * sourceFormatSize];
  switch ( elementSize )
  {
    case 1u:
      if ( source < (const __m128i *)v7 )
      {
        v11 = dest;
        do
        {
          *v11 = v6->m128i_i8[0];
          v6 = (const __m128i *)((char *)v6 + sourceFormatSize);
          v11 += destFormatSize;
        }
        while ( v6 < (const __m128i *)v7 );
      }
      break;
    case 2u:
      if ( source < (const __m128i *)v7 )
      {
        v10 = dest;
        do
        {
          *(_WORD *)v10 = v6->m128i_i16[0];
          v6 = (const __m128i *)((char *)v6 + sourceFormatSize);
          v10 += destFormatSize;
        }
        while ( v6 < (const __m128i *)v7 );
      }
      break;
    case 4u:
      if ( source < (const __m128i *)v7 )
      {
        v9 = dest;
        do
        {
          *(_DWORD *)v9 = v6->m128i_i32[0];
          v6 = (const __m128i *)((char *)v6 + sourceFormatSize);
          v9 += destFormatSize;
        }
        while ( v6 < (const __m128i *)v7 );
      }
      break;
    default:
      if ( source < (const __m128i *)v7 )
      {
        v8 = dest;
        do
        {
          memcpy((int)v8, v6, elementSize);
          v8 += destFormatSize;
          v6 = (const __m128i *)((char *)v6 + sourceFormatSize);
        }
        while ( v6 < (const __m128i *)v7 );
      }
      break;
  }
}
