char __thiscall Scaleform::GFx::AS2ValueObjectInterface::Invoke(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        Scaleform::GFx::Value *presult,
        char *name,
        const Scaleform::GFx::Value *pargs,
        unsigned int nargs,
        bool isdobj)
{
  Scaleform::GFx::AS2::ObjectInterface *pObject; // edi
  Scaleform::GFx::AS2::Environment *pEnv; // ebp
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  const Scaleform::GFx::Value *v11; // edi
  unsigned int v12; // ebx
  char v13; // bl
  Scaleform::GFx::Value_AS2ObjectData o; // [esp+4h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::Value result; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value member; // [esp+20h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value asArg; // [esp+30h] [ebp-10h] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&o, this, pdata, isdobj);
  pObject = o.pObject;
  if ( !o.pObject )
    return 0;
  pEnv = o.pEnv;
  member.T.Type = 0;
  result.T.Type = 0;
  if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(o.pObject, &o.pEnv->StringContext, name, &member) )
  {
    asArg.T.Type = 0;
    if ( (int)(nargs - 1) > -1 )
    {
      p_pCurrent = &pEnv->Stack.pCurrent;
      v11 = &pargs[nargs - 1];
      v12 = nargs;
      do
      {
        Scaleform::GFx::AS2::MovieRoot::Value2ASValue(o.pRoot, v11, &asArg);
        ++*p_pCurrent;
        if ( pEnv->Stack.pCurrent >= pEnv->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&pEnv->Stack);
        if ( *p_pCurrent )
          Scaleform::GFx::AS2::Value::Value(*p_pCurrent, &asArg);
        --v11;
        --v12;
      }
      while ( v12 );
      pObject = o.pObject;
    }
    v13 = Scaleform::GFx::AS2::GAS_Invoke(
            &member,
            &result,
            pObject,
            pEnv,
            nargs,
            pEnv->Stack.pCurrent - pEnv->Stack.pPageStart + 32 * pEnv->Stack.Pages.Data.Size - 32,
            0);
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&pEnv->Stack, nargs);
    if ( presult )
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(o.pRoot, pEnv, &result, presult);
    if ( asArg.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&asArg);
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
    if ( member.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&member);
    return v13;
  }
  else
  {
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
    if ( member.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&member);
    return 0;
  }
}
