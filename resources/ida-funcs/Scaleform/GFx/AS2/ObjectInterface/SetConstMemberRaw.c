bool __thiscall Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::ASStringNode *psc,
        char *pname,
        const Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // edi
  const char *pData; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  bool v8; // bl
  Scaleform::GFx::ASStringNode *v9; // eax
  const Scaleform::GFx::AS2::Value *v11; // [esp-8h] [ebp-1Ch]
  char v12; // [esp+13h] [ebp-1h] BYREF

  v4 = (Scaleform::GFx::AS2::ASStringContext *)psc;
  pData = psc->pData;
  v12 = 0;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*((_DWORD *)pData + 5) + 12) + 788),
                      pname,
                      strlen(pname),
                      0);
  v11 = val;
  psc = ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = this->SetMemberRaw(
         this,
         v4,
         (const Scaleform::GFx::ASString *)&psc,
         v11,
         (const Scaleform::GFx::AS2::PropFlags *)&v12);
  v9 = psc;
  --psc->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return v8;
}


bool __thiscall Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::ASStringNode *psc,
        char *pname,
        const Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::ASStringContext *v5; // edi
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  bool v8; // bl
  Scaleform::GFx::ASStringNode *v9; // eax
  const Scaleform::GFx::AS2::Value *v11; // [esp-8h] [ebp-18h]
  const Scaleform::GFx::AS2::PropFlags *v12; // [esp-4h] [ebp-14h]

  v5 = (Scaleform::GFx::AS2::ASStringContext *)psc;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*((_DWORD *)psc->pData + 5) + 12) + 788),
                      pname,
                      strlen(pname),
                      0);
  v12 = flags;
  v11 = val;
  psc = ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = this->SetMemberRaw(this, v5, (const Scaleform::GFx::ASString *)&psc, v11, v12);
  v9 = psc;
  --psc->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return v8;
}
