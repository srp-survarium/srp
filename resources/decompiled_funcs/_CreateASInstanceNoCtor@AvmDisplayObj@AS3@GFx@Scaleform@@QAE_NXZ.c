char __usercall Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor@<al>(
        Scaleform::GFx::AS3::AvmDisplayObj *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>)
{
  Scaleform::GFx::AS3::VM *v5; // edi
  Scaleform::GFx::ASStringNode *AppDomain; // ecx
  Scaleform::GFx::AS3::VM *v7; // ecx
  Scaleform::GFx::AS3::Value::V1U v8; // ebp
  Scaleform::GFx::DisplayObject *pDispObj; // edi
  Scaleform::RefCountNTSImpl **v10; // ebx
  Scaleform::GFx::AS3::VM *v13; // [esp+8h] [ebp-40h]
  Scaleform::String className; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *as3iobj[2]; // [esp+1Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::VM *avm; // [esp+24h] [ebp-24h]
  Scaleform::GFx::AS3::Value _this; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+38h] [ebp-10h] BYREF

  if ( this->pAS3RawPtr || this->pAS3CollectiblePtr.pObject )
    return 0;
  v5 = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].__vftable;
  avm = v5;
  if ( !v5 )
    return 0;
  Scaleform::String::String(&className);
  this->GetASClassName(this, &className);
  as3iobj[0] = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((className.HeapTypeBits & 0xFFFFFFFC) + 8);
  AppDomain = (Scaleform::GFx::ASStringNode *)this->AppDomain;
  _this.Flags = 0;
  _this.Bonus.pWeakProxy = 0;
  as3iobj[1] = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(*(_DWORD *)(className.HeapTypeBits
                                                                                       & 0xFFFFFFFC)
                                                                           & 0x7FFFFFFF);
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0;
  if ( !Scaleform::GFx::AS3::VM::GetClassUnsafe(v5, (Scaleform::GFx::ASStringNode *)as3iobj, AppDomain, &value) )
  {
    if ( v5->HandleException )
    {
      v7 = v5;
LABEL_14:
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v7);
      this->pDispObj->Flags |= 0x20u;
    }
LABEL_15:
    Scaleform::GFx::AS3::Value::~Value(&value);
    Scaleform::GFx::AS3::Value::~Value(&_this);
    Scaleform::String::~String(&className);
    return 0;
  }
  v8 = value.value.VS._1;
  (*(void (__stdcall **)(Scaleform::GFx::AS3::Value *, _DWORD, int, int))(**(_DWORD **)(*(_DWORD *)(value.value.VS._1.VInt
                                                                                                  + 20)
                                                                                      + 100)
                                                                        + 48))(
    &_this,
    *(_DWORD *)(*(_DWORD *)(value.value.VS._1.VInt + 20) + 100),
    a2,
    a3);
  pDispObj = this->pDispObj;
  avm = (Scaleform::GFx::AS3::VM *)value.Flags;
  v10 = (Scaleform::RefCountNTSImpl **)(value.Flags + 48);
  if ( pDispObj )
    ++pDispObj->RefCount;
  if ( *v10 )
    Scaleform::RefCountNTSImpl::Release(*v10);
  v13 = avm;
  *v10 = pDispObj;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pAS3CollectiblePtr,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v13);
  this->pAS3RawPtr = 0;
  if ( !*(_BYTE *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, char *, Scaleform::GFx::AS3::Value::VU *))(*(_DWORD *)v8.VInt + 68))(
                    v8,
                    (char *)as3iobj + 3,
                    &_this.value) )
  {
    v7 = avm;
    if ( avm->HandleException )
      goto LABEL_14;
    goto LABEL_15;
  }
  (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, int))(*(_DWORD *)_this.value.VS._1.VInt + 40))(
    _this.value.VS._1,
    1);
  Scaleform::GFx::AS3::Value::~Value(&value);
  Scaleform::GFx::AS3::Value::~Value(&_this);
  Scaleform::String::~String(&className);
  return 1;
}
