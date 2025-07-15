Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::InstanceTraits::CTraits::GetName(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::ASString *result)
{
  char *Name; // edx
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax

  Name = (char *)this->CI->Type->Name;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pVM->StringManagerRef->pStringManager,
                      Name,
                      strlen(Name),
                      0);
  ++ConstStringNode->RefCount;
  result->pNode = ConstStringNode;
  return result;
}
