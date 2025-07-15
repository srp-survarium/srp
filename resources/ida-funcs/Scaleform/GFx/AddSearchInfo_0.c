void __usercall Scaleform::GFx::AddSearchInfo_0(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<eax>,
        const __m128i *str1,
        const __m128i *str2,
        const __m128i *str3)
{
  Scaleform::String::DataDesc *v5; // ecx
  const __m128i *pData; // eax
  Scaleform::StringBuffer v7; // [esp+4h] [ebp-18h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&v7, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&v7, str1, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v7, str2, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&v7, str3, 0xFFFFFFFF);
    pData = (const __m128i *)v7.pData;
    if ( !v7.pData )
      pData = (const __m128i *)uri;
    Scaleform::GFx::AddSearchInfo(psearchInfo, v5, pData);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v7);
  }
}
