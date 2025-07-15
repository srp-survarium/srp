void __thiscall Scaleform::GFx::AMP::Server::CollectTaskData(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile)
{
  Scaleform::GFx::AMP::Server *v2; // edi
  unsigned int Size; // ebx
  unsigned int v4; // eax
  unsigned int v5; // esi
  Scaleform::GFx::Resource **v6; // ebp
  Scaleform::RefCountVImpl **v7; // edi
  int v8; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v9; // esi
  unsigned int v10; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_TaskStats; // ebp
  Scaleform::RefCountVImpl **v12; // esi
  unsigned int v13; // edi
  Scaleform::GFx::Resource *v14; // esi
  Scaleform::GFx::AMP::ViewStats *v15; // eax
  Scaleform::GFx::ResourceLibBase *v16; // eax
  Scaleform::GFx::ResourceLibBase *v17; // edi
  Scaleform::RefCountVImpl *pLib; // ecx
  Scaleform::GFx::LoadProcess *v19; // edi
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::ResourceLibBase **p_LoadProcessStats; // edi
  Scaleform::RefCountVImpl *v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edi
  Scaleform::RefCountVImpl **v25; // ebx
  int v26; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // edx
  Scaleform::GFx::Resource **v28; // edi
  unsigned int j; // esi
  Scaleform::GFx::AS3::Instances::fl::Object **v30; // eax
  Scaleform::RefCountVImpl **v31; // esi
  unsigned int v32; // edi
  Scaleform::GFx::Resource **v34; // [esp+1Ch] [ebp-20h]
  Scaleform::GFx::Resource *v35; // [esp+1Ch] [ebp-20h]
  unsigned int i; // [esp+20h] [ebp-1Ch]
  int v37; // [esp+20h] [ebp-1Ch]
  int v38; // [esp+24h] [ebp-18h] BYREF
  int v39; // [esp+28h] [ebp-14h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+2Ch] [ebp-10h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+30h] [ebp-Ch] BYREF

  v2 = this;
  Size = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  lpCriticalSection = &this->LoadProcessLock.cs;
  EnterCriticalSection(&this->LoadProcessLock.cs);
  v4 = 0;
  for ( i = 0; v4 < v2->TaskStats.Data.Size; i = v4 )
  {
    v5 = Size + 1;
    v6 = (Scaleform::GFx::Resource **)&v2->TaskStats.Data.Data[v4];
    v34 = v6;
    if ( Size + 1 >= Size )
    {
      if ( v5 >= pheapAddr.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v5 + (v5 >> 2));
    }
    else
    {
      v7 = (Scaleform::RefCountVImpl **)&pheapAddr.Data[Size - 1];
      v8 = -1;
      do
      {
        if ( *v7 )
          Scaleform::RefCountImpl::Release(*v7);
        --v7;
        --v8;
      }
      while ( v8 );
      v6 = v34;
      if ( v5 < pheapAddr.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v5);
      v2 = this;
    }
    pheapAddr.Size = Size + 1;
    v9 = &pheapAddr.Data[v5 - 1];
    if ( v9 )
    {
      if ( *v6 )
        Scaleform::RefCountImpl::AddRef(*v6);
      *v9 = (Scaleform::GFx::AS3::Instances::fl::Object *)*v6;
    }
    Size = pheapAddr.Size;
    v4 = i + 1;
  }
  v10 = v2->TaskStats.Data.Size;
  p_TaskStats = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v2->TaskStats;
  if ( v10 )
  {
    v12 = (Scaleform::RefCountVImpl **)&p_TaskStats->Data[v10 - 1];
    v13 = v2->TaskStats.Data.Size;
    do
    {
      if ( *v12 )
        Scaleform::RefCountImpl::Release(*v12);
      --v12;
      --v13;
    }
    while ( v13 );
    if ( (p_TaskStats->Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_TaskStats->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_TaskStats->Data);
        p_TaskStats->Data = 0;
      }
      p_TaskStats->Policy.Capacity = 0;
    }
    v2 = this;
  }
  else if ( !v2->TaskStats.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v2->TaskStats,
      &v2->TaskStats,
      0);
  }
  p_TaskStats->Size = 0;
  v37 = 0;
  if ( v2->LoadProcesses.Data.Size )
  {
    while ( 1 )
    {
      v38 = 579;
      v14 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          v2,
                                          12,
                                          &v38);
      if ( v14 )
      {
        v14->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
        v14->RefCount.Value = 1;
        v14->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AMP::Server::RenderProfile::`vftable';
        v14->pLib = 0;
        v39 = 2;
        v15 = (Scaleform::GFx::AMP::ViewStats *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  v14,
                                                  288,
                                                  &v39);
        if ( v15 )
        {
          Scaleform::GFx::AMP::ViewStats::ViewStats(v15);
          v17 = v16;
        }
        else
        {
          v17 = 0;
        }
        pLib = (Scaleform::RefCountVImpl *)v14->pLib;
        if ( pLib )
          Scaleform::RefCountImpl::Release(pLib);
        v14->pLib = v17;
        v2 = this;
        v35 = v14;
      }
      else
      {
        v35 = 0;
        v14 = 0;
      }
      v19 = v2->LoadProcesses.Data.Data[v37];
      pObject = (Scaleform::GFx::Resource *)v19->LoadProcessStats.pObject;
      p_LoadProcessStats = (Scaleform::GFx::ResourceLibBase **)&v19->LoadProcessStats;
      if ( pObject )
        Scaleform::RefCountImpl::AddRef(pObject);
      v22 = (Scaleform::RefCountVImpl *)v14->pLib;
      if ( v22 )
        Scaleform::RefCountImpl::Release(v22);
      v14->pLib = *p_LoadProcessStats;
      v23 = p_TaskStats->Size;
      v24 = v23 + 1;
      if ( v23 + 1 >= v23 )
      {
        if ( v24 >= p_TaskStats->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_TaskStats,
            p_TaskStats,
            v24 + (v24 >> 2));
      }
      else
      {
        v25 = (Scaleform::RefCountVImpl **)&p_TaskStats->Data[v23 - 1];
        v26 = -1;
        do
        {
          if ( *v25 )
            Scaleform::RefCountImpl::Release(*v25);
          --v25;
          --v26;
        }
        while ( v26 );
        v14 = v35;
        if ( v24 < p_TaskStats->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_TaskStats,
            p_TaskStats,
            v24);
        Size = pheapAddr.Size;
      }
      Data = p_TaskStats->Data;
      p_TaskStats->Size = v24;
      v28 = (Scaleform::GFx::Resource **)&Data[v24 - 1];
      if ( v28 )
      {
        if ( v14 )
          Scaleform::RefCountImpl::AddRef(v14);
        *v28 = v14;
      }
      if ( v14 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14);
      if ( ++v37 >= this->LoadProcesses.Data.Size )
        break;
      v2 = this;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  for ( j = 0; j < Size; ++j )
  {
    if ( frameProfile )
      Scaleform::GFx::AMP::Server::RenderProfile::CollectStats(
        (Scaleform::GFx::AMP::Server::RenderProfile *)pheapAddr.Data[j],
        frameProfile);
    Scaleform::GFx::AMP::ViewStats::ClearAmpFunctionStats((Scaleform::GFx::AMP::ViewStats *)pheapAddr.Data[j]->pNext);
  }
  v30 = pheapAddr.Data;
  v31 = (Scaleform::RefCountVImpl **)&pheapAddr.Data[Size - 1];
  if ( Size )
  {
    v32 = Size;
    do
    {
      if ( *v31 )
        Scaleform::RefCountImpl::Release(*v31);
      --v31;
      --v32;
    }
    while ( v32 );
    v30 = pheapAddr.Data;
  }
  if ( v30 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v30);
}
