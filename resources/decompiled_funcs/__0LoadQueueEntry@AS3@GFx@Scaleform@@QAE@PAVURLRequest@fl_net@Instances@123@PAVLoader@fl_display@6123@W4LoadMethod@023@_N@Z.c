void __thiscall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request,
        Scaleform::GFx::AS3::Instances::fl_display::Loader *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool quietOpen)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // ebp
  char *pData; // eax
  Scaleform::GFx::LoadQueueEntry::LoadMethod v8; // edx
  bool v9; // cl
  void *v10; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v11; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v13; // [esp-Ch] [ebp-18h]

  v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)request;
  if ( request )
    pData = (char *)Scaleform::GFx::AS3::Instances::fl::XML::GetName(request)->pNode->pData;
  else
    pData = (char *)&buf;
  Scaleform::String::String((Scaleform::String *)&request, pData);
  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntry_vtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable';
  Scaleform::String::String(&this->URL);
  v8 = method;
  this->Type = ((unsigned int)request & 0xFFFFFFFC) == -8;
  this->Method = v8;
  this->pNext = 0;
  Scaleform::String::operator=(&this->URL, (const Scaleform::String *)&request);
  v9 = quietOpen;
  v10 = (void *)((unsigned int)request & 0xFFFFFFFC);
  v13 = (volatile LONG *)(((unsigned int)request & 0xFFFFFFFC) + 4);
  this->EntryTime = -1;
  this->QuietOpen = v9;
  this->Canceled = 0;
  if ( InterlockedExchangeAdd(v13, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  v11 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)loader;
  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntry_vtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable';
  this->mLoader.pObject = 0;
  this->mURLLoader.pObject = 0;
  this->mURLRequest.pObject = 0;
  this->mBytes.pObject = 0;
  this->mBytes.Owner = 1;
  this->NotifyLoadInitCInterface.pObject = 0;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->mLoader,
    v11);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->mURLRequest,
    v5);
  this->FirstExec = 1;
  pObject = (Scaleform::RefCountVImpl *)this->NotifyLoadInitCInterface.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->NotifyLoadInitCInterface.pObject = 0;
}
