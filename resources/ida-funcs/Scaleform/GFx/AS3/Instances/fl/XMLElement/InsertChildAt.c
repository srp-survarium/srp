Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::InsertChildAt(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *pos,
        const Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Value *v5; // edi
  const Scaleform::GFx::AS3::Value *VInt; // eax
  unsigned int Flags; // ecx
  unsigned int v8; // ebp
  unsigned int v9; // edi
  unsigned int v10; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pObject; // eax
  unsigned int v12; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // ebx
  unsigned int RefCount; // eax
  int v15; // eax
  Scaleform::GFx::AS3::CheckResult *v16; // eax
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *v19; // ebx
  unsigned int v20; // eax
  const Scaleform::GFx::AS3::Value *v21; // edi
  Scaleform::GFx::AS3::Traits *v22; // ecx
  Scaleform::GFx::AS3::Class *Constructor; // eax
  __int16 v24; // ax
  Scaleform::GFx::AS3::Value::V1U v25; // eax
  const Scaleform::GFx::AS3::Value *v26; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // edi
  const Scaleform::GFx::AS3::VM::Error *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v32; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v33; // eax
  bool resulta; // [esp+13h] [ebp-1Dh]
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-1Ch]
  unsigned int size; // [esp+18h] [ebp-18h]
  _BYTE v37[4]; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+20h] [ebp-10h] BYREF

  v5 = value;
  vm = this->pTraits.pObject->pVM;
  resulta = 0;
  if ( (value->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(value->value.VS._1.VObj) )
  {
    VInt = (const Scaleform::GFx::AS3::Value *)v5->value.VS._1.VInt;
    Flags = VInt[3].Flags;
    v8 = 0;
    value = VInt;
    size = Flags;
    if ( Flags )
    {
      v9 = (unsigned int)pos;
LABEL_6:
      v10 = *((_DWORD *)&VInt[2].value.VS._2.VObj->__vftable + v8);
      pObject = this;
      while ( pObject != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v10 )
      {
        pObject = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)pObject->Parent.pObject;
        if ( !pObject )
        {
          v12 = this->Children.Data.Size;
          if ( v9 < v12 )
          {
            if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v10 + 92))(v10) == 2 )
            {
              v13 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(*(int (__thiscall **)(unsigned int, _BYTE *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))(*(_DWORD *)v10 + 128))(
                                                                    v10,
                                                                    v37,
                                                                    this);
              pos = v13;
              Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
                &this->Children,
                v9,
                (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&pos);
              if ( v13 )
              {
                if ( ((unsigned __int8)v13 & 1) == 0 )
                {
                  RefCount = v13->RefCount;
                  if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
                    goto LABEL_14;
                }
              }
              goto LABEL_27;
            }
            *(_DWORD *)(v10 + 16) = (*(_DWORD *)(v10 + 16) + 1) & 0x8FBFFFFF;
            pos = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10;
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
              &this->Children,
              v9,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&pos);
LABEL_23:
            if ( (v10 & 1) == 0 )
            {
              v15 = *(_DWORD *)(v10 + 16);
              if ( ((unsigned int)&byte_3FFFFF & v15) != 0 )
              {
                *(_DWORD *)(v10 + 16) = v15 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10);
              }
            }
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)(v10 + 36),
              (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
            goto LABEL_27;
          }
          if ( v9 == v12 )
          {
            if ( (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v10 + 92))(v10) != 2 )
            {
              *(_DWORD *)(v10 + 16) = (*(_DWORD *)(v10 + 16) + 1) & 0x8FBFFFFF;
              pos = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10;
              Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
                (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
                (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&pos);
              goto LABEL_23;
            }
            v13 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(*(int (__thiscall **)(unsigned int, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl::XMLElement *))(*(_DWORD *)v10 + 128))(
                                                                  v10,
                                                                  &_this,
                                                                  this);
            pos = v13;
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&pos);
            if ( v13 )
            {
              if ( ((unsigned __int8)v13 & 1) == 0 )
              {
                RefCount = v13->RefCount;
                if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
                {
LABEL_14:
                  v13->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
                }
              }
            }
LABEL_27:
            resulta = 1;
          }
          ++v8;
          ++v9;
          if ( v8 < size )
          {
            VInt = value;
            goto LABEL_6;
          }
          v16 = result;
          result->Result = resulta;
          return v16;
        }
      }
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&_this, eXMLIllegalCyclicalLoop, vm);
      Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v17);
      pWeakProxy = (Scaleform::GFx::ASStringNode *)_this.Bonus.pWeakProxy;
      --_this.Bonus.pWeakProxy[1].pObject;
      if ( pWeakProxy->RefCount )
        goto LABEL_72;
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
      v16 = result;
      result->Result = resulta;
    }
    else
    {
LABEL_72:
      v16 = result;
      result->Result = resulta;
    }
    return v16;
  }
  v19 = 0;
  v20 = (v5->Flags & 0x1F) - 12;
  value = 0;
  if ( v20 <= 3 && Scaleform::GFx::AS3::IsXMLObject(v5->value.VS._1.VObj) )
  {
    v21 = (const Scaleform::GFx::AS3::Value *)v5->value.VS._1.VInt;
    if ( v21 )
    {
      v19 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)v21;
      v21[1].Flags = (v21[1].Flags + 1) & 0x8FBFFFFF;
      value = v21;
    }
LABEL_48:
    v27 = this;
    while ( v27 != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v19 )
    {
      v27 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v27->Parent.pObject;
      if ( !v27 )
      {
        v28 = this->Children.Data.Size;
        v29 = (unsigned int)pos;
        if ( (unsigned int)pos < v28 )
        {
          if ( ((int (__thiscall *)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *))v19->pObject[1].V.__vftable)(v19) == 2 )
          {
            pos = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((int (__thiscall *)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *, const Scaleform::GFx::AS3::Value **, Scaleform::GFx::AS3::Instances::fl::XMLElement *))v19->pObject[2].pNext)(
                                                                  v19,
                                                                  &value,
                                                                  this);
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
              &this->Children,
              v29,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&pos);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pos);
            goto LABEL_67;
          }
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
            &this->Children,
            v29,
            (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&value);
LABEL_66:
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
            v19 + 9,
            (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
          goto LABEL_67;
        }
        if ( pos == (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v28 )
        {
          if ( ((int (__thiscall *)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *))v19->pObject[1].V.__vftable)(v19) != 2 )
          {
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&value);
            goto LABEL_66;
          }
          pos = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((int (__thiscall *)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *, const Scaleform::GFx::AS3::Value **, Scaleform::GFx::AS3::Instances::fl::XMLElement *))v19->pObject[2].pNext)(
                                                                v19,
                                                                &value,
                                                                this);
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
            (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&pos);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pos);
LABEL_67:
          resulta = 1;
        }
        if ( v19 )
        {
          if ( ((unsigned __int8)v19 & 1) == 0 )
          {
            v33 = v19[4].pObject;
            if ( ((unsigned int)&byte_3FFFFF & (unsigned int)v33) != 0 )
            {
              v19[4].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v33 - 1);
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v19);
            }
          }
        }
        goto LABEL_72;
      }
    }
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&_this, eXMLIllegalCyclicalLoop, vm);
    Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v30);
    v31 = (Scaleform::GFx::ASStringNode *)_this.Bonus.pWeakProxy;
    --_this.Bonus.pWeakProxy[1].pObject;
    if ( !v31->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    result->Result = 0;
    if ( v19 )
    {
      if ( ((unsigned __int8)v19 & 1) == 0 )
      {
        v32 = v19[4].pObject;
        if ( ((unsigned int)&byte_3FFFFF & (unsigned int)v32) != 0 )
        {
          v19[4].pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v32 - 1);
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v19);
        }
      }
    }
    return result;
  }
  v22 = this->pTraits.pObject;
  _this.Flags = 0;
  _this.Bonus.pWeakProxy = 0;
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(v22);
  Constructor->Construct(Constructor, &_this, 1u, v5, 1);
  v24 = _this.Flags;
  if ( !this->pTraits.pObject->pVM->HandleException )
  {
    v25 = _this.value.VS._1;
    if ( (_this.Flags & 0x1F) - 12 <= 3 && !_this.value.VS._1.VInt )
    {
      result->Result = 0;
      Scaleform::GFx::AS3::Value::~Value(&_this);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&value);
      return result;
    }
    v26 = (const Scaleform::GFx::AS3::Value *)_this.value.VS._1.VInt;
    if ( _this.value.VS._1.VInt )
    {
      ++*(_DWORD *)(_this.value.VS._1.VInt + 16);
      *(_DWORD *)(v25.VInt + 16) &= 0x8FBFFFFF;
      v19 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)v26;
      value = v26;
    }
    Scaleform::GFx::AS3::Value::~Value(&_this);
    goto LABEL_48;
  }
  result->Result = 0;
  if ( (v24 & 0x1Fu) > 9 )
  {
    if ( (v24 & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      return result;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  }
  return result;
}
