Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::XMLSupportImpl::EqualsXML(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *resulta,
        Scaleform::GFx::AS3::Instances::fl::XML *l,
        Scaleform::GFx::AS3::Instances::fl::XML *r)
{
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v5; // ebx
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v6; // ebp
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  char *pData; // ecx
  char *v9; // eax
  bool v10; // al
  Scaleform::StringBuffer rbuf; // [esp+10h] [ebp-30h] BYREF
  Scaleform::StringBuffer lbuf; // [esp+28h] [ebp-18h] BYREF

  v5 = l->GetKind(l);
  v6 = r->GetKind(r);
  if ( (v5 == kText || v5 == kAttr) && r->HasSimpleContent(r) || (v6 == kText || v6 == kAttr) && l->HasSimpleContent(l) )
  {
    Scaleform::StringBuffer::StringBuffer(&lbuf, Scaleform::Memory::pGlobalHeap);
    Scaleform::StringBuffer::StringBuffer(&rbuf, Scaleform::Memory::pGlobalHeap);
    l->ToString(l, &lbuf, 0);
    r->ToString(r, &rbuf, 0);
    if ( lbuf.Size != rbuf.Size )
      goto LABEL_15;
    pData = rbuf.pData;
    if ( !rbuf.pData )
      pData = (char *)&buf;
    v9 = lbuf.pData;
    if ( !lbuf.pData )
      v9 = (char *)&buf;
    if ( !strncmp(v9, pData, lbuf.Size) )
      v10 = 1;
    else
LABEL_15:
      v10 = 0;
    *resulta = v10;
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&rbuf);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&lbuf);
    v7 = result;
    result->Result = 1;
  }
  else
  {
    *resulta = l->EqualsInternal(l, r) == true3;
    v7 = result;
    result->Result = 1;
  }
  return v7;
}
