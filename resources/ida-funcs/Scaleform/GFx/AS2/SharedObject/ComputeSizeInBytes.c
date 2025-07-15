int __thiscall Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes(
        Scaleform::GFx::AS2::SharedObject *this,
        Scaleform::GFx::ASStringNode *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // edi
  unsigned int Size; // eax
  Scaleform::GFx::AS2::ASStringContext *p_Size; // esi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  int v8; // esi
  _DWORD v10[2]; // [esp+1Ch] [ebp-1Ch] BYREF
  int v11; // [esp+24h] [ebp-14h]
  Scaleform::GFx::AS2::Value v12; // [esp+28h] [ebp-10h] BYREF

  v2 = (Scaleform::GFx::AS2::Environment *)penv;
  Size = penv[4].Size;
  v12.T.Type = 0;
  p_Size = (Scaleform::GFx::AS2::ASStringContext *)&penv[4].Size;
  penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(
           *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(Size + 20) + 12) + 788),
           "data",
           4u,
           0);
  ++penv->RefCount;
  this->GetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, p_Size, (const Scaleform::GFx::ASString *)&penv, &v12);
  v6 = penv;
  --penv->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v7 = Scaleform::GFx::AS2::Value::ToObject(&v12, v2);
  v10[0] = &`Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes'::`2'::DataSizeEstimator::`vftable';
  v10[1] = v2;
  v11 = 0;
  v7->VisitMembers(
    &v7->Scaleform::GFx::AS2::ObjectInterface,
    p_Size,
    (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)v10,
    0,
    0);
  v8 = v11;
  v10[0] = &Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( v12.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v12);
  return v8;
}
