void __thiscall Scaleform::GFx::AS2ValueObjectInterface::ToString(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::String *pstr,
        Scaleform::GFx::Value *thisVal)
{
  Scaleform::GFx::AS2::MovieRoot *pObject; // esi
  int v4; // ecx
  Scaleform::GFx::AS2::Environment *v5; // edi
  Scaleform::GFx::ASStringNode *v6; // edi
  const Scaleform::String *v7; // eax
  void *v8; // esi
  Scaleform::String v10; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value asVal; // [esp+Ch] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v4 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v5 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 124))(v4);
  asVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, thisVal, &asVal);
  Scaleform::GFx::AS2::Value::ToStringImpl(&asVal, (Scaleform::GFx::ASString *)&thisVal, v5, -1, 0);
  v6 = (Scaleform::GFx::ASStringNode *)thisVal;
  Scaleform::String::String(&v10, (char *)thisVal->pObjectInterface);
  Scaleform::String::operator=(pstr, v7);
  v8 = (void *)(v10.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v10.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  if ( v6->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( asVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&asVal);
}
