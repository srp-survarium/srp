void __thiscall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        Scaleform::GFx::AS3::Instances::fl_display::Loader *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry::LoadType v5; // eax
  void *v6; // edi
  int **p_mBytes; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // eax
  unsigned int Length; // ebx
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *v11; // edi
  volatile LONG *v12; // [esp-8h] [ebp-1Ch]
  Scaleform::String src; // [esp+10h] [ebp-4h] BYREF

  Scaleform::String::String(&src, (const __m128i *)uri);
  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntry_vtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable';
  Scaleform::String::String(&this->URL);
  v5 = (src.HeapTypeBits & 0xFFFFFFFC) == -8;
  this->Method = method;
  this->Type = v5;
  this->pNext = 0;
  Scaleform::String::operator=(&this->URL, &src);
  v6 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  v12 = (volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4);
  this->EntryTime = -1;
  this->QuietOpen = 0;
  this->Canceled = 0;
  if ( InterlockedExchangeAdd(v12, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntry_vtbl *)&Scaleform::GFx::AS3::LoadQueueEntry::`vftable';
  this->mLoader.pObject = 0;
  this->mURLLoader.pObject = 0;
  this->mURLRequest.pObject = 0;
  p_mBytes = (int **)&this->mBytes;
  this->mBytes.pObject = 0;
  this->mBytes.Owner = 1;
  this->NotifyLoadInitCInterface.pObject = 0;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->mLoader,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)loader);
  this->FirstExec = 1;
  pObject = (Scaleform::RefCountVImpl *)this->NotifyLoadInitCInterface.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->NotifyLoadInitCInterface.pObject = 0;
  method = LM_Post;
  v9 = (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                               Scaleform::Memory::pGlobalHeap,
                                                                               this,
                                                                               12,
                                                                               &method);
  if ( v9 )
  {
    v9->Data.Data = 0;
    v9->Data.Size = 0;
    v9->Data.Policy.Capacity = 0;
  }
  else
  {
    v9 = 0;
  }
  Scaleform::AutoPtr<Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::operator=(&this->mBytes, v9);
  Length = bytes->Length;
  v11 = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)*p_mBytes;
  if ( Length >= (*p_mBytes)[1] )
  {
    if ( Length >= v11->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v11,
        v11,
        Length + (Length >> 2));
  }
  else if ( Length < v11->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v11,
      v11,
      bytes->Length);
  }
  v11->Size = Length;
  memcpy(**p_mBytes, (const __m128i *)bytes->Data.Data.Data, (*p_mBytes)[1]);
}


void __thiscall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request,
        Scaleform::GFx::AS3::Instances::fl_display::Loader *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool quietOpen)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // ebp
  const __m128i *pData; // eax
  Scaleform::GFx::LoadQueueEntry::LoadMethod v8; // edx
  bool v9; // cl
  void *v10; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v11; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v13; // [esp-Ch] [ebp-18h]

  v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)request;
  if ( request )
    pData = (const __m128i *)Scaleform::GFx::AS3::Instances::fl::XML::GetName(request)->pNode->pData;
  else
    pData = (const __m128i *)uri;
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


void __thiscall Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request,
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool quietOpen)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // ebp
  const __m128i *pData; // eax
  bool v8; // al
  void *v9; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v10; // edx
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v12; // [esp-Ch] [ebp-18h]

  v5 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)request;
  if ( request )
    pData = (const __m128i *)Scaleform::GFx::AS3::Instances::fl::XML::GetName(request)->pNode->pData;
  else
    pData = (const __m128i *)uri;
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
