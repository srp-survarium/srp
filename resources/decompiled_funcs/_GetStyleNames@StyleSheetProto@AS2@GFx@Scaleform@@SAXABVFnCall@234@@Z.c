void __cdecl Scaleform::GFx::AS2::StyleSheetProto::GetStyleNames(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  Scaleform::GFx::AS2::ArrayObject *v3; // ebx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebp
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> > *Styles; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> > v6; // ecx
  unsigned int v7; // edx
  unsigned int SizeMask; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> >::TableType *v9; // ecx
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> > *pHash; // edi
  int Index; // esi
  int v12; // esi
  Scaleform::GFx::ASStringNode *StringNode; // esi
  void *v15; // esi
  unsigned int RefCount; // eax
  Scaleform::String temp; // [esp+4h] [ebp-20h] BYREF
  Scaleform::Render::GlyphCache *v18; // [esp+8h] [ebp-1Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> >::ConstIterator iter; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+14h] [ebp-10h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_StyleSheet )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        v3 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                   fn->Env,
                                                   fn->Env->StringContext.pContext->pGlobal.pObject,
                                                   (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
                                                   0,
                                                   -1);
        p_StringContext = &fn->Env->StringContext;
        Scaleform::String::String(&temp);
        v18 = (Scaleform::Render::GlyphCache *)&p_pProto[13];
        Styles = (const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> > *)Scaleform::GFx::Text::StyleManager::GetStyles((Scaleform::Render::GlyphCache *)&p_pProto[13]);
        v6.pTable = Styles->pTable;
        if ( Styles->pTable )
        {
          SizeMask = v6.pTable->SizeMask;
          v7 = 0;
          v9 = v6.pTable + 1;
          do
          {
            if ( v9->EntryCount != -2 )
              break;
            ++v7;
            v9 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> >::TableType *)((char *)v9 + 20);
          }
          while ( v7 <= SizeMask );
        }
        else
        {
          Styles = 0;
          v7 = 0;
        }
        pHash = Styles;
        Index = v7;
        iter.pHash = Styles;
        iter.Index = v7;
        while ( 1 )
        {
          Scaleform::GFx::Text::StyleManager::GetStyles(v18);
          if ( !pHash || !pHash->pTable || Index > (signed int)pHash->pTable->SizeMask )
            break;
          Scaleform::String::Clear(&temp);
          v12 = 20 * Index;
          if ( *(unsigned int *)((char *)&pHash->pTable[1].SizeMask + v12) == 1 )
            Scaleform::String::AppendChar(&temp, 0x2Eu);
          Scaleform::String::operator+=(&temp, (const Scaleform::String *)((char *)&pHash->pTable[2] + v12));
          StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                         (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                         (char *)((temp.HeapTypeBits & 0xFFFFFFFC) + 8),
                         *(_DWORD *)(temp.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
          ++StringNode->RefCount;
          ++StringNode->RefCount;
          val.T.Type = 5;
          val.NV.Int32Value = (int)StringNode;
          Scaleform::GFx::AS2::ArrayObject::PushBack(v3, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          if ( StringNode->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF>>::ConstIterator::operator++(&iter);
          Index = iter.Index;
          pHash = iter.pHash;
        }
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v3);
        v15 = (void *)(temp.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((temp.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
        if ( v3 )
        {
          RefCount = v3->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v3->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "StyleSheet");
  }
}
