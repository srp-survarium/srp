Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS2::GFxCapabilities_ServerString(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::RefCountVImpl *v3; // esi
  int v4; // ebx
  Scaleform::GFx::MovieImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v8; // esi
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // esi
  Scaleform::GFx::InteractiveObject *Target; // edx
  Scaleform::GFx::ASStringNode *v13; // esi
  Scaleform::GFx::ASStringNode *v14; // esi
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // esi
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::String::DataDesc *v19; // esi
  volatile LONG *v20; // esi
  void *v21; // esi
  void *v22; // esi
  void *v23; // esi
  Scaleform::String v25; // [esp+18h] [ebp-74h] BYREF
  int v26; // [esp+1Ch] [ebp-70h] BYREF
  Scaleform::String v27; // [esp+20h] [ebp-6Ch] BYREF
  Scaleform::String v28; // [esp+24h] [ebp-68h] BYREF
  Scaleform::String v29; // [esp+28h] [ebp-64h] BYREF
  Scaleform::GFx::ASStringNode *v30; // [esp+2Ch] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v31; // [esp+30h] [ebp-5Ch] BYREF
  Scaleform::StringBuffer v32; // [esp+40h] [ebp-4Ch] BYREF
  int v33; // [esp+58h] [ebp-34h] BYREF
  int v34; // [esp+5Ch] [ebp-30h]
  int v35; // [esp+60h] [ebp-2Ch]
  int v36; // [esp+64h] [ebp-28h]
  int v37; // [esp+68h] [ebp-24h]
  int v38; // [esp+6Ch] [ebp-20h]
  int v39; // [esp+70h] [ebp-1Ch]
  int v40; // [esp+74h] [ebp-18h]
  int v41; // [esp+78h] [ebp-14h]
  float v42; // [esp+7Ch] [ebp-10h]
  float v43; // [esp+80h] [ebp-Ch]
  float v44; // [esp+84h] [ebp-8h]
  float v45; // [esp+88h] [ebp-4h]

  Scaleform::StringBuffer::StringBuffer(&v32, Scaleform::Memory::pGlobalHeap);
  pMovieImpl = penv->Target->pASRoot->pMovieImpl;
  v3 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(&pMovieImpl->Scaleform::GFx::StateBag, State_Audio);
  if ( v3 )
  {
    v4 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v3->AddRef)(v3);
    Scaleform::RefCountImpl::Release(v3);
  }
  else
  {
    v4 = 0;
  }
  v26 = 0;
  if ( !v4 )
  {
    Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"A=t", 0xFFFFFFFF);
    goto LABEL_8;
  }
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 4))(v4, &v26);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"A=t", 0xFFFFFFFF);
  if ( (v26 & 1) != 0 )
  {
LABEL_8:
    Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&MP3=f", 0xFFFFFFFF);
    goto LABEL_9;
  }
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&MP3=t", 0xFFFFFFFF);
LABEL_9:
  if ( !v4 || (v26 & 4) != 0 )
    Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&SA=f", 0xFFFFFFFF);
  else
    Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&SA=t", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&SV=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&EV=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&IME=", 0xFFFFFFFF);
  v5 = penv->Target->pASRoot->pMovieImpl;
  v6 = (Scaleform::RefCountVImpl *)v5->GetStateAddRef(&v5->Scaleform::GFx::StateBag, State_IMEManager);
  if ( v6 )
  {
    Scaleform::RefCountImpl::Release(v6);
    Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"t", 0xFFFFFFFF);
  }
  else
  {
    Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"f", 0xFFFFFFFF);
  }
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&AE=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&VE=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&ACC=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&PR=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&SP=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&SB=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&DEB=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&V=", 0xFFFFFFFF);
  Scaleform::String::String(&v25);
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "WIN 8,0,0,0",
                      0xBu,
                      0);
  v8 = ConstStringNode;
  ++ConstStringNode->RefCount;
  v9 = ++ConstStringNode->RefCount == 1;
  --ConstStringNode->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  Scaleform::String::String(&v29, (const __m128i *)v8->pData);
  v9 = v8->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  Scaleform::GFx::ASUtils::Escape(
    (char *)((v29.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(v29.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    &v25);
  Scaleform::StringBuffer::AppendString(
    &v32,
    (const __m128i *)((v25.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(v25.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&M=", 0xFFFFFFFF);
  Scaleform::String::Clear(&v25);
  v10 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "Scaleform Windows",
          0x11u,
          0);
  v11 = v10;
  ++v10->RefCount;
  v9 = ++v10->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  Scaleform::String::String(&v28, (const __m128i *)v11->pData);
  v9 = v11->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  Scaleform::GFx::ASUtils::Escape(
    (char *)((v28.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(v28.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    &v25);
  Scaleform::StringBuffer::AppendString(
    &v32,
    (const __m128i *)((v25.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(v25.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Target = penv->Target;
  v45 = 1.0;
  v44 = 1.0;
  v33 = 0;
  v34 = 0;
  v36 = 0;
  v35 = 0;
  v38 = 1;
  v37 = 1;
  v42 = 0.0;
  v41 = 0;
  v40 = 0;
  v39 = 0;
  v43 = 0.0;
  Target->pASRoot->pMovieImpl->GetViewport(Target->pASRoot->pMovieImpl, (Scaleform::GFx::Viewport *)&v33);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&R=", 0xFFFFFFFF);
  v31.T.Type = 4;
  v31.NV.Int32Value = v33;
  Scaleform::GFx::AS2::Value::ToStringImpl(&v31, (Scaleform::GFx::ASString *)&v30, penv, -1, 0);
  v13 = v30;
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)v30->pData, 0xFFFFFFFF);
  v9 = v13->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"x", 0xFFFFFFFF);
  v31.T.Type = 4;
  v31.NV.Int32Value = v34;
  Scaleform::GFx::AS2::Value::ToStringImpl(&v31, (Scaleform::GFx::ASString *)&v30, penv, -1, 0);
  v14 = v30;
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)v30->pData, 0xFFFFFFFF);
  v9 = v14->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&DP=72", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&COL=color", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&AR=1.0", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&OS=", 0xFFFFFFFF);
  Scaleform::String::Clear(&v25);
  v15 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "Windows",
          7u,
          0);
  v16 = v15;
  ++v15->RefCount;
  v9 = ++v15->RefCount == 1;
  --v15->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  Scaleform::String::String(&v27, (const __m128i *)v16->pData);
  v9 = v16->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  Scaleform::GFx::ASUtils::Escape(
    (char *)((v27.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(v27.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    &v25);
  Scaleform::StringBuffer::AppendString(
    &v32,
    (const __m128i *)((v25.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(v25.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&L=en", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&PT=External", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&AVD=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&LFD=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&v32, (const __m128i *)"&WD=f", 0xFFFFFFFF);
  pData = (__m128i *)v32.pData;
  if ( !v32.pData )
    pData = (__m128i *)uri;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 pData,
                 v32.Size);
  ++StringNode->RefCount;
  v19 = v27.pData;
  result->pNode = StringNode;
  v20 = (volatile LONG *)((unsigned int)v19 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v20 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v20);
  v21 = (void *)(v28.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v28.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
  v22 = (void *)(v29.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v29.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
  v23 = (void *)(v25.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v25.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v32);
  return result;
}
