void __thiscall Scaleform::GFx::AS3::Object::GetDefaultValueUnsafe(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value::Hint hint)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // eax
  const Scaleform::GFx::ASString *StringManagerRef; // ebp
  Scaleform::GFx::AS3::Value::Hint v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // eax
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Traits *v11; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult *SlotValueUnsafe; // eax
  Scaleform::GFx::AS3::Value *p_v; // ecx
  Scaleform::GFx::AS3::Traits *v15; // edx
  Scaleform::GFx::AS3::WeakProxy *v16; // eax
  unsigned int v17; // eax
  Scaleform::GFx::AS3::Traits *v18; // edx
  Scaleform::GFx::AS3::WeakProxy *v19; // eax
  Scaleform::GFx::AS3::CheckResult *v20; // eax
  Scaleform::GFx::AS3::Traits *v21; // edx
  Scaleform::GFx::AS3::WeakProxy *v22; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // [esp-8h] [ebp-5Ch]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // [esp-8h] [ebp-5Ch]
  Scaleform::GFx::AS3::Value value; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+34h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+44h] [ebp-10h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  TraitsType = pObject->TraitsType;
  StringManagerRef = (const Scaleform::GFx::ASString *)pVM->StringManagerRef;
  if ( TraitsType == Traits_XML || TraitsType == Traits_XMLList )
  {
    v8 = hintString;
  }
  else
  {
    v8 = hint;
    if ( hint == hintNone )
      v8 = (TraitsType == Traits_Date) + 1;
  }
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0;
  v9 = pVM->PublicNamespace.pObject;
  if ( v8 == hintString )
  {
    if ( Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
           this,
           (Scaleform::GFx::AS3::CheckResult *)&hint,
           StringManagerRef + 24,
           v9,
           &value)->Result )
    {
      v10 = value.Flags & 0x1F;
      if ( v10 > 0xF || v10 == 14 || v10 == 5 || v10 == 15 || v10 == 6 || v10 == 7 || v10 == 12 || v10 == 13 )
      {
        v11 = this->pTraits.pObject;
        this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        _this.Flags = 12;
        _this.Bonus.pWeakProxy = 0;
        _this.value.VS._1.VInt = (int)this;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v11->pVM, &value, &_this, &v, 0, 0, 0);
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags & 0x200) != 0 )
          {
            pWeakProxy = _this.Bonus.pWeakProxy;
            --_this.Bonus.pWeakProxy->RefCount;
            if ( !pWeakProxy->RefCount )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
        }
        Scaleform::GFx::AS3::Value::Swap(result, &v);
        Scaleform::GFx::AS3::Value::~Value(&v);
      }
      if ( !pVM->HandleException && (result->Flags & 0x1F) >= 5 && (result->Flags & 0x1F) != 0xA )
      {
        v23 = pVM->PublicNamespace.pObject;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        SlotValueUnsafe = Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
                            this,
                            (Scaleform::GFx::AS3::CheckResult *)&hint,
                            StringManagerRef + 25,
                            v23,
                            &v);
        p_v = &v;
        if ( SlotValueUnsafe->Result )
        {
          if ( Scaleform::GFx::AS3::Value::IsCallable(&v) )
          {
            v15 = this->pTraits.pObject;
            this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
            other.Flags = 0;
            other.Bonus.pWeakProxy = 0;
            _this.Flags = 12;
            _this.Bonus.pWeakProxy = 0;
            _this.value.VS._1.VInt = (int)this;
            Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v15->pVM, &v, &_this, &other, 0, 0, 0);
            if ( (_this.Flags & 0x1F) > 9 )
            {
              if ( (_this.Flags & 0x200) != 0 )
              {
                v16 = _this.Bonus.pWeakProxy;
                --_this.Bonus.pWeakProxy->RefCount;
                if ( !v16->RefCount )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
              }
            }
            Scaleform::GFx::AS3::Value::Swap(result, &other);
            Scaleform::GFx::AS3::Value::~Value(&other);
          }
          p_v = &v;
        }
LABEL_61:
        Scaleform::GFx::AS3::Value::~Value(p_v);
      }
    }
  }
  else if ( Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
              this,
              (Scaleform::GFx::AS3::CheckResult *)&hint,
              StringManagerRef + 25,
              v9,
              &value)->Result )
  {
    v17 = value.Flags & 0x1F;
    if ( v17 > 0xF || v17 == 14 || v17 == 5 || v17 == 15 || v17 == 6 || v17 == 7 || v17 == 12 || v17 == 13 )
    {
      v18 = this->pTraits.pObject;
      this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
      other.Flags = 0;
      other.Bonus.pWeakProxy = 0;
      v.Flags = 12;
      v.Bonus.pWeakProxy = 0;
      v.value.VS._1.VInt = (int)this;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v18->pVM, &value, &v, &other, 0, 0, 0);
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          v19 = v.Bonus.pWeakProxy;
          --v.Bonus.pWeakProxy->RefCount;
          if ( !v19->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
      }
      Scaleform::GFx::AS3::Value::Swap(result, &other);
      Scaleform::GFx::AS3::Value::~Value(&other);
    }
    if ( !pVM->HandleException && (result->Flags & 0x1F) >= 5 && (result->Flags & 0x1F) != 0xA )
    {
      v24 = pVM->PublicNamespace.pObject;
      _this.Flags = 0;
      _this.Bonus.pWeakProxy = 0;
      v20 = Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
              this,
              (Scaleform::GFx::AS3::CheckResult *)&hint,
              StringManagerRef + 24,
              v24,
              &_this);
      p_v = &_this;
      if ( v20->Result )
      {
        if ( Scaleform::GFx::AS3::Value::IsCallable(&_this) )
        {
          v21 = this->pTraits.pObject;
          this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
          other.Flags = 0;
          other.Bonus.pWeakProxy = 0;
          v.Flags = 12;
          v.Bonus.pWeakProxy = 0;
          v.value.VS._1.VInt = (int)this;
          Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v21->pVM, &_this, &v, &other, 0, 0, 0);
          if ( (v.Flags & 0x1F) > 9 )
          {
            if ( (v.Flags & 0x200) != 0 )
            {
              v22 = v.Bonus.pWeakProxy;
              --v.Bonus.pWeakProxy->RefCount;
              if ( !v22->RefCount )
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
            }
          }
          Scaleform::GFx::AS3::Value::Swap(result, &other);
          Scaleform::GFx::AS3::Value::~Value(&other);
        }
        p_v = &_this;
      }
      goto LABEL_61;
    }
  }
  Scaleform::GFx::AS3::Value::~Value(&value);
}
