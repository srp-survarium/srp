void __cdecl Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  int v3; // eax
  Scaleform::GFx::State *(__thiscall *GetStateAddRef)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // edx
  Scaleform::GFx::StateBag *v5; // esi
  Scaleform::RefCountVImpl *v6; // eax
  Scaleform::GFx::FontLib *v7; // edi
  Scaleform::RefCountVImpl *v8; // eax
  Scaleform::RefCountVImpl *v9; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ArrayObject *v11; // eax
  Scaleform::GFx::AS2::ArrayObject *v12; // eax
  const Scaleform::GFx::AS2::FnCall **p_fn; // ecx
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::ObjectInterface **p_ThisPtr; // ecx
  const Scaleform::GFx::AS2::FnCall **v16; // edi
  int v17; // esi
  const Scaleform::GFx::AS2::FnCall *v18; // ecx
  Scaleform::GFx::ASStringNode *StringNode; // eax
  bool v20; // zf
  Scaleform::GFx::AS2::Value *Result; // eax
  Scaleform::GFx::AS2::ObjectInterface **v22; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ArrayObject *v24; // [esp+1Ch] [ebp-1Ch]
  _DWORD v25[2]; // [esp+20h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+28h] [ebp-10h] BYREF

  v1 = fn;
  pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
  v3 = (int)pMovieImpl->GetMovieDef(pMovieImpl);
  v25[1] = &fn;
  fn = 0;
  v25[0] = &`Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList'::`2'::FontsVisitor::`vftable';
  (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)v3 + 104))(v3, v25, 1);
  GetStateAddRef = pMovieImpl->GetStateAddRef;
  v5 = &pMovieImpl->Scaleform::GFx::StateBag;
  v6 = (Scaleform::RefCountVImpl *)GetStateAddRef(v5, State_FontLib);
  v7 = (Scaleform::GFx::FontLib *)v6;
  if ( v6 )
  {
    Scaleform::RefCountImpl::Release(v6);
    Scaleform::GFx::FontLib::LoadFontNames(
      v7,
      (Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *)&fn);
  }
  v8 = (Scaleform::RefCountVImpl *)v5->GetStateAddRef(v5, State_FontProvider);
  v9 = v8;
  if ( v8 )
  {
    Scaleform::RefCountImpl::Release(v8);
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, const Scaleform::GFx::AS2::FnCall **))v9->Release)(v9, &fn);
  }
  pHeap = v1->Env->StringContext.pContext->pHeap;
  v11 = (Scaleform::GFx::AS2::ArrayObject *)pHeap->Alloc(pHeap, 80u, 0);
  if ( v11 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v11, v1->Env);
    v24 = v12;
  }
  else
  {
    v24 = 0;
  }
  p_fn = (const Scaleform::GFx::AS2::FnCall **)fn;
  if ( fn )
  {
    v14 = 0;
    p_ThisPtr = &fn->ThisPtr;
    do
    {
      if ( *p_ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)-2 )
        break;
      v14 = (Scaleform::GFx::AS2::Value *)((char *)v14 + 1);
      p_ThisPtr += 4;
    }
    while ( v14 <= fn->Result );
    p_fn = &fn;
  }
  else
  {
    v14 = 0;
  }
  v16 = p_fn;
  v17 = (int)v14;
  while ( v16 )
  {
    v18 = *v16;
    if ( !*v16 || v17 > (int)v18->Result )
      break;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   (__m128i *)(((int)*(&v18->ThisFunctionRef.pLocalFrame + 4 * v17) & 0xFFFFFFFC) + 8),
                   *(_DWORD *)((int)*(&v18->ThisFunctionRef.pLocalFrame + 4 * v17) & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++StringNode->RefCount;
    v20 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    val.T.Type = 5;
    val.NV.Int32Value = (int)StringNode;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    Scaleform::GFx::AS2::ArrayObject::PushBack(v24, &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    Result = (*v16)->Result;
    if ( v17 <= (int)Result && ++v17 <= (unsigned int)Result )
    {
      v22 = &(*v16)->ThisPtr + 4 * v17;
      do
      {
        if ( *v22 != (Scaleform::GFx::AS2::ObjectInterface *)-2 )
          break;
        ++v17;
        v22 += 4;
      }
      while ( v17 <= (unsigned int)Result );
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v24);
  if ( v24 )
  {
    RefCount = v24->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v24->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
    }
  }
  v25[0] = &Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&fn);
}
