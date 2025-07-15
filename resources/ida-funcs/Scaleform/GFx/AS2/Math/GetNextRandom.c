unsigned int __usercall Scaleform::GFx::AS2::Math::GetNextRandom@<eax>(int a1@<ebx>, Scaleform::String proot)
{
  Scaleform::RefCountVImpl *v2; // eax
  _DWORD *v3; // esi
  unsigned int Random; // edi
  void *v6; // esi
  Scaleform::LongFormatter v7; // [esp+Ch] [ebp-50h] BYREF

  v2 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(char *, int))(*(_DWORD *)proot.pData->Data + 12))(
                                     proot.pData->Data,
                                     31);
  v3 = &v2->__vftable;
  if ( !v2 )
    return Scaleform::Alg::Random::NextRandom();
  Scaleform::RefCountImpl::Release(v2);
  if ( !v3[3] )
  {
    Random = Scaleform::Alg::Random::NextRandom();
    Scaleform::LongFormatter::LongFormatter(&v7, Random);
    Scaleform::LongFormatter::Convert(&v7);
    (*(void (__thiscall **)(_DWORD *, const char *, char *))(*v3 + 8))(v3, "random", v7.ValueStr);
    v7.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Formatter::~Formatter(&v7);
    return Random;
  }
  Scaleform::String::String(&proot);
  (*(void (__thiscall **)(_DWORD *, const char *, Scaleform::String *))(*v3 + 4))(v3, "random", &proot);
  Random = strtoul(a1, (const char *)((proot.HeapTypeBits & 0xFFFFFFFC) + 8), 0, 10);
  v6 = (void *)(proot.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((proot.HeapTypeBits & 0xFFFFFFFC) + 4), -1) != 1 )
    return Random;
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  return Random;
}
