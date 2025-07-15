void __thiscall Scaleform::GFx::AS2::GASSharedObjectLoader::PushArray(
        Scaleform::GFx::AS2::GASSharedObjectLoader *this,
        Scaleform::GFx::ASStringNode *name)
{
  Scaleform::GFx::AS2::ArrayObject *v3; // ebp
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *p_ObjectStack; // edi
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // ebx
  const Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  const Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  unsigned int v11; // esi
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // edx
  Scaleform::GFx::AS2::Object **v13; // esi
  unsigned int RefCount; // eax
  char v15; // [esp+13h] [ebp-19h] BYREF
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v16; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value v17; // [esp+1Ch] [ebp-10h] BYREF

  v3 = (Scaleform::GFx::AS2::ArrayObject *)this->ObjectStack.Data.Data[this->ObjectStack.Data.Size - 1];
  p_ObjectStack = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ObjectStack;
  v5 = Scaleform::GFx::AS2::Environment::OperatorNew(
         this->pEnv,
         this->pEnv->StringContext.pContext->pGlobal.pObject,
         (const Scaleform::GFx::ASString *)&this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
         0,
         -1);
  v6 = v5;
  if ( this->bArrayIsTop )
  {
    Scaleform::GFx::AS2::Value::Value(&v17, v5);
    Scaleform::GFx::AS2::ArrayObject::PushBack(v3, v7);
  }
  else
  {
    pEnv = this->pEnv;
    v15 = 0;
    name = Scaleform::GFx::ASStringManager::CreateStringNode(
             (Scaleform::GFx::ASStringManager *)pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             (__m128i *)(((int)name->pData & 0xFFFFFFFC) + 8),
             *(_DWORD *)((int)name->pData & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++name->RefCount;
    v16 = v3->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
    Scaleform::GFx::AS2::Value::Value(&v17, v6);
    v16->SetMember(
      &v3->Scaleform::GFx::AS2::ObjectInterface,
      this->pEnv,
      (const Scaleform::GFx::ASString *)&name,
      v9,
      (const Scaleform::GFx::AS2::PropFlags *)&v15);
    v10 = name;
    --name->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  this->bArrayIsTop = 1;
  v11 = this->ObjectStack.Data.Size + 1;
  if ( v11 >= p_ObjectStack->Size )
  {
    if ( v11 >= p_ObjectStack->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ObjectStack,
        p_ObjectStack,
        v11 + (v11 >> 2));
  }
  else if ( v11 < p_ObjectStack->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ObjectStack,
      p_ObjectStack,
      p_ObjectStack->Size + 1);
  }
  Data = p_ObjectStack->Data;
  p_ObjectStack->Size = v11;
  v13 = (Scaleform::GFx::AS2::Object **)&Data[v11 - 1];
  if ( v13 )
    *v13 = v6;
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
}
