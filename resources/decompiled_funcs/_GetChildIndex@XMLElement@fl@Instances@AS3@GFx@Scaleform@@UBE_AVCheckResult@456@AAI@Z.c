Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::GetChildIndex(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int *ind)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  Scaleform::GFx::ASStringNode *pNode; // edi
  unsigned int v5; // edx
  Scaleform::GFx::AS3::CheckResult *v6; // eax

  pObject = this->Parent.pObject;
  if ( pObject )
  {
    pNode = pObject[1].Text.pNode;
    *ind = 0;
    if ( pNode )
    {
      while ( *((Scaleform::GFx::AS3::Instances::fl::XMLElement **)&pObject[1].pUserDataHolder->pMovieView + *ind) != this )
      {
        v5 = *ind + 1;
        *ind = v5;
        if ( v5 >= (unsigned int)pNode )
        {
          v6 = result;
          result->Result = 0;
          return v6;
        }
      }
      v6 = result;
      result->Result = 1;
    }
    else
    {
      v6 = result;
      result->Result = 0;
    }
  }
  else
  {
    v6 = result;
    result->Result = 0;
  }
  return v6;
}
