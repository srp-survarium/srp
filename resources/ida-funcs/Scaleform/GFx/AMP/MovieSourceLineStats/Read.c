void __userpurge Scaleform::GFx::AMP::MovieSourceLineStats::Read(
        Scaleform::GFx::AMP::MovieSourceLineStats *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        Scaleform::File *str,
        Scaleform::String version,
        unsigned int a6,
        unsigned int a7)
{
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int Size; // eax
  unsigned int v11; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *p_SourceLineTimings; // ebx
  int v13; // edi
  int (__thiscall *v14)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *Data; // eax
  int (__thiscall *v16)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v17; // eax
  int (__thiscall *v18)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v19; // ebx
  int (__thiscall *v20)(Scaleform::File *, unsigned __int8 *, int); // edx
  void *v21; // edi
  Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [esp+30h] [ebp-18h] BYREF
  _DWORD v24[2]; // [esp+38h] [ebp-10h] BYREF
  unsigned int v25; // [esp+40h] [ebp-8h] BYREF
  unsigned int v26; // [esp+44h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+48h] [ebp+0h] BYREF
  Scaleform::String::DataDesc *file; // [esp+4Ch] [ebp+4h]

  key.pFirst = (const unsigned __int64 *)this;
  if ( version.HeapTypeBits >= 9 )
  {
    Read = str->Read;
    version.pData = 0;
    ((void (__thiscall *)(Scaleform::File *, Scaleform::String *, int, int, int))Read)(str, &version, 4, a2, a3);
    Size = this->SourceLineTimings.Data.Size;
    v11 = a7;
    p_SourceLineTimings = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *)&this->SourceLineTimings;
    if ( a7 >= Size )
    {
      if ( a7 >= p_SourceLineTimings->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_SourceLineTimings,
          p_SourceLineTimings,
          a7 + (a7 >> 2));
    }
    else if ( a7 < p_SourceLineTimings->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_SourceLineTimings,
        p_SourceLineTimings,
        a7);
    }
    p_SourceLineTimings->Size = v11;
    if ( v11 )
    {
      v13 = 0;
      a6 = a7;
      do
      {
        v14 = str->Read;
        v25 = 0;
        v26 = 0;
        v14(str, (unsigned __int8 *)&v25, 8);
        Data = p_SourceLineTimings->Data;
        Data[v13].Priority = v25;
        *(&Data[v13].Priority + 1) = v26;
        v16 = str->Read;
        a7 = 0;
        v16(str, (unsigned __int8 *)&a7, 4);
        p_SourceLineTimings->Data[v13].mFunction.Flags = a7;
        str->Read(str, (unsigned __int8 *)&retaddr, 8);
        v17 = p_SourceLineTimings->Data;
        v17[v13].mFunction.value.VS._1.VInt = 0;
        v17[v13++].mFunction.value.VS._2.VObj = 0;
        --a6;
      }
      while ( a6 );
    }
    v18 = str->Read;
    a7 = 0;
    v18(str, (unsigned __int8 *)&a7, 4);
    if ( version.pData )
    {
      v19 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)key.pFirst
          + 5;
      key.pFirst = (const unsigned __int64 *)v24;
      key.pSecond = &version;
      file = version.pData;
      do
      {
        v20 = str->Read;
        v25 = 0;
        v26 = 0;
        v20(str, (unsigned __int8 *)&v25, 8);
        v24[1] = v26;
        v24[0] = v25;
        Scaleform::String::String(&version);
        Scaleform::GFx::AMP::readString(str, &version);
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          v19,
          v19,
          &key);
        v21 = (void *)(version.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((version.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
        file = (Scaleform::String::DataDesc *)((char *)file - 1);
      }
      while ( file );
    }
  }
}
