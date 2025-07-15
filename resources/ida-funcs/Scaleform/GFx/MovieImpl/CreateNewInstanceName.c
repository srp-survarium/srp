Scaleform::GFx::ASString *__thiscall Scaleform::GFx::MovieImpl::CreateNewInstanceName(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringManager *v3; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::MsgFormat::Sink v6; // [esp+8h] [ebp-3Ch] BYREF
  char pstr[48]; // [esp+14h] [ebp-30h] BYREF

  ++this->InstanceNameCount;
  memset(pstr, 0, sizeof(pstr));
  v6.Type = tDataPtr;
  v6.SinkData.pStr = (Scaleform::String *)pstr;
  v6.SinkData.DataPtr.Size = 48;
  Scaleform::Format<unsigned long>(&v6, "instance{0}", &this->InstanceNameCount);
  v3 = this->pASMovieRoot.pObject->GetStringManager(this->pASMovieRoot.pObject);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(v3, pstr);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
