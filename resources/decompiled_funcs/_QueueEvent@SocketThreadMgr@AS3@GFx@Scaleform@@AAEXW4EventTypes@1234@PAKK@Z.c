void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::QueueEvent(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        Scaleform::GFx::AS3::SocketThreadMgr::EventTypes eventType,
        unsigned int *eventParams,
        unsigned int numParams)
{
  int v5; // ebp
  unsigned int v6; // ebx
  unsigned int Capacity; // eax
  unsigned int v8; // esi
  unsigned int Size; // esi
  unsigned int v10; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *p_EventQueue; // edi
  unsigned int v12; // esi
  Scaleform::GFx::AS3::Value *Data; // eax
  Scaleform::GFx::AS3::Value *v14; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *p_Bonus; // esi
  unsigned int VUInt; // ebp
  unsigned int v17; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v18; // edx
  unsigned int *v19; // ecx
  unsigned int *v20; // eax
  Scaleform::Lock *locker; // [esp+4h] [ebp-14h]
  Scaleform::GFx::AS3::SocketThreadMgr::EventInfo eventInfo; // [esp+8h] [ebp-10h] BYREF

  locker = &this->EventQueueLock;
  EnterCriticalSection(&this->EventQueueLock.cs);
  v5 = 0;
  v6 = 0;
  Capacity = 0;
  memset(&eventInfo.EventParameters, 0, sizeof(eventInfo.EventParameters));
  if ( numParams )
  {
    while ( 1 )
    {
      v8 = v6 + 1;
      if ( v6 + 1 >= v6 )
      {
        if ( v8 >= Capacity )
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&eventInfo.EventParameters,
            &eventInfo.EventParameters,
            v8 + (v8 >> 2));
      }
      else if ( v8 < Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&eventInfo.EventParameters,
          &eventInfo.EventParameters,
          v6 + 1);
      }
      ++v6;
      eventInfo.EventParameters.Data.Size = v8;
      if ( &eventInfo.EventParameters.Data.Data[v8] != (unsigned int *)4 )
        eventInfo.EventParameters.Data.Data[v8 - 1] = eventParams[v5];
      if ( ++v5 >= numParams )
        break;
      Capacity = eventInfo.EventParameters.Data.Policy.Capacity;
    }
  }
  Size = this->EventQueue.Data.Size;
  v10 = Size;
  p_EventQueue = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->EventQueue;
  v12 = Size + 1;
  if ( v12 >= v10 )
  {
    if ( v12 >= p_EventQueue->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_EventQueue,
        p_EventQueue,
        v12 + (v12 >> 2));
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo>::DestructArray(
      (Scaleform::GFx::AS3::SocketThreadMgr::EventInfo *)&p_EventQueue->Data[v12],
      v10 - v12);
    if ( v12 < p_EventQueue->Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_EventQueue,
        p_EventQueue,
        v12);
  }
  Data = p_EventQueue->Data;
  p_EventQueue->Size = v12;
  v14 = &Data[v12 - 1];
  if ( v14 )
  {
    p_Bonus = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&v14->Bonus;
    v14->Flags = eventType;
    v14->Bonus.pWeakProxy = 0;
    v14->value.VS._1.VInt = 0;
    v14->value.VS._2.VObj = 0;
    if ( v6 )
    {
      VUInt = v14->value.VS._1.VUInt;
      v17 = v6 + VUInt;
      if ( v6 + VUInt >= VUInt )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Bonus,
          p_Bonus,
          v17 + (v17 >> 2));
      v18 = p_Bonus->Data;
      v19 = eventInfo.EventParameters.Data.Data;
      p_Bonus->Size = v17;
      v20 = (unsigned int *)&v18[VUInt];
      do
      {
        if ( v20 )
          *v20 = *v19;
        ++v19;
        ++v20;
        --v6;
      }
      while ( v6 );
    }
  }
  if ( eventInfo.EventParameters.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, eventInfo.EventParameters.Data.Data);
  LeaveCriticalSection(&locker->cs);
}
