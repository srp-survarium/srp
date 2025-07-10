void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::parseFloat(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        long double *result,
        const Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int Size; // ebx
  const char *pData; // edi
  int v6; // eax
  const char *ByteIndex; // eax
  void *v8; // esi
  char *v9; // esi
  Scaleform::String stra; // [esp+Ch] [ebp-4h] BYREF

  pNode = str->pNode;
  Size = str->pNode->Size;
  str = 0;
  pData = pNode->pData;
  Scaleform::String::String(&stra, (char *)pNode->pData);
  v6 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&stra);
  ByteIndex = Scaleform::UTF8Util::GetByteIndex(v6, pData, Size);
  v8 = (void *)(stra.HeapTypeBits & 0xFFFFFFFC);
  str = (const Scaleform::GFx::ASString *)ByteIndex;
  if ( InterlockedExchangeAdd((volatile LONG *)((stra.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  v9 = (char *)str + (_DWORD)pData;
  if ( !strncmp((const char *)str + (_DWORD)pData, "0x", 2u) || !strncmp(v9, "0X", 2u) )
    *result = 0.0;
  else
    *result = Scaleform::GFx::NumberUtil::StringToDouble(v9, Size - (unsigned int)str, (unsigned int *)&str);
}
