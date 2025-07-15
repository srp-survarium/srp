char __thiscall Scaleform::GFx::AS2::ArrayObject::GetMemberRaw(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  const char *pData; // ecx
  char v6; // al
  int v7; // eax
  int v8; // ecx
  const Scaleform::GFx::AS2::Value **v9; // eax
  volatile int *p_RefCount; // esi
  bool v12; // zf
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // ebx

  pData = name->pNode->pData;
  v6 = *pData;
  if ( !*pData )
    goto LABEL_7;
  while ( v6 >= 48 && v6 <= 57 )
  {
    v6 = *++pData;
    if ( !v6 )
      goto LABEL_7;
  }
  if ( !*pData )
  {
LABEL_7:
    v7 = atoi(name->pNode->pData);
    if ( v7 >= 0 )
    {
      if ( v7 >= (int)this->pWatchpoints
        || (v8 = *(_DWORD *)&this->ResolveHandler.Flags,
            v12 = *(_DWORD *)(v8 + 4 * v7) == 0,
            v9 = (const Scaleform::GFx::AS2::Value **)(v8 + 4 * v7),
            v12) )
      {
        Scaleform::GFx::AS2::Value::DropRefs(val);
        val->T.Type = 0;
        return 1;
      }
      else
      {
        Scaleform::GFx::AS2::Value::operator=(val, *v9);
        return 1;
      }
    }
  }
  p_RefCount = &psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].RefCount;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v12 = *(Scaleform::GFx::ASStringNode **)(*p_RefCount + 8) == name->pNode->pLower;
  }
  else
  {
    v12 = (Scaleform::GFx::ASStringNode *)*p_RefCount == name->pNode;
  }
  if ( !v12 || LOBYTE(this->Elements.Data.Size) && !this->pWatchpoints )
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
  pWatchpoints = this->pWatchpoints;
  if ( val->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(val);
  val->NV.Int32Value = (int)pWatchpoints;
  val->T.Type = 4;
  LOBYTE(this->Elements.Data.Size) = 0;
  return 1;
}
