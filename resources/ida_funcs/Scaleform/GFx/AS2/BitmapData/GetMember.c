char __thiscall Scaleform::GFx::AS2::BitmapData::GetMember(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edi
  unsigned int v5; // esi
  unsigned int v7; // edi
  _BYTE v8[8]; // [esp+10h] [ebp-8h] BYREF

  pLocalFrame = this->ResolveHandler.pLocalFrame;
  if ( !pLocalFrame )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::BitmapData *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::BitmapData)(
             this,
             &penv->StringContext,
             name,
             val);
  if ( !strcmp(name->pNode->pData, "width") )
  {
    if ( pLocalFrame->RefCount )
      v5 = *(_DWORD *)(*(int (__thiscall **)(unsigned int, _BYTE *))(*(_DWORD *)pLocalFrame->RefCount + 20))(
                        pLocalFrame->RefCount,
                        v8);
    else
      v5 = 0;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    val->T.Type = 3;
    val->NV.NumberValue = (double)v5;
    return 1;
  }
  if ( strcmp(name->pNode->pData, "height") )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::BitmapData *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::BitmapData)(
             this,
             &penv->StringContext,
             name,
             val);
  if ( pLocalFrame->RefCount )
    v7 = *(_DWORD *)((*(int (__thiscall **)(unsigned int, _BYTE *))(*(_DWORD *)pLocalFrame->RefCount + 20))(
                       pLocalFrame->RefCount,
                       v8)
                   + 4);
  else
    v7 = 0;
  if ( val->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(val);
  val->T.Type = 3;
  val->NV.NumberValue = (double)v7;
  return 1;
}
