void __usercall Scaleform::GFx::AddSearchInfo_2(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<eax>,
        const __m128i *str1,
        const __m128i *str2,
        const __m128i *str3,
        unsigned int flags1,
        const __m128i *str4,
        const __m128i *str5,
        const __m128i *str6,
        unsigned int flags2)
{
  const __m128i *v10; // eax
  const __m128i *v11; // eax
  Scaleform::String::DataDesc *v12; // ecx
  const __m128i *pData; // eax
  Scaleform::StringBuffer v14; // [esp+4h] [ebp-18h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&v14, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v14, str1, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v14, str2, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v14, str3, 0xFFFFFFFF);
    v10 = (const __m128i *)Scaleform::GFx::FontFlagsToString(flags1);
    Scaleform::StringBuffer::AppendString(&v14, v10, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v14, str4, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v14, str5, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v14, str6, 0xFFFFFFFF);
    v11 = (const __m128i *)Scaleform::GFx::FontFlagsToString(flags2);
    Scaleform::StringBuffer::AppendString(&v14, v11, 0xFFFFFFFF);
    pData = (const __m128i *)v14.pData;
    if ( !v14.pData )
      pData = (const __m128i *)uri;
    Scaleform::GFx::AddSearchInfo(psearchInfo, v12, pData);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v14);
  }
}
