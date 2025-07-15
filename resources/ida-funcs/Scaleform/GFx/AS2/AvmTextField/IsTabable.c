bool __thiscall Scaleform::GFx::AS2::AvmTextField::IsTabable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::Object *pObject; // ebx
  const Scaleform::GFx::AS2::Environment *(__thiscall *GetASEnvironment)(Scaleform::GFx::AS2::AvmCharacter *); // edx
  const Scaleform::GFx::AS2::Environment *v4; // ebp
  bool v5; // bl
  Scaleform::GFx::ASStringNode *v6; // eax
  bool v7; // bl
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v10; // [esp+10h] [ebp-10h] BYREF

  pObject = this->pProto.pObject;
  if ( !pObject )
    return (unsigned __int8)Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)this->pDispObj) == 0;
  GetASEnvironment = this->GetASEnvironment;
  v10.T.Type = 0;
  v4 = GetASEnvironment(this);
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "tabEnabled",
                      0xAu,
                      0);
  ++ConstStringNode->RefCount;
  v5 = pObject->GetMemberRaw(
         &pObject->Scaleform::GFx::AS2::ObjectInterface,
         &v4->StringContext,
         (const Scaleform::GFx::ASString *)&ConstStringNode,
         &v10);
  v6 = ConstStringNode;
  --ConstStringNode->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( !v5 || !v10.T.Type || v10.T.Type == 10 )
  {
    if ( v10.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v10);
    return (unsigned __int8)Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)this->pDispObj) == 0;
  }
  v7 = Scaleform::GFx::AS2::Value::ToBool(&v10, (int)this, v4);
  if ( v10.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v10);
  return v7;
}


bool __thiscall Scaleform::GFx::AS2::AvmTextField::IsTabable(char *this)
{
  return Scaleform::GFx::AS2::AvmTextField::IsTabable((Scaleform::GFx::AS2::AvmTextField *)(this - 24));
}
