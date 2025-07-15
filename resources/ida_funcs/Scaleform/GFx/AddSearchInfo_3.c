void __usercall Scaleform::GFx::AddSearchInfo_3(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<eax>,
        char *str1,
        char *str2,
        char *str3,
        char *str4,
        char *str5,
        unsigned int flags)
{
  char *v8; // eax
  Scaleform::String::DataDesc *v9; // ecx
  char *pData; // eax
  Scaleform::StringBuffer buf; // [esp+4h] [ebp-18h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&buf, str1, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str2, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str3, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str4, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str5, 0xFFFFFFFF);
    v8 = (char *)Scaleform::GFx::FontFlagsToString(flags);
    Scaleform::StringBuffer::AppendString(&buf, v8, 0xFFFFFFFF);
    pData = buf.pData;
    if ( !buf.pData )
      pData = (char *)&::buf;
    Scaleform::GFx::AddSearchInfo(psearchInfo, v9, pData);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
  }
}
