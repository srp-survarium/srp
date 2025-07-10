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
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v14; // esi
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // esi
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::String::DataDesc *v19; // esi
  volatile LONG *v20; // esi
  void *v21; // esi
  void *v22; // esi
  void *v23; // esi
  Scaleform::String etemp; // [esp+18h] [ebp-74h] BYREF
  unsigned int cap_bits; // [esp+1Ch] [ebp-70h] BYREF
  Scaleform::String ostemp; // [esp+20h] [ebp-6Ch] BYREF
  Scaleform::String mtemp; // [esp+24h] [ebp-68h] BYREF
  Scaleform::String vtemp; // [esp+28h] [ebp-64h] BYREF
  Scaleform::GFx::ASString v30; // [esp+2Ch] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v31; // [esp+30h] [ebp-5Ch] BYREF
  Scaleform::StringBuffer temp; // [esp+40h] [ebp-4Ch] BYREF
  Scaleform::GFx::Viewport vp; // [esp+58h] [ebp-34h] BYREF

  Scaleform::StringBuffer::StringBuffer(&temp, Scaleform::Memory::pGlobalHeap);
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
  cap_bits = 0;
  if ( !v4 )
  {
    Scaleform::StringBuffer::AppendString(&temp, "A=t", 0xFFFFFFFF);
    goto LABEL_8;
  }
  (*(void (__thiscall **)(int, unsigned int *))(*(_DWORD *)v4 + 4))(v4, &cap_bits);
  Scaleform::StringBuffer::AppendString(&temp, "A=t", 0xFFFFFFFF);
  if ( (cap_bits & 1) != 0 )
  {
LABEL_8:
    Scaleform::StringBuffer::AppendString(&temp, "&MP3=f", 0xFFFFFFFF);
    goto LABEL_9;
  }
  Scaleform::StringBuffer::AppendString(&temp, "&MP3=t", 0xFFFFFFFF);
LABEL_9:
  if ( !v4 || (cap_bits & 4) != 0 )
    Scaleform::StringBuffer::AppendString(&temp, "&SA=f", 0xFFFFFFFF);
  else
    Scaleform::StringBuffer::AppendString(&temp, "&SA=t", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&SV=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&EV=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&IME=", 0xFFFFFFFF);
  v5 = penv->Target->pASRoot->pMovieImpl;
  v6 = (Scaleform::RefCountVImpl *)v5->GetStateAddRef(&v5->Scaleform::GFx::StateBag, State_IMEManager);
  if ( v6 )
  {
    Scaleform::RefCountImpl::Release(v6);
    Scaleform::StringBuffer::AppendString(&temp, "t", 0xFFFFFFFF);
  }
  else
  {
    Scaleform::StringBuffer::AppendString(&temp, "f", 0xFFFFFFFF);
  }
  Scaleform::StringBuffer::AppendString(&temp, "&AE=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&VE=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&ACC=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&PR=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&SP=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&SB=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&DEB=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&V=", 0xFFFFFFFF);
  Scaleform::String::String(&etemp);
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
  Scaleform::String::String(&vtemp, (char *)v8->pData);
  v9 = v8->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  Scaleform::GFx::ASUtils::Escape(
    (const char *)((vtemp.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(vtemp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    &etemp);
  Scaleform::StringBuffer::AppendString(
    &temp,
    (char *)((etemp.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(etemp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&M=", 0xFFFFFFFF);
  Scaleform::String::Clear(&etemp);
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
  Scaleform::String::String(&mtemp, (char *)v11->pData);
  v9 = v11->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  Scaleform::GFx::ASUtils::Escape(
    (const char *)((mtemp.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(mtemp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    &etemp);
  Scaleform::StringBuffer::AppendString(
    &temp,
    (char *)((etemp.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(etemp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Target = penv->Target;
  vp.AspectRatio = 1.0;
  vp.Scale = 1.0;
  memset(&vp, 0, 16);
  vp.Height = 1;
  vp.Width = 1;
  memset(&vp.ScissorLeft, 0, 20);
  Target->pASRoot->pMovieImpl->GetViewport(Target->pASRoot->pMovieImpl, &vp);
  Scaleform::StringBuffer::AppendString(&temp, "&R=", 0xFFFFFFFF);
  v31.T.Type = 4;
  v31.NV.Int32Value = vp.BufferWidth;
  Scaleform::GFx::AS2::Value::ToStringImpl(&v31, &v30, penv, -1, 0);
  pNode = v30.pNode;
  Scaleform::StringBuffer::AppendString(&temp, (char *)v30.pNode->pData, 0xFFFFFFFF);
  v9 = pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::StringBuffer::AppendString(&temp, "x", 0xFFFFFFFF);
  v31.T.Type = 4;
  v31.NV.Int32Value = vp.BufferHeight;
  Scaleform::GFx::AS2::Value::ToStringImpl(&v31, &v30, penv, -1, 0);
  v14 = v30.pNode;
  Scaleform::StringBuffer::AppendString(&temp, (char *)v30.pNode->pData, 0xFFFFFFFF);
  v9 = v14->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  Scaleform::StringBuffer::AppendString(&temp, "&DP=72", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&COL=color", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&AR=1.0", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&OS=", 0xFFFFFFFF);
  Scaleform::String::Clear(&etemp);
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
  Scaleform::String::String(&ostemp, (char *)v16->pData);
  v9 = v16->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  Scaleform::GFx::ASUtils::Escape(
    (const char *)((ostemp.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(ostemp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    &etemp);
  Scaleform::StringBuffer::AppendString(
    &temp,
    (char *)((etemp.HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(etemp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&L=en", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&PT=External", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&AVD=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&LFD=f", 0xFFFFFFFF);
  Scaleform::StringBuffer::AppendString(&temp, "&WD=f", 0xFFFFFFFF);
  pData = temp.pData;
  if ( !temp.pData )
    pData = (char *)&buf;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 pData,
                 temp.Size);
  ++StringNode->RefCount;
  v19 = ostemp.pData;
  result->pNode = StringNode;
  v20 = (volatile LONG *)((unsigned int)v19 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v20 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v20);
  v21 = (void *)(mtemp.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((mtemp.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
  v22 = (void *)(vtemp.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((vtemp.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
  v23 = (void *)(etemp.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((etemp.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&temp);
  return result;
}
