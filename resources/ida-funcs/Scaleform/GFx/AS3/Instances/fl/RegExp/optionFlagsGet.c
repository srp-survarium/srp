Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::optionFlagsGet(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  char *v4; // edx
  char *v5; // edx
  char *v6; // edx
  char *v7; // edx
  char *v8; // edx

  p_EmptyStringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v4 = "g";
  if ( !this->IsGlobal )
    v4 = (char *)&buf;
  Scaleform::GFx::ASString::Append(result, v4, (Scaleform::GFx::ASStringNode *)strlen(v4));
  v5 = "i";
  if ( (this->OptionFlags & 1) == 0 )
    v5 = (char *)&buf;
  Scaleform::GFx::ASString::Append(result, v5, (Scaleform::GFx::ASStringNode *)strlen(v5));
  v6 = "m";
  if ( (this->OptionFlags & 2) == 0 )
    v6 = (char *)&buf;
  Scaleform::GFx::ASString::Append(result, v6, (Scaleform::GFx::ASStringNode *)strlen(v6));
  v7 = "s";
  if ( (this->OptionFlags & 4) == 0 )
    v7 = (char *)&buf;
  Scaleform::GFx::ASString::Append(result, v7, (Scaleform::GFx::ASStringNode *)strlen(v7));
  v8 = "x";
  if ( (this->OptionFlags & 8) == 0 )
    v8 = (char *)&buf;
  Scaleform::GFx::ASString::Append(result, v8, (Scaleform::GFx::ASStringNode *)strlen(v8));
  return result;
}
