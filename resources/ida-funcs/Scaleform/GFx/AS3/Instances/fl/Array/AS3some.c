void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3some(
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
  __int16 v12; // ax
  Scaleform::GFx::AS3::Value *v13; // esi
  int k; // edi
  unsigned int v15; // eax
  Scaleform::GFx::AS3::Value *v16; // esi
  int i; // edi
  unsigned int v18; // eax
  Scaleform::GFx::AS3::Value *v19; // esi
  int j; // edi
  unsigned int v21; // eax
  Scaleform::GFx::AS3::Value _this; // [esp+10h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+20h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value argv[3]; // [esp+30h] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h] BYREF

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
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, callback, &_this, &r, 3u, argv, 0);
        v12 = r.Flags;
        if ( this->pTraits.pObject->pVM->HandleException )
        {
          if ( (r.Flags & 0x1F) > 9 )
          {
            if ( (r.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
          }
          v16 = (Scaleform::GFx::AS3::Value *)&retaddr;
          for ( i = 2; i >= 0; --i )
          {
            v18 = v16[-1].Flags;
            --v16;
            if ( (v18 & 0x1F) > 9 )
            {
              if ( (v18 & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(v16);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(v16);
            }
          }
          goto LABEL_31;
        }
        if ( (r.Flags & 0x1F) != 1 || r.value.VS._1.VBool )
        {
          *result = 1;
          if ( (v12 & 0x1Fu) > 9 )
          {
            if ( (v12 & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
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
          if ( (_this.Flags & 0x1F) > 9 )
          {
            if ( (_this.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
          return;
        }
        `vector destructor iterator'(
          (char *)argv,
          0x10u,
          3,
          (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        v7 = (const Scaleform::GFx::AS3::Value *)((char *)v7 + 1);
        ++v8;
        if ( (unsigned int)v7 >= this->SA.Length )
          goto LABEL_31;
      }
      v13 = (Scaleform::GFx::AS3::Value *)&retaddr;
      for ( k = 2; k >= 0; --k )
      {
        v15 = v13[-1].Flags;
        --v13;
        if ( (v15 & 0x1F) > 9 )
        {
          if ( (v15 & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(v13);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(v13);
        }
      }
    }
LABEL_31:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
        *result = 0;
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  *result = 0;
}
