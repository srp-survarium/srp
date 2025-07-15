void __cdecl Scaleform::Render::ConvertVertices(
        const Scaleform::Render::VertexFormat *sourceFormat,
        unsigned __int8 *psource,
        const Scaleform::Render::VertexFormat *destFormat,
        unsigned __int8 *pdest,
        unsigned int count,
        const void **pargs)
{
  Scaleform::Render::VertexElement *pElements; // edi
  unsigned int Attribute; // ebx
  const Scaleform::Render::VertexFormat *v8; // ebp
  int v9; // eax
  const Scaleform::Render::VertexElement *v10; // eax
  Scaleform::Render::ConvertTarget *v11; // edx
  unsigned int i; // ecx
  Scaleform::Render::VertexElementType TargetType; // ecx
  const void *v14; // ecx

  pElements = destFormat->pElements;
  Attribute = pElements->Attribute;
  if ( Attribute )
  {
    v8 = sourceFormat;
    do
    {
      v9 = pElements->Attribute & 0xF0;
      if ( v9 != 112 && v9 != 128 )
      {
        v10 = v8->pElements;
        v11 = VertexConvertTable[(Attribute >> 8) & 0xF];
        for ( i = v10->Attribute; i; ++v10 )
        {
          if ( (i & 0xFF00) == (pElements->Attribute & 0xFF00) )
            break;
          i = v10[1].Attribute;
        }
        TargetType = v11->TargetType;
        if ( TargetType )
        {
          while ( ((unsigned int)&_sbh_sizeHeaderList & Attribute) == 0 && v10->Attribute != v11->SourceType
               || (Attribute & v11->TargetMask) != TargetType )
          {
            TargetType = v11[1].TargetType;
            ++v11;
            if ( TargetType == VET_None )
            {
              v8 = sourceFormat;
              goto LABEL_14;
            }
          }
          if ( pargs )
            v14 = *pargs;
          else
            v14 = 0;
          v8 = sourceFormat;
          v11->pConvertFunc(
            v10,
            pElements,
            psource,
            sourceFormat->Size,
            v10->Offset,
            pdest,
            destFormat->Size,
            pElements->Offset,
            count,
            v14);
        }
        else
        {
LABEL_14:
          Scaleform::Render::CopyVertexElements(
            (const __m128i *)&psource[v10->Offset],
            v8->Size,
            &pdest[pElements->Offset],
            destFormat->Size,
            *((_DWORD *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<1056964608,1056964608,1056964608,1056964608>'::`2'::v
            + ((unsigned __int8)v10->Attribute >> 4)
            + 3)
          * (v10->Attribute & 0xF),
            count);
        }
      }
      Attribute = pElements[1].Attribute;
      ++pElements;
    }
    while ( Attribute );
  }
}
