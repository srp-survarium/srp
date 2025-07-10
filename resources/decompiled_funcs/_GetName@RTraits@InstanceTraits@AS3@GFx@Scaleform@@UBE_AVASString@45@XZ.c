Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::InstanceTraits::RTraits::GetName(
        Scaleform::GFx::AS3::InstanceTraits::RTraits *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASString *v3; // eax

  pNode = this->Name.pNode;
  v3 = result;
  ++pNode->RefCount;
  result->pNode = pNode;
  return v3;
}
