void __thiscall Scaleform::GFx::AS2::LoadVarsProto::ToString_::_7_::MemberVisitor::Visit(
        Scaleform::GFx::AS2::LoadVarsProto::ToString::__l7::MemberVisitor *this,
        Scaleform::GFx::ASStringNode *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::ASStringNode *v5; // esi
  void *v7; // esi
  Scaleform::String v8; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::StringBuffer src; // [esp+Ch] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&src, Scaleform::Memory::pGlobalHeap);
  Scaleform::String::String(&v8);
  Scaleform::GFx::ASUtils::Escape(*(char **)name->pData, *((_DWORD *)name->pData + 5), &v8);
  Scaleform::StringBuffer::AppendString(
    &src,
    (const __m128i *)((v8.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(v8.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Scaleform::StringBuffer::AppendString(&src, (const __m128i *)"=", 0xFFFFFFFF);
  Scaleform::String::Clear(&v8);
  Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&name, this->pEnvironment, -1, 0);
  v5 = name;
  Scaleform::GFx::ASUtils::Escape((char *)name->pData, name->Size, &v8);
  Scaleform::StringBuffer::AppendString(
    &src,
    (const __m128i *)((v8.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(v8.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Scaleform::StringBuffer::AppendString(&src, (const __m128i *)"&", 0xFFFFFFFF);
  Scaleform::String::operator=(this->pString, &src);
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v7 = (void *)(v8.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v8.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&src);
}
