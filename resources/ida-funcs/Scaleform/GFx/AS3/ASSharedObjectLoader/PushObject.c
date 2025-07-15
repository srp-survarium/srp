void __thiscall Scaleform::GFx::AS3::ASSharedObjectLoader::PushObject(
        Scaleform::GFx::AS3::ASSharedObjectLoader *this,
        Scaleform::String *name)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v3; // ebx
  Scaleform::Array<Scaleform::GFx::AS3::Instances::fl::Object *,2,Scaleform::ArrayDefaultPolicy> *p_ObjectStack; // esi
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // eax
  Scaleform::GFx::AS3::Value *p_v; // ecx
  unsigned int v7; // ebp
  int Length; // eax
  Scaleform::GFx::AS3::VM *pVM; // ecx
  void (__thiscall **p_SetProperty)(Scaleform::GFx::AS3::Instances::fl::Object *, char *, int, Scaleform::GFx::AS3::Value *); // ebp
  int v11; // eax
  unsigned int v12; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v14; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // ecx
  unsigned int RefCount; // eax
  char v17; // [esp+Fh] [ebp-41h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> pobj; // [esp+10h] [ebp-40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [esp+14h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value v21; // [esp+28h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname v22; // [esp+38h] [ebp-18h] BYREF

  v3 = this->ObjectStack.Data.Data[this->ObjectStack.Data.Size - 1];
  p_ObjectStack = &this->ObjectStack;
  pV = Scaleform::GFx::AS3::VM::MakeObject(this->pVM, &result)->pV;
  pobj.pObject = pV;
  if ( this->bArrayIsTop )
  {
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v, pV);
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)&v3[1], &v);
    if ( (v.Flags & 0x1F) <= 9 )
      goto LABEL_9;
    p_v = &v;
    if ( (v.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      goto LABEL_9;
    }
  }
  else
  {
    v21.Flags = 0;
    v21.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v21, pV);
    v7 = name->HeapTypeBits & 0xFFFFFFFC;
    Length = Scaleform::String::GetLength(name);
    pVM = this->pVM;
    v.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)Length;
    v.Flags = v7 + 8;
    p_SetProperty = (void (__thiscall **)(Scaleform::GFx::AS3::Instances::fl::Object *, char *, int, Scaleform::GFx::AS3::Value *))&v3->SetProperty;
    Scaleform::GFx::AS3::Multiname::Multiname(&v22, pVM, (const Scaleform::StringDataPtr *)&v);
    (*p_SetProperty)(v3, &v17, v11, &v21);
    Scaleform::GFx::AS3::Multiname::~Multiname(&v22);
    if ( (v21.Flags & 0x1F) <= 9 )
      goto LABEL_9;
    p_v = &v21;
    if ( (v21.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v21);
      goto LABEL_9;
    }
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(p_v);
LABEL_9:
  this->bArrayIsTop = 0;
  v12 = this->ObjectStack.Data.Size + 1;
  if ( v12 >= p_ObjectStack->Data.Size )
  {
    if ( v12 >= p_ObjectStack->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_ObjectStack->Data,
        p_ObjectStack,
        v12 + (v12 >> 2));
  }
  else if ( v12 < p_ObjectStack->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_ObjectStack->Data,
      p_ObjectStack,
      p_ObjectStack->Data.Size + 1);
  }
  Data = p_ObjectStack->Data.Data;
  p_ObjectStack->Data.Size = v12;
  v14 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *)&Data[v12 - 1];
  pObject = pobj.pObject;
  if ( v14 )
    v14->pObject = pobj.pObject;
  if ( pObject && ((unsigned __int8)pObject & 1) == 0 )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
