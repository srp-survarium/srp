char __thiscall Scaleform::GFx::AS2::MovieRoot::CreateObjectValue(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pval,
        Scaleform::GFx::Value::ObjectInterface *pobjifc,
        Scaleform::GFx::CharacterHandle *pdata,
        bool isdobj)
{
  int v5; // edi
  Scaleform::GFx::InteractiveObject *v6; // eax
  Scaleform::GFx::DisplayObject **p_pCharacter; // eax

  v5 = 8;
  if ( isdobj )
  {
    v5 = 10;
    v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieImpl);
    if ( !v6 || (v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
      return 0;
  }
  else
  {
    if ( (unsigned int)((*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *))(pdata->RefCount + 8))(pdata) - 6) > 0x26 )
      p_pCharacter = 0;
    else
      p_pCharacter = &pdata[-1].pCharacter;
    if ( ((int (__thiscall *)(char *))p_pCharacter[4]->pWeakProxy)((char *)p_pCharacter + 16) == 7 )
      v5 = 9;
  }
  if ( (pval->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(pval, pval->mValue.IValue);
    pval->pObjectInterface = 0;
  }
  pval->Type = v5 | 0x40;
  pval->mValue.IValue = (int)pdata;
  pval->pObjectInterface = pobjifc;
  pobjifc->ObjectAddRef(pobjifc, pval, pdata);
  return 1;
}
