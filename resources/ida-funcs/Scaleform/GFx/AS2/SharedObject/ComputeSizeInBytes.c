unsigned int __thiscall Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes(
        Scaleform::GFx::AS2::SharedObject *this,
        Scaleform::GFx::ASStringNode *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // edi
  Scaleform::GFx::AS2::GlobalContext *Size; // eax
  Scaleform::GFx::AS2::ASStringContext *p_Size; // esi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  unsigned int SizeInBytes; // esi
  Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes::__l2::DataSizeEstimator visitor; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+28h] [ebp-10h] BYREF

  v2 = (Scaleform::GFx::AS2::Environment *)penv;
  Size = (Scaleform::GFx::AS2::GlobalContext *)penv[4].Size;
  val.T.Type = 0;
  p_Size = (Scaleform::GFx::AS2::ASStringContext *)&penv[4].Size;
  penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(
           (Scaleform::GFx::ASStringManager *)Size->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
           "data",
           4u,
           0);
  ++penv->RefCount;
  this->GetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, p_Size, (const Scaleform::GFx::ASString *)&penv, &val);
  v6 = penv;
  --penv->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v7 = Scaleform::GFx::AS2::Value::ToObject(&val, v2);
  visitor.__vftable = (Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes::__l2::DataSizeEstimator_vtbl *)&`Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes'::`2'::DataSizeEstimator::`vftable';
  visitor.pEnv = v2;
  visitor.SizeInBytes = 0;
  v7->VisitMembers(&v7->Scaleform::GFx::AS2::ObjectInterface, p_Size, &visitor, 0, 0);
  SizeInBytes = visitor.SizeInBytes;
  visitor.__vftable = (Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes::__l2::DataSizeEstimator_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return SizeInBytes;
}
