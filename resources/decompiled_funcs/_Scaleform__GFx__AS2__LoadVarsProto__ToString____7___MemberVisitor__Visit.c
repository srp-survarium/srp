void __thiscall Scaleform::GFx::AS2::LoadVarsProto::ToString_::_7_::MemberVisitor::Visit(
        Scaleform::GFx::AS2::LoadVarsProto::ToString::__l7::MemberVisitor *this,
        Scaleform::GFx::ASStringNode *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::ASStringNode *v5; // esi
  void *v7; // esi
  Scaleform::String tmp; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::StringBuffer buf; // [esp+Ch] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
  Scaleform::String::String(&tmp);
  Scaleform::GFx::ASUtils::Escape(*(const char **)name->pData, *((_DWORD *)name->pData + 5), &tmp);
  Scaleform::StringBuffer::AppendString(
    &buf,
    (char *)((tmp.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(tmp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Scaleform::StringBuffer::AppendString(&buf, "=", 0xFFFFFFFF);
  Scaleform::String::Clear(&tmp);
  Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&name, this->pEnvironment, -1, 0);
  v5 = name;
  Scaleform::GFx::ASUtils::Escape(name->pData, name->Size, &tmp);
  Scaleform::StringBuffer::AppendString(
    &buf,
    (char *)((tmp.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(tmp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Scaleform::StringBuffer::AppendString(&buf, "&", 0xFFFFFFFF);
  Scaleform::String::operator=(this->pString, &buf);
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v7 = (void *)(tmp.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((tmp.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
}
