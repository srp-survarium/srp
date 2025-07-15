void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::parseFloat(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        long double *result,
        const Scaleform::GFx::ASString *str)
{
  const __m128i **pNode; // eax
  unsigned int Size; // ebx
  __m128i *v5; // edi
  int v6; // eax
  char *ByteIndex; // eax
  void *v8; // esi
  __m128i *v9; // esi
  Scaleform::String stra; // [esp+Ch] [ebp-4h] BYREF

  pNode = (const __m128i **)str->pNode;
  Size = str->pNode->Size;
  str = 0;
  v5 = (__m128i *)*pNode;
  Scaleform::String::String(&stra, *pNode);
  v6 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&stra);
  ByteIndex = Scaleform::UTF8Util::GetByteIndex(v6, v5->m128i_i8, Size);
  v8 = (void *)(stra.HeapTypeBits & 0xFFFFFFFC);
  str = (const Scaleform::GFx::ASString *)ByteIndex;
  if ( InterlockedExchangeAdd((volatile LONG *)((stra.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  v9 = (__m128i *)((char *)str + (_DWORD)v5);
  if ( !strncmp((const char *)str + (_DWORD)v5, "0x", 2u) || !strncmp(v9->m128i_i8, "0X", 2u) )
    *result = 0.0;
  else
    *result = Scaleform::GFx::NumberUtil::StringToDouble(v9, Size - (unsigned int)str, (Scaleform::String)&str);
}
