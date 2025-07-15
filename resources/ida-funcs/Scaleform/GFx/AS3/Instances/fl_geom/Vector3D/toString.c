void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::toString(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  const __m128i ***v4; // esi
  const Scaleform::GFx::ASString *v5; // eax
  Scaleform::String *v6; // eax
  Scaleform::String *v7; // ebp
  const Scaleform::String *v8; // eax
  void *v9; // esi
  const __m128i ***v10; // esi
  Scaleform::String *v11; // edi
  const Scaleform::String *v12; // eax
  void *v13; // esi
  const __m128i *v14; // ecx
  void *v15; // esi
  void *v16; // esi
  void *v17; // esi
  void *v18; // esi
  void *v19; // esi
  void *v20; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::String v24; // [esp+10h] [ebp-5Ch] BYREF
  Scaleform::String v25; // [esp+14h] [ebp-58h] BYREF
  Scaleform::String v26; // [esp+18h] [ebp-54h] BYREF
  Scaleform::String v27; // [esp+1Ch] [ebp-50h] BYREF
  Scaleform::String v28; // [esp+20h] [ebp-4Ch] BYREF
  Scaleform::String v29; // [esp+24h] [ebp-48h] BYREF
  Scaleform::String v30; // [esp+28h] [ebp-44h] BYREF
  Scaleform::String v31; // [esp+2Ch] [ebp-40h] BYREF
  Scaleform::GFx::ASString v32; // [esp+30h] [ebp-3Ch] BYREF
  Scaleform::GFx::ASString v33; // [esp+34h] [ebp-38h] BYREF
  Scaleform::GFx::ASString v34; // [esp+38h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::Value v35; // [esp+3Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+4Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v37; // [esp+5Ch] [ebp-10h] BYREF

  pObject = this->pTraits.pObject;
  v37.value.VNumber = this->z;
  value.value.VNumber = this->y;
  pVM = pObject->pVM;
  v35.value.VNumber = this->x;
  v37.Flags = 4;
  v37.Bonus.pWeakProxy = 0;
  value.Flags = 4;
  value.Bonus.pWeakProxy = 0;
  v35.Flags = 4;
  v35.Bonus.pWeakProxy = 0;
  v4 = (const __m128i ***)Scaleform::GFx::AS3::VM::AsString(pVM, &v33, &value);
  v5 = Scaleform::GFx::AS3::VM::AsString(pVM, &v32, &v35);
  v6 = Scaleform::operator+(&v31, (const __m128i *)"(x=", v5);
  v7 = Scaleform::String::operator+(v6, &v30, (const __m128i *)", y=");
  Scaleform::String::String(&v26, **v4, (unsigned int)(*v4)[5]);
  Scaleform::String::operator+(v7, &v25, v8);
  v9 = (void *)(v26.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v26.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  v10 = (const __m128i ***)Scaleform::GFx::AS3::VM::AsString(pVM, &v34, &v37);
  v11 = Scaleform::String::operator+(&v25, &v29, (const __m128i *)", z=");
  Scaleform::String::String(&v27, **v10, (unsigned int)(*v10)[5]);
  Scaleform::String::operator+(v11, &v24, v12);
  v13 = (void *)(v27.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v27.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  v14 = (const __m128i *)((Scaleform::String::operator+(&v24, &v28, (const __m128i *)")")->HeapTypeBits & 0xFFFFFFFC) + 8);
  Scaleform::GFx::ASString::Append(result, v14, (Scaleform::GFx::ASStringNode *)strlen(v14->m128i_i8));
  v15 = (void *)(v28.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v28.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  v16 = (void *)(v24.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v24.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
  v17 = (void *)(v29.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v29.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
  v18 = (void *)(v25.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v25.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
  v19 = (void *)(v30.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v30.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
  v20 = (void *)(v31.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v31.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
  pNode = v32.pNode;
  --v32.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (v35.Flags & 0x1F) > 9 )
  {
    if ( (v35.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v35);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
  }
  v22 = v33.pNode;
  --v33.pNode->RefCount;
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
  }
  v23 = v34.pNode;
  --v34.pNode->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( (v37.Flags & 0x1F) > 9 )
  {
    if ( (v37.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v37);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v37);
  }
}
