void __thiscall Scaleform::GFx::AMP::MovieInstructionStats::Read(
        Scaleform::GFx::AMP::MovieInstructionStats *this,
        Scaleform::File *str,
        unsigned int version)
{
  Scaleform::GFx::AMP::MovieInstructionStats *v3; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // eax
  unsigned int v5; // esi
  unsigned int Size; // ebp
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats>,2,Scaleform::ArrayDefaultPolicy> *p_BufferStatsArray; // ebx
  unsigned int v8; // esi
  Scaleform::Ptr<Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats> *v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ebp
  _DWORD *v12; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  int *v14; // esi
  unsigned int v15; // [esp+10h] [ebp-Ch] BYREF
  int v16; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::AMP::MovieInstructionStats *v17; // [esp+18h] [ebp-4h]

  v3 = this;
  Read = str->Read;
  v17 = this;
  v15 = 0;
  Read(str, (unsigned __int8 *)&v15, 4);
  v5 = v15;
  Size = v3->BufferStatsArray.Data.Size;
  p_BufferStatsArray = &v3->BufferStatsArray;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->BufferStatsArray,
    &v3->BufferStatsArray,
    v15);
  if ( v5 > Size )
  {
    v8 = v5 - Size;
    v9 = &p_BufferStatsArray->Data.Data[Size];
    if ( v8 )
    {
      v10 = v8;
      do
      {
        if ( v9 )
          v9->pObject = 0;
        ++v9;
        --v10;
      }
      while ( v10 );
    }
  }
  v11 = 0;
  if ( v3->BufferStatsArray.Data.Size )
  {
    while ( 1 )
    {
      v16 = 578;
      v12 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, v3, 32, &v16);
      if ( v12 )
      {
        *v12 = &Scaleform::RefCountImplCore::`vftable';
        v12[1] = 1;
        *v12 = &Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats::`vftable';
        v12[5] = 0;
        v12[6] = 0;
        v12[7] = 0;
        v16 = (int)v12;
      }
      else
      {
        v16 = 0;
      }
      pObject = (Scaleform::RefCountVImpl *)p_BufferStatsArray->Data.Data[v11].pObject;
      v14 = (int *)&p_BufferStatsArray->Data.Data[v11];
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      *v14 = v16;
      Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats::Read(
        p_BufferStatsArray->Data.Data[v11++].pObject,
        (unsigned int)str,
        version);
      if ( v11 >= v17->BufferStatsArray.Data.Size )
        break;
      v3 = v17;
    }
  }
}
