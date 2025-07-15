void __usercall Scaleform::GFx::AddSearchInfo_2(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<eax>,
        char *str1,
        char *str2,
        char *str3,
        unsigned int flags1,
        char *str4,
        char *str5,
        char *str6,
        unsigned int flags2)
{
  char *v10; // eax
  char *v11; // eax
  Scaleform::String::DataDesc *v12; // ecx
  char *pData; // eax
  Scaleform::StringBuffer buf; // [esp+4h] [ebp-18h] BYREF

  if ( psearchInfo )
  {
    Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::AppendString(&buf, str1, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str2, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str3, 0xFFFFFFFF);
    v10 = (char *)Scaleform::GFx::FontFlagsToString(flags1);
    Scaleform::StringBuffer::AppendString(&buf, v10, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str4, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str5, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&buf, str6, 0xFFFFFFFF);
    v11 = (char *)Scaleform::GFx::FontFlagsToString(flags2);
    Scaleform::StringBuffer::AppendString(&buf, v11, 0xFFFFFFFF);
    pData = buf.pData;
    if ( !buf.pData )
      pData = (char *)&::buf;
    Scaleform::GFx::AddSearchInfo(psearchInfo, v12, pData);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
  }
}
