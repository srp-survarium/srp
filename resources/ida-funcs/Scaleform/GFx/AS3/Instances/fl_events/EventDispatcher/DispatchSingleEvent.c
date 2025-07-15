char __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evtObj,
        bool useCapture)
{
  bool v3; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pObject; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v6; // esi
  int v7; // eax
  unsigned int *v8; // esi
  char *v9; // esi
  _DWORD *v10; // ebx
  unsigned int v11; // eax
  Scaleform::GFx::AS3::Value *v12; // esi
  unsigned int v13; // eax
  char v14; // bl
  const Scaleform::GFx::AS3::Value *v15; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *v17; // esi
  int v18; // edi
  int v19; // ebp
  unsigned int v20; // ebp
  int v21; // ebx
  Scaleform::GFx::AS3::Value *v22; // edi
  const Scaleform::GFx::AS3::Value *v23; // eax
  Scaleform::GFx::AS3::VM *v24; // ecx
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // esi
  Scaleform::GFx::AS3::Value *p_this; // ecx
  unsigned int v27; // ebp
  Scaleform::GFx::AS3::Value *v28; // esi
  unsigned int v29; // edi
  unsigned int RefCount; // eax
  bool rv; // [esp+5h] [ebp-141h]
  unsigned __int8 *arr; // [esp+Ah] [ebp-13Ch]
  unsigned int n; // [esp+Eh] [ebp-138h]
  Scaleform::GFx::AS3::Value _this; // [esp+12h] [ebp-134h] BYREF
  int v36; // [esp+22h] [ebp-124h]
  Scaleform::GFx::AS3::Value result; // [esp+26h] [ebp-120h] BYREF
  Scaleform::GFx::AS3::Value v38; // [esp+36h] [ebp-110h] BYREF
  Scaleform::GFx::AS3::Value param; // [esp+46h] [ebp-100h] BYREF
  unsigned __int8 fixedarr[240]; // [esp+56h] [ebp-F0h] BYREF

  v3 = this->pImpl.pObject == 0;
  v36 = 0;
  if ( v3 )
    return 1;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  pObject = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)this->pImpl.pObject;
  if ( !useCapture )
    ++pObject;
  v6.pTable = pObject->pTable;
  if ( pObject->pTable
    && (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               pObject,
               &evtObj->Type,
               evtObj->Type.pNode->HashFlags & v6.pTable->SizeMask),
        v7 >= 0)
    && (v8 = &v6.pTable[1].SizeMask + 3 * v7) != 0 )
  {
    v9 = (char *)(v8 + 1);
  }
  else
  {
    v9 = 0;
  }
  rv = 1;
  if ( v9 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evtObj->CurrentTarget,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    v10 = *(_DWORD **)v9;
    v11 = *(_DWORD *)(*(_DWORD *)v9 + 4);
    if ( v11 == 1 )
    {
      v12 = (Scaleform::GFx::AS3::Value *)(*v10 + 8);
      if ( Scaleform::GFx::AS3::Value::IsValidWeakRef(v12) )
      {
        _this.Flags = 0;
        _this.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::Value::Value(&param, &evtObj->Scaleform::GFx::AS3::Instances::fl::Object);
        v13 = v12->Flags >> 9;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0;
        if ( (v13 & 1) != 0 )
        {
          v14 = 1;
          Scaleform::GFx::AS3::Value::Value(&v38, v12, StrongRefValue);
        }
        else
        {
          v14 = v36;
          v15 = v12;
        }
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, v15, &_this, &result, 1u, &param, 0);
        if ( (v14 & 1) != 0 )
          Scaleform::GFx::AS3::Value::~Value(&v38);
        pVM = this->pTraits.pObject->pVM;
        if ( pVM->HandleException )
        {
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(pVM);
          rv = 0;
        }
        Scaleform::GFx::AS3::Value::~Value(&result);
        Scaleform::GFx::AS3::Value::~Value(&param);
        Scaleform::GFx::AS3::Value::~Value(&_this);
      }
      goto LABEL_90;
    }
    if ( v11 > 1 )
    {
      if ( v11 > 0xA )
        arr = (unsigned __int8 *)Scaleform::Memory::AllocAutoHeap(this, 24 * v11);
      else
        arr = fixedarr;
      n = v10[1];
      if ( n )
      {
        v17 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)arr;
        v18 = 0;
        v19 = v10[1];
        do
        {
          if ( v17 )
            Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener::Listener(
              v17,
              (const Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *)(v18 + *v10));
          v18 += 24;
          ++v17;
          --v19;
        }
        while ( v19 );
      }
      v20 = 0;
      if ( !n )
      {
LABEL_81:
        v27 = v20 + 1;
        if ( v27 < n )
        {
          v28 = (Scaleform::GFx::AS3::Value *)&arr[24 * v27 + 8];
          v29 = n - v27;
          do
          {
            if ( (v28->Flags & 0x1F) > 9 )
            {
              if ( (v28->Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(v28);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(v28);
            }
            v28 = (Scaleform::GFx::AS3::Value *)((char *)v28 + 24);
            --v29;
          }
          while ( v29 );
        }
        if ( arr != fixedarr )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, arr);
        goto LABEL_90;
      }
      v21 = v36;
      v22 = (Scaleform::GFx::AS3::Value *)(arr + 8);
      while ( Scaleform::GFx::AS3::Value::IsValidWeakRef(v22) )
      {
        _this.Flags = 0;
        _this.Bonus.pWeakProxy = 0;
        v38.Flags = 0;
        v38.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::Value::Value(&result, &evtObj->Scaleform::GFx::AS3::Instances::fl::Object);
        if ( (v22->Flags & 0x200) != 0 )
        {
          v21 |= 2u;
          Scaleform::GFx::AS3::Value::Value(&param, v22, StrongRefValue);
        }
        else
        {
          v23 = v22;
        }
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, v23, &_this, &v38, 1u, &result, 0);
        if ( (v21 & 2) != 0 )
        {
          v21 &= ~2u;
          if ( (param.Flags & 0x1F) > 9 )
          {
            if ( (param.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&param);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&param);
          }
        }
        v24 = this->pTraits.pObject->pVM;
        if ( v24->HandleException )
        {
          p_ExceptionObj = &v24->ExceptionObj;
          v24->HandleException = 0;
          Scaleform::GFx::AS3::VM::OutputError(v24, &v24->ExceptionObj);
          if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
          {
            if ( (p_ExceptionObj->Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_ExceptionObj);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
          }
          p_ExceptionObj->Flags &= 0xFFFFFFE0;
          rv = 0;
        }
        if ( (v22->Flags & 0x1F) > 9 )
        {
          if ( (v22->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(v22);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(v22);
        }
        if ( (*((_BYTE *)evtObj + 48) & 0x10) != 0 || !rv )
        {
          if ( (result.Flags & 0x1F) > 9 )
          {
            if ( (result.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
          }
          if ( (v38.Flags & 0x1F) > 9 )
          {
            if ( (v38.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v38);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
          }
          if ( (_this.Flags & 0x1F) > 9 )
          {
            if ( (_this.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
          goto LABEL_81;
        }
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
        if ( (v38.Flags & 0x1F) > 9 )
        {
          if ( (v38.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v38);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
        }
        if ( (_this.Flags & 0x1F) > 9 )
        {
          p_this = &_this;
          if ( (_this.Flags & 0x200) == 0 )
            goto LABEL_66;
LABEL_63:
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_this);
        }
LABEL_67:
        ++v20;
        v22 = (Scaleform::GFx::AS3::Value *)((char *)v22 + 24);
        if ( v20 >= n )
          goto LABEL_81;
      }
      if ( (v22->Flags & 0x1F) <= 9 )
        goto LABEL_67;
      p_this = v22;
      if ( (v22->Flags & 0x200) == 0 )
      {
LABEL_66:
        Scaleform::GFx::AS3::Value::ReleaseInternal(p_this);
        goto LABEL_67;
      }
      goto LABEL_63;
    }
  }
LABEL_90:
  if ( ((unsigned __int8)this & 1) == 0 )
  {
    RefCount = this->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      this->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(this);
    }
  }
  return rv;
}
