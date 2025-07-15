void __thiscall Scaleform::GFx::SpriteDef::AddFrameName(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::String *name,
        Scaleform::GFx::LogState *plog)
{
  int LoadingFrame; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v5; // eax
  unsigned int SizeMask; // eax
  Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeRef v7; // [esp+4h] [ebp-8h] BYREF

  LoadingFrame = this->LoadingFrame;
  if ( LoadingFrame < 0 || LoadingFrame >= this->FrameCount )
  {
    if ( plog )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "AddFrameName(%d, '%s') -- frame is out of range (frameCount = %d; skipping",
        LoadingFrame,
        (const char *)((name->HeapTypeBits & 0xFFFFFFFC) + 8),
        this->FrameCount);
  }
  else
  {
    v5 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String>(
           (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->NamedFrames,
           name);
    if ( v5 )
    {
      SizeMask = v5->SizeMask;
      if ( plog )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &plog->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "AddFrameName(%d, '%s') -- frame name already assigned to frame %d; overriding",
          this->LoadingFrame,
          (const char *)((name->HeapTypeBits & 0xFFFFFFFC) + 8),
          SizeMask);
    }
    if ( Scaleform::String::GetLength(name) && *(_BYTE *)((name->HeapTypeBits & 0xFFFFFFFC) + 8) == 95 )
    {
      if ( Scaleform::String::operator==(name, "_up") )
      {
        this->Flags |= 1u;
      }
      else if ( Scaleform::String::operator==(name, "_down") )
      {
        this->Flags |= 2u;
      }
      else if ( Scaleform::String::operator==(name, "_over") )
      {
        this->Flags |= 4u;
      }
    }
    plog = (Scaleform::GFx::LogState *)this->LoadingFrame;
    v7.pFirst = name;
    v7.pSecond = (const unsigned int *)&plog;
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      &this->NamedFrames.mHash,
      &this->NamedFrames,
      &v7);
  }
}
