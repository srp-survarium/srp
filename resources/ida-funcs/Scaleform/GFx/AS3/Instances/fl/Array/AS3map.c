void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3map(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *v8; // ecx
  unsigned int Flags; // eax
  const Scaleform::GFx::AS3::Value *v10; // ebx
  Scaleform::GFx::AS3::Value *p_DefaultValue; // ecx
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v13; // eax
  Scaleform::GFx::AS3::Traits *v14; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v15; // esi
  unsigned int Length; // ecx
  Scaleform::GFx::AS3::Value *v17; // esi
  int j; // ebp
  unsigned int v19; // eax
  Scaleform::GFx::AS3::Value *v20; // esi
  int k; // edi
  unsigned int v22; // eax
  Scaleform::GFx::AS3::Value *v23; // esi
  int i; // edi
  unsigned int v25; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> r; // [esp+Ch] [ebp-5Ch] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+10h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+18h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+28h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value argv[3]; // [esp+38h] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+68h] [ebp+0h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *resulta; // [esp+6Ch] [ebp+4h]

  Scaleform::GFx::AS3::InstanceTraits::MakeInstance<Scaleform::GFx::AS3::InstanceTraits::fl::Array>(
    &r,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  pObject = result->pObject;
  pV = r.pV;
  if ( r.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
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
    if ( this->SA.Length )
    {
      resulta = 0;
      while ( 1 )
      {
        thisObject = (Scaleform::GFx::AS3::Value *)v10;
        if ( (unsigned int)v10 >= this->SA.ValueA.Data.Size )
        {
          if ( (unsigned int)v10 < this->SA.ValueHLowInd
            || (unsigned int)v10 > this->SA.ValueHHighInd
            || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                          &this->SA.ValueH.mHash,
                          (const unsigned int *)&thisObject),
                Index < 0)
            || (v13 = &this->SA.ValueH.mHash.pTable[4 * Index + 2]) == 0
            || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v13[1],
                v13 == (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)-8) )
          {
            p_DefaultValue = (Scaleform::GFx::AS3::Value *)&this->SA.DefaultValue;
          }
        }
        else
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)((char *)resulta + (unsigned int)this->SA.ValueA.Data.Data);
        }
        argv[0] = *p_DefaultValue;
        if ( (p_DefaultValue->Flags & 0x1F) > 9 )
        {
          if ( (p_DefaultValue->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(p_DefaultValue);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(p_DefaultValue);
        }
        argv[1].Flags = 3;
        argv[1].Bonus.pWeakProxy = 0;
        argv[1].value.VS._1.VInt = (int)v10;
        Scaleform::GFx::AS3::Value::Value(&argv[2], this);
        if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
          break;
        v14 = this->pTraits.pObject;
        val.Flags = 0;
        val.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v14->pVM, callback, &_this, &val, 3u, argv, 0);
        if ( this->pTraits.pObject->pVM->HandleException )
        {
          if ( (val.Flags & 0x1F) > 9 )
          {
            if ( (val.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
          }
          v23 = (Scaleform::GFx::AS3::Value *)&retaddr;
          for ( i = 2; i >= 0; --i )
          {
            v25 = v23[-1].Flags;
            --v23;
            if ( (v25 & 0x1F) > 9 )
            {
              if ( (v25 & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(v23);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(v23);
            }
          }
          goto LABEL_67;
        }
        v15 = r.pV;
        Length = r.pV->SA.Length;
        if ( Length == r.pV->SA.ValueA.Data.Size )
        {
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &r.pV->SA.ValueA.Data,
            &val);
        }
        else
        {
          r.pV->SA.ValueHHighInd = Length;
          key.pFirst = &v15->SA.ValueHHighInd;
          key.pSecond = &val;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
            &v15->SA.ValueH.mHash,
            v15->SA.ValueH.mHash.pHeap,
            &key);
        }
        ++v15->SA.Length;
        if ( (val.Flags & 0x1F) > 9 )
        {
          if ( (val.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
        }
        v17 = (Scaleform::GFx::AS3::Value *)&retaddr;
        for ( j = 2; j >= 0; --j )
        {
          v19 = v17[-1].Flags;
          --v17;
          if ( (v19 & 0x1F) > 9 )
          {
            if ( (v19 & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(v17);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(v17);
          }
        }
        resulta += 4;
        v10 = (const Scaleform::GFx::AS3::Value *)((char *)v10 + 1);
        if ( (unsigned int)v10 >= this->SA.Length )
          goto LABEL_67;
      }
      v20 = (Scaleform::GFx::AS3::Value *)&retaddr;
      for ( k = 2; k >= 0; --k )
      {
        v22 = v20[-1].Flags;
        --v20;
        if ( (v22 & 0x1F) > 9 )
        {
          if ( (v22 & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(v20);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(v20);
        }
      }
    }
LABEL_67:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}
