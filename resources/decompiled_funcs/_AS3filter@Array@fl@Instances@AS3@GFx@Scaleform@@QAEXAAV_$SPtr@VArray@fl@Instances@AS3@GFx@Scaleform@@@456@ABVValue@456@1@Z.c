void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3filter(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *v8; // ecx
  unsigned int Flags; // eax
  const Scaleform::GFx::AS3::Value *v10; // ebx
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // ebp
  Scaleform::GFx::AS3::Value *p_DefaultValue; // ecx
  signed int Index; // eax
  int v14; // eax
  Scaleform::GFx::AS3::Object *v15; // esi
  Scaleform::GFx::AS3::Value *v16; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v17; // esi
  unsigned int Length; // ecx
  Scaleform::GFx::AS3::Value *v19; // esi
  int j; // edi
  unsigned int v21; // eax
  Scaleform::GFx::AS3::Value *v22; // esi
  int k; // edi
  unsigned int v24; // eax
  Scaleform::GFx::AS3::Value *v25; // esi
  int i; // edi
  unsigned int v27; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Array *pObject; // [esp-4h] [ebp-70h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> r; // [esp+Ch] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Object *v; // [esp+10h] [ebp-5Ch]
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+14h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Value v32; // [esp+1Ch] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+2Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value argv[3]; // [esp+3Ch] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+6Ch] [ebp+0h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *resulta; // [esp+70h] [ebp+4h]

  pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject;
  v = this;
  Scaleform::GFx::AS3::InstanceTraits::MakeInstance<Scaleform::GFx::AS3::InstanceTraits::fl::Array>(&r, pObject);
  v5 = result->pObject;
  pV = r.pV;
  if ( r.pV != result->pObject )
  {
    if ( v5 )
    {
      if ( ((unsigned __int8)v5 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v5 - 1);
      }
      else
      {
        RefCount = v5->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v5->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
        }
      }
    }
    result->pObject = pV;
  }
  if ( (callback->Flags & 0x1F) != 0 && ((callback->Flags & 0x1F) - 12 > 3 || callback->value.VS._1.VInt) )
  {
    v8 = thisObject;
    if ( (thisObject->Flags & 0x1F) == 0 || (thisObject->Flags & 0x1F) - 12 <= 3 && !thisObject->value.VS._1.VInt )
      v8 = callback;
    Flags = v8->Flags;
    _this.Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
    _this.value.VNumber = v8->value.VNumber;
    _this.Flags = Flags;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v8);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v8);
    }
    v10 = 0;
    p_SA = &this->SA;
    if ( p_SA->Length )
    {
      resulta = 0;
      while ( 1 )
      {
        thisObject = (Scaleform::GFx::AS3::Value *)v10;
        if ( (unsigned int)v10 >= p_SA->ValueA.Data.Size )
        {
          if ( (unsigned int)v10 < p_SA->ValueHLowInd
            || (unsigned int)v10 > p_SA->ValueHHighInd
            || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                          &p_SA->ValueH.mHash,
                          (const unsigned int *)&thisObject),
                Index < 0)
            || (v14 = (int)&p_SA->ValueH.mHash.pTable[4 * Index + 2]) == 0
            || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v14 + 8), v14 == -8) )
          {
            p_DefaultValue = (Scaleform::GFx::AS3::Value *)&p_SA->DefaultValue;
          }
        }
        else
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)((char *)resulta + (unsigned int)p_SA->ValueA.Data.Data);
        }
        argv[0] = *p_DefaultValue;
        if ( (p_DefaultValue->Flags & 0x1F) > 9 )
        {
          if ( (p_DefaultValue->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(p_DefaultValue);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(p_DefaultValue);
        }
        v15 = v;
        argv[1].Flags = 3;
        argv[1].Bonus.pWeakProxy = 0;
        argv[1].value.VS._1.VInt = (int)v10;
        Scaleform::GFx::AS3::Value::Value(&argv[2], v);
        if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
          break;
        v32.Flags = 0;
        v32.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v15->pTraits.pObject->pVM, callback, &_this, &v32, 3u, argv, 0);
        if ( v15->pTraits.pObject->pVM->HandleException )
        {
          if ( (v32.Flags & 0x1F) > 9 )
          {
            if ( (v32.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v32);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
          }
          v25 = (Scaleform::GFx::AS3::Value *)&retaddr;
          for ( i = 2; i >= 0; --i )
          {
            v27 = v25[-1].Flags;
            --v25;
            if ( (v27 & 0x1F) > 9 )
            {
              if ( (v27 & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(v25);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(v25);
            }
          }
          goto LABEL_74;
        }
        if ( (v32.Flags & 0x1F) == 1 && v32.value.VS._1.VBool )
        {
          v16 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(p_SA, (unsigned int)v10);
          v17 = r.pV;
          Length = r.pV->SA.Length;
          if ( Length == r.pV->SA.ValueA.Data.Size )
          {
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &r.pV->SA.ValueA.Data,
              v16);
          }
          else
          {
            r.pV->SA.ValueHHighInd = Length;
            key.pSecond = v16;
            key.pFirst = &v17->SA.ValueHHighInd;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
              &v17->SA.ValueH.mHash,
              v17->SA.ValueH.mHash.pHeap,
              &key);
          }
          ++v17->SA.Length;
          if ( (v32.Flags & 0x1F) > 9 )
          {
            if ( (v32.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v32);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
          }
          `vector destructor iterator'(
            (char *)argv,
            0x10u,
            3,
            (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        }
        else
        {
          if ( (v32.Flags & 0x1F) > 9 )
          {
            if ( (v32.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v32);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
          }
          v19 = (Scaleform::GFx::AS3::Value *)&retaddr;
          for ( j = 2; j >= 0; --j )
          {
            v21 = v19[-1].Flags;
            --v19;
            if ( (v21 & 0x1F) > 9 )
            {
              if ( (v21 & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(v19);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(v19);
            }
          }
        }
        resulta += 4;
        v10 = (const Scaleform::GFx::AS3::Value *)((char *)v10 + 1);
        if ( (unsigned int)v10 >= p_SA->Length )
          goto LABEL_74;
      }
      v22 = (Scaleform::GFx::AS3::Value *)&retaddr;
      for ( k = 2; k >= 0; --k )
      {
        v24 = v22[-1].Flags;
        --v22;
        if ( (v24 & 0x1F) > 9 )
        {
          if ( (v24 & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(v22);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(v22);
        }
      }
    }
LABEL_74:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}
