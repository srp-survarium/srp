void __usercall Scaleform::GFx::AddSearchInfo_1(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<eax>,
        const __m128i *str1,
        const __m128i *str2,
        const __m128i *str3,
        unsigned int flags,
        const __m128i *str4)
{
  const __m128i *v7; // eax
  Scaleform::String::DataDesc *v8; // ecx
  const __m128i *pData; // eax
  Scaleform::StringBuffer v10; // [esp+4h] [ebp-18h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&v10, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v10, str1, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v10, str2, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v10, str3, 0xFFFFFFFF);
    v7 = (const __m128i *)Scaleform::GFx::FontFlagsToString(flags);
    Scaleform::StringBuffer::AppendString(&v10, v7, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v10, str4, 0xFFFFFFFF);
    pData = (const __m128i *)v10.pData;
    if ( !v10.pData )
      pData = (const __m128i *)uri;
    Scaleform::GFx::AddSearchInfo(psearchInfo, v8, pData);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v10);
  }
}
