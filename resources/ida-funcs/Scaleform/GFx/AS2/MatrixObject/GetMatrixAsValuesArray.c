Scaleform::GFx::AS2::Value (*__thiscall Scaleform::GFx::AS2::MatrixObject::GetMatrixAsValuesArray(
        Scaleform::GFx::AS2::MatrixObject *this,
        Scaleform::GFx::ASStringNode *psc,
        Scaleform::GFx::AS2::Value (*marr)[6]))[6]
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi
  Scaleform::GFx::AS2::Value v; // [esp+10h] [ebp-10h] BYREF

  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
          &this->Scaleform::GFx::AS2::ObjectInterface,
          psc,
          (char *)&stru_809F70,
          (Scaleform::GFx::AS2::Value *)marr) )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 1;
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)marr, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, psc, "b", &(*marr)[1]) )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 0;
    Scaleform::GFx::AS2::Value::operator=(&(*marr)[1], &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, psc, "c", &(*marr)[2]) )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 0;
    Scaleform::GFx::AS2::Value::operator=(&(*marr)[2], &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, psc, "d", &(*marr)[3]) )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 1;
    Scaleform::GFx::AS2::Value::operator=(&(*marr)[3], &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, psc, "tx", &(*marr)[4]) )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 0;
    Scaleform::GFx::AS2::Value::operator=(&(*marr)[4], &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( !Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v3, psc, "ty", &(*marr)[5]) )
  {
    v.T.Type = 4;
    v.NV.Int32Value = 0;
    Scaleform::GFx::AS2::Value::operator=(&(*marr)[5], &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  return marr;
}
