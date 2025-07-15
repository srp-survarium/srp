void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3forEach(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Value *v5; // ecx
  unsigned int Flags; // eax
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::Value *p_DefaultValue; // ecx
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v10; // eax
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Value *v12; // esi
  int j; // ebp
  unsigned int v14; // eax
  Scaleform::GFx::AS3::Value *v15; // esi
  int k; // edi
  unsigned int v17; // eax
  Scaleform::GFx::AS3::Value *v18; // esi
  int i; // edi
  unsigned int v20; // eax
  unsigned int key; // [esp+4h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::Value v22; // [esp+8h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+18h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value argv[3]; // [esp+28h] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+58h] [ebp+0h] BYREF
  const Scaleform::GFx::AS3::Value *thisObjecta; // [esp+64h] [ebp+Ch]

  if ( (callback->Flags & 0x1F) != 0 && ((callback->Flags & 0x1F) - 12 > 3 || callback->value.VS._1.VInt) )
  {
    v5 = thisObject;
    if ( (thisObject->Flags & 0x1F) == 0 || (thisObject->Flags & 0x1F) - 12 <= 3 && !thisObject->value.VS._1.VInt )
      v5 = callback;
    Flags = v5->Flags;
    _this.Bonus.pWeakProxy = v5->Bonus.pWeakProxy;
    _this.value.VNumber = v5->value.VNumber;
    _this.Flags = Flags;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v5);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v5);
    }
    v7 = 0;
    if ( this->SA.Length )
    {
      thisObjecta = 0;
      while ( 1 )
      {
        key = v7;
        if ( v7 >= this->SA.ValueA.Data.Size )
        {
          if ( v7 < this->SA.ValueHLowInd
            || v7 > this->SA.ValueHHighInd
            || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                          &this->SA.ValueH.mHash,
                          &key),
                Index < 0)
            || (v10 = &this->SA.ValueH.mHash.pTable[4 * Index + 2]) == 0
            || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v10[1],
                v10 == (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)-8) )
          {
            p_DefaultValue = (Scaleform::GFx::AS3::Value *)&this->SA.DefaultValue;
          }
        }
        else
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)((char *)thisObjecta + (unsigned int)this->SA.ValueA.Data.Data);
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
        argv[1].value.VS._1.VInt = v7;
        Scaleform::GFx::AS3::Value::Value(&argv[2], this);
        if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
          break;
        pObject = this->pTraits.pObject;
        v22.Flags = 0;
        v22.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(pObject->pVM, callback, &_this, &v22, 3u, argv, 0);
        if ( this->pTraits.pObject->pVM->HandleException )
        {
          if ( (v22.Flags & 0x1F) > 9 )
          {
            if ( (v22.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v22);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
          }
          v18 = (Scaleform::GFx::AS3::Value *)&retaddr;
          for ( i = 2; i >= 0; --i )
          {
            v20 = v18[-1].Flags;
            --v18;
            if ( (v20 & 0x1F) > 9 )
            {
              if ( (v20 & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(v18);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(v18);
            }
          }
          goto LABEL_57;
        }
        if ( (v22.Flags & 0x1F) > 9 )
        {
          if ( (v22.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v22);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
        }
        v12 = (Scaleform::GFx::AS3::Value *)&retaddr;
        for ( j = 2; j >= 0; --j )
        {
          v14 = v12[-1].Flags;
          --v12;
          if ( (v14 & 0x1F) > 9 )
          {
            if ( (v14 & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(v12);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(v12);
          }
        }
        ++thisObjecta;
        if ( ++v7 >= this->SA.Length )
          goto LABEL_57;
      }
      v15 = (Scaleform::GFx::AS3::Value *)&retaddr;
      for ( k = 2; k >= 0; --k )
      {
        v17 = v15[-1].Flags;
        --v15;
        if ( (v17 & 0x1F) > 9 )
        {
          if ( (v17 & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(v15);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(v15);
        }
      }
    }
LABEL_57:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}
