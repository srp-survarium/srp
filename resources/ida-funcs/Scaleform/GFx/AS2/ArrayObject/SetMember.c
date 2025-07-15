char __thiscall Scaleform::GFx::AS2::ArrayObject::SetMember(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  volatile int *p_RefCount; // ebx
  bool v7; // zf
  int v8; // eax
  int v10; // eax
  int v11; // ebx
  bool v12; // cc
  _BYTE *v13; // eax

  p_RefCount = &penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].RefCount;
  if ( penv->StringContext.SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v7 = *(Scaleform::GFx::ASStringNode **)(*p_RefCount + 8) == name->pNode->pLower;
  }
  else
  {
    v7 = (Scaleform::GFx::ASStringNode *)*p_RefCount == name->pNode;
  }
  if ( v7 )
  {
    v8 = Scaleform::GFx::AS2::Value::ToInt32(val, 0);
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)((char *)this - 16), v8 < 0 ? 0 : v8);
    LOBYTE(this->Elements.Data.Size) = 1;
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
  }
  else
  {
    v10 = Scaleform::GFx::AS2::ArrayObject::ParseIndex(name);
    v11 = v10;
    if ( v10 < 0 )
    {
      return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
    }
    else
    {
      v12 = v10 < (int)this->pWatchpoints;
      LOBYTE(this->Elements.Data.Size) = 0;
      if ( !v12 )
        Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)((char *)this - 16), v10 + 1);
      if ( !*(_DWORD *)(*(_DWORD *)&this->ResolveHandler.Flags + 4 * v11) )
      {
        v13 = penv->StringContext.pContext->pHeap->Alloc(penv->StringContext.pContext->pHeap, 16, 0);
        if ( v13 )
          *v13 = 0;
        else
          v13 = 0;
        *(_DWORD *)(*(_DWORD *)&this->ResolveHandler.Flags + 4 * v11) = v13;
      }
      Scaleform::GFx::AS2::Value::operator=(
        *(Scaleform::GFx::AS2::Value **)(*(_DWORD *)&this->ResolveHandler.Flags + 4 * v11),
        val);
      return 1;
    }
  }
}
