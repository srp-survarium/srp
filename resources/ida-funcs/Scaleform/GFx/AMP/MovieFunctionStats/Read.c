void __thiscall Scaleform::GFx::AMP::MovieFunctionStats::Read(
        Scaleform::GFx::AMP::MovieFunctionStats *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int Size; // eax
  unsigned int v7; // edi
  Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *p_FunctionTimings; // ebx
  int v9; // edi
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::Render::ExternalFontWinAPI::GlyphType *Data; // eax
  int (__thiscall *v12)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v13; // eax
  int (__thiscall *v14)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v15)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v16; // eax
  int (__thiscall *v17)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v18; // edi
  int (__thiscall *v19)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::StringLH *v20; // eax
  Scaleform::StringLH *v21; // ebx
  int (__thiscall *v22)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v23)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v24; // ecx
  int (__thiscall *v25)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v26)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v27; // [esp+58h] [ebp-58h] BYREF
  unsigned int v28; // [esp+5Ch] [ebp-54h] BYREF
  unsigned int v29; // [esp+60h] [ebp-50h] BYREF
  unsigned int v30; // [esp+64h] [ebp-4Ch] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v31; // [esp+68h] [ebp-48h]
  Scaleform::RefCountVImpl *v32; // [esp+6Ch] [ebp-44h] BYREF
  unsigned int v33; // [esp+70h] [ebp-40h]
  int v34; // [esp+74h] [ebp-3Ch] BYREF
  unsigned int v35; // [esp+78h] [ebp-38h] BYREF
  float v36; // [esp+7Ch] [ebp-34h]
  int v37; // [esp+80h] [ebp-30h] BYREF
  int v38; // [esp+84h] [ebp-2Ch]
  float v39; // [esp+88h] [ebp-28h] BYREF
  float v40; // [esp+8Ch] [ebp-24h]
  int v41; // [esp+90h] [ebp-20h] BYREF
  int v42; // [esp+94h] [ebp-1Ch]
  unsigned int v43; // [esp+98h] [ebp-18h] BYREF
  unsigned int v44; // [esp+9Ch] [ebp-14h]
  _DWORD v45[2]; // [esp+A0h] [ebp-10h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [esp+A8h] [ebp-8h] BYREF

  v3 = str;
  Read = str->Read;
  v31 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)this;
  v27 = 0;
  Read(str, (unsigned __int8 *)&v27, 4);
  Size = this->FunctionTimings.Data.Size;
  v7 = v27;
  p_FunctionTimings = (Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *)&this->FunctionTimings;
  if ( v27 >= Size )
  {
    if ( v27 >= p_FunctionTimings->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_FunctionTimings,
        p_FunctionTimings,
        v27 + (v27 >> 2));
  }
  else if ( v27 < p_FunctionTimings->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,Scaleform::AllocatorLH<Scaleform::GFx::AMP::MovieFunctionStats::FuncStats,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_FunctionTimings,
      p_FunctionTimings,
      v27);
  }
  p_FunctionTimings->Size = v7;
  if ( v7 )
  {
    v9 = 0;
    v28 = v27;
    do
    {
      v10 = v3->Read;
      v35 = 0;
      v36 = 0.0;
      v10(v3, (unsigned __int8 *)&v35, 8);
      Data = p_FunctionTimings->Data;
      Data[v9].Code = v35;
      Data[v9].Advance = v36;
      v12 = v3->Read;
      v37 = 0;
      v38 = 0;
      v12(v3, (unsigned __int8 *)&v37, 8);
      v13 = p_FunctionTimings->Data;
      *((_DWORD *)&v13[v9].Advance + 1) = v37;
      *((_DWORD *)&v13[v9].Advance + 2) = v38;
      v14 = v3->Read;
      str = 0;
      v14(v3, (unsigned __int8 *)&str, 4);
      LODWORD(p_FunctionTimings->Data[v9].Bounds.x1) = str;
      v15 = v3->Read;
      v39 = 0.0;
      v40 = 0.0;
      v15(v3, (unsigned __int8 *)&v39, 8);
      v16 = p_FunctionTimings->Data;
      v16[v9].Bounds.x2 = v39;
      v16[v9++].Bounds.y2 = v40;
      --v28;
    }
    while ( v28 );
  }
  v17 = v3->Read;
  v28 = 0;
  v17(v3, (unsigned __int8 *)&v28, 4);
  if ( v28 )
  {
    v18 = version;
    v33 = v28;
    do
    {
      v19 = v3->Read;
      v41 = 0;
      v42 = 0;
      v19(v3, (unsigned __int8 *)&v41, 8);
      v45[0] = v41;
      v45[1] = v42;
      v34 = 578;
      v20 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                     Scaleform::Memory::pGlobalHeap,
                                     v31,
                                     32,
                                     &v34);
      v21 = v20;
      if ( v20 )
      {
        v20->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
        v20[1].HeapTypeBits = 1;
        v20->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::Server::SourceFileInfo::`vftable';
        Scaleform::StringLH::StringLH(v20 + 2);
      }
      else
      {
        v21 = 0;
      }
      Scaleform::GFx::AMP::readString(v3, v21 + 2);
      v22 = v3->Read;
      version = 0;
      v22(v3, (unsigned __int8 *)&version, 4);
      v21[3].HeapTypeBits = version;
      if ( v18 >= 9 )
      {
        v23 = v3->Read;
        v43 = 0;
        v44 = 0;
        v23(v3, (unsigned __int8 *)&v43, 8);
        v24 = v44;
        v21[4].HeapTypeBits = v43;
        v21[5].HeapTypeBits = v24;
        v25 = v3->Read;
        v29 = 0;
        v25(v3, (unsigned __int8 *)&v29, 4);
        v21[6].HeapTypeBits = v29;
        if ( v18 >= 0xD )
        {
          v26 = v3->Read;
          v30 = 0;
          v26(v3, (unsigned __int8 *)&v30, 4);
          v21[7].HeapTypeBits = v30;
        }
      }
      key.pFirst = (const unsigned __int64 *)v45;
      v32 = (Scaleform::RefCountVImpl *)v21;
      key.pSecond = (const Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes> *)&v32;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        v31 + 5,
        &v31[5],
        &key);
      if ( v32 )
        Scaleform::RefCountImpl::Release(v32);
      --v33;
    }
    while ( v33 );
  }
}
