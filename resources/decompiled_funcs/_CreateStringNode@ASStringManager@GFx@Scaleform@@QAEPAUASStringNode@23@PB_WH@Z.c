Scaleform::GFx::ASStringNode *__thiscall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        const wchar_t *pwstr,
        int len)
{
  Scaleform::GFx::ASStringNode *StringNode; // edi
  void *v5; // esi
  Scaleform::String strBuff; // [esp+8h] [ebp-4h] BYREF

  Scaleform::String::String(&strBuff);
  Scaleform::String::AppendString(&strBuff, pwstr, len);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this,
                 (char *)((strBuff.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(strBuff.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  v5 = (void *)(strBuff.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((strBuff.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  return StringNode;
}
