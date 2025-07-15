void __thiscall Scaleform::GFx::AS2::MovieRoot::CreateFunction(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        Scaleform::GFx::Resource *pfc,
        void *puserData)
{
  Scaleform::GFx::AS2::Environment *v5; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS2::UserDefinedFunctionObject *v8; // eax
  Scaleform::GFx::AS2::FunctionObject *v9; // eax
  Scaleform::GFx::AS2::FunctionObject *v10; // esi
  unsigned int RefCount; // eax
  unsigned int v12; // eax
  Scaleform::GFx::AS2::FunctionRefBase func; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+18h] [ebp-10h] BYREF

  v5 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(char *))(*((_DWORD *)&this->pMovieImpl->pMainMovie->__vftable
                                                                           + this->pMovieImpl->pMainMovie->AvmObjOffset)
                                                                         + 124))(
                                             (char *)&this->pMovieImpl->pMainMovie->__vftable
                                           + 4 * this->pMovieImpl->pMainMovie->AvmObjOffset);
  pHeap = v5->StringContext.pContext->pHeap;
  Alloc = pHeap->Alloc;
  value.T.Type = 0;
  v8 = (Scaleform::GFx::AS2::UserDefinedFunctionObject *)Alloc(pHeap, 60u, 0);
  if ( v8 )
  {
    Scaleform::GFx::AS2::UserDefinedFunctionObject::UserDefinedFunctionObject(v8, &v5->StringContext, pfc, puserData);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  func.Flags = 0;
  func.Function = v10;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
  func.pLocalFrame = 0;
  Scaleform::GFx::AS2::Value::SetAsFunction(&value, &func);
  if ( v10 )
  {
    RefCount = v10->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v10->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v5, &value, pvalue);
  if ( v10 )
  {
    v12 = v10->RefCount;
    if ( (v12 & 0x3FFFFFF) != 0 )
    {
      v10->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
}
