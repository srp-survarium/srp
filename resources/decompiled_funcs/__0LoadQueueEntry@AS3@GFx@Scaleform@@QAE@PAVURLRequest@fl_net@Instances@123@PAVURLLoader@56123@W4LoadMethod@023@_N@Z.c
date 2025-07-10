void __thiscall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request,
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool quietOpen)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // ebp
  char *pData; // eax
  bool v8; // al
  void *v9; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v10; // edx
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v12; // [esp-Ch] [ebp-18h]

  v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)request;
  if ( request )
    pData = (char *)Scaleform::GFx::AS3::Instances::fl::XML::GetName(request)->pNode->pData;
  else
    pData = (char *)&buf;
  Scaleform::String::String((Scaleform::String *)&request, pData);
  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntry_vtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable';
  Scaleform::String::String(&this->URL);
  this->Method = method;
  this->Type = LT_LoadText;
  this->pNext = 0;
  Scaleform::String::operator=(&this->URL, (const Scaleform::String *)&request);
  v8 = quietOpen;
  v9 = (void *)((unsigned int)request & 0xFFFFFFFC);
  v12 = (volatile LONG *)(((unsigned int)request & 0xFFFFFFFC) + 4);
  this->EntryTime = -1;
  this->QuietOpen = v8;
  this->Canceled = 0;
  if ( InterlockedExchangeAdd(v12, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)loader;
  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntry_vtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable';
  this->mLoader.pObject = 0;
  this->mURLLoader.pObject = 0;
  this->mURLRequest.pObject = 0;
  this->mBytes.pObject = 0;
  this->mBytes.Owner = 1;
  this->NotifyLoadInitCInterface.pObject = 0;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->mURLLoader,
    v10);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->mURLRequest,
    v5);
  this->FirstExec = 1;
  pObject = (Scaleform::RefCountVImpl *)this->NotifyLoadInitCInterface.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->NotifyLoadInitCInterface.pObject = 0;
}
