void __cdecl Scaleform::Render::InitVertexData_U8(
        const Scaleform::Render::VertexElement *psourceElement,
        const Scaleform::Render::VertexElement *pdestElement,
        unsigned __int8 *__formal,
        unsigned int a4,
        unsigned int a5,
        unsigned __int8 *pdest,
        unsigned int destSize,
        unsigned int destOffset,
        unsigned int count,
        unsigned __int8 *parg)
{
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // dl
  unsigned __int8 *v12; // ecx

  v10 = pdest;
  v11 = *parg;
  v12 = &pdest[count * destSize];
  if ( pdest < v12 )
  {
    do
    {
      v10[destOffset] = v11;
      v10 += destSize;
    }
    while ( v10 < v12 );
  }
}
