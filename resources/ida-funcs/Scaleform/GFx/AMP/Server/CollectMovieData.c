void __thiscall Scaleform::GFx::AMP::Server::CollectMovieData(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile)
{
  unsigned int v3; // ebp
  unsigned int v4; // eax
  unsigned int v5; // esi
  int v6; // ebp
  Scaleform::RefCountVImpl **v7; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v8; // esi
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_MovieStats; // ebx
  Scaleform::RefCountVImpl **v11; // esi
  unsigned int v12; // edi
  Scaleform::GFx::Resource *v13; // esi
  Scaleform::GFx::MovieImpl *v14; // edi
  Scaleform::GFx::Resource *pObject; // ecx
  unsigned int v16; // eax
  unsigned int v17; // edi
  Scaleform::RefCountVImpl **v18; // esi
  int v19; // ebp
  _DWORD *p_pObject; // esi
  unsigned int v21; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v22; // esi
  Scaleform::RefCountVImpl **v23; // edi
  unsigned int v24; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v25; // eax
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // ebx
  unsigned int k; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v28; // esi
  Scaleform::RefCountVImpl **m; // esi
  Scaleform::GFx::Resource **v30; // [esp+10h] [ebp-20h]
  Scaleform::GFx::Resource *v31; // [esp+10h] [ebp-20h]
  unsigned int i; // [esp+18h] [ebp-18h]
  unsigned int j; // [esp+18h] [ebp-18h]
  unsigned int v35; // [esp+18h] [ebp-18h]
  int v36; // [esp+1Ch] [ebp-14h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+20h] [ebp-10h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+24h] [ebp-Ch] BYREF

  v3 = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  lpCriticalSection = &this->MovieLock.cs;
  EnterCriticalSection(&this->MovieLock.cs);
  v4 = 0;
  for ( i = 0; v4 < this->MovieStats.Data.Size; i = v4 )
  {
    v5 = v3 + 1;
    v30 = (Scaleform::GFx::Resource **)&this->MovieStats.Data.Data[v4];
    if ( v3 + 1 >= v3 )
    {
      if ( v5 >= pheapAddr.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v5 + (v5 >> 2));
    }
    else
    {
      v6 = -1;
      v7 = (Scaleform::RefCountVImpl **)&pheapAddr.Data[v5 - 2];
      do
      {
        if ( *v7 )
          Scaleform::RefCountImpl::Release(*v7);
        --v7;
        --v6;
      }
      while ( v6 );
      if ( v5 < pheapAddr.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v5);
    }
    v3 = v5;
    v8 = &pheapAddr.Data[v5 - 1];
    pheapAddr.Size = v3;
    if ( v8 )
    {
      if ( *v30 )
        Scaleform::RefCountImpl::AddRef(*v30);
      *v8 = (Scaleform::GFx::AS3::Instances::fl::Object *)*v30;
    }
    v4 = i + 1;
  }
  Size = this->MovieStats.Data.Size;
  p_MovieStats = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->MovieStats;
  if ( Size )
  {
    v11 = (Scaleform::RefCountVImpl **)&p_MovieStats->Data[Size - 1];
    v12 = Size;
    do
    {
      if ( *v11 )
        Scaleform::RefCountImpl::Release(*v11);
      --v11;
      --v12;
    }
    while ( v12 );
    if ( (p_MovieStats->Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_MovieStats->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_MovieStats->Data);
        p_MovieStats->Data = 0;
      }
      p_MovieStats->Policy.Capacity = 0;
    }
  }
  else if ( !p_MovieStats->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_MovieStats,
      p_MovieStats,
      0);
  }
  p_MovieStats->Size = 0;
  for ( j = 0; j < this->Movies.Data.Size; ++j )
  {
    v36 = 579;
    v13 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                        Scaleform::Memory::pGlobalHeap,
                                        this,
                                        12,
                                        &v36);
    if ( v13 )
    {
      v14 = this->Movies.Data.Data[j];
      v13->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v13->RefCount.Value = 1;
      v13->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::Server::RenderProfile::`vftable';
      pObject = (Scaleform::GFx::Resource *)v14->AdvanceStats.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::AddRef(pObject);
      v13->pLib = (Scaleform::GFx::ResourceLibBase *)v14->AdvanceStats.pObject;
      v31 = v13;
    }
    else
    {
      v31 = 0;
    }
    v16 = p_MovieStats->Size;
    v17 = v16 + 1;
    if ( v16 + 1 >= v16 )
    {
      if ( v17 >= p_MovieStats->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_MovieStats,
          p_MovieStats,
          v17 + (v17 >> 2));
    }
    else
    {
      v18 = (Scaleform::RefCountVImpl **)&p_MovieStats->Data[v16 - 1];
      v19 = -1;
      do
      {
        if ( *v18 )
          Scaleform::RefCountImpl::Release(*v18);
        --v18;
        --v19;
      }
      while ( v19 );
      if ( v17 < p_MovieStats->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_MovieStats,
          p_MovieStats,
          v17);
      v3 = pheapAddr.Size;
    }
    p_pObject = &p_MovieStats->Data[v17 - 1].pObject;
    p_MovieStats->Size = v17;
    if ( p_pObject )
    {
      if ( v31 )
        Scaleform::RefCountImpl::AddRef(v31);
      *p_pObject = v31;
    }
    if ( v31 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v31);
  }
  LeaveCriticalSection(lpCriticalSection);
  if ( frameProfile )
  {
    v21 = frameProfile->MovieStats.Data.Size;
    v22 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&frameProfile->MovieStats;
    if ( v3 >= v21 )
    {
      if ( v3 >= frameProfile->MovieStats.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v22,
          v22,
          v3 + (v3 >> 2));
    }
    else
    {
      v23 = (Scaleform::RefCountVImpl **)&v22->Data[v21 - 1];
      if ( v21 != v3 )
      {
        v35 = v21 - v3;
        do
        {
          if ( *v23 )
            Scaleform::RefCountImpl::Release(*v23);
          --v23;
          --v35;
        }
        while ( v35 );
      }
      if ( v3 < frameProfile->MovieStats.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v22,
          v22,
          v3);
    }
    frameProfile->MovieStats.Data.Size = v3;
    if ( v3 > v21 )
    {
      v24 = v3 - v21;
      v25 = &v22->Data[v21];
      if ( v3 != v21 )
      {
        do
        {
          if ( v25 )
            v25->pObject = 0;
          ++v25;
          --v24;
        }
        while ( v24 );
      }
    }
  }
  Data = pheapAddr.Data;
  for ( k = 0; k < v3; ++k )
  {
    if ( frameProfile )
      Scaleform::GFx::AMP::Server::ViewProfile::CollectStats(
        (Scaleform::GFx::AMP::Server::ViewProfile *)Data[k],
        frameProfile,
        k);
    v28 = Data[k];
    Scaleform::GFx::AMP::ViewStats::ClearAmpFunctionStats((Scaleform::GFx::AMP::ViewStats *)v28->pNext);
    Scaleform::GFx::AMP::ViewStats::ClearAmpInstructionStats((Scaleform::GFx::AMP::ViewStats *)v28->pNext);
    Scaleform::GFx::AMP::ViewStats::ClearAmpSourceLineStats((Scaleform::GFx::AMP::ViewStats *)v28->pNext);
    Scaleform::GFx::AMP::ViewStats::ClearMarkers((Scaleform::GFx::AMP::ViewStats *)v28->pNext);
    Scaleform::GFx::AMP::ViewStats::ClearGcStats((Scaleform::GFx::AMP::ViewStats *)v28->pNext);
  }
  for ( m = (Scaleform::RefCountVImpl **)&Data[v3 - 1]; v3; --v3 )
  {
    if ( *m )
      Scaleform::RefCountImpl::Release(*m);
    --m;
  }
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
