void __thiscall Scaleform::GFx::AS3::Classes::fl::XML::AS3setSettings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *o)
{
  unsigned int v4; // ecx
  Scaleform::GFx::AS3::Value::V1U v5; // edi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebx
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  int v8; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v9; // edi
  signed int v10; // eax
  int v11; // eax
  int v12; // ebp
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > v15; // ebp
  signed int v16; // eax
  int v17; // eax
  int v18; // ebp
  Scaleform::GFx::ASStringNode *v19; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > v20; // ebp
  signed int v21; // eax
  int v22; // eax
  int v23; // ebp
  Scaleform::GFx::ASStringNode *v24; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > v25; // ebp
  signed int v26; // eax
  int v27; // eax
  int v28; // ebp
  Scaleform::GFx::ASStringNode *v29; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > v30; // ebp
  signed int v31; // eax
  int v32; // eax
  _DWORD *v33; // edi
  int v34; // eax
  Scaleform::GFx::AS3::Classes::fl::XML *v35; // [esp+4h] [ebp-Ch]
  Scaleform::GFx::AS3::Object::DynAttrsKey key; // [esp+8h] [ebp-8h] BYREF

  v4 = o->Flags & 0x1F;
  v35 = this;
  if ( v4 && (v4 - 12 > 3 || o->value.VS._1.VInt) )
  {
    if ( v4 - 12 <= 3 )
    {
      v5 = o->value.VS._1;
      StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManagerRef->pStringManager,
                          "ignoreComments",
                          0xEu,
                          0);
      ++ConstStringNode->RefCount;
      ++ConstStringNode->RefCount;
      v8 = *(_DWORD *)(v5.VInt + 24);
      v9 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)(v5.VInt + 24);
      key.Flags = 0;
      key.Name.pNode = ConstStringNode;
      if ( v8
        && (v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Object::DynAttrsKey>(
                    v9,
                    &key,
                    (unsigned int)&vostok::memory::s_CRT_arena[5574199]
                  & ConstStringNode->HashFlags
                  & *(_DWORD *)(v8 + 4)),
            v10 >= 0)
        && (v11 = 32 * v10 + v8 + 16) != 0 )
      {
        v12 = v11 + 8;
      }
      else
      {
        v12 = 0;
      }
      v13 = ConstStringNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
      v13 = ConstStringNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
      if ( v12 && (*(_DWORD *)v12 & 0x1F) == 1 )
        v35->ignoreComments = *(_BYTE *)(v12 + 8);
      v14 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              StringManagerRef->pStringManager,
              "ignoreProcessingInstructions",
              0x1Cu,
              0);
      ++v14->RefCount;
      ++v14->RefCount;
      v15.pTable = v9->pTable;
      key.Flags = 0;
      key.Name.pNode = v14;
      if ( v15.pTable
        && (v16 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Object::DynAttrsKey>(
                    v9,
                    &key,
                    (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v14->HashFlags & v15.pTable->SizeMask),
            v16 >= 0)
        && (v17 = (int)&v15.pTable[4 * v16 + 2]) != 0 )
      {
        v18 = v17 + 8;
      }
      else
      {
        v18 = 0;
      }
      v13 = v14->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v13 = v14->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( v18 && (*(_DWORD *)v18 & 0x1F) == 1 )
        v35->ignoreProcessingInstructions = *(_BYTE *)(v18 + 8);
      v19 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              StringManagerRef->pStringManager,
              "ignoreWhitespace",
              0x10u,
              0);
      ++v19->RefCount;
      ++v19->RefCount;
      v20.pTable = v9->pTable;
      key.Flags = 0;
      key.Name.pNode = v19;
      if ( v20.pTable
        && (v21 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Object::DynAttrsKey>(
                    v9,
                    &key,
                    (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v19->HashFlags & v20.pTable->SizeMask),
            v21 >= 0)
        && (v22 = (int)&v20.pTable[4 * v21 + 2]) != 0 )
      {
        v23 = v22 + 8;
      }
      else
      {
        v23 = 0;
      }
      v13 = v19->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      v13 = v19->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      if ( v23 && (*(_DWORD *)v23 & 0x1F) == 1 )
        v35->ignoreWhitespace = *(_BYTE *)(v23 + 8);
      v24 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              StringManagerRef->pStringManager,
              "prettyPrinting",
              0xEu,
              0);
      ++v24->RefCount;
      ++v24->RefCount;
      v25.pTable = v9->pTable;
      key.Flags = 0;
      key.Name.pNode = v24;
      if ( v25.pTable
        && (v26 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Object::DynAttrsKey>(
                    v9,
                    &key,
                    (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v24->HashFlags & v25.pTable->SizeMask),
            v26 >= 0)
        && (v27 = (int)&v25.pTable[4 * v26 + 2]) != 0 )
      {
        v28 = v27 + 8;
      }
      else
      {
        v28 = 0;
      }
      v13 = v24->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      v13 = v24->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( v28 && (*(_DWORD *)v28 & 0x1F) == 1 )
        v35->prettyPrinting = *(_BYTE *)(v28 + 8);
      v29 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              StringManagerRef->pStringManager,
              "prettyIndent",
              0xCu,
              0);
      ++v29->RefCount;
      ++v29->RefCount;
      v30.pTable = v9->pTable;
      key.Flags = 0;
      key.Name.pNode = v29;
      if ( v30.pTable
        && (v31 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Object::DynAttrsKey>(
                    v9,
                    &key,
                    (unsigned int)&vostok::memory::s_CRT_arena[5574199] & v29->HashFlags & v30.pTable->SizeMask),
            v31 >= 0)
        && (v32 = (int)&v30.pTable[4 * v31 + 2]) != 0 )
      {
        v33 = (_DWORD *)(v32 + 8);
      }
      else
      {
        v33 = 0;
      }
      v13 = v29->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      v13 = v29->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      if ( v33 )
      {
        v34 = *v33 & 0x1F;
        if ( v34 == 2 || v34 == 3 )
          v35->prettyIndent = v33[2];
      }
    }
  }
  else
  {
    this->ignoreComments = 1;
    this->ignoreProcessingInstructions = 1;
    this->ignoreWhitespace = 1;
    this->prettyPrinting = 1;
    this->prettyIndent = 2;
  }
}
