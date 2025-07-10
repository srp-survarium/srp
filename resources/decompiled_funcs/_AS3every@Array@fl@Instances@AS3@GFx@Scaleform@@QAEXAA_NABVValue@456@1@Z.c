void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3every(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        bool *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Value *v5; // ecx
  unsigned int Flags; // eax
  const Scaleform::GFx::AS3::Value *v7; // ebp
  int v8; // ebx
  Scaleform::GFx::AS3::Value *p_DefaultValue; // ecx
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v11; // eax
  Scaleform::GFx::AS3::Value *v12; // esi
  int k; // edi
  unsigned int v14; // eax
  Scaleform::GFx::AS3::Value *v15; // esi
  int i; // edi
  unsigned int v17; // eax
  Scaleform::GFx::AS3::Value *v18; // esi
  int j; // edi
  unsigned int v20; // eax
  Scaleform::GFx::AS3::Value v21; // [esp+4h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value argv[3]; // [esp+24h] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+54h] [ebp+0h] BYREF

  if ( (callback->Flags & 0x1F) == 0 )
    goto LABEL_63;
  if ( (callback->Flags & 0x1F) - 12 <= 3 && !callback->value.VS._1.VInt )
  {
LABEL_65:
    *result = 0;
    return;
  }
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
    v8 = 0;
    while ( 1 )
    {
      thisObject = (Scaleform::GFx::AS3::Value *)v7;
      if ( (unsigned int)v7 >= this->SA.ValueA.Data.Size )
      {
        if ( (unsigned int)v7 < this->SA.ValueHLowInd
          || (unsigned int)v7 > this->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                        &this->SA.ValueH.mHash,
                        (const unsigned int *)&thisObject),
              Index < 0)
          || (v11 = &this->SA.ValueH.mHash.pTable[4 * Index + 2]) == 0
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v11[1],
              v11 == (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)-8) )
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)&this->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->SA.ValueA.Data.Data[v8];
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
      argv[1].value.VS._1.VInt = (int)v7;
      Scaleform::GFx::AS3::Value::Value(&argv[2], this);
      if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
        break;
      v21.Flags = 0;
      v21.Bonus.pWeakProxy = 0;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, callback, &_this, &v21, 3u, argv, 0);
      if ( this->pTraits.pObject->pVM->HandleException )
      {
        if ( (v21.Flags & 0x1F) > 9 )
        {
          if ( (v21.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v21);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v21);
        }
        v15 = (Scaleform::GFx::AS3::Value *)&retaddr;
        for ( i = 2; i >= 0; --i )
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
        goto LABEL_60;
      }
      if ( (v21.Flags & 0x1F) != 1 || !v21.value.VS._1.VBool )
      {
        if ( (v21.Flags & 0x1F) > 9 )
        {
          if ( (v21.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v21);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v21);
        }
        v18 = (Scaleform::GFx::AS3::Value *)&retaddr;
        for ( j = 2; j >= 0; --j )
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
        goto LABEL_60;
      }
      `vector destructor iterator'(
        (char *)argv,
        0x10u,
        3,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      v7 = (const Scaleform::GFx::AS3::Value *)((char *)v7 + 1);
      ++v8;
      if ( (unsigned int)v7 >= this->SA.Length )
        goto LABEL_60;
    }
    v12 = (Scaleform::GFx::AS3::Value *)&retaddr;
    for ( k = 2; k >= 0; --k )
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
  }
LABEL_60:
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
LABEL_63:
      *result = 0;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    goto LABEL_65;
  }
  *result = 0;
}
