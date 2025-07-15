void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::trace(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v4; // esi
  unsigned int v5; // ebp
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  bool v8; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  _DWORD *v10; // eax
  void *v11; // esi
  Scaleform::GFx::ASStringNode *v12; // eax
  unsigned int Size; // ebp
  int i; // edi
  unsigned int v15; // esi
  char *pData; // eax
  Scaleform::GFx::AS3::FlashUI *UI; // ecx
  Scaleform::GFx::ASString tmp; // [esp+10h] [ebp-7FCh] BYREF
  Scaleform::GFx::AS3::CheckResult v19; // [esp+17h] [ebp-7F5h] BYREF
  Scaleform::String v20; // [esp+18h] [ebp-7F4h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+1Ch] [ebp-7F0h]
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v22; // [esp+20h] [ebp-7ECh]
  Scaleform::StringBuffer r; // [esp+24h] [ebp-7E8h] BYREF
  char dst[2000]; // [esp+3Ch] [ebp-7D0h] BYREF

  v4 = this;
  v22 = this;
  Scaleform::StringBuffer::StringBuffer(&r, Scaleform::Memory::pGlobalHeap);
  v5 = 0;
  vm = v4->pTraits.pObject->pVM;
  if ( argc )
  {
    while ( 1 )
    {
      if ( v5 )
        Scaleform::StringBuffer::AppendChar(&r, 0x20u);
      pStringManager = v4->pTraits.pObject->pVM->StringManagerRef->pStringManager;
      tmp.pNode = &pStringManager->EmptyStringNode;
      ++pStringManager->EmptyStringNode.RefCount;
      v8 = !Scaleform::GFx::AS3::Value::Convert2String(argv, &v19, &tmp)->Result;
      pNode = tmp.pNode;
      if ( v8 )
        break;
      Scaleform::String::String(&v20, (const __m128i *)tmp.pNode->pData, tmp.pNode->Size);
      Scaleform::StringBuffer::AppendString(&r, (const __m128i *)((*v10 & 0xFFFFFFFC) + 8), 0xFFFFFFFF);
      v11 = (void *)(v20.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v20.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
      v12 = tmp.pNode;
      --tmp.pNode->RefCount;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      ++v5;
      ++argv;
      if ( v5 >= argc )
        goto LABEL_12;
      v4 = v22;
    }
    --tmp.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
LABEL_12:
    Scaleform::StringBuffer::AppendString(&r, (const __m128i *)"\n", 0xFFFFFFFF);
    Size = r.Size;
    for ( i = 0; Size; Size -= v15 )
    {
      v15 = Size;
      if ( Size >= 0x7CF )
        v15 = 1999;
      pData = r.pData;
      if ( !r.pData )
        pData = (char *)uri;
      memcpy((int)dst, (const __m128i *)&pData[i], v15);
      UI = vm->UI;
      dst[v15] = 0;
      UI->Output(UI, Output_Message, dst);
      i += v15;
    }
  }
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&r);
}
