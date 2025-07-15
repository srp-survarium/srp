void __thiscall Scaleform::GFx::AS3::MovieRoot::ProcessLoadBinaryMT(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry,
        Scaleform::GFx::LoadStates *__formal,
        const Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *data,
        unsigned int fileLen,
        bool succeeded)
{
  const Scaleform::GFx::ASString *Name; // eax
  char buf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( succeeded )
  {
    Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(
      (Scaleform::GFx::AS3::Instances::fl_net::URLLoader *)pentry[1].pNext,
      data);
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
