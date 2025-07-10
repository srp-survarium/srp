void __thiscall Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes_::_2_::DataSizeEstimator::Visit(
        Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes::__l2::DataSizeEstimator *this,
        Scaleform::GFx::ASStringNode *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::ASStringNode *v5; // ecx
  Scaleform::GFx::AS2::Object *v7; // eax

  this->SizeInBytes += *((_DWORD *)name->pData + 5);
  switch ( val->T.Type )
  {
    case 3u:
    case 4u:
      this->SizeInBytes += 4;
      break;
    case 5u:
      Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&name, this->pEnv, -1, 0);
      v5 = name;
      this->SizeInBytes += name->Size;
      if ( v5->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      break;
    case 6u:
      v7 = Scaleform::GFx::AS2::Value::ToObject(val, this->pEnv);
      v7->VisitMembers(&v7->Scaleform::GFx::AS2::ObjectInterface, &this->pEnv->StringContext, this, 0, 0);
      break;
    default:
      return;
  }
}
