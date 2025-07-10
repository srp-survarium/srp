Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::XMLSupportImpl::EqualsXML(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *stop,
        bool *resulta,
        Scaleform::GFx::AS3::Instances::fl::XML *l,
        Scaleform::GFx::AS3::Value *r)
{
  Scaleform::GFx::AS3::Instances::fl::XML *v6; // esi
  char *v7; // edi
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  char *pData; // ecx
  char *v10; // eax
  bool v11; // al
  Scaleform::StringBuffer r_buf; // [esp+8h] [ebp-30h] BYREF
  Scaleform::StringBuffer l_buf; // [esp+20h] [ebp-18h] BYREF

  v6 = l;
  v7 = (char *)stop;
  *stop = 0;
  if ( v6->HasSimpleContent(v6) )
  {
    Scaleform::StringBuffer::StringBuffer(&l_buf, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::StringBuffer(&r_buf, Scaleform::Memory::pGlobalHeap);
    v6->ToString(v6, &l_buf, 0);
    if ( !Scaleform::GFx::AS3::Value::Convert2String(r, v7, (Scaleform::GFx::AS3::CheckResult *)&stop, &r_buf)->Result )
    {
      result->Result = 0;
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&r_buf);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&l_buf);
      return result;
    }
    if ( l_buf.Size != r_buf.Size )
      goto LABEL_11;
    pData = r_buf.pData;
    if ( !r_buf.pData )
      pData = (char *)&buf;
    v10 = l_buf.pData;
    if ( !l_buf.pData )
      v10 = (char *)&buf;
    if ( !strncmp(v10, pData, r_buf.Size) )
      v11 = 1;
    else
LABEL_11:
      v11 = 0;
    *resulta = v11;
    *v7 = 1;
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&r_buf);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&l_buf);
  }
  v8 = result;
  result->Result = 1;
  return v8;
}
