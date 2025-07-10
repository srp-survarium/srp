char __usercall Scaleform::GFx::AS3::Instances::fl::IsWhiteSpaceString@<al>(const Scaleform::GFx::ASString *str@<edi>)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v2; // esi

  pNode = str->pNode;
  v2 = 0;
  if ( !str->pNode->Size )
    return 1;
  while ( Scaleform::GFx::ASUtils::IsWhiteSpace(pNode->pData[v2]) )
  {
    pNode = str->pNode;
    if ( ++v2 >= str->pNode->Size )
      return 1;
  }
  return 0;
}
