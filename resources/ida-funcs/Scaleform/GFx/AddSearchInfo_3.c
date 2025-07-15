void __usercall Scaleform::GFx::AddSearchInfo_3(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<eax>,
        const __m128i *str1,
        const __m128i *str2,
        const __m128i *str3,
        const __m128i *str4,
        const __m128i *str5,
        unsigned int flags)
{
  const __m128i *v8; // eax
  Scaleform::String::DataDesc *v9; // ecx
  const __m128i *pData; // eax
  Scaleform::StringBuffer v11; // [esp+4h] [ebp-18h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&v11, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v11, str1, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v11, str2, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v11, str3, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v11, str4, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v11, str5, 0xFFFFFFFF);
    v8 = (const __m128i *)Scaleform::GFx::FontFlagsToString(flags);
    Scaleform::StringBuffer::AppendString(&v11, v8, 0xFFFFFFFF);
    pData = (const __m128i *)v11.pData;
    if ( !v11.pData )
      pData = (const __m128i *)uri;
    Scaleform::GFx::AddSearchInfo(psearchInfo, v9, pData);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v11);
  }
}
