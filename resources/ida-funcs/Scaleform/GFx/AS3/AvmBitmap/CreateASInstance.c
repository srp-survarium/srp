unsigned int __thiscall Scaleform::GFx::AS3::AvmBitmap::CreateASInstance(
        Scaleform::GFx::AS3::AvmBitmap *this,
        bool execute)
{
  Scaleform::WeakPtrProxy *pWeakProxy; // ecx
  int v4; // edi
  int RefCount; // eax
  Scaleform::WeakPtrProxy *v6; // ecx
  int v7; // eax
  Scaleform::WeakPtrProxy *v8; // eax
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::MovieDefImpl *v10; // eax
  const Scaleform::String *NameOfExportedResource; // eax
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *Width; // ebx
  Scaleform::GFx::InteractiveObject *v13; // edi
  Scaleform::RefCountVImpl *v14; // eax
  void *v15; // esi
  unsigned int v16; // eax
  bool (__thiscall *IsVerboseActionErrors)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *); // [esp-4h] [ebp-58h]
  unsigned int rv; // [esp+10h] [ebp-44h]
  Scaleform::String className; // [esp+14h] [ebp-40h] BYREF
  Scaleform::Render::Size<unsigned long> size; // [esp+18h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v22; // [esp+20h] [ebp-34h]
  Scaleform::GFx::AS3::Value other; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value params[2]; // [esp+34h] [ebp-20h] BYREF

  pWeakProxy = this->pWeakProxy;
  v4 = 1;
  rv = 1;
  RefCount = (int)pWeakProxy;
  if ( !pWeakProxy )
    RefCount = this->RefCount;
  if ( (RefCount & 1) != 0 )
    --RefCount;
  if ( !RefCount )
  {
    if ( pWeakProxy
      || this->RefCount
      || !Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor((Scaleform::GFx::AS3::AvmDisplayObj *)this, 0, 1) )
    {
      rv = 0;
      v4 = 0;
    }
    else
    {
      rv = Scaleform::GFx::AS3::AvmDisplayObj::CallCtor((Scaleform::GFx::AS3::AvmDisplayObj *)this, execute);
      v4 = rv;
    }
  }
  v6 = this->pWeakProxy;
  v7 = (int)v6;
  if ( !v6 )
    v7 = this->RefCount;
  if ( (v7 & 1) != 0 )
    --v7;
  if ( !v7 )
    return v4;
  v8 = this->pWeakProxy;
  if ( !v6 )
    v8 = (Scaleform::WeakPtrProxy *)this->RefCount;
  v22 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)v8;
  if ( ((unsigned __int8)v8 & 1) != 0 )
  {
    v8 = (Scaleform::WeakPtrProxy *)((char *)v8 - 1);
    v22 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)v8;
  }
  if ( v8[7].RefCount
    || !(*((int (__thiscall **)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *))this->~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>
         + 64))(this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable) )
  {
    return v4;
  }
  params[0].Flags = 4;
  params[0].value.VNumber = 0.0;
  params[1].Flags = 4;
  params[1].value.VNumber = 0.0;
  pParent = this->pParent;
  params[0].Bonus.pWeakProxy = 0;
  params[1].Bonus.pWeakProxy = 0;
  if ( pParent
    && pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable )
  {
    (*((void (__thiscall **)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *, Scaleform::Render::Size<unsigned long> *))pParent->~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>
     + 5))(
      pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable,
      &size);
    other.Flags = 3;
    other.Bonus.pWeakProxy = 0;
    other.value.VS._1.VInt = size.Width;
    Scaleform::GFx::AS3::Value::Assign(params, &other);
    Scaleform::GFx::AS3::Value::~Value(&other);
    other.Flags = 3;
    other.Bonus.pWeakProxy = 0;
    other.value.VS._1.VInt = size.Height;
    Scaleform::GFx::AS3::Value::Assign(&params[1], &other);
    Scaleform::GFx::AS3::Value::~Value(&other);
  }
  size.Width = 0;
  Scaleform::String::String(&className);
  IsVerboseActionErrors = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable[2].IsVerboseActionErrors;
  v10 = (Scaleform::GFx::MovieDefImpl *)(*((int (__thiscall **)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *))this->~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>
                                         + 64))(this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable);
  NameOfExportedResource = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(
                             v10,
                             (Scaleform::GFx::ResourceId)IsVerboseActionErrors);
  if ( NameOfExportedResource )
    Scaleform::String::operator=(&className, NameOfExportedResource);
  else
    Scaleform::String::operator=(&className, "flash.display.BitmapData");
  Scaleform::GFx::AS3::VM::constructBuiltinObject(
    *((Scaleform::GFx::AS3::VM **)this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable[2].~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>
    + 10),
    (Scaleform::GFx::AS3::CheckResult *)&execute,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&size,
    (const char *)((className.HeapTypeBits & 0xFFFFFFFC) + 8),
    2u,
    params);
  Width = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)size.Width;
  if ( execute )
  {
    v13 = this->pParent;
    v14 = (Scaleform::RefCountVImpl *)(*((int (__thiscall **)(Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *))this->~Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>
                                       + 64))(this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable);
    Scaleform::GFx::AS3::Instances::fl_display::BitmapData::CreateLibraryObject(
      Width,
      (Scaleform::GFx::ImageResource *)v13,
      v14);
    Scaleform::GFx::AS3::Instances::fl_display::Bitmap::SetBitmapData(v22, Width);
  }
  v15 = (void *)(className.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((className.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  if ( Width && ((unsigned __int8)Width & 1) == 0 )
  {
    v16 = Width->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v16) != 0 )
    {
      Width->RefCount = v16 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(Width);
    }
  }
  `vector destructor iterator'(
    (char *)params,
    0x10u,
    2,
    (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  return rv;
}
