void __thiscall Scaleform::GFx::AMP::MovieProfile::Read(
        Scaleform::GFx::AMP::MovieProfile *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::File *v3; // esi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v6)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v7)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::String v8; // edi
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v12)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v13)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::StringLH *v14; // eax
  Scaleform::StringLH *v15; // edi
  Scaleform::Ptr<Scaleform::GFx::AMP::MovieProfile::MarkerInfo> *Data; // ebx
  unsigned int v17; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  _DWORD *p_pObject; // ebx
  bool v20; // cf
  int (__thiscall *v21)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v22; // [esp+4Ch] [ebp-3Ch]
  unsigned int v23; // [esp+50h] [ebp-38h]
  unsigned int v24; // [esp+5Ch] [ebp-2Ch]
  unsigned int v25; // [esp+60h] [ebp-28h] BYREF
  unsigned int v26; // [esp+64h] [ebp-24h] BYREF
  unsigned int v27; // [esp+68h] [ebp-20h] BYREF
  unsigned int v28; // [esp+6Ch] [ebp-1Ch] BYREF
  float v29; // [esp+70h] [ebp-18h] BYREF
  float v30; // [esp+74h] [ebp-14h] BYREF
  float v31; // [esp+78h] [ebp-10h] BYREF
  unsigned int v32; // [esp+7Ch] [ebp-Ch] BYREF
  unsigned int v33; // [esp+80h] [ebp-8h] BYREF
  int v34; // [esp+84h] [ebp-4h] BYREF

  v3 = str;
  Read = str->Read;
  v25 = 0;
  Read(str, (unsigned __int8 *)&v25, 4);
  this->ViewHandle = v25;
  v6 = v3->Read;
  v26 = 0;
  v6(v3, (unsigned __int8 *)&v26, 4);
  this->MinFrame = v26;
  v7 = v3->Read;
  v27 = 0;
  v7(v3, (unsigned __int8 *)&v27, 4);
  v8.pData = (Scaleform::String::DataDesc *)version;
  this->MaxFrame = v27;
  if ( v8.HeapTypeBits >= 4 )
  {
    Scaleform::GFx::AMP::readString(v3, &this->ViewName);
    v9 = v3->Read;
    v28 = 0;
    v9(v3, (unsigned __int8 *)&v28, 4);
    v29 = 0.0;
    this->Version = v28;
    v3->Read(v3, (unsigned __int8 *)&v29, 4);
    this->Width = v29;
    v10 = v3->Read;
    v30 = 0.0;
    v10(v3, (unsigned __int8 *)&v30, 4);
    this->Height = v30;
    v11 = v3->Read;
    v31 = 0.0;
    v11(v3, (unsigned __int8 *)&v31, 4);
    this->FrameRate = v31;
    v12 = v3->Read;
    v32 = 0;
    v12(v3, (unsigned __int8 *)&v32, 4);
    this->FrameCount = v32;
  }
  if ( v8.HeapTypeBits >= 6 )
  {
    v13 = v3->Read;
    str = 0;
    v13(v3, (unsigned __int8 *)&str, 4);
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AMP::MovieProfile::MarkerInfo>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::MovieProfile::MarkerInfo>,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->Markers,
      (unsigned int)str);
    v24 = 0;
    if ( str )
    {
      do
      {
        v34 = 578;
        v14 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                       Scaleform::Memory::pGlobalHeap,
                                       this,
                                       16,
                                       &v34);
        v15 = v14;
        if ( v14 )
        {
          v14->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
          v14[1].HeapTypeBits = 1;
          v14->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::Server::SourceFileInfo::`vftable';
          Scaleform::StringLH::StringLH(v14 + 2);
          v33 = (unsigned int)v15;
        }
        else
        {
          v33 = 0;
        }
        Data = this->Markers.Data.Data;
        v17 = v24;
        pObject = (Scaleform::RefCountVImpl *)Data[v24].pObject;
        p_pObject = &Data[v24].pObject;
        if ( pObject )
          Scaleform::RefCountImpl::Release(pObject);
        v20 = version < 0xB;
        *p_pObject = v33;
        if ( v20 )
          Scaleform::String::operator=(&this->Markers.Data.Data[v17].pObject->Name, (const __m128i *)"Marker");
        else
          Scaleform::GFx::AMP::readString(v3, &this->Markers.Data.Data[v17].pObject->Name);
        v21 = v3->Read;
        v33 = 0;
        v21(v3, (unsigned __int8 *)&v33, 4);
        this->Markers.Data.Data[v17].pObject->Number = v33;
        ++v24;
      }
      while ( v24 < (unsigned int)str );
      v8.pData = (Scaleform::String::DataDesc *)version;
    }
  }
  Scaleform::GFx::AMP::MovieInstructionStats::Read(this->InstructionStats.pObject, v3, v8.HeapTypeBits);
  Scaleform::GFx::AMP::MovieFunctionStats::Read(this->FunctionStats.pObject, v3, v8.HeapTypeBits);
  Scaleform::GFx::AMP::MovieSourceLineStats::Read(
    this->SourceLineStats.pObject,
    (int)v8.pData,
    (int)v3,
    v3,
    v8,
    v22,
    v23);
  if ( v8.HeapTypeBits >= 0x19 )
    Scaleform::GFx::AMP::MovieFunctionTreeStats::Read(this->FunctionTreeStats.pObject, v3, v8.HeapTypeBits);
}
