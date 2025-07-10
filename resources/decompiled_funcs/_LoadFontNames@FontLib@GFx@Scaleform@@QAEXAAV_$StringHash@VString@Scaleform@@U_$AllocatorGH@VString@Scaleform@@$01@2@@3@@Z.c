void __thiscall Scaleform::GFx::FontLib::LoadFontNames(
        Scaleform::GFx::FontLib *this,
        Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *fontnames)
{
  Scaleform::GFx::FontLibImpl *pImpl; // eax
  unsigned int v3; // esi
  Scaleform::GFx::MovieDataDef *pObject; // edi
  Scaleform::GFx::FontDataUseNode *volatile Value; // edi
  char *v6; // eax
  void *v7; // esi
  Scaleform::String fontname; // [esp+Ch] [ebp-14h] BYREF
  unsigned int i; // [esp+10h] [ebp-10h]
  Scaleform::GFx::FontLib *v10; // [esp+14h] [ebp-Ch]
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [esp+18h] [ebp-8h] BYREF

  pImpl = this->pImpl;
  v10 = this;
  if ( pImpl )
  {
    v3 = 0;
    for ( i = 0; v3 < pImpl->FontMovies.Data.Size; i = v3 )
    {
      pObject = pImpl->FontMovies.Data.Data[v3].pObject;
      Scaleform::GFx::MovieDataDef::LoadTaskData::WaitForLoadFinish(pObject->pData.pObject);
      Value = pObject->pData.pObject->BindData.pFonts.Value;
      if ( Value )
      {
        key.pFirst = &fontname;
        key.pSecond = &fontname;
        do
        {
          v6 = (char *)Value->pFontData.pObject->GetName(Value->pFontData.pObject);
          Scaleform::String::String(&fontname, v6);
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
            &fontnames->mHash,
            fontnames,
            &key);
          v7 = (void *)(fontname.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd((volatile LONG *)((fontname.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
          Value = Value->pNext.Value;
        }
        while ( Value );
        v3 = i;
      }
      pImpl = v10->pImpl;
      ++v3;
    }
  }
}
