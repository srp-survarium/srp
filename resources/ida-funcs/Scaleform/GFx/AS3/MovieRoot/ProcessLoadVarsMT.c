void __thiscall Scaleform::GFx::AS3::MovieRoot::ProcessLoadVarsMT(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry,
        Scaleform::GFx::LoadStates *__formal,
        const Scaleform::String *data,
        unsigned int fileLen,
        bool succeeded)
{
  const Scaleform::GFx::ASString *Name; // eax
  void *v7; // esi
  Scaleform::String decodedData; // [esp+4h] [ebp-404h] BYREF
  char buf[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( succeeded )
  {
    if ( Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingVariables((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext) )
    {
      Scaleform::String::String(&decodedData);
      Scaleform::GFx::ASUtils::Unescape(
        (const char *)((data->HeapTypeBits & 0xFFFFFFFC) + 8),
        *(_DWORD *)(data->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
        &decodedData);
      Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
        (char *)((decodedData.HeapTypeBits & 0xFFFFFFFC) + 8));
      v7 = (void *)(decodedData.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((decodedData.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
    else if ( Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingText((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext) )
    {
      Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(
        (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
        (char *)((data->HeapTypeBits & 0xFFFFFFFC) + 8));
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingBinary((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
    }
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::ExecuteOpenEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
      fileLen,
      fileLen);
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteCompleteEvent((Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext);
  }
  else
  {
    Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)pentry[1].Type);
    Scaleform::SFsprintf(buf, 0x400u, "Can't open %s", Name->pNode->pData);
    Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
      buf);
  }
}
