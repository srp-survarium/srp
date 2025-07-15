void __thiscall Scaleform::GFx::AS2::SharedObject::SetDataObject(
        Scaleform::GFx::AS2::SharedObject *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::AS2::Object *pobj)
{
  Scaleform::GFx::AS2::Environment *v3; // edi
  Scaleform::GFx::ASStringManager *v5; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::AS2::Object *v7; // ecx
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS2::PropFlags v10; // [esp+Bh] [ebp-11h] BYREF
  Scaleform::GFx::AS2::Value v11; // [esp+Ch] [ebp-10h] BYREF

  v3 = (Scaleform::GFx::AS2::Environment *)penv;
  v5 = *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(penv[4].Size + 20) + 12) + 788);
  v10.Flags = 0;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v5, "data", 4u, 0);
  v7 = pobj;
  penv = ConstStringNode;
  ++ConstStringNode->RefCount;
  Scaleform::GFx::AS2::Value::Value(&v11, v7);
  Scaleform::GFx::AS2::Object::SetMember(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v3,
    (const Scaleform::GFx::ASString *)&penv,
    v8,
    &v10);
  v9 = penv;
  --penv->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}
