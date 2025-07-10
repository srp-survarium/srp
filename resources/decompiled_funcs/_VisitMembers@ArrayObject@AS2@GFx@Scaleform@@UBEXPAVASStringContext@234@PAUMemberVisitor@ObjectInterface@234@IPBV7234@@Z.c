void __thiscall Scaleform::GFx::AS2::ArrayObject::VisitMembers(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags,
        unsigned int instance)
{
  Scaleform::GFx::AS2::ArrayObject *v5; // esi
  const Scaleform::GFx::AS2::ObjectInterface *pWatchpoints; // ecx
  unsigned int i; // edi
  const Scaleform::GFx::AS2::Value **v8; // eax
  const Scaleform::GFx::AS2::Value **v9; // esi
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::StringDataPtr result; // [esp+1Ch] [ebp-58h] BYREF
  Scaleform::LongFormatter f; // [esp+24h] [ebp-50h] BYREF
  unsigned int n; // [esp+80h] [ebp+Ch]

  v5 = this;
  Scaleform::GFx::AS2::Object::VisitMembers(this, psc, pvisitor, visitFlags, (Scaleform::GFx::AS2::Object *)instance);
  pWatchpoints = (const Scaleform::GFx::AS2::ObjectInterface *)v5->pWatchpoints;
  n = (unsigned int)pWatchpoints;
  instance = 8;
  if ( (unsigned int)pWatchpoints <= 7 )
    instance = (unsigned int)pWatchpoints;
  for ( i = 0; i < instance; ++i )
  {
    v8 = (const Scaleform::GFx::AS2::Value **)(*(_DWORD *)&v5->ResolveHandler.Flags + 4 * i);
    if ( *v8 )
    {
      pvisitor->Visit(
        pvisitor,
        (const Scaleform::GFx::ASString *)(&psc->pContext->pMovieRoot->pASMovieRoot.pObject[36].AVMVersion + 4 * i),
        *v8,
        0);
      pWatchpoints = (const Scaleform::GFx::AS2::ObjectInterface *)n;
    }
  }
  for ( ; i < (unsigned int)pWatchpoints; ++i )
  {
    if ( *(_DWORD *)(*(_DWORD *)&v5->ResolveHandler.Flags + 4 * i) )
    {
      Scaleform::LongFormatter::LongFormatter(&f, i);
      Scaleform::LongFormatter::Convert(&f);
      Scaleform::DoubleFormatter::GetResult((Scaleform::DoubleFormatter *)&f, &result);
      v9 = (const Scaleform::GFx::AS2::Value **)(4 * i + *(_DWORD *)&v5->ResolveHandler.Flags);
      instance = (unsigned int)Scaleform::GFx::ASStringManager::CreateStringNode(
                                 (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                 (char *)result.pStr,
                                 result.Size);
      ++*(_DWORD *)(instance + 12);
      pvisitor->Visit(pvisitor, (const Scaleform::GFx::ASString *)&instance, *v9, 0);
      v10 = (Scaleform::GFx::ASStringNode *)instance;
      --*(_DWORD *)(instance + 12);
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Formatter::~Formatter(&f);
      v5 = this;
      pWatchpoints = (const Scaleform::GFx::AS2::ObjectInterface *)n;
    }
  }
}
